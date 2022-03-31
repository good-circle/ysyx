#include <isa.h>
#include <memory/vaddr.h>
#include <memory/paddr.h>

paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type)
{
    vaddr_t vpn0 = (vaddr << 43) >> 55;
    vaddr_t vpn1 = (vaddr << 34) >> 55;
    vaddr_t vpn2 = (vaddr << 25) >> 55;
    vaddr_t offset = (vaddr << 52) >> 52;
    printf("vaddr %lx, vpn0 %lx, vpn1 %lx, vpn2 %lx ", vaddr, vpn0, vpn1, vpn2);
    word_t base_addr = (cpu.csr[SATP] << 20) >> 8;
    printf("base_addr = %lx ", (cpu.csr[SATP] << 20) >> 8);
    word_t first_level_pgdir = paddr_read(base_addr + vpn2 * sizeof(word_t), sizeof(word_t));
    word_t second_level_pgdir = paddr_read(((first_level_pgdir >> 10) << 12) + vpn1 * sizeof(word_t), sizeof(word_t));
    word_t last_level_pgdir = paddr_read(((second_level_pgdir >> 10) << 12) + vpn0 * sizeof(word_t), sizeof(word_t));

    word_t paddr = ((last_level_pgdir >> 10) << 12) | offset;
    printf("paddr = %lx\n", paddr);
    assert(paddr == vaddr);
    return paddr;
}
