import chisel3._
import chisel3.util._
import Define._
import chisel3.util.experimental.BoringUtils

class EXU extends Module with Config {
  val io = IO(new Bundle {
    val dmem = new Cpu_Cache_IO
    val in = Flipped(Decoupled(Vec(2, new Issue_IO)))
    val out = Decoupled(Vec(2, new EX_IO))
    val forward = Vec(2, new Forward_Bus)
    val reflush_bus = new Reflush_Bus
    val bpu = new EX_BPU_Bus
  })

  val in = io.in
  val out = io.out

  val alu = for (i <- 0 until 2) yield {
    val alu = Module(new ALU)
    alu
  }
  val mdu = Module(new MDU)
  val bru = Module(new BRU)
  val lsu = Module(new LSU)
  val csr = Module(new CSR)
  val clint = Module(new CLINT)

  val alu_result = WireInit(VecInit(Seq.fill(2)(0.U(64.W))))
  val mdu_result = WireInit(0.U(64.W))
  val mdu_ok = WireInit(false.B)
  val is_lsu = Wire(Bool())
  val is_mdu = Wire(Bool())
  val lsu_addr = Wire(UInt(32.W))
  val lsu_rdata = Wire(UInt(64.W))
  val csr_rdata = Wire(UInt(64.W))
  val is_clint = Wire(Bool())
  val final_result = WireInit(VecInit(Seq.fill(2)(0.U(64.W))))

  val br_taken = Wire(Bool())
  val br_target = Wire(UInt(32.W))
  val br_type = Wire(UInt(BTB_TYPE_WIDTH.W))
  val csr_is_reflush = Wire(Bool())
  val csr_target = Wire(UInt(32.W))
  val handle_int = Wire(Bool())
  val fence = Wire(Bool())
  val bp_wrong = Wire(Bool())
  val frontend_reflush = Wire(Bool())

  val blk_idle :: blk_wait_mdu :: blk_wait_lsu :: blk_wait_2 :: Nil = Enum(4)
  val blk_state = RegInit(blk_idle)
  val blk_ready = WireInit(true.B)

  /* ALU */
  for (i <- 0 until 2) {
    alu_result(i) := alu(i).io.result
    alu(i).io.alu_op := in.bits(i).alu_op
    alu(i).io.rv64 := in.bits(i).rv64
    alu(i).io.src1 := in.bits(i).src1_value
    alu(i).io.src2 := in.bits(i).src2_value
  }

  /* MDU */
  is_mdu := false.B
  mdu.io.src1 := 0.U
  mdu.io.src2 := 0.U
  mdu.io.mdu_op := 0.U
  mdu.io.rv64 := false.B
  mdu_result := mdu.io.result
  mdu_ok := mdu.io.result_ok
  mdu.io.is_lsu := is_lsu && !is_clint
  mdu.io.lsu_ok := io.dmem.data_ok
  for (i <- 0 until 2) {
    when(in.bits(i).fu_type === fu_mdu && in.bits(i).valid) {
      is_mdu := io.in.valid
      mdu.io.src1 := in.bits(i).src1_value
      mdu.io.src2 := in.bits(i).src2_value
      mdu.io.mdu_op := in.bits(i).mdu_op & Fill(MDUOP_WIDTH, is_mdu)
      mdu.io.rv64 := in.bits(i).rv64
    }
  }

  /* BRU */
  br_taken := bru.io.br_taken
  br_target := bru.io.br_target
  br_type := bru.io.btb_type

  bru.io.bru_op := 0.U
  bru.io.src1 := 0.U
  bru.io.src2 := 0.U
  bru.io.pc := 0.U
  bru.io.imm := 0.U
  bru.io.rs1 := 0.U
  bru.io.rd := 0.U
  for (i <- 0 until 2) {
    when (in.bits(i).fu_type === fu_bru && in.bits(i).valid) {
      bru.io.bru_op := in.bits(i).bru_op
      bru.io.src1 := in.bits(i).src1_value
      bru.io.src2 := in.bits(i).src2_value
      bru.io.pc := in.bits(i).pc
      bru.io.imm := in.bits(i).imm
      bru.io.rs1 := in.bits(i).rs1
      bru.io.rd := in.bits(i).dest
    }
  }

  /* BPU */
  val call_count = RegInit(0.U(log2Up(RAS_ENTRY).W))
  val ret_count = RegInit(0.U(log2Up(RAS_ENTRY).W))

  when (frontend_reflush) {
    call_count := 0.U
    ret_count := 0.U
  } .elsewhen (io.bpu.valid && blk_state === blk_idle) {
    call_count := call_count + (br_type === BTB_CALL)
    ret_count := ret_count + (br_type === BTB_RET)
  }

