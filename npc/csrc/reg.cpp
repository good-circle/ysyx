#include "common.h"

extern Vtop *top;
uint64_t *cpu_gpr = NULL;
extern "C" void set_gpr_ptr(const svOpenArrayHandle r)
{
    cpu_gpr = (uint64_t *)(((VerilatedDpiOpenVar *)r)->datap());
}

const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

void isa_reg_display()
{
    printf("%s\t\t0x%lx\t\t%ld\t\t\n", "pc", top->pc, top->pc);
    for (int i = 0; i < 32; i++)
    {
        printf("%s\t\t0x%lx\t\t%ld\t\t\n", regs[i], cpu_gpr[i], cpu_gpr[i]);
    }
}

uint64_t isa_reg_str2val(const char *s, bool *success)
{
    *success = true;
    if (strcmp(s, "pc") == 0)
    {
        return top->pc;
    }
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(s, regs[i]) == 0)
        {
            return cpu_gpr[i];
        }
    }

    /* In fact will not happen */
    *success = false;
    return 0;
}

void difftest_read_regs(uint64_t *difftest_regs)
{
    for (int i = 0; i < 32; i++)
    {
        difftest_regs[i] = cpu_gpr[i];
    }
    difftest_regs[32] = top->pc;
}
