import chisel3._
import chisel3.util._
import difftest._

class MySimTop extends Module {
  val io = IO(new Bundle {
    val axi = new AXIIO_Soc
  })

  val soctop = Module(new SocTop)
  io.axi <> soctop.io.master

  val sram_from_soctop = Wire(Vec(8, new SRAMIO_Soc))
  sram_from_soctop(0) <> soctop.io.sram0
  sram_from_soctop(1) <> soctop.io.sram1
  sram_from_soctop(2) <> soctop.io.sram2
  sram_from_soctop(3) <> soctop.io.sram3
  sram_from_soctop(4) <> soctop.io.sram4
  sram_from_soctop(5) <> soctop.io.sram5
  sram_from_soctop(6) <> soctop.io.sram6
  sram_from_soctop(7) <> soctop.io.sram7

  val sram = for (i <- 0 until 8) yield {
    val sram = Module(new SRAM)
    sram
  }

  for (i <- 0 until 8) yield {
    sram(i).io.addr := sram_from_soctop(i).addr
    sram(i).io.en := !sram_from_soctop(i).cen
    sram(i).io.wen := !sram_from_soctop(i).wen
    sram(i).io.wdata := sram_from_soctop(i).wdata

    sram_from_soctop(i).rdata := sram(i).io.rdata
  }


}