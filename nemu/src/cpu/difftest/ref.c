#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
    printf("n = %d\n", n);
    if (direction == DIFFTEST_TO_DUT)
    {
        memcpy(buf, guest_to_host(addr), n);
    }
    else
    {
        memcpy(guest_to_host(addr), buf, n);
    }
}

void difftest_regcpy(void *dut, bool direction)
{
    //uint64_t *dut_64 = dut;
    if (direction == DIFFTEST_TO_DUT)
    {
        memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
    }
    else
    {
        //printf("111\n");
        //printf("nemu cpu_pc = %lx\n", cpu.pc);
        memcpy(&cpu, dut, DIFFTEST_REG_SIZE);
        //printf("nemu dut_pc = %lx\n", dut_64[32]);
    }
}

bool reset = false;
void difftest_exec(uint64_t n)
{
    //printf("222\n");
    if (!reset)
    {
        // I do not know why cpu.pc = 0
        cpu.pc = RESET_VECTOR;
        reset = true;
    }

    cpu_exec(n);
}

void difftest_raise_intr(word_t NO)
{
    assert(0);
}

void difftest_init()
{
    /* Perform ISA dependent initialization. */
    init_isa();
}
