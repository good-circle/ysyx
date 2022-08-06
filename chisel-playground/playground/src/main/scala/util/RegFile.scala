import chisel3._
import chisel3.util.experimental._
import difftest._

class RegFile extends Module {
  val io = IO(new Bundle {
    val raddr1 = Input(UInt(5.W))
    val raddr2 = Input(UInt(5.W))
    val rdata1 = Output(UInt(64.W))
    val rdata2 = Output(UInt(64.W))
    val waddr = Input(UInt(5.W))
    val wdata = Input(UInt(64.W))
    val wen = Input(Bool())
  })

  val rf = RegInit(VecInit(Seq.fill(32)(0.U(64.W))))

  when (io.wen && (io.waddr =/= 0.U)) {
    rf(io.waddr) := io.wdata;
  }

  io.rdata1 := Mux((io.raddr1 =/= 0.U), rf(io.raddr1), 0.U)
  io.rdata2 := Mux((io.raddr2 =/= 0.U), rf(io.raddr2), 0.U)

  val dt_ar = Module(new DifftestArchIntRegState)
  dt_ar.io.clock  := clock
  dt_ar.io.coreid := 0.U
  dt_ar.io.gpr    := rf

  BoringUtils.addSource(rf(10), "rf_a0")
}
