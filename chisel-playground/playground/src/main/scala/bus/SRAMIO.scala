import chisel3._
import chisel3.util._
import Define._

class SRAMIO extends Bundle {
  val req = Output(Bool())
  val wr = Output(Bool())
  val size = Output(UInt(3.W))
  val addr = Output(UInt(32.W))
  val wstrb = Output(UInt(8.W))
  val wdata = Output(UInt(64.W))
  val addr_ok  = Input(Bool())
  val data_ok  = Input(Bool())
  val rdata = Input(UInt(64.W))
}

class SRAMIO_Soc extends Bundle {
  val addr = Output(UInt(SRAM_ADDR_WIDTH.W))
  val cen = Output(Bool())
  val wen = Output(Bool())
  val wmask = Output(UInt(SRAM_BITS.W))
  val wdata = Output(UInt(SRAM_BITS.W))
  val rdata = Input(UInt(SRAM_BITS.W))
}

class SRAMIO_Cache extends Bundle {
  val en = Output(Bool())
  val wen = Output(Bool())
  val addr = Output(UInt(SRAM_ADDR_WIDTH.W))
  val wdata = Output(UInt(SRAM_BITS.W))
  val rdata = Input(UInt(SRAM_BITS.W))
}