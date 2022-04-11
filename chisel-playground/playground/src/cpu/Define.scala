import chisel3._
import chisel3.util._

object Define {
  val alu_x :: alu_add :: alu_sub :: alu_and :: alu_or :: alu_xor :: alu_slt :: alu_sltu :: alu_sll :: alu_srl :: alu_sra :: alu_mul :: alu_mulh :: alu_mulhsu :: alu_mulhu :: alu_div :: alu_divu :: alu_rem :: alu_remu :: Nil = Enum(19)

  val bru_x :: bru_jal :: bru_jalr :: bru_beq :: bru_bne :: bru_blt :: bru_bge :: bru_bltu :: bru_bgeu :: Nil = Enum(9)

  val mem_x :: mem_lb :: mem_lh :: mem_lw :: mem_lbu :: mem_lhu :: mem_sb :: mem_sh :: mem_sw :: mem_lwu :: mem_ld :: mem_sd :: Nil = Enum(12)

  val r_type :: i_type :: s_type :: b_type :: u_type :: j_type :: Nil = Enum(6)

  val y = true.B
  val n = false.B

  val fu_alu :: fu_bru :: fu_mem :: fu_csr :: Nil = Enum(4)

  val src_x :: src_pc :: src_rf :: src_imm :: Nil = Enum(4)
}