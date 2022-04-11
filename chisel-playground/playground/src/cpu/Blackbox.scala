import chisel3._
import chisel3.util._

class Blackbox extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val mem_read = Input(Bool())
    val mem_raddr = Input(UInt(64.W))
    val mem_rdata = Output(UInt(64.W))

    val mem_write = Input(Bool())
    val mem_waddr = Input(UInt(64.W))
    val mem_wmask = Input(UInt(8.W))
    val mem_wdata = Input(UInt(64.W))

    val inst_ready = Input(Bool())
    val pc = Input(UInt(64.W))
    val inst_2 = Output(UInt(64.W))

    val ebreak = Input(Bool())
  })

  setInline("Blackbox.v",
    """module Blackbox(
      |    input  [63:0] mem_raddr,
      |    input         mem_read ,
      |    output [63:0] mem_rdata,
      |
      |    input  [63:0] mem_waddr,
      |    input         mem_write,
      |    input  [ 7:0] mem_wmask,
      |    input  [63:0] mem_wdata,
      |
      |    input         inst_ready,
      |    input  [63:0] pc        ,
      |    output [63:0] inst_2    ,
      |
      |    input ebreak
      |);
      |
      |export "DPI-C" function finish;
      |function bit finish();
      |    return ebreak;
      |endfunction
      |
      |import "DPI-C" context function void pmem_read(
      |  input longint mem_raddr, output longint mem_rdata, input bit mem_read);
      |import "DPI-C" context function void pmem_write(
      |  input longint mem_waddr, input longint mem_wdata, input byte mem_wmask, input bit mem_write);
      |
      |always @(*) begin
      |  pmem_read(mem_raddr, mem_rdata, mem_read);
      |  pmem_write(mem_waddr, mem_wdata, mem_wmask, mem_write);
      |end
      |
      |always @(*) begin
      |    pmem_read(pc, inst_2, inst_ready);
      |end
      |
      |endmodule
      |""".stripMargin)

}


