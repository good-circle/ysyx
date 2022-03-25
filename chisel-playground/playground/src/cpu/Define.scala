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

  //val bru_x :: bru_jal :: bru_jalr :: bru_beq :: bru_bne :: bru_blt :: bru_bge :: bru_bltu :: bru_bgeu :: Nil = Enum(9)
  val bru_x = 0.U(4.W)
  val bru_jal = 1.U(4.W)
  val bru_jalr = 2.U(4.W)
  val bru_beq = 3.U(4.W)
  val bru_bne = 4.U(4.W)
  val bru_blt = 5.U(4.W)
  val bru_bge = 6.U(4.W)
  val bru_bltu = 7.U(4.W)
  val bru_bgeu = 8.U(4.W)

  //val mem_x :: mem_lb :: mem_lh :: mem_lw :: mem_lbu :: mem_lhu :: mem_sb :: mem_sh :: mem_sw :: mem_lwu :: mem_ld :: mem_sd :: Nil = Enum(12)
  val mem_x = 0.U(4.W)
  val mem_lb = 1.U(4.W)
  val mem_lh = 2.U(4.W)
  val mem_lw = 3.U(4.W)
  val mem_lbu = 4.U(4.W)
  val mem_lhu = 5.U(4.W)
  val mem_sb = 6.U(4.W)
  val mem_sh = 7.U(4.W)
  val mem_sw = 8.U(4.W)
  val mem_lwu = 9.U(4.W)
  val mem_ld = 10.U(4.W)
  val mem_sd = 11.U(4.W)

  //val r_type :: i_type :: s_type :: b_type :: u_type :: j_type :: Nil = Enum(6)
  val r_type = 0.U(3.W)
  val i_type = 1.U(3.W)
  val s_type = 2.U(3.W)
  val b_type = 3.U(3.W)
  val u_type = 4.U(3.W)
  val j_type = 5.U(3.W)

  val y = true.B
  val n = false.B

  //val fu_alu :: fu_bru :: fu_mem :: fu_csr :: Nil = Enum(4)
  val fu_alu = 0.U(3.W) 
  val fu_bru = 1.U(3.W) 
  val fu_mem = 2.U(3.W) 
  val fu_csr = 3.U(3.W) 
  
  //val src_pc :: src_rf :: src_imm :: Nil = Enum(3)
  val src_pc = 0.U(2.W) 
  val src_rf = 1.U(2.W) 
  val src_imm = 2.U(2.W)
}
