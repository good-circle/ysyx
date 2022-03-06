#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <common.h>
#include <elf.h>

typedef struct
{
    Elf64_Word st_name;
    Elf64_Addr st_value;
    Elf64_Xword st_size;
} Elf64_Func;

int func_num;
char *strtab;
Elf64_Func *func;

#endif