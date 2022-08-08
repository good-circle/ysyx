#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/time.h>
#include "common.h"

VerilatedContext *contextp = new VerilatedContext;
VSimTop *top = new VSimTop{contextp};
//#define WAVE_ON 1;
#ifdef WAVE_ON
VerilatedVcdC *m_trace = new VerilatedVcdC;
#endif

svBit is_finish = 0;
svBit is_commit = 0;
svBit is_mmio = 0;
int npc_cycle = 0;

u_int8_t pmem[0x8000000];
const char *img_file = NULL;
char *log_file = NULL;
int cycle_num = 0;
int inst_num = 0;
bool is_batch_mode = false;
static char *diff_so_file = NULL;
u_int64_t difftest_regs[33] = {0};
extern uint64_t cpu_pc;
extern u_int64_t mmio_pc;

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
#ifdef WAVE_ON
        m_trace->dump(2 * npc_cycle);
#endif
        top->clock = !top->clock;
        top->eval();

#ifdef WAVE_ON
        m_trace->dump(2 * npc_cycle + 1);
#endif
        top->clock = !top->clock;
        top->eval();

        npc_cycle++;
    }
}

bool first_commit = true;
void npc_exec(unsigned int n)
{
    struct timeval begin;
    struct timeval end;
    gettimeofday(&begin, NULL);
    while (!is_finish && n > 0)
    {
        cycle_num++;
        // printf("%08lx \n", top->io_pc);
        // top->inst = inst_fetch(top->io_pc);
        // printf("%08x\n", top->inst);
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
#ifdef WAVE_ON
        m_trace->dump(2 * npc_cycle);
#endif
        top->clock = !top->clock;
        top->eval();
#ifdef WAVE_ON
        m_trace->dump(2 * npc_cycle + 1);
#endif
        top->clock = !top->clock;
        top->eval();

        svSetScope(svGetScopeFromName("TOP.SimTop.core.commit"));

        is_commit = export_commit();
        // printf("%d\n", is_commit);

        if (is_commit)
        {
            if (first_commit)
            {
                inst_num++;
                first_commit = false;
            }
            else
            {
                inst_num++;
                difftest_read_regs(difftest_regs);
                is_finish = export_finish();
                is_mmio = export_mmio();
                printf("is_mmio : %d\n", is_mmio);
                assert(is_mmio == 0);

                // printf("\n is_finish = %d\n", is_finish);
                if (!is_finish && difftest_step(difftest_regs, cpu_pc) != 0)
                {
                    is_finish = 1;
                    break;
                }
            }
        }

        n--;
        npc_cycle++;
    }

    if (is_finish)
    {
        gettimeofday(&end, NULL);
        double npc_time = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
        printf("number of cycles is %d, ", cycle_num);
        printf("number of instructions is %d\n", inst_num);
        printf("total spend time %lfs\n", npc_time / 1000000);
        double frequency = (double)cycle_num / (npc_time / 1000000);
        printf("simulation frequency = %d inst/s\n", (int)frequency);
        double IPC = (double)inst_num / (double)cycle_num;
        printf("IPC = %lf\n", IPC);
        if (difftest_regs[10] == 0)
        {
            printf(COLOR_BLUE "NPC: " COLOR_GREEN "HIT GOOD TRAP " COLOR_NONE "at pc 0x%016lx\n", cpu_pc);
        }
        else
        {
            printf(COLOR_BLUE "NPC: " COLOR_RED "HIT BAD TRAP " COLOR_NONE "at pc 0x%016lx\n", cpu_pc);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    contextp->commandArgs(argc, argv);

#ifdef WAVE_ON
    Verilated::traceEverOn(true);
    top->trace(m_trace, 99);
    m_trace->open("waveform.vcd");
#endif

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

    // Verilated::scopesDump();

    sdb_mainloop();

#ifdef WAVE_ON
    m_trace->close();
#endif
    delete top;
    delete contextp;
}
