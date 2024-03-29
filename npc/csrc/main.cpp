#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/time.h>
#include "common.h"

VerilatedContext *contextp = new VerilatedContext;
VMySimTop *top = new VMySimTop{contextp};
//#define WAVE_ON 1;
#define DIFF_ON 1;
#ifdef WAVE_ON
#include "verilated_fst_c.h"
VerilatedFstC *m_trace = new VerilatedFstC;
// VerilatedVcdC *m_trace = new VerilatedVcdC;
#endif

bool is_finish = false;
bool is_wrong = false;
int npc_cycle = 0;

u_int8_t pmem[0x8000000];
const char *img_file = NULL;
char *log_file = NULL;
long long cycle_num = 0;
long long inst_num = 0;
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
extern void difftest_read_regs(uint64_t *difftest_regs, uint64_t pc);
extern int difftest_step(uint64_t *difftest_regs, uint64_t pc, int num, bool skip);
extern void difftest_skip_ref();
extern void (*ref_difftest_regcpy)(void *dut, bool direction);
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
extern "C" void init_disasm(const char *triple);
extern void init_device();
extern void device_update();

axi4_mem<32, 64, 4> mem(4294967296);
axi4_ptr<32, 64, 4> mem_ptr;

struct timeval begin;
struct timeval end;

void connect_wire(axi4_ptr<32, 64, 4> &mem_ptr, VMySimTop *top)
{
    // aw
    mem_ptr.awaddr = &(top->io_axi_awaddr);
    mem_ptr.awburst = &(top->io_axi_awburst);
    mem_ptr.awid = &(top->io_axi_awid);
    mem_ptr.awlen = &(top->io_axi_awlen);
    mem_ptr.awready = &(top->io_axi_awready);
    mem_ptr.awsize = &(top->io_axi_awsize);
    mem_ptr.awvalid = &(top->io_axi_awvalid);
    // w
    mem_ptr.wdata = &(top->io_axi_wdata);
    mem_ptr.wlast = &(top->io_axi_wlast);
    mem_ptr.wready = &(top->io_axi_wready);
    mem_ptr.wstrb = &(top->io_axi_wstrb);
    mem_ptr.wvalid = &(top->io_axi_wvalid);
    // b
    mem_ptr.bid = &(top->io_axi_bid);
    mem_ptr.bready = &(top->io_axi_bready);
    mem_ptr.bresp = &(top->io_axi_bresp);
    mem_ptr.bvalid = &(top->io_axi_bvalid);
    // ar
    mem_ptr.araddr = &(top->io_axi_araddr);
    mem_ptr.arburst = &(top->io_axi_arburst);
    mem_ptr.arid = &(top->io_axi_arid);
    mem_ptr.arlen = &(top->io_axi_arlen);
    mem_ptr.arready = &(top->io_axi_arready);
    mem_ptr.arsize = &(top->io_axi_arsize);
    mem_ptr.arvalid = &(top->io_axi_arvalid);
    // r
    mem_ptr.rdata = &(top->io_axi_rdata);
    mem_ptr.rid = &(top->io_axi_rid);
    mem_ptr.rlast = &(top->io_axi_rlast);
    mem_ptr.rready = &(top->io_axi_rready);
    mem_ptr.rresp = &(top->io_axi_rresp);
    mem_ptr.rvalid = &(top->io_axi_rvalid);
}

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

void finish_sim()
{
    gettimeofday(&end, NULL);
    double npc_time = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
    printf("number of cycles is %lld, ", cycle_num);
    printf("number of instructions is %lld\n", inst_num);
    printf("total spend time %lfs\n", npc_time / 1000000);
    double frequency = (double)cycle_num / (npc_time / 1000000);
    printf("simulation frequency = %d cycles/s\n", (int)frequency);
    double IPC = (double)inst_num / (double)cycle_num;
    printf("IPC = %lf\n", IPC);
    if (difftest_regs[10] == 0)
    {
        printf(COLOR_BLUE "NPC: " COLOR_GREEN "HIT GOOD TRAP " COLOR_NONE "at pc 0x%08x\n", top->io_commit_0_pc);
    }
    else
    {
        printf(COLOR_BLUE "NPC: " COLOR_RED "HIT BAD TRAP " COLOR_NONE "at pc 0x%08x\n", top->io_commit_0_pc);
    }
}

