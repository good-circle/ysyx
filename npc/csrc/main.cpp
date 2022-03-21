#include <stdlib.h>

#include <getopt.h>

#include "common.h"

VerilatedContext *contextp = new VerilatedContext;
Vtop *top = new Vtop{contextp};
svBit is_finish = 0;

u_int8_t pmem[0x8000000];
const char *img_file = NULL;
char *log_file = NULL;
int inst_num = 0;
bool is_batch_mode = false;

static int parse_args(int argc, char *argv[]);
void init_pmem();
int pmem_read(unsigned long long pc);
void exec(Vtop *top, VerilatedVcdC *m_trace, svBit is_finish, unsigned int n);
void set_batch_mode();

void set_batch_mode()
{
    is_batch_mode = true;
}

static int parse_args(int argc, char *argv[])
{
    const struct option table[] = {
        {"batch", no_argument, NULL, 'b'},
        {"log", required_argument, NULL, 'l'},
        {0, 0, NULL, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-bl:", table, NULL)) != -1)
    {
        switch (o)
        {
        case 'b':
            set_batch_mode();
            break;
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


void exec(Vtop *top, VerilatedVcdC *m_trace, svBit is_finish, unsigned int n)
{
    int i = 0;
    while (!is_finish && n > 0)
    {
        n--;
        i++;
        if (i <= 10)
        {
            m_trace->dump(2 * i);
            top->clk = !top->clk;
            top->eval();

            m_trace->dump(2 * i + 1);
            top->clk = !top->clk;
            top->eval();
            continue;
        }

        top->rst = 0;
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
}

int main(int argc, char **argv, char **env)
{
    contextp->commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 99);
    m_trace->open("waveform.vcd");

    parse_args(argc, argv);
    init_pmem();

    top->clk = 1;
    top->rst = 1;

    svSetScope(svGetScopeFromName("TOP.top"));

    unsigned int n = -1;
    exec(top, m_trace, is_finish, n);

    printf("number of instructions is %d\n", inst_num);
    if (top->halt == 0)
    {
        printf(COLOR_BLUE "NPC: " COLOR_GREEN "HIT GOOD TRAP " COLOR_NONE "at pc 0x%016lx\n", top->pc);
    }
    else
    {
        printf(COLOR_BLUE "NPC: " COLOR_RED "HIT BAD TRAP " COLOR_NONE "at pc 0x%016lx\n", top->pc);
    }
    m_trace->close();
    delete top;
    delete contextp;
    return 0;
}


