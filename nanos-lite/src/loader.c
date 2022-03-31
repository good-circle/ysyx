#include <proc.h>
#include <elf.h>
#include <fs.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif

size_t ramdisk_read(void *buf, size_t offset, size_t len);
void *new_page(size_t nr_page);

static uintptr_t loader(PCB *pcb, const char *filename)
{
    Elf_Ehdr *ehdr = new_page(1);
    Elf_Phdr *phdr = new_page(1);

    /* read elf from ramdisk */
    int fd = fs_open(filename, 0, 0);
    fs_read(fd, ehdr, sizeof(Elf_Ehdr));

    /* assert if not elf file */
    //! pay attention: this is uint32_t not size_t
    assert(*(uint32_t *)ehdr->e_ident == 0x464c457f);

    /* read program header */
    for (int i = 0; i < ehdr->e_phnum; i++)
    {
        fs_lseek(fd, ehdr->e_phoff + i * ehdr->e_phentsize, SEEK_SET);
        fs_read(fd, phdr, ehdr->e_phentsize);
        if (phdr->p_type == PT_LOAD)
        {
            fs_lseek(fd, phdr->p_offset, SEEK_SET);
            fs_read(fd, (void *)phdr->p_vaddr, phdr->p_filesz);
            /* padding filesz ~ memsz zero */
            memset((void *)(phdr->p_vaddr + phdr->p_filesz), 0, phdr->p_memsz - phdr->p_filesz);
        }
    }
    return ehdr->e_entry;
}

void naive_uload(PCB *pcb, const char *filename)
{
    uintptr_t entry = loader(pcb, filename);
    Log("Jump to entry = %p", entry);
    ((void (*)())entry)();
}

void context_kload(PCB *pcb, void (*entry)(void *), void *arg)
{
    Area kstack;
    kstack.start = pcb;
    kstack.end = kstack.start + STACK_SIZE;

    pcb->cp = kcontext(kstack, entry, arg);
}

void context_uload(PCB *pcb, const char *filename, char *const argv[], char *const envp[])
{
    void *ustack = new_page(8) + 8 * PGSIZE;
    char *envp_buf[128];
    char *argv_buf[128];
    uintptr_t envp_num = 0;
    uintptr_t argc = 0;
    int i = 0;
    for (i = 0; envp[i] != NULL; i++)
    {
        ustack -= (strlen(envp[i]) + 1);
        envp_buf[i] = strcpy(ustack, envp[i]);
        //printf("envp %d = %s\n", i, envp[i]);
    }
    envp_num = i;

    for (i = 0; argv[i] != NULL; i++)
    {
        ustack -= (strlen(argv[i]) + 1);
        argv_buf[i] = strcpy(ustack, argv[i]);
        //printf("argv %d = %s\n", i, argv[i]);
    }
    argc = i;

    ustack -= sizeof((uintptr_t)NULL);
    *(uintptr_t *)ustack = (uintptr_t)NULL;

    int envp_size = envp_num * sizeof(char *);
    ustack -= envp_size;
    memcpy(ustack, envp_buf, envp_size);

    ustack -= sizeof((uintptr_t)NULL);
    *(uintptr_t *)ustack = (uintptr_t)NULL;

    int argv_size = argc * sizeof(char *);
    ustack -= argv_size;
    memcpy(ustack, argv_buf, argv_size);

    ustack -= sizeof((uintptr_t)NULL);
    *(uintptr_t *)ustack = (uintptr_t)NULL;

    ustack -= sizeof(uintptr_t);
    *(uintptr_t *)ustack = argc;

    /* load after copy argv and envp to stack,
     * or loader will cover these args.
     * pay attention! */
    uintptr_t entry = loader(pcb, filename);
    Log("uload: %s load to entry = %p", filename, entry);

    Area kstack;
    kstack.start = pcb;
    kstack.end = kstack.start + STACK_SIZE;
    pcb->cp = ucontext(NULL, kstack, (void (*)())entry);

    pcb->cp->GPRx = (uintptr_t)ustack;
}