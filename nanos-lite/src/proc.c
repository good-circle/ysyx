#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB *current = NULL;
void naive_uload(PCB *pcb, const char *filename);
void context_kload(PCB *pcb, void (*entry)(void *), void *arg);

void switch_boot_pcb()
{
    current = &pcb_boot;
}

void hello_fun(void *arg)
{
    int j = 1;
    while (1)
    {
        Log("Hello World from Nanos-lite with arg '%d' for the %dth time!", (uintptr_t)arg, j);
        j++;
        yield();
    }
}

void init_proc()
{
    switch_boot_pcb();

    Log("Initializing processes...");

    // load program here
    context_kload(&pcb[0], hello_fun, (void *)10);
    context_kload(&pcb[1], hello_fun, (void *)11);
    switch_boot_pcb();
}

Context *schedule(Context *prev)
{
    // save the context pointer
    printf("cps: %x %x\n", pcb[0].cp, pcb[1].cp);
    printf("pcb_cps: %x %x\n", &pcb[0].cp, &pcb[1].cp);
    printf("prev: %x\n", prev);
    current->cp = prev;
    
    current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
    //current = &pcb[0];

    // then return the new context
    printf("current->cp: %x\n", current->cp);
    return current->cp;
}
