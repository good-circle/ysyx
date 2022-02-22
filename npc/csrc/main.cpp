#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated.h"
#include <verilated_vcd_c.h>

int main(int argc, char **argv, char **env)
{
  VerilatedContext *contextp = new VerilatedContext;
  Vtop *top = new Vtop{contextp};
  contextp->commandArgs(argc, argv);
  Verilated::traceEverOn(true);
  VerilatedVcdC *m_trace = new VerilatedVcdC;
  top->trace(m_trace, 99);
  m_trace->open("waveform.vcd");
  while (!contextp->gotFinish())
  {
    contextp->timeInc(1);
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();
    m_trace->dump(contextp->time());
    printf("a = %d, b = %d, f = %d\n", a, b, top->f);
    assert(top->f == a ^ b);
  }
  m_trace->close();
  delete top;
  delete contextp;
  return 0;
}
