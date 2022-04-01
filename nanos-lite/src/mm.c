#include <memory.h>
#include <proc.h>

static void *pf = NULL;

void *new_page(size_t nr_page)
{
    void *new = pf;
    pf += PGSIZE * nr_page;
    return new;
}

#ifdef HAS_VME
static void *pg_alloc(int n)
{
    int size = n / PGSIZE;
    void *newpage = new_page(size);
    memset(newpage, 0, n);
    return newpage;
}
#endif

void free_page(void *p)
{
    panic("not implement yet");
}

/* The brk() system call handler. */
int mm_brk(uintptr_t brk)
{
    uintptr_t current_ppn = current->max_brk >> 12;
    uintptr_t new_ppn = brk >> 12;

    if (brk >= current->max_brk)
    {
        void *new = new_page(new_ppn - current_ppn);
        for (int i = 0; i < new_ppn -current_ppn; i++)
        {

            map(&current->as, (void *)(current->max_brk + i * PGSIZE), (void *)(new + i * PGSIZE), 0);
        }

        current->max_brk = new_ppn << 12;
    }
    return 0;
}

void init_mm()
{
    pf = (void *)ROUNDUP(heap.start, PGSIZE);
    Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
    vme_init(pg_alloc, free_page);
#endif
}
