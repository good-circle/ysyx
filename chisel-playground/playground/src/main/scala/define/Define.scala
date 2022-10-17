import chisel3._
import chisel3.util._

object Define {

  val y = true.B
  val n = false.B

  val TYPEOP_WDITH = 3
  val r_type = "b000".U(TYPEOP_WDITH.W)
  val i_type = "b001".U(TYPEOP_WDITH.W)
  val s_type = "b010".U(TYPEOP_WDITH.W)
  val b_type = "b011".U(TYPEOP_WDITH.W)
  val u_type = "b100".U(TYPEOP_WDITH.W)
  val j_type = "b101".U(TYPEOP_WDITH.W)

  val FUOP_WIDTH = 3
  val fu_alu = "b000".U(FUOP_WIDTH.W)
  val fu_bru = "b001".U(FUOP_WIDTH.W)
  val fu_lsu = "b010".U(FUOP_WIDTH.W)
  val fu_csr = "b011".U(FUOP_WIDTH.W)
  val fu_mdu = "b100".U(FUOP_WIDTH.W)

  val ALUOP_WIDTH = 5
  val alu_x = "b0000".U(ALUOP_WIDTH.W)
  val alu_add = "b0001".U(ALUOP_WIDTH.W)
  val alu_sub = "b0010".U(ALUOP_WIDTH.W)
  val alu_and = "b0011".U(ALUOP_WIDTH.W)
  val alu_or = "b0100".U(ALUOP_WIDTH.W)
  val alu_xor = "b0101".U(ALUOP_WIDTH.W)
  val alu_slt = "b0110".U(ALUOP_WIDTH.W)
  val alu_sltu = "b0111".U(ALUOP_WIDTH.W)
  val alu_sll = "b1000".U(ALUOP_WIDTH.W)
  val alu_srl = "b1001".U(ALUOP_WIDTH.W)
  val alu_sra = "b1010".U(ALUOP_WIDTH.W)

  val MDUOP_WIDTH = 4
  val mdu_x = "b0000".U(MDUOP_WIDTH.W)
  val mdu_mul = "b0001".U(MDUOP_WIDTH.W)
  val mdu_mulh = "b0010".U(MDUOP_WIDTH.W)
  val mdu_mulhsu = "b0011".U(MDUOP_WIDTH.W)
  val mdu_mulhu = "b0100".U(MDUOP_WIDTH.W)
  val mdu_div = "b0101".U(MDUOP_WIDTH.W)
  val mdu_divu = "b0110".U(MDUOP_WIDTH.W)
  val mdu_rem = "b0111".U(MDUOP_WIDTH.W)
  val mdu_remu = "b1000".U(MDUOP_WIDTH.W)

  val BRUOP_WIDTH = 4
  val bru_x = "b0000".U(BRUOP_WIDTH.W)
  val bru_jal = "b0001".U(BRUOP_WIDTH.W)
  val bru_jalr = "b0010".U(BRUOP_WIDTH.W)
  val bru_beq = "b0011".U(BRUOP_WIDTH.W)
  val bru_bne = "b0100".U(BRUOP_WIDTH.W)
  val bru_blt = "b0101".U(BRUOP_WIDTH.W)
  val bru_bge = "b0110".U(BRUOP_WIDTH.W)
  val bru_bltu = "b0111".U(BRUOP_WIDTH.W)
  val bru_bgeu = "b1000".U(BRUOP_WIDTH.W)

  val LSUOP_WIDTH = 4
  val lsu_x = "b0000".U(LSUOP_WIDTH.W)
  val lsu_lb = "b0001".U(LSUOP_WIDTH.W)
  val lsu_lh = "b0010".U(LSUOP_WIDTH.W)
  val lsu_lw = "b0011".U(LSUOP_WIDTH.W)
  val lsu_lbu = "b0100".U(LSUOP_WIDTH.W)
  val lsu_lhu = "b0101".U(LSUOP_WIDTH.W)
  val lsu_sb = "b0110".U(LSUOP_WIDTH.W)
  val lsu_sh = "b0111".U(LSUOP_WIDTH.W)
  val lsu_sw = "b1000".U(LSUOP_WIDTH.W)
  val lsu_lwu = "b1001".U(LSUOP_WIDTH.W)
  val lsu_ld = "b1010".U(LSUOP_WIDTH.W)
  val lsu_sd = "b1011".U(LSUOP_WIDTH.W)

  val CSROP_WIDTH = 3
  val csr_x = "b000".U(CSROP_WIDTH.W)
  val csr_csrrw = "b001".U(CSROP_WIDTH.W)
  val csr_csrrs = "b010".U(CSROP_WIDTH.W)
  val csr_csrrc = "b011".U(CSROP_WIDTH.W)
  val csr_ecall = "b100".U(CSROP_WIDTH.W)
  val csr_mret = "b101".U(CSROP_WIDTH.W)
  val csr_fence = "b110".U(CSROP_WIDTH.W)

  val SRCOP_WIDTH = 2
  val src_x = "b00".U(SRCOP_WIDTH.W)
  val src_pc = "b01".U(SRCOP_WIDTH.W)
  val src_rf = "b10".U(SRCOP_WIDTH.W)
  val src_imm = "b11".U(SRCOP_WIDTH.W)

  val CSR_WIDTH = 12
  val mcycle_addr = "hb00".U(12.W)
  val mepc_addr = "h341".U(12.W)
  val mcause_addr = "h342".U(12.W)
  val mstatus_addr = "h300".U(12.W)
  val mtvec_addr = "h305".U(12.W)
  val mip_addr = "h344".U(12.W)
  val mie_addr = "h304".U(12.W)
  val mscratch_addr = "h340".U(12.W)

  val WRITE = true.B
  val READ = false.B

  val SIZE_B = "b000".U(3.W)
  val SIZE_H = "b001".U(3.W)
  val SIZE_W = "b010".U(3.W)
  val SIZE_D = "b011".U(3.W)

  val SRAM_BITS = 128
  val SRAM_ADDR_WIDTH = 6

  val INDEX_WIDTH = 6 // 4kB cache / 4-way associative / 16 bytes = 64
  val TAG_WIDTH = 22 // 32 - 4 - 6 = 22
  val OFFSET_WIDTH = 4

  val BPU_OFFSET_WIDTH = OFFSET_WIDTH
  val BTB_ENTRY = 8 // 32 entrys, 4-way associative
  val BTB_INDEX_WIDTH = log2Up(BTB_ENTRY)
  val BTB_TAG_WIDTH = 32 - 4 - BTB_INDEX_WIDTH // 32 - 4 - 3 = 25
  val BTB_OFFSET_WIDTH = 2 // pc(3, 2)

  val BTB_TYPE_WIDTH = 2
  val BTB_CALL = "b00".U(2.W)
  val BTB_RET = "b01".U(2.W)
  val BTB_BRANCH = "b10".U(2.W)
  val BTB_JUMP = "b11".U(2.W) // except call and ret

  val RAS_ENTRY = 8

  val PHT_ENTRY = 16
  val PHT_INDEX_WIDTH = log2Up(PHT_ENTRY)
  val INST_QUEUE_ENTRY = 16
}