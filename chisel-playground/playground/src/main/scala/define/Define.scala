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

  val FUOP_WIDTH = 2
  val fu_alu = "b00".U(FUOP_WIDTH.W)
  val fu_bru = "b01".U(FUOP_WIDTH.W)
  val fu_lsu = "b10".U(FUOP_WIDTH.W)
  val fu_csr = "b11".U(FUOP_WIDTH.W)

  val ALUOP_WIDTH = 5
  val alu_x = "b00000".U(ALUOP_WIDTH.W)
  val alu_add = "b00001".U(ALUOP_WIDTH.W)
  val alu_sub = "b00010".U(ALUOP_WIDTH.W)
  val alu_and = "b00011".U(ALUOP_WIDTH.W)
  val alu_or = "b00100".U(ALUOP_WIDTH.W)
  val alu_xor = "b00101".U(ALUOP_WIDTH.W)
  val alu_slt = "b00110".U(ALUOP_WIDTH.W)
  val alu_sltu = "b00111".U(ALUOP_WIDTH.W)
  val alu_sll = "b01000".U(ALUOP_WIDTH.W)
  val alu_srl = "b01001".U(ALUOP_WIDTH.W)
  val alu_sra = "b01010".U(ALUOP_WIDTH.W)
  val alu_mul = "b01011".U(ALUOP_WIDTH.W)
  val alu_mulh = "b01100".U(ALUOP_WIDTH.W)
  val alu_mulhsu = "b01101".U(ALUOP_WIDTH.W)
  val alu_mulhu = "b01110".U(ALUOP_WIDTH.W)
  val alu_div = "b01111".U(ALUOP_WIDTH.W)
  val alu_divu = "b10000".U(ALUOP_WIDTH.W)
  val alu_rem = "b10001".U(ALUOP_WIDTH.W)
  val alu_remu = "b10010".U(ALUOP_WIDTH.W)

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
}