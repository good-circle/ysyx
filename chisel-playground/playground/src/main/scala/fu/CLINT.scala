import chisel3._
import chisel3.util._
import chisel3.util.experimental._
import Define._


class CLINT extends Module {
  val io = IO(new Bundle() {
    val is_mtime = Input(Bool())
    val is_mtimecmp = Input(Bool())
    val is_clint = Input(Bool())
    val wen = Input(Bool())
    val wdata = Input(UInt(64.W))
    val rdata = Output(UInt(64.W))
  })

  val mtime = RegInit(UInt(64.W), 0.U)
  val mtimecmp = RegInit(UInt(64.W), 0.U)
  val is_mtime = io.is_mtime
  val is_mtimecmp = io.is_mtimecmp
  val is_clint = io.is_clint
  val wen = io.wen
  val wdata = io.wdata

  val has_int = WireInit(Bool(), 0.B)
  val rdata = WireInit(UInt(64.W), 0.U)
  mtime := mtime + 1.U

  when (is_clint) {
    when (wen) {
      rdata := Mux(is_mtime, mtime, mtimecmp)
    }
    when (!wen) {
      when (is_mtime) {
        mtime := wdata
      }
      when (is_mtimecmp) {
        mtimecmp := wdata
      }
    }
  }

  BoringUtils.addSource(has_int, "clint_has_int")

  when ( mtime >= mtimecmp) {
    has_int := true.B
  }

  io.rdata := rdata
}
