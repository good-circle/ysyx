#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display()
{
    printf("%s\t\t0x%lx\t\t%ld\t\t\n", "pc", cpu.pc, cpu.pc);
    for (int i = 0; i < 31; i++)
    {
        printf("%s\t\t0x%lx\t\t%ld\t\t\n", regs[i], cpu.gpr[i], cpu.gpr[i]);
    }
}

word_t isa_reg_str2val(const char *s, bool *success)
{
    *success = true;
    if (strcmp(s, "pc") == 0)
    {
        return cpu.pc;
    }
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(s, regs[i]) == 0)
        {
            return cpu.gpr[i];
        }
    }

    /* In fact will not happen */
    *success = false;
    return 0;
}