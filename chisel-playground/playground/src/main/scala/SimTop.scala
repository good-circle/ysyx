import chisel3._
import chisel3.util._
import difftest._

class SimTop extends Module {
  val io = IO(new Bundle {
  })

  val core = Module(new Core)

  val mem = Module(new Ram2r1w)
  mem.io.imem <> core.io.imem
  mem.io.dmem <> core.io.dmem

}
