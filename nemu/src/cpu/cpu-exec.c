#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <ftrace/ftrace.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();
int check_watchpoint();

IFDEF(CONFIG_IRINGBUF, static char iringbuf[16][128]);
IFDEF(CONFIG_IRINGBUF, static int iring_num);
IFDEF(CONFIG_FTRACE, static int call_depth);
IFDEF(CONFIG_FTRACE, static char ftracebuf[64 * 64 * 64 * 64 * 64]);
IFDEF(CONFIG_FTRACE, static char *ftrace_pos = ftracebuf);
IFDEF(CONFIG_DTRACE, char dtracebuf[64 * 64 * 64 * 64]);
IFDEF(CONFIG_DTRACE, char *dtrace_pos = dtracebuf);

static void print_iring()
{
#ifdef CONFIG_IRINGBUF
    int max = (g_nr_guest_inst >= 16) ? 15 : iring_num;
    int pos = (iring_num >= 1) ? iring_num - 1 : 15;
    for (int j = 0; j <= max; j++)
    {
        if (j == pos)
        {
            printf("--> ");
        }
        else
        {
            printf("    ");
        }

        printf("%s\n", iringbuf[j]);
    }
#endif
}

static void trace_and_difftest(Decode *_this, vaddr_t dnpc)
{
#ifdef CONFIG_ITRACE_COND
    if (ITRACE_COND)
    {
        log_write("%s\n", _this->logbuf);
    }
#endif
    if (g_print_step)
    {
        IFDEF(CONFIG_ITRACE, puts(_this->logbuf));
    }
    IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_IRINGBUF
    //printf("%s\n", _this->logbuf);
    memcpy(iringbuf[iring_num], _this->logbuf, sizeof(_this->logbuf));
    iring_num++;
    iring_num = (iring_num > 15) ? 0 : iring_num;
#endif
#ifdef CONFIG_FTRACE
#endif
#ifdef CONFIG_WATCHPOINT
    if (check_watchpoint())
    {
        if (nemu_state.state == NEMU_RUNNING)
        {
            nemu_state.state = NEMU_STOP;
        }
    }
#endif
}

static void exec_once(Decode *s, vaddr_t pc)
{
    s->pc = pc;
    s->snpc = pc;
    isa_exec_once(s);
    cpu.pc = s->dnpc;

#ifdef CONFIG_FTRACE
    if ((s->ftrace == JAL || s->ftrace == JALR) && BITS(s->isa.inst.val, 11, 7) == 1)
    {
        ftrace_pos += sprintf(ftrace_pos, "0x%8lx: ", s->pc);
        memset(ftrace_pos, ' ', 2 * call_depth);
        ftrace_pos += 2 * call_depth;
        call_depth++;
        for (int i = 0; i < func_num; i++)
        {
            if (s->dnpc >= func[i].st_value && s->dnpc < func[i].st_value + func[i].st_size)
            {
                ftrace_pos += sprintf(ftrace_pos, "call [%s@0x%8lx]\n", (char *)((word_t)strtab + func[i].st_name), s->dnpc);
                break;
            }
        }
    }
    else if (s->ftrace == JALR && BITS(s->isa.inst.val, 19, 15) == 1)
    {
        call_depth--;
        ftrace_pos += sprintf(ftrace_pos, "0x%8lx: ", s->pc);
        memset(ftrace_pos, ' ', 2 * call_depth);
        ftrace_pos += 2 * call_depth;
        for (int i = 0; i < func_num; i++)
        {
            if (s->pc >= func[i].st_value && s->pc < func[i].st_value + func[i].st_size)
            {
                ftrace_pos += sprintf(ftrace_pos, "ret  [%s]\n", (char *)((word_t)strtab + func[i].st_name));
                break;
            }
        }
    }
#endif

#ifdef CONFIG_ITRACE
    char *p = s->logbuf;
    p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
    int ilen = s->snpc - s->pc;
    int i;
    uint8_t *inst = (uint8_t *)&s->isa.inst.val;
    for (i = 0; i < ilen; i++)
    {
        p += snprintf(p, 4, " %02x", inst[i]);
    }
    int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
    int space_len = ilen_max - ilen;
    if (space_len < 0)
        space_len = 0;
    space_len = space_len * 3 + 1;
    memset(p, ' ', space_len);
    p += space_len;

    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
                MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#endif
}

static void execute(uint64_t n)
{
    Decode s;
    //int i = 0;
    printf("111\n");
    for (; n > 0; n--)
    {
        //printf("nemu cpu-exec.c execute cpu.pc = %lx\n", cpu.pc);
        exec_once(&s, cpu.pc);
        //printf("%d\n", i++);
        //printf("%lx\n", cpu.pc);
        g_nr_guest_inst++;
        trace_and_difftest(&s, cpu.pc);
        if (nemu_state.state != NEMU_RUNNING)
            break;
        IFDEF(CONFIG_DEVICE, device_update());
    }
}

static void statistic()
{
    IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%ld", "%'ld")
    Log("host time spent = " NUMBERIC_FMT " us", g_timer);
    Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
    if (g_timer > 0)
        Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
    else
        Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg()
{
    isa_reg_display();
    print_iring();
    statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n)
{
    g_print_step = (n < MAX_INST_TO_PRINT);
    switch (nemu_state.state)
    {
    case NEMU_END:
    case NEMU_ABORT:
        printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
        return;
    default:
        nemu_state.state = NEMU_RUNNING;
    }

    uint64_t timer_start = get_time();

    execute(n);

    uint64_t timer_end = get_time();
    g_timer += timer_end - timer_start;

    switch (nemu_state.state)
    {
    case NEMU_RUNNING:
        nemu_state.state = NEMU_STOP;
        break;

    case NEMU_END:
#ifdef CONFIG_FTRACE
        call_depth--;
        ftrace_pos += sprintf(ftrace_pos, "0x%8lx: ", nemu_state.halt_pc);
        memset(ftrace_pos, ' ', 2 * call_depth);
        ftrace_pos += 2 * call_depth;
        for (int i = 0; i < func_num; i++)
        {
            if (nemu_state.halt_pc >= func[i].st_value && nemu_state.halt_pc < func[i].st_value + func[i].st_size)
            {
                ftrace_pos += sprintf(ftrace_pos, "ret  [%s]\n", (char *)((word_t)strtab + func[i].st_name));
                break;
            }
        }
#endif
    case NEMU_ABORT:
        Log("nemu: %s at pc = " FMT_WORD,
            (nemu_state.state == NEMU_ABORT ? ASNI_FMT("ABORT", ASNI_FG_RED) : (nemu_state.halt_ret == 0 ? ASNI_FMT("HIT GOOD TRAP", ASNI_FG_GREEN) : ASNI_FMT("HIT BAD TRAP", ASNI_FG_RED))),
            nemu_state.halt_pc);
        if (nemu_state.state == NEMU_ABORT || nemu_state.halt_ret != 0)
        {
            print_iring();
        }
        // fall through
    case NEMU_QUIT:
        statistic();

#ifdef CONFIG_FTRACE
        log_write("%s\n", ftracebuf);
#endif
#ifdef CONFIG_DTRACE
        log_write("%s\n", dtracebuf);
#endif
    }
}
