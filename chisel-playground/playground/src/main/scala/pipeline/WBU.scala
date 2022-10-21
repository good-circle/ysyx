import chisel3._
import chisel3.util._
import chisel3.util.experimental._
import Define._

class WBU extends Module with Config {
  val io = IO(new Bundle() {
    val in = Flipped(Decoupled(Vec(2, new EX_IO)))
    val wb_bus = Vec(2, new Wb_Bus)
    val commit = Vec(2, new Commit_Bus)
  })

  val in = io.in
  io.in.ready := true.B

  for (i <- 0 until 2) {
    io.wb_bus(i).rf_wen := in.bits(i).wen && in.bits(i).dest =/= 0.U && io.in.valid && in.bits(i).valid
    io.wb_bus(i).rf_waddr := in.bits(i).dest
    io.wb_bus(i).rf_wdata := in.bits(i).final_result

    io.commit(i).pc := in.bits(i).pc
    io.commit(i).inst := in.bits(i).inst
    io.commit(i).wen := in.bits(i).wen
    io.commit(i).waddr := in.bits(i).dest
    io.commit(i).wdata := in.bits(i).final_result
    io.commit(i).valid := io.in.valid && in.bits(i).valid

    io.commit(i).mcycle := false.B
    io.commit(i).is_clint := false.B
  }

  BoringUtils.addSource(io.commit(0).pc, "commit_pc")

  if (Difftest) {
    for (i <- 0 until 2) {
      io.commit(i).mcycle := io.in.bits(i).mcycle
      io.commit(i).is_clint := io.in.bits(i).is_clint
    }

  }
}
