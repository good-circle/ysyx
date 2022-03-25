package cpu

import chisel3._
import chisel3.util._
import cpu.Define._

class ALU extends Module {
  val io = IO(new Bundle {
    val aluop = Input(UInt(5.W))
    val rv64 = Input(Bool())
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val result = Output(UInt(64.W))
  })

  val aluop = io.aluop
  val rv64 = io.rv64
  val src1 = io.src1
  val src2 = io.src2

  val shamt = Mux(rv64, src2(4, 0), src2(5, 0))
  val tmp_result = Wire(UInt(64.W))

  tmp_result := MuxLookup(aluop, 0.U, Array(
    alu_add    ->  (src1 + src2),
    alu_sub    ->  (src1 - src2),
    alu_and    ->  (src1 & src2),
    alu_or     ->  (src1 | src2),
    alu_xor    ->  (src1 ^ src2),
    alu_slt    ->  (src1.asSInt < src2.asSInt),
    alu_sltu   ->  (src1 < src2),
    alu_sll    ->  (src1 << shamt),
    alu_srl    ->  (src1 >> shamt),
    alu_sra    ->  (src1.asSInt >> shamt),
    alu_mul    ->  (src1 * src2),
    alu_mulh   ->  (src1.asSInt * src2.asSInt >> 64),
    alu_mulhsu ->  (src1.asSInt * src2.asUInt >> 64),
    alu_mulhu  ->  (src1.asUInt * src2.asUInt >> 64),
    alu_div    ->  (src1.asSInt / src2.asSInt),
    alu_divu   ->  (src1.asUInt / src2.asUInt),
    alu_rem    ->  (src1.asSInt % src2.asSInt),
    alu_remu   ->  (src1.asUInt % src2.asUInt),
  ))

  io.result := Mux(rv64, Cat(Fill(32, tmp_result(31)), tmp_result(31, 0)), tmp_result)
}


