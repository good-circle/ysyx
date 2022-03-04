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
    Elf64_Shdr *shdr = (Elf64_Shdr *)(ehdr + ehdr->e_shoff);
    printf("%lx\n", (word_t)ehdr);
    printf("%ld\n", ehdr->e_shoff);

    printf("%p\n", shdr);

    //printf("%d\n", ehdr->e_shnum);
    //for(int i = 0 ; i < ehdr->e_shnum; i++)
    //{
        //printf("%d\n", shdr[0].sh_name);
    //}
}