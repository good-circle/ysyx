import chisel3._
import chisel3.util._
import Define._

class SramBridge extends Module {
  val io = IO(new Bundle() {
    val sram_cache = Vec(8, Flipped(new SRAMIO_Cache))
    val sram_share = Vec(8, new SRAMIO_Soc)
  })

  val sram_cache = io.sram_cache
  val sram_share = io.sram_share

  for (i <- 0 until 8) {
    sram_share(i).addr := sram_cache(i).addr
    sram_share(i).cen := !sram_cache(i).en
    sram_share(i).wen := !sram_cache(i).wen
    sram_share(i).wmask := Fill(SRAM_BITS, 0.U)
    sram_share(i).wdata := sram_cache(i).wdata

    sram_cache(i).rdata := sram_share(i).rdata
  }
}
