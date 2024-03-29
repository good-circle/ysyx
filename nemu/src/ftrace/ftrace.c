#include <ftrace/ftrace.h>

int func_num = 0;
char *strtab = NULL;
Elf64_Func *func = NULL;

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
    long elf_size = ftell(fp);

    /* read elf_file to ehdr */
    Elf64_Ehdr *ehdr = malloc(elf_size);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(ehdr, elf_size, 1, fp);
    assert(ret == 1);

    /* close elf_file */
    fclose(fp);

    /* read section headers */
    Elf64_Shdr *shdr = (Elf64_Shdr *)((word_t)ehdr + ehdr->e_shoff);
    Elf64_Sym *sym = NULL;
    int sym_num = 0;

    for (int i = 0; i < ehdr->e_shnum; i++)
    {
        if (shdr[i].sh_type == SHT_SYMTAB)
        {
            /* read symbol table */
            sym = (Elf64_Sym *)((word_t)ehdr + shdr[i].sh_offset);
            sym_num = shdr[i].sh_size / sizeof(Elf64_Sym);
        }
        else if (shdr[i].sh_type == SHT_STRTAB && i != ehdr->e_shstrndx)
        {
            /* read strtab table */
            strtab = (char *)((word_t)ehdr + shdr[i].sh_offset);
        }
    }

    /* get function table */
    for (int i = 0; i < sym_num; i++)
    {
        if (ELF64_ST_TYPE(sym[i].st_info) == STT_FUNC)
        {
            func_num++;
        }
    }

    int func_size = sizeof(Elf64_Func) * func_num;
    func = malloc(func_size);

    int func_info = 0;
    for (int i = 0; i < sym_num; i++)
    {
        if (ELF64_ST_TYPE(sym[i].st_info) == STT_FUNC)
        {
            func[func_info].st_name = sym[i].st_name;
            func[func_info].st_value = sym[i].st_value;
            func[func_info].st_size = sym[i].st_size;
            func_info++;
        }
    }
}