#include <common.h>
#include <elf.h>

Elf64_Ehdr *elf = NULL;
void init_ftrace(const char *elf_file)
{
    if (elf_file != NULL)
    {
        FILE *fp = fopen(elf_file, "r");
        Assert(fp, "Can not open '%s'", elf_file);

        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);

        fseek(fp, 0, SEEK_SET);
        int ret = fread(elf, size, 1, fp);
        assert(ret == 1);

        fclose(fp);
    }
    else
    {
        Log("Usage: -f $(elf) to init ftrace");
    }
}