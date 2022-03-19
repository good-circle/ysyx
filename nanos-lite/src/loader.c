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

static uintptr_t loader(PCB *pcb, const char *filename)
{
    Elf_Ehdr *ehdr = malloc(sizeof(Elf_Ehdr));
    Elf_Phdr *phdr = malloc(sizeof(Elf_Phdr));

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