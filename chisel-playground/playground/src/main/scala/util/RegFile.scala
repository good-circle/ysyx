import chisel3._
import chisel3.util.experimental._

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
  
  setInline("regfile.v",
    """module regfile(
      |    input         clock ,
      |
      |    input  [ 4:0] raddr1,
      |    output [63:0] rdata1,
      |
      |    input  [ 4:0] raddr2,
      |    output [63:0] rdata2,
      |
      |    input         wen   ,
      |    input  [ 4:0] waddr ,
      |    input  [63:0] wdata
      |);
      |
      |reg [63:0] rf [31:0];
      |
      |always @(posedge clock) begin
      |    if (wen) rf[waddr] <= wdata;
      |end
      |
      |assign rdata1 = (raddr1 == 5'b0) ? 64'b0 : rf[raddr1];
      |assign rdata2 = (raddr2 == 5'b0) ? 64'b0 : rf[raddr2];
      |
      |import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
      |initial set_gpr_ptr(rf);
      |
      |endmodule
      |""".stripMargin)

}
