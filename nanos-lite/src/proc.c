#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB *current = NULL;
void naive_uload(PCB *pcb, const char *filename);
void context_kload(PCB *pcb, void (*entry)(void *), void *arg);
void context_uload(PCB *pcb, const char *filename, char *const argv[], char *const envp[]);

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

    //char *skip_arg[] = {"/bin/pal","--skip", NULL};
    //char *exec_arg[] = {"/bin/menu"};
    //char *null_arg[] = {NULL};

    // load program here
    //context_kload(&pcb[0], hello_fun, (void *)12345678);
    //context_uload(&pcb[0], "/bin/pal", skip_arg, null_arg);
    //context_uload(&pcb[0], "/bin/nterm", null_arg, null_arg);
    naive_uload(NULL, "/bin/pal");
}

Context *schedule(Context *prev)
{
    // save the context pointer
    current->cp = prev;

    //current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
    current = &pcb[0];

    // then return the new context
    return current->cp;
}
