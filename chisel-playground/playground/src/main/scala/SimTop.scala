import chisel3._
import chisel3.util._
import difftest._

class SimTop extends Module {
  val io = IO(new Bundle {
    val logCtrl = new LogCtrlIO
    val perfInfo = new PerfInfoIO
    val uart = new UARTIO
    val memAXI_0 = new AXIIO
  })

  val core = Module(new Core_Sim)

  val transfer_bridge = Module(new CacheBridge)
  transfer_bridge.io.icache <> core.io.icache_bridge
  transfer_bridge.io.dcache <> core.io.dcache_bridge
  transfer_bridge.io.out <> io.memAXI_0

  io.uart.out.valid := false.B
  io.uart.out.ch := 0.U
  io.uart.in.valid := false.B

}
