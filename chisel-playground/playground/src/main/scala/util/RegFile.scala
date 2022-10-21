import chisel3._
import chisel3.util.experimental._

class RegFile extends Module with Config {
  val io = IO(new Bundle {
    val rf_bus = Vec(2, new RF_BUS)
  })

  val rf_bus = io.rf_bus

  val rf = RegInit(VecInit(Seq.fill(32)(0.U(64.W))))

  for (i <- 0 until 2) {
    when (rf_bus(i).wen && (rf_bus(i).waddr =/= 0.U)) {
      rf(rf_bus(i).waddr) := rf_bus(i).wdata;
    }
    rf_bus(i).rdata1 := Mux((rf_bus(i).raddr1 =/= 0.U), rf(rf_bus(i).raddr1), 0.U)
    rf_bus(i).rdata2 := Mux((rf_bus(i).raddr2 =/= 0.U), rf(rf_bus(i).raddr2), 0.U)
  }

  if (Difftest) {
    import difftest._

    BoringUtils.addSource(rf(10), "rf_a0")
    
    val dt_ar = Module(new DifftestArchIntRegState)
    dt_ar.io.clock  := clock
    dt_ar.io.coreid := 0.U
    dt_ar.io.gpr    := rf
  }
}
