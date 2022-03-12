#include <common.h>
#include "syscall.h"

#define STRACE 1

void do_syscall(Context *c)
{
    uintptr_t a[4];
    a[0] = c->GPR1; // a7
    a[1] = c->GPR2; // a0
    a[2] = c->GPR3; // a1
    a[3] = c->GPR4; // a2

#ifdef STRACE
  printf("Syscall: a7=%d, a0=%d, a1=%d, a2=%d\n", a[0], a[1], a[2], a[3]);
#endif

    switch (a[0])
    {
    case SYS_yield:
        yield();
        c->GPRx = 0;
        break;
    case SYS_exit:
        halt(a[1]);
        c->GPRx = 0;
        break;
    default:
        panic("Unhandled syscall ID = %d", a[0]);
    }
}
