import chisel3._
import chisel3.util._
import chisel3.util.experimental._

class RegFile extends Module with Config {
  val io = IO(new Bundle {
    val rf_bus = Vec(2, new RF_BUS)
  })

  val rf_bus = io.rf_bus

  if (MyEnv) {
    val rf = Module (new SimRF)
    rf.io.rf_bus_0_raddr1 := io.rf_bus(0).raddr1
    rf.io.rf_bus_0_raddr2 := io.rf_bus(0).raddr2
    io.rf_bus(0).rdata1 := rf.io.rf_bus_0_rdata1
    io.rf_bus(0).rdata2 := rf.io.rf_bus_0_rdata2
    rf.io.rf_bus_0_waddr := io.rf_bus(0).waddr
    rf.io.rf_bus_0_wdata := io.rf_bus(0).wdata
    rf.io.rf_bus_0_wen := io.rf_bus(0).wen
    rf.io.rf_bus_1_raddr1 := io.rf_bus(1).raddr1
    rf.io.rf_bus_1_raddr2 := io.rf_bus(1).raddr2
    io.rf_bus(1).rdata1 := rf.io.rf_bus_1_rdata1
    io.rf_bus(1).rdata2 := rf.io.rf_bus_1_rdata2
    rf.io.rf_bus_1_waddr := io.rf_bus(1).waddr
    rf.io.rf_bus_1_wdata := io.rf_bus(1).wdata
    rf.io.rf_bus_1_wen := io.rf_bus(1).wen
  } else {
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
}


class SimRF extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val rf_bus_0_raddr1 = Input(UInt(5.W))
    val rf_bus_0_raddr2 = Input(UInt(5.W))
    val rf_bus_0_rdata1 = Output(UInt(64.W))
    val rf_bus_0_rdata2 = Output(UInt(64.W))
    val rf_bus_0_waddr = Input(UInt(5.W))
    val rf_bus_0_wdata = Input(UInt(64.W))
    val rf_bus_0_wen = Input(Bool())
    val rf_bus_1_raddr1 = Input(UInt(5.W))
    val rf_bus_1_raddr2 = Input(UInt(5.W))
    val rf_bus_1_rdata1 = Output(UInt(64.W))
    val rf_bus_1_rdata2 = Output(UInt(64.W))
    val rf_bus_1_waddr = Input(UInt(5.W))
    val rf_bus_1_wdata = Input(UInt(64.W))
    val rf_bus_1_wen = Input(Bool())
  })

    setInline("SimRF.v",
      """module RegFile(
        |  input         clock,
        |  input         reset,
        |  input  [4:0]  rf_bus_0_raddr1,
        |  input  [4:0]  rf_bus_0_raddr2,
        |  output [63:0] rf_bus_0_rdata1,
        |  output [63:0] rf_bus_0_rdata2,
        |  input  [4:0]  rf_bus_0_waddr,
        |  input  [63:0] rf_bus_0_wdata,
        |  input         rf_bus_0_wen,
        |  input  [4:0]  rf_bus_1_raddr1,
        |  input  [4:0]  rf_bus_1_raddr2,
        |  output [63:0] rf_bus_1_rdata1,
        |  output [63:0] rf_bus_1_rdata2,
        |  input  [4:0]  rf_bus_1_waddr,
        |  input  [63:0] rf_bus_1_wdata,
        |  input         rf_bus_1_wen
        |);
        |
        |reg [63:0] rf [31:0];
        |
        |always @(posedge clock) begin
        |    if (rf_bus_0_wen) rf[rf_bus_0_waddr] <= rf_bus_0_wdata;
        |    if (rf_bus_1_wen) rf[rf_bus_1_waddr] <= rf_bus_1_wdata;
        |end
        |
        |assign rf_bus_0_rdata1 = (rf_bus_0_raddr1 == 5'b0) ? 64'b0 : rf[rf_bus_0_raddr1];
        |assign rf_bus_0_rdata2 = (rf_bus_0_raddr2 == 5'b0) ? 64'b0 : rf[rf_bus_0_raddr2];
        |assign rf_bus_1_rdata1 = (rf_bus_1_raddr1 == 5'b0) ? 64'b0 : rf[rf_bus_1_raddr1];
        |assign rf_bus_1_rdata2 = (rf_bus_1_raddr2 == 5'b0) ? 64'b0 : rf[rf_bus_1_raddr2];
        |
        |import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
        |initial set_gpr_ptr(rf);
        |
        |endmodule
        |""".stripMargin)

}


