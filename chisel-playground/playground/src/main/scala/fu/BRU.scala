import chisel3._
import chisel3.util._
import Define._

class BRU extends Module {
  val io = IO(new Bundle {
    val bru_op = Input(UInt(4.W))
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val pc = Input(UInt(32.W))
    val imm = Input(UInt(64.W))
    val br_taken = Output(Bool())
    val br_target = Output(UInt(32.W))

    /* for branch prediction */
    val rs1 = Input(UInt(5.W))
    val rd = Input(UInt(5.W))
    val btb_type = Output(UInt(BTB_TYPE_WIDTH.W))
  })

  val btb_type = WireInit(0.U(BTB_TYPE_WIDTH.W))

  io.br_taken := MuxLookup(io.bru_op, 0.U, Array(
    bru_jal  -> true.B,
    bru_jalr -> true.B,
    bru_beq  -> (io.src1 === io.src2),
    bru_bne  -> (io.src1 =/= io.src2),
    bru_blt  -> (io.src1.asSInt <  io.src2.asSInt),
    bru_bge  -> (io.src1.asSInt >= io.src2.asSInt),
    bru_bltu -> (io.src1.asUInt <  io.src2.asUInt),
    bru_bgeu -> (io.src1.asUInt >= io.src2.asUInt),
  ))

  io.br_target := Mux(io.bru_op === bru_jalr, ((io.src1(31, 0) + io.imm(31, 0)) >> 1) << 1, io.pc(31, 0) + io.imm(31, 0))

  when ((io.bru_op === bru_jal || io.bru_op === bru_jalr) && io.rd === 1.U) {
    btb_type := BTB_CALL
  } .elsewhen ((io.bru_op === bru_jalr) && io.rs1 === 1.U) {
    btb_type := BTB_RET
  } .elsewhen (io.bru_op === bru_jal || io.bru_op === bru_jalr) {
    btb_type := BTB_JUMP
  } .otherwise {
    btb_type := BTB_BRANCH
  }

  io.btb_type := btb_type
}

