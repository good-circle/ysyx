#include <am.h>
#include <nemu.h>
#include <klib.h>

static AddrSpace kas = {};
static void *(*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void *) = NULL;
static int vme_enable = 0;

static Area segments[] = { // Kernel memory mappings
    NEMU_PADDR_SPACE};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir)
{
    uintptr_t mode = 1ul << (__riscv_xlen - 1);
    asm volatile("csrw satp, %0"
                 :
                 : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline uintptr_t get_satp()
{
    uintptr_t satp;
    asm volatile("csrr %0, satp"
                 : "=r"(satp));
    return satp << 12;
}

bool vme_init(void *(*pgalloc_f)(int), void (*pgfree_f)(void *))
{
    pgalloc_usr = pgalloc_f;
    pgfree_usr = pgfree_f;

    kas.ptr = pgalloc_f(PGSIZE);

    int i;
    for (i = 0; i < LENGTH(segments); i++)
    {
        void *va = segments[i].start;
        for (; va < segments[i].end; va += PGSIZE)
        {
            map(&kas, va, va, 0);
        }
    }

    set_satp(kas.ptr);
    vme_enable = 1;

    return true;
}

void protect(AddrSpace *as)
{
    PTE *updir = (PTE *)(pgalloc_usr(PGSIZE));
    as->ptr = updir;
    as->area = USER_SPACE;
    as->pgsize = PGSIZE;
    // map kernel space
    memcpy(updir, kas.ptr, PGSIZE);
}

void unprotect(AddrSpace *as)
{
}

void __am_get_cur_as(Context *c)
{
    c->pdir = (vme_enable ? (void *)get_satp() : NULL);
}

void __am_switch(Context *c)
{
    if (vme_enable && c->pdir != NULL)
    {
        set_satp(c->pdir);
    }
}

#define _PAGE_PRESENT (1 << 0)
void map(AddrSpace *as, void *va, void *pa, int prot)
{
    uintptr_t vpn0 = ((uintptr_t)va >> 12) & ~(~0 << 9);
    uintptr_t vpn1 = ((uintptr_t)va >> 21) & ~(~0 << 9);
    uintptr_t vpn2 = ((uintptr_t)va >> 30) & ~(~0 << 9);

    PTE *base_addr = as->ptr;
    PTE *first_level_pgdir = base_addr + vpn2;
    if ((*first_level_pgdir & _PAGE_PRESENT) == 0)
    {
        base_addr = pgalloc_usr(PGSIZE);
        *first_level_pgdir = (PTE)(((uintptr_t)base_addr >> 12) << 10 | _PAGE_PRESENT);
    }
    base_addr = (PTE *)((*first_level_pgdir >> 10) << 12);

    PTE *second_level_pgdir = base_addr + vpn1;
    if ((*second_level_pgdir & _PAGE_PRESENT) == 0)
    {
        base_addr = pgalloc_usr(PGSIZE);
        *second_level_pgdir = (PTE)(((uintptr_t)base_addr >> 12) << 10 | _PAGE_PRESENT);
    }
    base_addr = (PTE *)((*second_level_pgdir >> 10) << 12);

    PTE *last_level_pgdir = base_addr + vpn0;
    *last_level_pgdir = (PTE)(((uintptr_t)pa >> 12) << 10 | _PAGE_PRESENT);
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry)
{
    Context *uct = kstack.end - sizeof(Context);
    uct->mepc = (uintptr_t)entry;
    uct->mstatus = 0xa00001800;
    uct->pdir = as->ptr;
    
    return uct;
}
