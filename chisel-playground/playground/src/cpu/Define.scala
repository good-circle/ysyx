package cpu

import chisel3._
import chisel3.util._

object Define {
  //val alu_x :: alu_add :: alu_sub :: alu_and :: alu_or :: alu_xor :: alu_slt :: alu_sltu :: alu_sll :: alu_srl :: alu_sra :: alu_mul :: alu_mulh :: alu_mulhsu :: alu_mulhu :: alu_div :: alu_divu :: alu_rem :: alu_remu :: Nil = Enum(19)
  val alu_x = 0.U(5.W)
  val alu_add = 1.U(5.W)
  val alu_sub = 2.U(5.W)
  val alu_and = 3.U(5.W)
  val alu_or = 4.U(5.W)
  val alu_xor = 5.U(5.W)
  val alu_slt = 6.U(5.W)
  val alu_sltu = 7.U(5.W)
  val alu_sll = 8.U(5.W)
  val alu_srl = 9.U(5.W) 
  val alu_sra = 10.U(5.W)  
  val alu_mul = 11.U(5.W) 
  val alu_mulh = 12.U(5.W) 
  val alu_mulhsu = 13.U(5.W) 
  val alu_mulhu = 14.U(5.W) 
  val alu_div = 15.U(5.W)
  val alu_divu = 16.U(5.W) 
  val alu_rem = 17.U(5.W) 
  val alu_remu = 18.U(5.W)

  val bru_x :: bru_jal :: bru_jalr :: bru_beq :: bru_bne :: bru_blt :: bru_bge :: bru_bltu :: bru_bgeu :: Nil = Enum(9)

  val mem_x :: mem_lb :: mem_lh :: mem_lw :: mem_lbu :: mem_lhu :: mem_sb :: mem_sh :: mem_sw :: mem_lwu :: mem_ld :: mem_sd :: Nil = Enum(12)

  val r_type :: i_type :: s_type :: b_type :: u_type :: j_type :: Nil = Enum(6)

  val y = true.B
  val n = false.B

  val fu_alu :: fu_bru :: fu_mem :: fu_csr :: Nil = Enum(4)

  val src_pc :: src_rf :: src_imm :: Nil = Enum(3)
}
