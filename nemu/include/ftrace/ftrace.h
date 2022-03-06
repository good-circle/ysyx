#include <common.h>
#include <elf.h>

typedef struct
{
    Elf64_Word st_name;
    Elf64_Addr st_value;
    Elf64_Xword st_size;
} Elf64_Func;

static int func_num = 0;
static char *strtab = NULL;
static Elf64_Func *func = NULL;