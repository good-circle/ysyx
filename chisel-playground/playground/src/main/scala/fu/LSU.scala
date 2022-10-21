import chisel3._
import chisel3.util._
import Define._
import chisel3.util.experimental.BoringUtils

class LSU extends Module{
  val io = IO(new Bundle() {
    val dmem = new Cpu_Cache_IO
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val wdata = Input(UInt(64.W))
    val addr = Output(UInt(32.W))
    val is_lsu = Input(Bool())
    val wen = Input(Bool())
    val lsu_op = Input(UInt(LSUOP_WIDTH.W))
    val rdata = Output(UInt(64.W))
    val is_mdu = Input(Bool())
    val mdu_ok = Input(Bool())
  })

  val is_lsu = io.is_lsu
  val lsu_op = io.lsu_op
  val is_mdu = io.is_mdu
  val mdu_ok = io.mdu_ok
  val wdata = io.wdata
  val wen = io.wen
  val addr_low = Wire(UInt(3.W))
  io.addr := (io.src1 + io.src2)(31, 0)
  addr_low := io.addr(2, 0)

  val dmem_wdata = Wire(UInt(64.W))
  val dmem_wmask = Wire(UInt(8.W))
  val dmem_rdata = Wire(UInt(64.W))

  val sb_wmask = Wire(UInt(8.W))
  val sh_wmask = Wire(UInt(8.W))
  val sw_wmask = Wire(UInt(8.W))
  val sd_wmask = Wire(UInt(8.W))
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
    0.U -> "b00000001".U,
    1.U -> "b00000010".U,
    2.U -> "b00000100".U,
    3.U -> "b00001000".U,
    4.U -> "b00010000".U,
    5.U -> "b00100000".U,
    6.U -> "b01000000".U,
    7.U -> "b10000000".U
  ))
  sh_wmask := MuxLookup(addr_low, 0.U, Array(
    0.U -> "b00000011".U,
    2.U -> "b00001100".U,
    4.U -> "b00110000".U,
    6.U -> "b11000000".U
  ))
  sw_wmask := MuxLookup(addr_low, 0.U, Array(
    0.U -> "b00001111".U,
    4.U -> "b11110000".U
  ))
  sd_wmask := "b11111111".U
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

  val fence = WireInit(false.B)
  BoringUtils.addSink(fence, "fence_i")

  val icache_fence_finish = WireInit(false.B)
  BoringUtils.addSink(icache_fence_finish, "icache_fence_finish")

  val dcache_fence_finish = Wire(Bool())
  dcache_fence_finish := io.dmem.fence_finish
  BoringUtils.addSource(dcache_fence_finish, "dcache_fence_finish")

  val idle :: wait_2 :: wait_mdu :: wait_lsu :: dcache_fence :: wait_ifence :: wait_dfence :: Nil = Enum(7)
  val state = RegInit(idle)

  io.dmem.valid := false.B
  io.dmem.fence := false.B

  switch (state) {
    is (idle) {
      when (fence) {
        state := dcache_fence
        io.dmem.valid := false.B
      } .elsewhen (is_lsu && is_mdu) {
        state := wait_2
        io.dmem.valid := true.B
      } .elsewhen (is_lsu) {
        state := wait_lsu
        io.dmem.valid := true.B
      }.otherwise {
        state := idle
        io.dmem.valid := false.B
      }
    }
    is (wait_2) {
      io.dmem.valid := true.B
      when (io.dmem.data_ok && mdu_ok) {
        state := idle
        io.dmem.valid := false.B
      } .elsewhen (mdu_ok) {
        state := wait_lsu
        io.dmem.valid := true.B
      } .elsewhen (io.dmem.data_ok) {
        state := wait_mdu
        io.dmem.valid := false.B
      }
    }
    is (wait_lsu) {
      io.dmem.valid := true.B
      when (io.dmem.data_ok) {
        state := idle
        io.dmem.valid := false.B
      }
    }
    is (wait_mdu) {
      io.dmem.valid := false.B
      when (mdu_ok) {
        state := idle
      }
    }
    is (dcache_fence) {
      io.dmem.fence := true.B
      when (dcache_fence_finish && icache_fence_finish) {
        io.dmem.fence := false.B
        state := idle
      } .elsewhen (dcache_fence_finish) {
        io.dmem.fence := false.B
        state := wait_ifence
      } .elsewhen (icache_fence_finish) {
        state := wait_dfence
      }
    }
    is (wait_ifence) {
      when (icache_fence_finish) {
        state := idle
      }
    }
    is (wait_dfence) {
      io.dmem.fence := false.B
      state := idle
    }
  }

  io.dmem.op := Mux(wen === y, READ, WRITE)
  io.dmem.addr := io.addr
  io.dmem.wstrb := dmem_wmask
  io.dmem.wdata := dmem_wdata
  dmem_rdata := io.dmem.rdata

  io.rdata := load_rdata
}

