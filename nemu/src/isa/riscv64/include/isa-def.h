#ifndef __ISA_RISCV64_H__
#define __ISA_RISCV64_H__

#include <common.h>

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
  word_t csr[5]; // mepc, mstatus, mcause, mtvec, satp
} riscv64_CPU_state;

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} riscv64_ISADecodeInfo;

enum{
    MEPC, MSTATUS, MCAUSE, MTVEC, SATP
};

#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#endif
