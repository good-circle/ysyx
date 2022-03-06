#include <common.h>
#include <elf.h>

typedef struct {
  Elf64_Word	st_name;
  unsigned char	st_info;
  unsigned char st_other;
  Elf64_Section	st_shndx;
  Elf64_Addr	st_value;
  Elf64_Xword	st_size;
} Elf64_Func;

void init_ftrace(const char *elf_file)
{
    /* return if there is no elf_file */
    if (elf_file == NULL)
    {
        Log("Usage: -f $(elf) to init ftrace");
        return;
    }

    /* open elf_file */
    FILE *fp = fopen(elf_file, "r");
    Assert(fp, "Can not open '%s'", elf_file);

    /* read elf_file size */
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    /* read elf_file to ehdr */
    Elf64_Ehdr *ehdr = malloc(size);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(ehdr, size, 1, fp);
    assert(ret == 1);
    printf("ehdr: %p\n", ehdr);

    /* close elf_file */
    fclose(fp);

    /* read section headers */
    Elf64_Shdr *shdr = (Elf64_Shdr *)((word_t)ehdr + ehdr->e_shoff);

    for (int i = 0; i < ehdr->e_shnum; i++)
    {
        if (shdr[i].sh_type == SHT_SYMTAB)
        {
            //Elf64_Sym *sym = (Elf64_Sym *)((word_t)ehdr + shdr[i].sh_offset);
            //int sym_num = shdr[i].sh_size / sizeof(Elf64_Sym);
        }
        else if (shdr[i].sh_type == SHT_STRTAB && i != ehdr->e_shstrndx)
        {
            //char *strtab =(char *)((word_t)ehdr + shdr[i].sh_offset);
        }
        printf("%d\n", shdr[i].sh_name);
    }
}