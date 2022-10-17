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

  soctop.io.slave.awvalid := 0.U
  soctop.io.slave.awaddr := 0.U
  soctop.io.slave.awid := 0.U
  soctop.io.slave.awlen := 0.U
  soctop.io.slave.awsize := 0.U
  soctop.io.slave.awburst := 0.U
  soctop.io.slave.wvalid := 0.U
  soctop.io.slave.wdata := 0.U
  soctop.io.slave.wstrb := 0.U
  soctop.io.slave.wlast := 0.U
  soctop.io.slave.bready := 0.U
  soctop.io.slave.arvalid := 0.U
  soctop.io.slave.araddr := 0.U
  soctop.io.slave.arid := 0.U
  soctop.io.slave.arlen := 0.U
  soctop.io.slave.arsize := 0.U
  soctop.io.slave.arburst := 0.U
  soctop.io.slave.rready := 0.U

}