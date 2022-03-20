#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include "Vtop.h"
#include "verilated.h"
#include <verilated_vcd_c.h>
#include "svdpi.h"
#include "Vtop__Dpi.h"

static u_int8_t pmem[0x8000000];
static const char *img_file = NULL;
static char *log_file = NULL;

static int parse_args(int argc, char *argv[])
{
    const struct option table[] = {
        {"log", required_argument, NULL, 'l'},
        {0, 0, NULL, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-l:", table, NULL)) != -1)
    {
        switch (o)
        {
        case 'l':
            log_file = optarg;
            break;
        case 1:
            img_file = optarg;
            return optind - 1;
        }
    }
    return 0;
}

void init_pmem()
{
    if (img_file == NULL)
    {
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

int pmem_read(unsigned long long pc)
{
    return *(u_int32_t *)(pmem + pc - 0x80000000);
}

int main(int argc, char **argv, char **env)
{
    parse_args(argc, argv);
    VerilatedContext *contextp = new VerilatedContext;
    Vtop *top = new Vtop{contextp};
    contextp->commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 99);
    m_trace->open("waveform.vcd");
    init_pmem();
    top->clk = 1;
    top->rst = 1;
    int i = 0;
    svSetScope(svGetScopeFromName("TOP.top"));
    svBit is_finish = 0;
    while (!is_finish)
    {
        i++;
        if(i <= 10)
        {
            printf("%d ", i);
            printf("%d ", top->rst);
            printf("%016lx\n", top->pc);
                    //m_trace->dump(2 * i);
        //top->clk = !top->clk;
        top->eval();

        //m_trace->dump(2 * i + 1);
        //top->clk = !top->clk;
        top->eval();
        continue;
        }
        else
        {
            top->rst = 0;
        }
        
        printf("%08lx ", top->pc);
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