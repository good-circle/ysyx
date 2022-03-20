#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include "svdpi.h"
#include "Vtop__Dpi.h"

static u_int8_t pmem[0x8000000];
static const char *img_file = NULL;

void init_pmem()
{
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.");
    assert(0); 
  }

  FILE *fp = fopen(img_file, "rb");
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(pmem, size, 1, fp);
  assert(ret == 1);

  fclose(fp);
}

int pmem_read(unsigned int pc)
{
    return *(u_int32_t *) (pmem + pc - 0x80000000);
}

int main(int argc, char **argv, char **env)
{
    VerilatedContext *contextp = new VerilatedContext;
    Vtop *top = new Vtop{contextp};
    contextp->commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 99);
    m_trace->open("waveform.vcd");
    img_file = "/home/jn/Desktop/ysyx-workbench/am-kernels/tests/cpu-tests/build/dummy-riscv64-npc.bin";
    init_pmem();
    top->clk = 1;
    top->pc = 0x80000000;
    top->a = 0;
    int i = 0;
    svSetScope(svGetScopeFromName("TOP.top"));
    svBit is_finish = 0;
    while(!is_finish)
    {
        i++;
        printf("%08x ", top->pc);
        top->inst = pmem_read(top->pc);
        printf("%08x\n", top->inst);
        m_trace->dump(2 * i);
        top->clk = !top->clk;
        top->eval();
        m_trace->dump(2 * i + 1);
        top->clk = !top->clk;
        top->eval();
        finish(&is_finish);
    }
    m_trace->close();
    delete top;
    delete contextp;
    return 0;
}