bool first_commit = true;
void npc_exec(unsigned int n)
{
    axi4_ref<32, 64, 4> mem_ref(mem_ptr);
    axi4<32, 64, 4> mem_sigs;
    axi4_ref<32, 64, 4> mem_sigs_ref(mem_sigs);

    gettimeofday(&begin, NULL);
    while (!is_finish && !is_wrong && n > 0)
    {
        cycle_num++;
        if (cycle_num % 1000000 == 0)
        {
            gettimeofday(&end, NULL);
            printf("sim_time: %lds, cycles: %lld, ", end.tv_sec - begin.tv_sec, cycle_num);
            printf("insts: %lld, ", inst_num);
            printf("current_pc: %x\n", top->io_commit_0_pc);
        }
        // printf("%lld\n", cycle_num);
        // printf("%x\n", top->io_commit_0_pc);
        //  printf("%08lx \n", top->io_pc);
        //  top->inst = inst_fetch(top->io_pc);
        //  printf("%08x\n", top->inst);
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
        mem_sigs.update_input(mem_ref);
        top->eval();
        mem.beat(mem_sigs_ref);
        mem_sigs.update_output(mem_ref);
#ifdef WAVE_ON
        m_trace->dump(2 * npc_cycle + 1);
#endif
        top->clock = !top->clock;
        top->eval();

        bool commit_0 = false;
        bool commit_1 = false;
#ifdef DIFF_ON
        bool skip_0 = false;
        bool skip_1 = false;
        int commit_num = 0;
#endif

        if (top->io_commit_0_valid)
        {
            inst_num += 1;
#ifdef DIFF_ON
            commit_0 = true;
            if (top->io_commit_0_mcycle || top->io_commit_0_is_clint || top->io_commit_0_is_mmio)
            {
                skip_0 = true;
            }
#endif
        }
        if (top->io_commit_1_valid)
        {
            inst_num += 1;
#ifdef DIFF_ON
            commit_1 = true;
            if (top->io_commit_1_mcycle || top->io_commit_1_is_clint || top->io_commit_1_is_mmio)
            {
                skip_1 = true;
            }
#endif
        }

        is_finish = (top->io_commit_0_inst == 0x00100073 && top->io_commit_0_valid) ||
                    (top->io_commit_1_inst == 0x00100073 && top->io_commit_1_valid);

        if (commit_1 && !commit_0)
        {
            assert(0);
        }

#ifdef DIFF_ON
        commit_num = commit_0 + commit_1;

        if (skip_0 || skip_1)
        {
            if (commit_1)
            {
                // printf("commit_1: %lx %d\n", top->io_commit_1_pc, commit_num);
                difftest_read_regs(difftest_regs, top->io_commit_1_pc);
                is_wrong = difftest_step(difftest_regs, top->io_commit_1_pc, commit_num, true);
            }
            else
            {
                // printf("commit_0: %lx %d\n", top->io_commit_0_pc, commit_num);
                difftest_read_regs(difftest_regs, top->io_commit_0_pc);
                is_wrong = difftest_step(difftest_regs, top->io_commit_0_pc, commit_num, true);
            }
        }
        else if (commit_0)
        {
            if (first_commit)
            {
                first_commit = false;
                commit_num -= 1;
                if (commit_1)
                {
                    difftest_read_regs(difftest_regs, top->io_commit_1_pc);
                    is_wrong = difftest_step(difftest_regs, top->io_commit_1_pc, commit_num, false);
                }
                else
                {
                    difftest_read_regs(difftest_regs, top->io_commit_0_pc);
                }
            }
            else if (commit_1)
            {
                difftest_read_regs(difftest_regs, top->io_commit_1_pc);
                is_wrong = difftest_step(difftest_regs, top->io_commit_1_pc, commit_num, false);
            }
            else
            {
                difftest_read_regs(difftest_regs, top->io_commit_0_pc);
                is_wrong = difftest_step(difftest_regs, top->io_commit_0_pc, commit_num, false);
            }
        }
#endif
        n--;
        npc_cycle++;
        device_update();
    }

    if (is_finish || is_wrong || n <= 0)
    {
        finish_sim();
    }
}

int main(int argc, char **argv, char **env)
{
    contextp->commandArgs(argc, argv);

#ifdef WAVE_ON
    Verilated::traceEverOn(true);
    top->trace(m_trace, 99);
    m_trace->open("waveform.fst");
#endif

    parse_args(argc, argv);
    int img_size = init_pmem();
    init_regex();

    reset_npc(10);

#ifdef DIFF_ON
    difftest_read_regs(difftest_regs, 0x80000000);

    init_difftest(diff_so_file, img_size, difftest_regs);
#endif
    init_device();

    connect_wire(mem_ptr, top);
    assert(mem_ptr.check());
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
