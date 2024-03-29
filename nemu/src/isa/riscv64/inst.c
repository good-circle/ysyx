#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // none
};

enum{
    CSRRW, CSRRS
};

#define src1R(n) do { *src1 = R(n); } while (0)
#define src2R(n) do { *src2 = R(n); } while (0)
#define destR(n) do { *dest = n; } while (0)
#define src1I(i) do { *src1 = i; } while (0)
#define src2I(i) do { *src2 = i; } while (0)
#define destI(i) do { *dest = i; } while (0)
#define src1J(i) do { *src1 = i; } while (0)
#define destB(i) do { *dest = i; } while (0)

static word_t immI(uint32_t i) { return SEXT(BITS(i, 31, 20), 12); }
static word_t immU(uint32_t i) { return SEXT(BITS(i, 31, 12), 20) << 12; }
static word_t immS(uint32_t i) { return (SEXT(BITS(i, 31, 25), 7) << 5)  | BITS(i, 11, 7); }
static word_t immJ(uint32_t i) { return (SEXT(BITS(i, 31, 31), 1) << 20) | BITS(i, 19, 12) << 12 | BITS(i, 20, 20) << 11 | BITS(i, 30, 21) << 1; }
static word_t immB(uint32_t i) { return (SEXT(BITS(i, 31, 31), 1) << 12) | BITS(i, 7, 7) << 11 | BITS(i, 30, 25) << 5 | BITS(i, 11, 8) << 1; }

static void decode_operand(Decode *s, word_t *dest, word_t *src1, word_t *src2, int type) {
  uint32_t i = s->isa.inst.val;
  int rd  = BITS(i, 11, 7);
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  destR(rd);
  switch (type) {
    case TYPE_I: src1R(rs1); src2I(immI(i)); break;
    case TYPE_U: src1I(immU(i)); break;
    case TYPE_S: destI(immS(i)); src1R(rs1); src2R(rs2); break;
    case TYPE_J: src1J(immJ(i)); break;
    case TYPE_R: src1R(rs1); src2R(rs2); break;
    case TYPE_B: src1R(rs1); src2R(rs2); destB(immB(i)); break;
  }
}

static void CSR(word_t dest, word_t src1, word_t src2, int op)
{
    int csr = 0;
    switch(src2)
    {
    case 0x341:
        csr = MEPC;
        break;
    case 0x300:
        csr = MSTATUS;
        break;
    case 0x342:
        csr = MCAUSE;
        break;
    case 0x305:
        csr = MTVEC;
        break;
    default:
        assert(0);
    }

    word_t t = cpu.csr[csr];
    switch(op)
    {
    case CSRRW:
        cpu.csr[csr] = src1;
        break;
    case CSRRS:
        cpu.csr[csr] = t | src1;
        break;
    default:
        assert(0);        
    }
    
    R(dest) = t;   
}

