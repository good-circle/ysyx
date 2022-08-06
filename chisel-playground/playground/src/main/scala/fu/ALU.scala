import chisel3._
import chisel3.util._
import Define._

class ALU extends Module {
  val io = IO(new Bundle {
    val alu_op = Input(UInt(5.W))
    val rv64 = Input(Bool())
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val result = Output(UInt(64.W))
  })

  val alu_op = io.alu_op
  val rv64 = io.rv64

  val srl = Wire(Bool())
  val sra = Wire(Bool())
  srl := (alu_op === alu_srl) && rv64
  sra := (alu_op === alu_sra) && rv64

  val src1 = MuxCase(io.src1, Array(
    srl -> Cat(Fill(32, 0.U), io.src1(31, 0)),
    sra -> Cat(Fill(32, io.src1(31)), io.src1(31, 0))
  ))
  val src2 = io.src2

  val shamt = Mux(rv64, src2(4, 0), src2(5, 0))
  val tmp_result = Wire(UInt(64.W))

  tmp_result := MuxLookup(alu_op, 0.U, Array(
    alu_add    ->  (src1 + src2).asUInt,
    alu_sub    ->  (src1 - src2).asUInt,
    alu_and    ->  (src1 & src2).asUInt,
    alu_or     ->  (src1 | src2).asUInt,
    alu_xor    ->  (src1 ^ src2).asUInt,
    alu_slt    ->  (src1.asSInt < src2.asSInt).asUInt,
    alu_sltu   ->  (src1 < src2).asUInt,
    alu_sll    ->  (src1 << shamt).asUInt,
    alu_srl    ->  (src1 >> shamt).asUInt,
    alu_sra    ->  (src1.asSInt >> shamt).asUInt,
    alu_mul    ->  (src1 * src2).asUInt,
    alu_mulh   ->  (src1.asSInt * src2.asSInt >> 64).asUInt,
    alu_mulhsu ->  (src1.asSInt * src2.asUInt >> 64).asUInt,
    alu_mulhu  ->  (src1.asUInt * src2.asUInt >> 64).asUInt,
    alu_div    ->  (src1.asSInt / src2.asSInt).asUInt,
    alu_divu   ->  (src1.asUInt / src2.asUInt).asUInt,
    alu_rem    ->  (src1.asSInt % src2.asSInt).asUInt,
    alu_remu   ->  (src1.asUInt % src2.asUInt).asUInt
  ))

  io.result := Mux(rv64, Cat(Fill(32, tmp_result(31)), tmp_result(31, 0)), tmp_result)
}

