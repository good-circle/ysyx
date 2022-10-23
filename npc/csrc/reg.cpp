#include "common.h"

extern VMySimTop *top;
uint64_t *cpu_gpr = NULL;
u_int64_t tmp_difftest_regs[33] = {0};
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
    for (int i = 0; i < 32; i++)
    {
        printf("%s\t\t0x%lx\t\t\n", regs[i], cpu_gpr[i]);
    }
}

uint64_t isa_reg_str2val(const char *s, bool *success)
{
    *success = true;
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

bool tmp_init = false;
void difftest_read_regs(uint64_t *difftest_regs, uint64_t pc)
{
    if (!tmp_init)
    {
        for (int i = 0; i < 33; i++)
        {
            tmp_difftest_regs[i] = 0;
        }
        tmp_init = true;
    }
    difftest_regs[0] = 0;
    tmp_difftest_regs[0] = 0;
    for (int i = 1; i < 32; i++)
    {
        difftest_regs[i] = tmp_difftest_regs[i];
        tmp_difftest_regs[i] = cpu_gpr[i];
    }

    difftest_regs[32] = pc;

    // for (int i = 0; i < 32; i++)
    //{
    //     printf("%s\t\t0x%lx\t\t\n", regs[i], cpu_gpr[i]);
    // }
}
