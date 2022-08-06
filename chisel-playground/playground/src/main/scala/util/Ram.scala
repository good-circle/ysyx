import chisel3._
import chisel3.util._

class RomIO extends Bundle {
  val en = Output(Bool())
  val addr = Output(UInt(64.W))
  val rdata = Input(UInt(64.W))
}

class RamIO extends RomIO {
  val wdata = Output(UInt(64.W))
  val wmask = Output(UInt(64.W))
  val wen = Output(Bool())
}

class ram_2r1w extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    
    val imem_en = Input(Bool())
    val imem_addr = Input(UInt(64.W))
    val imem_data = Output(UInt(32.W))

    val dmem_en = Input(Bool())
    val dmem_addr = Input(UInt(64.W))
    val dmem_rdata = Output(UInt(64.W))
    val dmem_wdata = Input(UInt(64.W))
    val dmem_wmask = Input(UInt(64.W))
    val dmem_wen = Input(Bool())
  })

  setInline("Blackbox.v",
    """module Blackbox(
      |    input         clk,
      |    input         imem_en,
      |    input  [63:0] imem_addr,
      |
      |    input         dmem_en,
      |    input  [63:0] dmem_addr,
      |    output [63:0] dmem_rdata,
      |    input  [63:0] dmem_wdata,
      |
      |    input  [63:0] dmem_wmask,
      |    input         dmem_wen  
      |
      |);
      |
      |import "DPI-C" context function void pmem_read(
      |  input longint mem_raddr, input bit mem_read);
      |import "DPI-C" context function void pmem_write(
      |  input longint mem_waddr, input longint mem_wdata, input byte mem_wmask, input bit mem_write);
      |
      |always @(posedge clk) begin
      |  pmem_write(dmem_addr, dmem_wdata, dmem_wmask, dmem_wen);
      |end
      |
      |wire [63:0] inst_2 = pmem_read(imem_addr, imem_en);
      |assign imem_data = imem_addr[2] ? inst_2[63:32] : inst_2[31:0];
      |assign dmem_rdata = pmem_read(dmem_addr, dmem_en);
      |
      |
      |endmodule
      |""".stripMargin)

}

class Ram2r1w extends Module {
  val io = IO(new Bundle {
    val imem = Flipped(new RomIO)
    val dmem = Flipped(new RamIO)
  })
  val mem = Module(new ram_2r1w)
  mem.io.clk        := clock
  mem.io.imem_en    := io.imem.en
  mem.io.imem_addr  := io.imem.addr
  io.imem.rdata     := mem.io.imem_data
  mem.io.dmem_en    := io.dmem.en
  mem.io.dmem_addr  := io.dmem.addr
  io.dmem.rdata     := mem.io.dmem_rdata
  mem.io.dmem_wdata := io.dmem.wdata
  mem.io.dmem_wmask := io.dmem.wmask
  mem.io.dmem_wen   := io.dmem.wen
}
