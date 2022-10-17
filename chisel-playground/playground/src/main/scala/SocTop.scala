import chisel3._
import chisel3.util._

class SocTop extends Module {
  val io = IO(new Bundle {
    val interrupt = Input(Bool())
    val master = new AXIIO_Soc
    val slave  = Flipped(new AXIIO_Soc)
    val sram0 = new SRAMIO_Soc
    val sram1 = new SRAMIO_Soc
    val sram2 = new SRAMIO_Soc
    val sram3 = new SRAMIO_Soc
    val sram4 = new SRAMIO_Soc
    val sram5 = new SRAMIO_Soc
    val sram6 = new SRAMIO_Soc
    val sram7 = new SRAMIO_Soc
  })

  val core = Module(new Core_Soc)
  val sram_bridge = Module(new SramBridge)
  sram_bridge.io.sram_cache <> core.io.sram
  sram_bridge.io.sram_share(0) <> io.sram0
  sram_bridge.io.sram_share(1) <> io.sram1
  sram_bridge.io.sram_share(2) <> io.sram2
  sram_bridge.io.sram_share(3) <> io.sram3
  sram_bridge.io.sram_share(4) <> io.sram4
  sram_bridge.io.sram_share(5) <> io.sram5
  sram_bridge.io.sram_share(6) <> io.sram6
  sram_bridge.io.sram_share(7) <> io.sram7

  val transfer_bridge = Module(new SocBridge)
  transfer_bridge.io.icache <> core.io.icache_bridge
  transfer_bridge.io.dcache <> core.io.dcache_bridge
  transfer_bridge.io.out <> io.master

  io.slave.awready := 0.U
  io.slave.wready  := 0.U
  io.slave.bvalid  := 0.U
  io.slave.bresp   := 0.U
  io.slave.bid     := 0.U
  io.slave.arready := 0.U
  io.slave.rvalid  := 0.U
  io.slave.rresp   := 0.U
  io.slave.rdata   := 0.U
  io.slave.rlast   := 0.U
  io.slave.rid     := 0.U
}
