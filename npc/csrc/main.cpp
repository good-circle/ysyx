#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "common.h"

VerilatedContext *contextp = new VerilatedContext;
Vtop *top = new Vtop{contextp};
VerilatedVcdC *m_trace = new VerilatedVcdC;
svBit is_finish = 0;
int npc_time = 0;

u_int8_t pmem[0x8000000];
const char *img_file = NULL;
char *log_file = NULL;
int inst_num = 0;
bool is_batch_mode = false;
static char *diff_so_file = NULL;
u_int64_t difftest_regs[33] = {0};

static int parse_args(int argc, char *argv[]);
long init_pmem();
u_int32_t inst_fetch(unsigned long long pc);
void npc_exec(unsigned int n);
void set_batch_mode();
void init_regex();
extern void sdb_mainloop();
extern void init_difftest(char *ref_so_file, long img_size, u_int64_t *difftest_regs);
void reset_npc(uint n);
extern void difftest_read_regs(u_int64_t *difftest_regs);
extern int difftest_step(u_int64_t *difftest_regs, u_int64_t pc);

void set_batch_mode()
{
    is_batch_mode = true;
}

static int parse_args(int argc, char *argv[])
{
    const struct option table[] = {
        {"batch", no_argument, NULL, 'b'},
        {"log", required_argument, NULL, 'l'},
        {"diff", required_argument, NULL, 'd'},
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
        case 'd':
            diff_so_file = optarg;
            break;
        case 1:
            img_file = optarg;
            return optind - 1;
        }
    }
    return 0;
}

void reset_npc(uint n)
{
    top->rst = 1;
    for (int i = 0; i < n; i++)
    {
        m_trace->dump(2 * npc_time);
        top->clk = !top->clk;
        top->eval();

        m_trace->dump(2 * npc_time + 1);
        top->clk = !top->clk;
        top->eval();

        npc_time++;
    }
}

void npc_exec(unsigned int n)
{
    while (!is_finish && n > 0)
    {
        printf("%08lx ", top->pc);
        top->inst = inst_fetch(top->pc);
        printf("%08x\n", top->inst);

        m_trace->dump(2 * npc_time);
        top->clk = !top->clk;
        top->eval();

        m_trace->dump(2 * npc_time + 1);
        top->clk = !top->clk;
        top->eval();



        difftest_read_regs(difftest_regs);

        if(difftest_step(difftest_regs, top->pc) != 0)
        {
            is_finish = 1;
            break;
        }

        finish(&is_finish);

        n--;
        npc_time++;
    }

    if (is_finish)
    {
        printf("number of instructions is %d\n", inst_num);
        if (top->halt == 0)
        {
            printf(COLOR_BLUE "NPC: " COLOR_GREEN "HIT GOOD TRAP " COLOR_NONE "at pc 0x%016lx\n", top->pc);
        }
        else
        {
            printf(COLOR_BLUE "NPC: " COLOR_RED "HIT BAD TRAP " COLOR_NONE "at pc 0x%016lx\n", top->pc);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    contextp->commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    top->trace(m_trace, 99);
    m_trace->open("waveform.vcd");

    parse_args(argc, argv);
    int img_size = init_pmem();
    init_regex();

    reset_npc(10);
    
    difftest_read_regs(difftest_regs);
    init_difftest(diff_so_file, img_size, difftest_regs);

    top->clk = 1;
    top->rst = 0;

    svSetScope(svGetScopeFromName("TOP.top"));

    sdb_mainloop();

    m_trace->close();
    delete top;
    delete contextp;
}
