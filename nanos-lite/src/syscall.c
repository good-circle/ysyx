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
    printf("Syscall: a7=%x, a0=%x, a1=%x, a2=%x\n", a[0], a[1], a[2], a[3]);
#endif

    switch (a[0])
    {
    case SYS_yield:
        yield();
        c->GPRx = 0;
        break;
    case SYS_exit:
        if(a[1] != 0)
        {
            printf("a0 is not 0 when sys_exit, maybe you forget to add case in syscall.c?\n");
        }
        halt(a[1]);
        c->GPRx = 0;
        break;
    case SYS_write:
        if (a[1] == 1 || a[1] == 2)
        {
            for (int i = 0; i < a[3]; i++)
            {
                putch(*((char *)a[2] + i));
            }
        }
        else
        {
            assert(0);
        }
        c->GPRx = a[3];
        break;
    case SYS_brk:
        /* will always success in pa3 */
        c->GPRx = 0;
        break;
    default:
        panic("Unhandled syscall ID = %d", a[0]);
    }
}
