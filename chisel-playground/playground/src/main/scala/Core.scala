import chisel3._
import chisel3.util.experimental.{BoringUtils, _}
import Instructions._

class Core_Soc extends Module with Config {
  val io = IO(new Bundle {
    val icache_bridge = new Cache_Bridge_IO
    val dcache_bridge = new Cache_Bridge_IO
    val sram = Vec(8, new SRAMIO_Cache)
  })

  val ifu = Module(new IFU)
  val iqueue = Module(new IQueue)
  val idu = Module(new IDU)
  val issue = Module(new Issue)
  val exu = Module(new EXU)
  val wbu = Module(new WBU)
  val bpu = Module(new BPU)
  val icache = Module(new Cache_Soc)
  val dcache = Module(new Cache_Soc)
  io.sram <> icache.sram ++ dcache.sram

  val frontend_reflush = WireInit(false.B)
  BoringUtils.addSink(frontend_reflush, "frontend_reflush")

  icache.io.out <> io.icache_bridge
  ifu.io.imem <> icache.io.in
  ifu.io.reflush_bus <> exu.io.reflush_bus
  ifu.io.bpu <> bpu.io.ifu

  Connect(ifu.io.out, iqueue.io.in, iqueue.io.out.fire, frontend_reflush)
  Connect(iqueue.io.out, idu.io.in, idu.io.out.fire, frontend_reflush)
  Connect(idu.io.out, issue.io.in, issue.io.out.fire, frontend_reflush)
  issue.io.wb_bus <> wbu.io.wb_bus
  issue.io.ex_fwd <> exu.io.forward

  Connect(issue.io.out, exu.io.in, exu.io.out.fire, frontend_reflush)

  dcache.io.out <> io.dcache_bridge
  exu.io.dmem <> dcache.io.in
  exu.io.bpu <> bpu.io.exu
  Connect(exu.io.out, wbu.io.in, true.B, false.B)
}

class Core_Sim extends Module with Config {
  val io = IO(new Bundle {
    val icache_bridge = new Cache_Bridge_IO
    val dcache_bridge = new Cache_Bridge_IO
  })

  val ifu = Module(new IFU)
  val iqueue = Module(new IQueue)
  val idu = Module(new IDU)
  val issue = Module(new Issue)
  val exu = Module(new EXU)
  val wbu = Module(new WBU)
  val bpu = Module(new BPU)
  val icache = Module(new Cache_Sim)
  val dcache = Module(new Cache_Sim)

  val frontend_reflush = WireInit(false.B)
  BoringUtils.addSink(frontend_reflush, "frontend_reflush")

  icache.io.out <> io.icache_bridge
  ifu.io.imem <> icache.io.in
  ifu.io.reflush_bus <> exu.io.reflush_bus
  ifu.io.bpu <> bpu.io.ifu

  Connect(ifu.io.out, iqueue.io.in, iqueue.io.out.fire, frontend_reflush)
  Connect(iqueue.io.out, idu.io.in, idu.io.out.fire, frontend_reflush)
  Connect(idu.io.out, issue.io.in, issue.io.out.fire, frontend_reflush)
  issue.io.wb_bus <> wbu.io.wb_bus
  issue.io.ex_fwd <> exu.io.forward

  Connect(issue.io.out, exu.io.in, exu.io.out.fire, frontend_reflush)

  dcache.io.out <> io.dcache_bridge
  exu.io.dmem <> dcache.io.in
  exu.io.bpu <> bpu.io.exu
  Connect(exu.io.out, wbu.io.in, true.B, false.B)

