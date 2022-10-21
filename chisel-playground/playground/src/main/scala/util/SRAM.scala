import chisel3._
import chisel3.util._
import Define._

class S011HD1P_X32Y2D128 extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle() {
    val Q = Output(UInt(SRAM_BITS.W))
    val CLK = Input(Clock())
    val CEN = Input(Bool())
    val WEN = Input(Bool())
    val A = Input(UInt(SRAM_ADDR_WIDTH.W))
    val D = Input(UInt(SRAM_BITS.W))
  })

  setInline("S011HD1P_X32Y2D128.v",
  """
      |module S011HD1P_X32Y2D128(
      |    Q, CLK, CEN, WEN, A, D
      |);
      |parameter Bits = 128;
      |parameter Word_Depth = 64;
      |parameter Add_Width = 6;
      |
      |output  reg [Bits-1:0]      Q;
      |input                   CLK;
      |input                   CEN;
      |input                   WEN;
      |input   [Add_Width-1:0] A;
      |input   [Bits-1:0]      D;
      |
      |reg [Bits-1:0] ram [0:Word_Depth-1];
      |always @(posedge CLK) begin
      |    if(!CEN && !WEN) begin
      |        ram[A] <= D;
      |    end
      |    Q <= !CEN && WEN ? ram[A] : {128{$random}};
      |end
      |
      |endmodule""".stripMargin
  )
}

class SRAM extends Module {
  val io = IO(new Bundle {
    val en = Input(Bool())
    val wen = Input(Bool())
    val addr = Input(UInt(SRAM_ADDR_WIDTH.W))
    val wdata = Input(UInt(SRAM_BITS.W))
    val rdata = Output(UInt(SRAM_BITS.W))
  })

  val sram = Module(new S011HD1P_X32Y2D128)

  io.rdata := sram.io.Q

  sram.io.CLK := clock
  sram.io.CEN := !io.en
  sram.io.WEN := !io.wen
  sram.io.A := io.addr
  sram.io.D := io.wdata
}