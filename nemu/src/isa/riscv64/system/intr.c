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
    printf("intr: %lx\n", cpu.csr[MCAUSE]);
    bool mie = cpu.csr[MCAUSE] & MIE;
    printf("mie: %x\n", mie);
    word_t mcause = cpu.csr[MCAUSE];
    word_t offset_7 = ((mcause << 57) >> 57) & ~MIE;
    printf("offset_7 :%lx\n", offset_7);
    mcause = (mcause >> 8) << 1;
    mcause = mcause | mie;
    mcause = mcause << 7;
    mcause = mcause | offset_7;
    cpu.csr[MCAUSE] = mcause;
    printf("intr: %lx\n", cpu.csr[MCAUSE]);
    return cpu.csr[MTVEC];
}

word_t isa_query_intr()
{
    if ((cpu.csr[MCAUSE] & MIE) && cpu.INTR)
    {
        cpu.INTR = 0;
        return IRQ_TIMER;
    }

    return INTR_EMPTY;
}
