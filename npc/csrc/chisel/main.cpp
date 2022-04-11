#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/time.h>
#include "common.h"

VerilatedContext *contextp = new VerilatedContext;
VTop *top = new VTop{contextp};
//VerilatedVcdC *m_trace = new VerilatedVcdC;
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
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
extern "C" void init_disasm(const char *triple);

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
    while ((o = getopt_long(argc, argv, "-bl:d:", table, NULL)) != -1)
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
    top->reset = 1;
    for (int i = 0; i < n; i++)
    {
        //m_trace->dump(2 * npc_time);
        top->clock = !top->clock;
        top->eval();

        //m_trace->dump(2 * npc_time + 1);
        top->clock = !top->clock;
        top->eval();

        npc_time++;
    }
}

void npc_exec(unsigned int n)
{
    struct timeval begin;
    struct timeval end;
    gettimeofday(&begin, NULL);
    while (!is_finish && n > 0)
    {
        inst_num++;
        u_int64_t last_pc = top->io_pc;
        //printf("%08lx \n", top->io_pc);
        //top->inst = inst_fetch(top->io_pc);
        //printf("%08x\n", top->inst);
/*
#define ITRACE 1
#ifdef ITRACE
        char start[128];
        char *p = start;
        p += snprintf(p, sizeof(start),"0x%08lx:", top->io_pc);
        int ilen = 4;
        int i;
        int pc_inst = inst_fetch(top->io_pc);
        u_int8_t *inst = (u_int8_t *)&pc_inst;
        for (i = 0; i < ilen; i++)
        {
            p += snprintf(p, 4, " %02x", inst[i]);
        }
        int space_len = 1;
        memset(p, ' ', space_len);
        p += space_len;

        disassemble(p, start + 128 - p, top->io_pc, (uint8_t *)&pc_inst, ilen);

        //printf("%s\n", start);
#endif
*/
        //m_trace->dump(2 * npc_time);
        top->clock = !top->clock;
        top->eval();
        //m_trace->dump(2 * npc_time + 1);
        top->clock = !top->clock;
        top->eval();

        difftest_read_regs(difftest_regs);

        is_finish = finish();
        n--;
        npc_time++;

        if (!is_finish && difftest_step(difftest_regs, last_pc) != 0)
        {
            is_finish = 1;
            break;
        }

    }

    if (is_finish)
    {
        gettimeofday(&end, NULL);
        double npc_time = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec) ;
        printf("number of instructions is %d\n", inst_num);
        printf("total spend time %lfs\n", npc_time / 1000000);
        double frequency = inst_num  / (npc_time / 1000000);
        printf("simulation frequency = %d inst/s\n", (int)frequency);
        if (difftest_regs[10] == 0)
        {
            printf(COLOR_BLUE "NPC: " COLOR_GREEN "HIT GOOD TRAP " COLOR_NONE "at pc 0x%016lx\n", top->io_pc);
        }
        else
        {
            printf(COLOR_BLUE "NPC: " COLOR_RED "HIT BAD TRAP " COLOR_NONE "at pc 0x%016lx\n", top->io_pc);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    printf("11111\n");
    contextp->commandArgs(argc, argv);
    //Verilated::traceEverOn(true);
    //top->trace(m_trace, 99);
    //m_trace->open("waveform.vcd");

    parse_args(argc, argv);
    int img_size = init_pmem();
    init_regex();

    reset_npc(10);

    difftest_read_regs(difftest_regs);
    
    init_difftest(diff_so_file, img_size, difftest_regs);
/*
#ifdef ITRACE
    init_disasm("riscv64-pc-linux-gnu");
#endif
*/
    top->reset = 0;

    svSetScope(svGetScopeFromName("TOP.Top"));

    sdb_mainloop();

    //m_trace->close();
    delete top;
    delete contextp;
}
