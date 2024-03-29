#ifndef __ISA_RISCV64_H__
#define __ISA_RISCV64_H__

#include <common.h>

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
  word_t csr[4]; // mepc, mstatus, mcause, mtvec
} riscv64_CPU_state;

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} riscv64_ISADecodeInfo;

enum{
    MEPC, MSTATUS, MCAUSE, MTVEC
};

#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#endif
