#include <common.h>
#include <elf.h>

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
        if (shdr->sh_type == SHT_SYMTAB)
        {
            //Elf64_Sym *sym = (Elf64_Sym *)(((word_t)ehdr + shdr->sh_offset);
        }
        //else if(shdr->sh_type == SHT_STRTAB && )
        printf("%d\n", shdr->sh_name);
    }
}