import chisel3._
import chisel3.util._
import Define._

class WBU extends Module{
  val io = IO(new Bundle() {
    val in = Flipped(Decoupled(new EX_IO))
    val wb_bus = new Wb_Bus
    val commit = new Commit_Bus
  })

  val pc = io.in.bits.pc
  val inst = io.in.bits.inst
  val final_result = io.in.bits.final_result
  val dest = io.in.bits.dest
  val wen = io.in.bits.wen
  io.in.ready := true.B

  val rf_wen = wen
  val rf_waddr = dest
  val rf_wdata = final_result

  io.wb_bus.rf_wen := rf_wen && dest =/= 0.U && io.in.valid
  io.wb_bus.rf_waddr := rf_waddr
  io.wb_bus.rf_wdata := rf_wdata

  io.commit.pc := pc
  io.commit.inst := inst
  io.commit.wen := rf_wen
  io.commit.waddr := rf_waddr
  io.commit.wdata := rf_wdata
  io.commit.valid := io.in.valid

  io.commit.mcycle := io.in.bits.mcycle
  io.commit.is_clint := io.in.bits.is_clint
}
