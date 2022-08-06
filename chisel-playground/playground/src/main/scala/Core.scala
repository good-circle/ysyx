import chisel3._
import chisel3.util.experimental._
import Instructions._
import difftest._

class Core extends Module {
  val io = IO(new Bundle {
    val imem = new RomIO
    val dmem = new RamIO
  })

  val ifu = Module(new IFU)
  val idu = Module(new IDU)
  val exu = Module(new EXU)
  val wbu = Module(new WBU)

  ifu.io.imem <> io.imem
  ifu.io.br_bus <> idu.io.br_bus
  ifu.io.csr_br_bus <> exu.io.br_bus

  Connect(ifu.io.out, idu.io.in, idu.io.out.fire, ifu.io.csr_br_bus.is_reflush)
  idu.io.wb_bus <> wbu.io.wb_bus
  idu.io.ex_fwd <> exu.io.forward

  Connect(idu.io.out, exu.io.in, exu.io.out.fire, idu.io.ex_fwd.is_reflush)

  exu.io.dmem <> io.dmem
  Connect(exu.io.out, wbu.io.in, true.B, false.B)

  /* ----- Difftest ------------------------------ */

  val dt_ic = Module(new DifftestInstrCommit)
  dt_ic.io.clock    := clock
  dt_ic.io.coreid   := 0.U
  dt_ic.io.index    := 0.U
  dt_ic.io.valid    := RegNext(wbu.io.commit.valid)
  dt_ic.io.pc       := RegNext(wbu.io.commit.pc)
  dt_ic.io.instr    := RegNext(wbu.io.commit.inst)
  dt_ic.io.special  := 0.U
  dt_ic.io.skip     := RegNext(wbu.io.commit.inst === "h0000007b".U || wbu.io.commit.mcycle || wbu.io.commit.is_clint) 
  dt_ic.io.isRVC    := false.B
  dt_ic.io.scFailed := false.B
  dt_ic.io.wen      := RegNext(wbu.io.commit.wen)
  dt_ic.io.wdata    := RegNext(wbu.io.commit.wdata)
  dt_ic.io.wdest    := RegNext(wbu.io.commit.waddr)

  val cycle_cnt = RegInit(0.U(64.W))
  val instr_cnt = RegInit(0.U(64.W))

  cycle_cnt := cycle_cnt + 1.U
  instr_cnt := instr_cnt + 1.U

  val rf_a0 = WireInit(0.U(64.W))
  BoringUtils.addSink(rf_a0, "rf_a0")

  val dt_te = Module(new DifftestTrapEvent)
  dt_te.io.clock    := clock
  dt_te.io.coreid   := 0.U
  dt_te.io.valid    := (wbu.io.commit.inst === "h0000006b".U)
  dt_te.io.code     := rf_a0(2, 0)
  dt_te.io.pc       := wbu.io.commit.pc
  dt_te.io.cycleCnt := cycle_cnt
  dt_te.io.instrCnt := instr_cnt

  // PUTCH
  when (dt_ic.io.valid && dt_ic.io.instr === PUTCH) {
    printf("%c", rf_a0(7, 0))
  }
}
