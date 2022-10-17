import chisel3._
import chisel3.util._
import Define._

class Cpu_Cache_IO extends Bundle {
  val valid = Output(Bool())
  val op = Output(Bool())0
  val addr = Output(UInt(32.W))
  val wstrb = Output(UInt(8.W))
  val wdata = Output(UInt(64.W))
  val fence = Output(Bool())
  val fence_finish = Input(Bool())
  val data_ok = Input(Bool())
  val rdata = Input(UInt(64.W))
  val inst = Input(UInt(128.W))
}

class Cache_Bridge_IO extends Bundle {
  val rd_req = Output(Bool())
  val rd_size = Output(UInt(3.W))
  val rd_addr = Output(UInt(32.W))
  val rd_rdy = Input(Bool())
  val ret_valid = Input(Bool())
  val ret_data = Input(UInt(128.W))

  val wr_req = Output(Bool())
  val wr_size = Output(UInt(3.W))
  val wr_addr = Output(UInt(32.W))
  val wr_wstrb = Output(UInt(8.W))
  val wr_data = Output(UInt(128.W))
  val wr_rdy = Input(Bool())
  val wr_ok = Input(Bool())
}