  io.bpu := 0.U.asTypeOf(new EX_BPU_Bus)
  io.bpu.fence := fence
  bp_wrong := false.B
  for (i <- 0 until 2) {
    when (in.bits(i).fu_type === fu_bru && in.bits(i).valid) {
      io.bpu.valid := io.in.valid
      io.bpu.pc := in.bits(i).pc
      io.bpu.bp_taken := br_taken
      io.bpu.bp_target := br_target
      io.bpu.bp_type := br_type
      io.bpu.bp_wrong := bp_wrong
      io.bpu.bp_wrong_type := in.bits(i).bp_br_type
      io.bpu.call_count := call_count
      io.bpu.ret_count := ret_count
      bp_wrong := ((br_taken =/= in.bits(i).bp_br_taken) ||
        (br_taken && in.bits(i).bp_br_taken && ((br_target =/= in.bits(i).bp_br_target) || (br_type =/= in.bits(i).bp_br_type)))) &&
        io.in.valid
    }
  }

  /* LSU */
  is_lsu := false.B
  lsu.io.src1 := 0.U
  lsu.io.src2 := 0.U
  lsu.io.wdata := 0.U
  lsu.io.is_lsu := 0.U
  lsu.io.wen := 0.U
  lsu.io.lsu_op := 0.U
  lsu.io.is_mdu := false.B
  lsu.io.mdu_ok := false.B
  lsu.io.dmem <> io.dmem
  lsu_addr := lsu.io.addr
  lsu_rdata := Mux(is_clint, clint.io.rdata, lsu.io.rdata)
  for (i <- 0 until 2) {
    when (in.bits(i).fu_type === fu_lsu && in.bits(i).valid) {
      is_lsu := io.in.valid
      lsu.io.src1 := in.bits(i).src1_value
      lsu.io.src2 := in.bits(i).src2_value
      lsu.io.wdata := in.bits(i).rs2_value
      lsu.io.is_lsu := is_lsu && !is_clint
      lsu.io.wen := in.bits(i).wen
      lsu.io.lsu_op := in.bits(i).lsu_op
      lsu.io.is_mdu := is_mdu
      lsu.io.mdu_ok := mdu_ok
    }
  }

  /* CSR */
  csr.io.pc := 0.U
  csr.io.csr_op := 0.U
  csr.io.addr := 0.U
  csr.io.src := 0.U
  csr.io.valid := 0.U
  csr_rdata := csr.io.rdata
  csr_is_reflush := csr.io.is_reflush
  csr_target := csr.io.csr_target
  handle_int := csr.io.handle_int
  fence := (csr.io.csr_op === csr_fence)
  BoringUtils.addSource(fence, "fence_i")
  for (i <- 0 until 2) {
    when (in.bits(i).fu_type === fu_csr && in.bits(i).valid) {
      csr.io.pc := in.bits(i).pc
      csr.io.csr_op := in.bits(i).csr_op & Fill(CSROP_WIDTH, io.in.valid)
      csr.io.addr := in.bits(i).inst(31, 20)
      csr.io.src := in.bits(i).src1_value
      csr.io.valid := io.in.valid
    }
  }

  /* CLINT */
  clint.io.wen := 0.U
  clint.io.wdata := 0.U
  clint.io.is_mtime := (lsu_addr === "h0200bff8".U(64.W))
  clint.io.is_mtimecmp := (lsu_addr === "h02004000".U(64.W))
  clint.io.is_clint := is_lsu && is_clint
  is_clint := (clint.io.is_mtime || clint.io.is_mtimecmp) && io.in.valid
  for (i <- 0 until 2) {
    when (in.bits(i).fu_type === fu_lsu && in.bits(i).valid) {
      clint.io.wen := in.bits(i).wen
      clint.io.wdata := in.bits(i).rs2_value
    }
  }

  for (i <- 0 until 2) {
    final_result(i) := MuxLookup(in.bits(i).fu_type, 0.U, Array(
      fu_alu -> alu_result(i),
      fu_mdu -> mdu_result,
      fu_bru -> (in.bits(i).pc + 4.U),
      fu_lsu -> lsu_rdata,
      fu_csr -> csr_rdata
    ))
  }

  for (i <- 0 until 2) {
    io.out.bits(i).valid := in.bits(i).valid
    io.out.bits(i).pc := in.bits(i).pc
    io.out.bits(i).inst := in.bits(i).inst
    io.out.bits(i).final_result := final_result(i)
    io.out.bits(i).dest := in.bits(i).dest
    io.out.bits(i).wen := in.bits(i).wen
  }

  io.out.valid := io.in.valid && !handle_int && blk_ready
  io.in.ready := (io.out.ready && blk_ready) || !io.in.valid

