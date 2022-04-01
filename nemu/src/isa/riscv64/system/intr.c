#include <isa.h>

#define IRQ_TIMER 0x8000000000000007
#define MIE (1ULL << 3)
word_t isa_raise_intr(word_t NO, vaddr_t epc)
{
    /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
#ifdef CONFIG_ETRACE
    printf("Exception at PC 0X%08lx, mcause is %ld\n", epc, NO);
#endif

    cpu.csr[MEPC] = epc;
    cpu.csr[MCAUSE] = NO;
    bool mie = cpu.csr[MSTATUS] & MIE;
    word_t mstatus = cpu.csr[MSTATUS];
    word_t offset_7 = ((mstatus << 57) >> 57) & ~MIE;
    mstatus = (mstatus >> 8) << 1;
    mstatus = mstatus | mie;
    mstatus = mstatus << 7;
    mstatus = mstatus | offset_7;
    cpu.csr[MSTATUS] = mstatus;
    return cpu.csr[MTVEC];
}

word_t isa_query_intr()
{
    if ((cpu.csr[MSTATUS] & MIE) && cpu.INTR)
    {
        cpu.INTR = false;
        return IRQ_TIMER;
    }
    return INTR_EMPTY;
}