  /* ----- Difftest ------------------------------ */
  if (Difftest) {
    import difftest._

    val cycle_cnt = RegInit(0.U(64.W))
    val instr_cnt = RegInit(0.U(64.W))
    cycle_cnt := cycle_cnt + 1.U

    when (RegNext(wbu.io.commit(0).valid) && RegNext(wbu.io.commit(1).valid)) {
      instr_cnt := instr_cnt + 2.U
    } .elsewhen (RegNext(wbu.io.commit(0).valid) || RegNext(wbu.io.commit(1).valid)) {
      instr_cnt := instr_cnt + 1.U
    }

    val rf_a0 = WireInit(0.U(64.W))
    BoringUtils.addSink(rf_a0, "rf_a0")

    for (i <- 0 until 2) {
      val dt_ic = Module(new DifftestInstrCommit)
      dt_ic.io.clock    := clock
      dt_ic.io.coreid   := 0.U
      dt_ic.io.index    := i.U
      dt_ic.io.valid    := RegNext(wbu.io.commit(i).valid)
      dt_ic.io.pc       := RegNext(wbu.io.commit(i).pc)
      dt_ic.io.instr    := RegNext(wbu.io.commit(i).inst)
      dt_ic.io.special  := 0.U
      dt_ic.io.skip     := RegNext(wbu.io.commit(i).inst === "h0000007b".U || wbu.io.commit(i).mcycle || wbu.io.commit(i).is_clint)
      dt_ic.io.isRVC    := false.B
      dt_ic.io.scFailed := false.B
      dt_ic.io.wen      := RegNext(wbu.io.commit(i).wen)
      dt_ic.io.wdata    := RegNext(wbu.io.commit(i).wdata)
      dt_ic.io.wdest    := RegNext(wbu.io.commit(i).waddr)

      // PUTCH
      when (dt_ic.io.valid && dt_ic.io.instr === PUTCH) {
        printf("%c", rf_a0(7, 0))
      }
    }

    val call_ret_count = WireInit(0.U(64.W))
    BoringUtils.addSink(call_ret_count, "call_ret_count")

    val first_trap = wbu.io.commit(0).inst === "h0000006b".U
    val second_trap = wbu.io.commit(1).inst === "h0000006b".U
    val dt_te = Module(new DifftestTrapEvent)
    dt_te.io.clock    := clock
    dt_te.io.coreid   := 0.U
    dt_te.io.valid    := first_trap || second_trap
    dt_te.io.code     := rf_a0(2, 0)
    dt_te.io.pc       := Mux(first_trap, wbu.io.commit(0).pc, wbu.io.commit(1).pc)
    dt_te.io.cycleCnt := cycle_cnt
    dt_te.io.instrCnt := instr_cnt

    val br_times = WireInit(0.U(64.W))
    val bp_wrong_times = WireInit(0.U(64.W))
    BoringUtils.addSink(br_times, "br_times")
    BoringUtils.addSink(bp_wrong_times, "bp_wrong_times")

    when (dt_te.io.valid) {
      printf("call_ret_count = %d\n", call_ret_count)
      printf("br_times = %d\n", br_times)
      printf("bp_wrong_times = %d\n", bp_wrong_times)
    }

    val br_times_1 = RegInit(0.U(64.W))
    val br_times_2 = RegInit(0.U(64.W))

    when (RegNext(wbu.io.commit(0).valid) &&
      (RegNext(wbu.io.commit(0).inst) === JAL ||
        RegNext(wbu.io.commit(0).inst) === JALR ||
        RegNext(wbu.io.commit(0).inst) === BEQ ||
        RegNext(wbu.io.commit(0).inst) === BNE ||
        RegNext(wbu.io.commit(0).inst) === BLT ||
        RegNext(wbu.io.commit(0).inst) === BGE ||
        RegNext(wbu.io.commit(0).inst) === BLTU ||
        RegNext(wbu.io.commit(0).inst) === BGEU)) {
      br_times_1 := br_times_1 + 1.U
    }

    when(RegNext(wbu.io.commit(1).valid) &&
      (RegNext(wbu.io.commit(1).inst) === JAL ||
        RegNext(wbu.io.commit(1).inst) === JALR ||
        RegNext(wbu.io.commit(1).inst) === BEQ ||
        RegNext(wbu.io.commit(1).inst) === BNE ||
        RegNext(wbu.io.commit(1).inst) === BLT ||
        RegNext(wbu.io.commit(1).inst) === BGE ||
        RegNext(wbu.io.commit(1).inst) === BLTU ||
        RegNext(wbu.io.commit(1).inst) === BGEU)) {
      br_times_2 := br_times_2 + 1.U
    }

    val real_br_times = WireInit(0.U(64.W))
    real_br_times := br_times_1 + br_times_2
    when(dt_te.io.valid) {
      printf("real_br_times = %d\n", real_br_times)
    }
  }
}