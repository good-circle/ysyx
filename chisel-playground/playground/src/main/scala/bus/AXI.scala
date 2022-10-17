import chisel3._
import chisel3.util._
import Define._

class AXIA extends Bundle {
  val addr = Output(UInt(32.W))
  val prot = Output(UInt(3.W))
  val id = Output(UInt(4.W))
  val user = Output(UInt(1.W))
  val len = Output(UInt(8.W))
  val size = Output(UInt(3.W))
  val burst = Output(UInt(2.W))
  val lock = Output(Bool())
  val cache = Output(UInt(4.W))
  val qos = Output(UInt(4.W))
}

class AxiW extends Bundle {
  val data = Output(UInt(64.W))
  val strb = Output(UInt(8.W))
  val last = Output(Bool())
}

class AXIB extends Bundle {
  val resp = Output(UInt(2.W))
  val id = Output(UInt(4.W))
  val user = Output(UInt(1.W))
}

class AXIR extends Bundle {
  val resp = Output(UInt(2.W))
  val data = Output(UInt(64.W))
  val last = Output(Bool())
  val id = Output(UInt(4.W))
  val user = Output(UInt(1.W))
}

class AXIIO extends Bundle {
  val aw = Decoupled(new AXIA)
  val w = Decoupled(new AxiW)
  val b = Flipped(Decoupled(new AXIB))
  val ar = Decoupled(new AXIA)
  val r = Flipped(Decoupled(new AXIR))
}

class AXIIO_Soc extends Bundle {
  val awready = Input(Bool())
  val awvalid = Output(Bool())
  val awaddr = Output(UInt(32.W))
  val awid = Output(UInt(4.W))
  val awlen = Output(UInt(8.W))
  val awsize = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))

  val wready = Input(Bool())
  val wvalid = Output(Bool())
  val wdata = Output(UInt(64.W))
  val wstrb = Output(UInt(8.W))
  val wlast = Output(Bool())

  val bready = Output(Bool())
  val bvalid = Input(Bool())
  val bresp = Input(UInt(2.W))
  val bid = Input(UInt(4.W))

  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr = Output(UInt(32.W))
  val arid = Output(UInt(4.W))
  val arlen = Output(UInt(8.W))
  val arsize = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))

  val rready = Output(Bool())
  val rvalid = Input(Bool())
  val rresp = Input(UInt(2.W))
  val rdata = Input(UInt(64.W))
  val rlast = Input(Bool())
  val rid = Input(UInt(4.W))
}