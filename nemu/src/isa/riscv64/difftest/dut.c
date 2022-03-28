#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc)
{
    for (int i = 0; i < 32; i++)
    {
        if (!difftest_check_reg(reg_name(i, 4), pc, ref_r->gpr[i], cpu.gpr[i]))
        {
            return false;
        }
    }
    if (!difftest_check_reg("pc", pc, ref_r->pc, cpu.pc))
    {
        return false;
    }
    return true;
}

void isa_difftest_attach()
{
}
