#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include "svdpi.h"
#include "Vtop__Dpi.h"

static u_int8_t pmem[0x8000];

void init_pmem()
{
    for (int i = 0; i < 200; i++)
    {
        pmem[4 * i] = 0x11;
        pmem[4 * i + 1] = 0x22;
        pmem[4 * i + 2] = 0x33;
        pmem[4 * i + 3] = 0x44;
    }
}

int pmem_read(unsigned int pc)
{
    return *(u_int32_t *) (pmem + pc - 0x80000000);
}

extern void finish(svBit* is_finish);



int main(int argc, char **argv, char **env)
{
    VerilatedContext *contextp = new VerilatedContext;
    Vtop *top = new Vtop{contextp};
    contextp->commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 99);
    m_trace->open("waveform.vcd");
    init_pmem();
    top->clk = 1;
    top->pc = 0x80000000;
    top->a = 0;
    int i = 0;
    svSetScope(svGetScopeFromName("TOP.top"));
    svBit* is_finish;
    while(!is_finish)
    {
        printf("%x ", top->pc);
        top->inst = pmem_read(top->pc);
        printf("%x\n", top->inst);
        m_trace->dump(2 * i);
        top->clk = !top->clk;
        top->eval();
        m_trace->dump(2 * i + 1);
        top->clk = !top->clk;
        top->eval();
        finish(is_finish);
        printf("%x\n", top->inst);
    }
    m_trace->close();
    delete top;
    delete contextp;
    return 0;
}