static int decode_exec(Decode *s) {
  word_t dest = 0, src1 = 0, src2 = 0;
  s->dnpc = s->snpc;

#ifdef CONFIG_FTRACE
  s->ftrace = 0;
#endif

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* body */ ) { \
  decode_operand(s, &dest, &src1, &src2, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();

  // RV32I
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(dest) = src1);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(dest) = src1 + s->pc);

  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(dest) = s->pc + 4; s->dnpc = s->pc + src1; IFDEF(CONFIG_FTRACE, s->ftrace = JAL;));
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(dest) = s->pc + 4; s->dnpc = (src1 + src2) | 0; IFDEF(CONFIG_FTRACE, s->ftrace = JALR;));

  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) s->dnpc = s->pc + dest);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) s->dnpc = s->pc + dest);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((sword_t)src1 < (sword_t)src2) s->dnpc = s->pc + dest);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((sword_t)src1 >= (sword_t)src2) s->dnpc = s->pc + dest);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(src1 < src2) s->dnpc = s->pc + dest);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) s->dnpc = s->pc + dest);

  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(dest) = (sword_t)((int8_t)Mr(src1 + src2, 1)));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(dest) = (sword_t)((int16_t)Mr(src1 + src2, 2)));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(dest) = (sword_t)((int32_t)Mr(src1 + src2, 4)));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(dest) = (uint8_t)Mr(src1 + src2, 1));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(dest) = (uint16_t)Mr(src1 + src2, 2));

  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + dest, 1, (int8_t)src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + dest, 2, (int16_t)src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + dest, 4, (int32_t)src2));

  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(dest) = src1 + src2);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(dest) = (sword_t)src1 < (sword_t)src2);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(dest) = src1 < src2);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(dest) = src1 ^ src2);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(dest) = src1 | src2);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(dest) = src1 & src2);
  INSTPAT("000000? ????? ????? 001 ????? 00100 11", slli   , I, R(dest) = src1 << ((src2 << 58) >> 58));
  INSTPAT("000000? ????? ????? 101 ????? 00100 11", srli   , I, R(dest) = src1 >> ((src2 << 58) >> 58));
  INSTPAT("010000? ????? ????? 101 ????? 00100 11", srai   , I, R(dest) = (sword_t)src1 >> ((src2 << 58) >> 58));
  
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(dest) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(dest) = src1 - src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(dest) = src1 << ((src2 << 58) >> 58));
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(dest) = (sword_t)src1 < (sword_t)src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(dest) = src1 < src2);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(dest) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(dest) = src1 >> ((src2 << 58) >> 58));
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(dest) = (sword_t)src1 >> ((src2 << 58) >> 58));
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(dest) = src1 | src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(dest) = src1 & src2);

  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, s->dnpc = isa_raise_intr(11, s->pc));
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, CSR(dest, src1, src2, CSRRW));
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, CSR(dest, src1, src2, CSRRS));

  // FIX ME !!! FIXED?
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , R, s->dnpc = cpu.csr[MEPC]);
  
  // RV64I
  INSTPAT("??????? ????? ????? 110 ????? 00000 11", lwu    , I, R(dest) = (uint32_t)Mr(src1 + src2, 4));
  INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld     , I, R(dest) = Mr(src1 + src2, 8));
  INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd     , S, Mw(src1 + dest, 8, src2));

  INSTPAT("??????? ????? ????? 000 ????? 00110 11", addiw  , I, R(dest) = (sword_t)((int32_t)(src1 + src2)));
  INSTPAT("0000000 ????? ????? 001 ????? 00110 11", slliw  , I, R(dest) = (sword_t)((int32_t)src1 << ((src2 << 59) >> 59)));
  INSTPAT("0000000 ????? ????? 101 ????? 00110 11", srliw  , I, R(dest) = (sword_t)(int32_t)((uint32_t)src1 >> ((src2 << 59) >> 59)));
  INSTPAT("0100000 ????? ????? 101 ????? 00110 11", sraiw  , I, R(dest) = (sword_t)((int32_t)src1 >> ((src2 << 59) >> 59)));

  INSTPAT("0000000 ????? ????? 000 ????? 01110 11", addw   , R, R(dest) = (sword_t)((int32_t)(src1 + src2)));
  INSTPAT("0100000 ????? ????? 000 ????? 01110 11", subw   , R, R(dest) = (sword_t)((int32_t)(src1 - src2)));
  INSTPAT("0000000 ????? ????? 001 ????? 01110 11", sllw   , R, R(dest) = (sword_t)((int32_t)src1 << ((src2 << 59) >> 59)));
  INSTPAT("0000000 ????? ????? 101 ????? 01110 11", srlw   , R, R(dest) = (sword_t)(int32_t)((uint32_t)src1 >> ((src2 << 59) >> 59)));
  INSTPAT("0100000 ????? ????? 101 ????? 01110 11", sraw   , R, R(dest) = (sword_t)((int32_t)src1 >> ((src2 << 59) >> 59)));

  // RV32M
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(dest) = src1 * src2);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(dest) = (sword_t)src1 / (sword_t)src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(dest) = src1 / src2);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(dest) = (sword_t)src1 % (sword_t)src2);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(dest) = src1 % src2);

  // RV64M
  INSTPAT("0000001 ????? ????? 000 ????? 01110 11", mulw   , R, R(dest) = (sword_t)((int32_t)(src1 * src2)));
  INSTPAT("0000001 ????? ????? 100 ????? 01110 11", divw   , R, R(dest) = (sword_t)(((int32_t)src1 / (int32_t)src2)));
  INSTPAT("0000001 ????? ????? 101 ????? 01110 11", divuw  , R, R(dest) = (sword_t)(int32_t)(((uint32_t)src1 / (uint32_t)src2)));
  INSTPAT("0000001 ????? ????? 110 ????? 01110 11", remw   , R, R(dest) = (sword_t)(((int32_t)src1 % (int32_t)src2)));
  INSTPAT("0000001 ????? ????? 111 ????? 01110 11", remuw  , R, R(dest) = (sword_t)(int32_t)(((uint32_t)src1 % (uint32_t)src2)));


  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
