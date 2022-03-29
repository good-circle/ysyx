#include <common.h>

void do_syscall(Context *c);
Context *schedule(Context *prev);
static Context *do_event(Event e, Context *c)
{
    switch (e.event)
    {
    case EVENT_YIELD:
        //c->mepc += 4;
        return schedule(c);
        break;
    case EVENT_SYSCALL:
        //c->mepc += 4;
        do_syscall(c);
        break;
    case EVENT_IRQ_TIMER:
        printf("event_irq_timer!\n");
        break;
    default:
        panic("Unhandled event ID = %d", e.event);
    }

    return c;
}

void init_irq(void)
{
    Log("Initializing interrupt/exception handler...");
    cte_init(do_event);
}
