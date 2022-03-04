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

    /* close elf_file */
    fclose(fp);

    /* read section headers */
    //Elf64_Shdr *shdr = ehdr + ehdr->e_shoff;

    printf("%d\n", ehdr->e_shnum);
}