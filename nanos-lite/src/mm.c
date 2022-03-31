#include <memory.h>

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
