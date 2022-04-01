#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context *(*user_handler)(Event, Context *) = NULL;
void __am_get_cur_as(Context *c);
void __am_switch(Context *c);
#define IRQ_TIMER 0x8000000000000007

Context *__am_irq_handle(Context *c)
{
    __am_get_cur_as(c);
    if (user_handler)
    {
        Event ev = {0};
        switch (c->mcause)
        {
        case 11:
            if (c->GPR1 == -1)
            {
                ev.event = EVENT_YIELD;
            }
            else
            {
                ev.event = EVENT_SYSCALL;
            }
            c->mepc += 4;
            break;
        case IRQ_TIMER:
            ev.event = EVENT_IRQ_TIMER;
            break;
        default:
            ev.event = EVENT_ERROR;
            break;
        }

        c = user_handler(ev, c);
        assert(c != NULL);
    }
    __am_switch(c);
    return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *))
{
    // initialize exception entry
    asm volatile("csrw mtvec, %0"
                 :
                 : "r"(__am_asm_trap));

    // register event handler
    user_handler = handler;

    return true;
}

#define MPIE (1ULL << 7)
Context *kcontext(Area kstack, void (*entry)(void *), void *arg)
{
    Context *kct = kstack.end - sizeof(Context);
    kct->mepc = (uintptr_t)entry;
    kct->mstatus = MPIE;
    kct->gpr[10] = (uintptr_t)arg;

    return kct;
}

void yield()
{
    asm volatile("li a7, -1; ecall");
}

bool ienabled()
{
    return false;
}

void iset(bool enable)
{
}
