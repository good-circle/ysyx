#include <common.h>

FILE *elf_fp = NULL;
void init_ftrace(const char *elf_file)
{
    elf_fp = stdout;
    if (elf_file != NULL)
    {
        FILE *fp = fopen(elf_file, "w");
        Assert(fp, "Can not open '%s'", elf_file);
        elf_fp = fp;
    }
    Log("Log is written to %s", elf_file ? elf_file : "stdout");
}