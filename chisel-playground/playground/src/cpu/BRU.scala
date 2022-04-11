import chisel3._
import chisel3.util._
import Define._

class BRU extends Module {
  val io = IO(new Bundle {
    val bruop = Input(UInt(4.W))
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val pc = Input(UInt(64.W))
    val imm = Input(UInt(64.W))
    val br_taken = Output(Bool())
    val br_target = Output(UInt(64.W))
  })

  io.br_taken := MuxLookup(io.bruop, 0.U, Array(
    bru_jal  -> true.B,
    bru_jalr -> true.B,
    bru_beq  -> (io.src1 === io.src2),
    bru_bne  -> (io.src1 =/= io.src2),
    bru_blt  -> (io.src1.asSInt <  io.src2.asSInt),
    bru_bge  -> (io.src1.asSInt >= io.src2.asSInt),
    bru_bltu -> (io.src1.asUInt <  io.src2.asUInt),
    bru_bgeu -> (io.src1.asUInt >= io.src2.asUInt),
  ))

  io.br_target := Mux(io.bruop === bru_jalr, ((io.src1 + io.imm) >> 1) << 1, io.pc + io.imm)
}


