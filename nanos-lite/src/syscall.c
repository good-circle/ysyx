#include <common.h>
#include "syscall.h"
#include <fs.h>
#include <sys/time.h>
#include <proc.h>

//#define STRACE

static int my_gettimeofday(struct timeval *tv, struct timezone *tz);
void naive_uload(PCB *pcb, const char *filename);

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
    case SYS_exit: // 0
        if (a[1] != 0)
        {
            printf("a0 is not 0 when sys_exit, maybe you forget to add case in navy-apps/libs/libos/src/syscall.c?\n");
        }
        naive_uload(NULL, "/bin/nterm");
        c->GPRx = 0;
        break;

    case SYS_yield: // 1
        yield();
        c->GPRx = 0;
        break;

    case SYS_open: // 2
        c->GPRx = fs_open((char *)a[1], a[2], a[3]);
        break;

    case SYS_read: // 3
        c->GPRx = fs_read(a[1], (void *)a[2], a[3]);
        break;

    case SYS_write: // 4
        c->GPRx = fs_write(a[1], (void *)a[2], a[3]);
        break;

    case SYS_close: // 7
        c->GPRx = fs_close(a[1]);
        break;

    case SYS_lseek: // 8
        c->GPRx = fs_lseek(a[1], a[2], a[3]);
        break;

    case SYS_brk: // 9
        /* will always success in pa3 */
        c->GPRx = 0;
        break;

    case SYS_execve: // 13
        naive_uload(NULL, (char *)a[1]);
        c->GPRx = 0;
        break;

    case SYS_gettimeofday: // 19
        c->GPRx = my_gettimeofday((struct timeval *)a[1], (struct timezone *)a[2]);
        break;
    default:
        panic("Unhandled syscall ID = %d", a[0]);
    }
}

static int my_gettimeofday(struct timeval *tv, struct timezone *tz)
{
    size_t usec = io_read(AM_TIMER_UPTIME).us;
    tv->tv_sec = usec / 1000000;
    tv->tv_usec = usec % 1000000;
    return 0;
}
