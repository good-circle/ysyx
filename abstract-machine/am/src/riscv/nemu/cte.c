#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c)
{
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
        default:
            ev.event = EVENT_ERROR;
            break;
        }

        c = user_handler(ev, c);
        assert(c != NULL);
    }

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

Context *kcontext(Area kstack, void (*entry)(void *), void *arg)
{
    Context *kct = kstack.end - sizeof(Context);
    kct->mepc = (uintptr_t)entry;
    kct->mstatus = 0xa00001800;
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
