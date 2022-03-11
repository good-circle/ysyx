#include <common.h>

static Context *do_event(Event e, Context *c)
{
    switch (e.event)
    {
    case EVENT_YIELD:
        printf("a sentence\n");
        break;
    case 2:
        assert(0);
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