  val frontend_reflush_reg = RegInit(false.B)
  when (((csr_is_reflush && !handle_int) || fence || bp_wrong) && io.in.valid && !io.out.valid) {
    frontend_reflush_reg := true.B
  } .elsewhen (io.out.valid) {
    frontend_reflush_reg := false.B
  }
  frontend_reflush := (((csr_is_reflush && !handle_int) || fence || bp_wrong) && io.in.valid && io.out.valid) ||
    frontend_reflush_reg && io.out.valid || handle_int

  switch (blk_state) {
    is (blk_idle) {
      blk_ready := true.B
      when ((is_lsu && !is_clint) && is_mdu) {
        blk_ready := false.B
        blk_state := blk_wait_2
      } .elsewhen (is_lsu && !is_clint) {
        blk_ready := false.B
        blk_state := blk_wait_lsu
      } .elsewhen (is_mdu) {
        blk_ready := false.B
        blk_state := blk_wait_mdu
      }
    }
    is (blk_wait_2) {
      blk_ready := false.B
      when (io.dmem.data_ok && mdu_ok) {
        blk_ready := true.B
        blk_state := blk_idle
      } .elsewhen (io.dmem.data_ok) {
        blk_state := blk_wait_mdu
      } .elsewhen (mdu_ok) {
        blk_state := blk_wait_lsu
      }
    }
    is (blk_wait_mdu) {
      blk_ready := false.B
      when (mdu_ok) {
        blk_ready := true.B
        blk_state := blk_idle
      }
    }
    is(blk_wait_lsu) {
      blk_ready := false.B
      when(io.dmem.data_ok) {
        blk_ready := true.B
        blk_state := blk_idle
      }
    }
  }
  for (i <- 0 until 2) {
    io.forward(i).blk_valid := io.forward(i).fwd_valid && !blk_ready
    io.forward(i).fwd_valid := in.bits(i).wen && in.bits(i).dest =/= 0.U && io.in.valid && in.bits(i).valid
    io.forward(i).rf_waddr := in.bits(i).dest
    io.forward(i).rf_wdata := final_result(i)
  }

  io.reflush_bus.is_reflush := frontend_reflush
  val static_next_pc = WireInit(0.U(32.W))
  for (i <- 0 until 2) {
    when ((in.bits(i).fu_type === fu_bru || fence) && in.bits(i).valid) {
      static_next_pc := in.bits(i).pc + 4.U
    }
  }

  io.reflush_bus.br_target := Mux(csr_is_reflush, csr_target,
    Mux(bp_wrong && br_taken, br_target, static_next_pc))

  BoringUtils.addSource(frontend_reflush, "frontend_reflush")

  for (i <- 0 until 2) {
    io.out.bits(i).mcycle := false.B
    io.out.bits(i).is_clint := false.B
    io.out.bits(i).is_mmio := false.B
  }

  if (MyEnv) {
    for (i <- 0 until 2) {
      io.out.bits(i).mcycle := (csr.io.addr === mcycle_addr) && (io.in.bits(i).fu_type === fu_csr)
      io.out.bits(i).is_clint := in.bits(i).fu_type === fu_lsu && in.bits(i).valid && is_clint
      io.out.bits(i).is_mmio := in.bits(i).fu_type === fu_lsu && in.bits(i).valid && lsu_addr(31) && lsu_addr(29)
    }
  }

  if (Difftest && !MyEnv) {
    for (i <- 0 until 2) {
      io.out.bits(i).mcycle := (csr.io.addr === mcycle_addr) && (io.in.bits(i).fu_type === fu_csr)
      io.out.bits(i).is_clint := in.bits(i).fu_type === fu_lsu && in.bits(i).valid && is_clint
      io.out.bits(i).is_mmio := in.bits(i).fu_type === fu_lsu && in.bits(i).valid && lsu_addr(31) && lsu_addr(29)
    }

    val call_ret_count = RegInit(0.U(64.W))
    when (br_type === BTB_CALL && io.bpu.valid && blk_state === blk_idle) {
      call_ret_count := call_ret_count + 1.U
    } .elsewhen (br_type === BTB_RET && io.bpu.valid && blk_state === blk_idle) {
      call_ret_count := call_ret_count - 1.U
    }
    BoringUtils.addSource(call_ret_count, "call_ret_count")

    val br_times = RegInit(0.U(64.W))
    val bp_wrong_times = RegInit(0.U(64.W))

    when (io.bpu.valid && blk_state === blk_idle) {
      br_times := br_times + 1.U
    }
    when (bp_wrong && blk_state === blk_idle) {
      bp_wrong_times := bp_wrong_times + 1.U
    }
    BoringUtils.addSource(br_times, "br_times")
    BoringUtils.addSource(bp_wrong_times, "bp_wrong_times")

  }
}

