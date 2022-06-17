#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)
#define MAP(c, f) c(f)

#if __riscv_xlen == 32
#define LOAD  lw
#define STORE sw
#define XLEN  4
#else
#define LOAD  ld
#define STORE sd
#define XLEN  8
#endif

#define REGS(f) \
      f( 1)       f( 3) f( 4) f( 5) f( 6) f( 7) f( 8) f( 9) \
f(10) f(11) f(12) f(13) f(14) f(15) f(16) f(17) f(18) f(19) \
f(20) f(21) f(22) f(23) f(24) f(25) f(26) f(27) f(28) f(29) \
f(30) f(31)

#define PUSH(n) STORE concat(x, n), (n * XLEN)(sp);
#define POP(n)  LOAD  concat(x, n), (n * XLEN)(sp);

// 32 + mcause, mstatus, mepc, np + pdir
#define CONTEXT_SIZE  ((32 + 4 + 1) * XLEN)
#define OFFSET_SP     ( 2 * XLEN)
#define OFFSET_CAUSE  (32 * XLEN)
#define OFFSET_STATUS (33 * XLEN)
#define OFFSET_EPC    (34 * XLEN)
#define OFFSET_NP     (35 * XLEN)

.align 3
.globl __am_asm_trap
__am_asm_trap:

  // atomically exchange sp and mscratch (ksp)
  csrrw sp, mscratch, sp   
  // take the branch if we trapped from user
  // if ksp != 0, then branch, and here mscratch is original sp
  bnez sp, _save_context_user  
  // if we trapped from kernel, restore the original sp
  csrr sp, mscratch       

  // trapped from kernel
  addi sp, sp, -CONTEXT_SIZE
  MAP(REGS, PUSH)
  // c->np = KERNEL (0)
  STORE x0, OFFSET_NP(sp)
  jal _save_csr

_save_context_user:
  // trapped from user
  addi sp, sp, -CONTEXT_SIZE
  MAP(REGS, PUSH)
  // c->np = USER (1)
  li t0, 1
  STORE t0, OFFSET_NP(sp)

_save_csr:
  csrr t0, mcause
  csrr t1, mstatus
  csrr t2, mepc

  STORE t0, OFFSET_CAUSE(sp)
  STORE t1, OFFSET_STATUS(sp)
  STORE t2, OFFSET_EPC(sp)

  // here mscratch is original sp
  csrr t3, mscratch
  STORE t3, OFFSET_SP(sp)

  // ksp -> 0 to support re-entry of CTE
  csrw mscratch, x0

  // set mstatus.MPRV to pass difftest
  li a0, (1 << 17)
  or t1, t1, a0
  csrw mstatus, t1

  mv a0, sp
  jal __am_irq_handle
  mv sp ,a0

  LOAD t1, OFFSET_STATUS(sp)
  LOAD t2, OFFSET_EPC(sp)
  csrw mstatus, t1
  csrw mepc, t2

  // read c->np and take the branch if is USER
  LOAD t0, OFFSET_NP(sp)
  bnez t0, _restore_context_user

  MAP(REGS, POP)
  addi sp, sp, CONTEXT_SIZE
  jal _mret

_restore_context_user:
  // set mscratch = c->sp
  LOAD t3, OFFSET_SP(sp)
  csrw mscratch, t3

  MAP(REGS, POP)
  addi sp, sp, CONTEXT_SIZE

  // mscratch = $sp, $sp = c->sp
  csrrw sp, mscratch, sp

_mret:
  mret