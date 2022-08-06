import chisel3._
import chisel3.util._
import Define._

class LSU extends Module{
  val io = IO(new Bundle() {
    val dmem = new RamIO
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val wdata = Input(UInt(64.W))
    val is_lsu = Input(Bool())
    val wen = Input(Bool())
    val lsu_op = Input(UInt(LSUOP_WIDTH.W))
    val rdata = Output(UInt(64.W))
  })

  val is_lsu = io.is_lsu
  val lsu_op = io.lsu_op
  val wdata = io.wdata
  val wen = io.wen
  val dmem_addr = Wire(UInt(64.W))
  val addr_low = Wire(UInt(3.W))
  dmem_addr := io.src1 + io.src2
  addr_low := dmem_addr(2, 0)

  val dmem_wdata = Wire(UInt(64.W))
  val dmem_wmask = Wire(UInt(64.W))
  val dmem_rdata = Wire(UInt(64.W))

  val sb_wmask = Wire(UInt(64.W))
  val sh_wmask = Wire(UInt(64.W))
  val sw_wmask = Wire(UInt(64.W))
  val sd_wmask = Wire(UInt(64.W))
  val sb_wdata = Wire(UInt(64.W))
  val sh_wdata = Wire(UInt(64.W))
  val sw_wdata = Wire(UInt(64.W))
  val sd_wdata = Wire(UInt(64.W))

  val lb_rdata = Wire(UInt(64.W))
  val lbu_rdata = Wire(UInt(64.W))
  val lh_rdata = Wire(UInt(64.W))
  val lhu_rdata = Wire(UInt(64.W))
  val lw_rdata = Wire(UInt(64.W))
  val lwu_rdata = Wire(UInt(64.W))
  val ld_rdata = Wire(UInt(64.W))
  val load_rdata = Wire(UInt(64.W))

  sb_wdata := Fill(8, wdata(7, 0))
  sh_wdata := Fill(4, wdata(15, 0))
  sw_wdata := Fill(2, wdata(31, 0))
  sd_wdata := wdata(63, 0)
  dmem_wdata := MuxLookup(lsu_op, 0.U, Array(
    lsu_sb -> sb_wdata,
    lsu_sh -> sh_wdata,
    lsu_sw -> sw_wdata,
    lsu_sd -> sd_wdata
  ))

  sb_wmask := MuxLookup(addr_low, 0.U, Array(
    0.U -> "h0000_0000_0000_00ff".U,
    1.U -> "h0000_0000_0000_ff00".U,
    2.U -> "h0000_0000_00ff_0000".U,
    3.U -> "h0000_0000_ff00_0000".U,
    4.U -> "h0000_00ff_0000_0000".U,
    5.U -> "h0000_ff00_0000_0000".U,
    6.U -> "h00ff_0000_0000_0000".U,
    7.U -> "hff00_0000_0000_0000".U
  ))
  sh_wmask := MuxLookup(addr_low, 0.U, Array(
    0.U -> "h0000_0000_0000_ffff".U,
    2.U -> "h0000_0000_ffff_0000".U,
    4.U -> "h0000_ffff_0000_0000".U,
    6.U -> "hffff_0000_0000_0000".U
  ))
  sw_wmask := MuxLookup(addr_low, 0.U, Array(
    0.U -> "h0000_0000_ffff_ffff".U,
    4.U -> "hffff_ffff_0000_0000".U
  ))
  sd_wmask := "hffff_ffff_ffff_ffff".U
  dmem_wmask := MuxLookup(lsu_op, 0.U, Array(
    lsu_sb -> sb_wmask,
    lsu_sh -> sh_wmask,
    lsu_sw -> sw_wmask,
    lsu_sd -> sd_wmask
  ))

  lb_rdata := MuxLookup(addr_low, 0.U, Array(
    0.U -> Cat(Fill(56, dmem_rdata(7)), dmem_rdata(7, 0)),
    1.U -> Cat(Fill(56, dmem_rdata(15)), dmem_rdata(15, 8)),
    2.U -> Cat(Fill(56, dmem_rdata(23)), dmem_rdata(23, 16)),
    3.U -> Cat(Fill(56, dmem_rdata(31)), dmem_rdata(31, 24)),
    4.U -> Cat(Fill(56, dmem_rdata(39)), dmem_rdata(39, 32)),
    5.U -> Cat(Fill(56, dmem_rdata(47)), dmem_rdata(47, 40)),
    6.U -> Cat(Fill(56, dmem_rdata(55)), dmem_rdata(55, 48)),
    7.U -> Cat(Fill(56, dmem_rdata(63)), dmem_rdata(63, 56))
  ))

  lbu_rdata := MuxLookup(addr_low, 0.U, Array(
    0.U -> Cat(Fill(56, 0.U), dmem_rdata(7, 0)),
    1.U -> Cat(Fill(56, 0.U), dmem_rdata(15, 8)),
    2.U -> Cat(Fill(56, 0.U), dmem_rdata(23, 16)),
    3.U -> Cat(Fill(56, 0.U), dmem_rdata(31, 24)),
    4.U -> Cat(Fill(56, 0.U), dmem_rdata(39, 32)),
    5.U -> Cat(Fill(56, 0.U), dmem_rdata(47, 40)),
    6.U -> Cat(Fill(56, 0.U), dmem_rdata(55, 48)),
    7.U -> Cat(Fill(56, 0.U), dmem_rdata(63, 56))
  ))
  lh_rdata := MuxLookup(addr_low, 0.U, Array(
    0.U -> Cat(Fill(48, dmem_rdata(15)), dmem_rdata(15, 0)),
    2.U -> Cat(Fill(48, dmem_rdata(31)), dmem_rdata(31, 16)),
    4.U -> Cat(Fill(48, dmem_rdata(47)), dmem_rdata(47, 32)),
    6.U -> Cat(Fill(48, dmem_rdata(63)), dmem_rdata(63, 48))
  ))
  lhu_rdata := MuxLookup(addr_low, 0.U, Array(
    0.U -> Cat(Fill(48, 0.U), dmem_rdata(15, 0)),
    2.U -> Cat(Fill(48, 0.U), dmem_rdata(31, 16)),
    4.U -> Cat(Fill(48, 0.U), dmem_rdata(47, 32)),
    6.U -> Cat(Fill(48, 0.U), dmem_rdata(63, 48))
  ))
  lw_rdata := MuxLookup(addr_low, 0.U, Array(
    0.U -> Cat(Fill(32, dmem_rdata(31)), dmem_rdata(31, 0)),
    4.U -> Cat(Fill(32, dmem_rdata(63)), dmem_rdata(63, 32)),
  ))
  lwu_rdata := MuxLookup(addr_low, 0.U, Array(
    0.U -> Cat(Fill(32, 0.U), dmem_rdata(31, 0)),
    4.U -> Cat(Fill(32, 0.U), dmem_rdata(63, 32)),
  ))
  ld_rdata := dmem_rdata
  load_rdata := MuxLookup(lsu_op, 0.U, Array(
    lsu_lb -> lb_rdata,
    lsu_lbu -> lbu_rdata,
    lsu_lh -> lh_rdata,
    lsu_lhu -> lhu_rdata,
    lsu_lw -> lw_rdata,
    lsu_lwu -> lwu_rdata,
    lsu_ld -> ld_rdata
  ))

  io.dmem.en := is_lsu
  io.dmem.addr := dmem_addr
  io.dmem.wen := is_lsu && (wen === n)
  io.dmem.wdata := dmem_wdata
  io.dmem.wmask := dmem_wmask
  dmem_rdata := io.dmem.rdata

  io.rdata := load_rdata
}
