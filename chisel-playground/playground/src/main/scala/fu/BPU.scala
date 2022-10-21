import chisel3._
import chisel3.util._
import Define._

class BTB_Entry extends Bundle {
  val tag = UInt(BTB_TAG_WIDTH.W)
  val offset = UInt(BTB_OFFSET_WIDTH.W)
  val btb_type = UInt(BTB_TYPE_WIDTH.W)
  val target = UInt(32.W)
}

class BTB extends Module {
  val io = IO(new Bundle {
    val wen = Input(Bool())
    val index_r = Input(UInt(BTB_INDEX_WIDTH.W))
    val index_w = Input(UInt(BTB_INDEX_WIDTH.W))
    val in = Input(new BTB_Entry)
    val out = Output(new BTB_Entry)
    val valid_r = Output(Bool())
    val fence = Input(Bool())
  })

  val in = io.in
  val out = io.out
  val index_w = io.index_w
  val index_r = io.index_r

  // As using sram is not allowed, I use regfile here
  // and maybe I shoule use fully associative to fit regfile
  // but I do not want to fix any more
  // So it is a really stupid way

  val btb_entry = RegInit(VecInit(Seq.fill(BTB_ENTRY)(0.U.asTypeOf(new BTB_Entry))))
  val valid = RegInit(VecInit(Seq.fill(BTB_ENTRY)(false.B)))

  when (io.wen) {
    btb_entry(index_w).tag := in.tag
    btb_entry(index_w).offset := in.offset
    btb_entry(index_w).target := in.target
    btb_entry(index_w).btb_type := in.btb_type
    valid(index_w) := true.B
  }

  out.tag := RegNext(btb_entry(index_r).tag, init = false.B)
  out.offset := RegNext(btb_entry(index_r).offset, init = false.B)
  out.target := RegNext(btb_entry(index_r).target, init = false.B)
  out.btb_type := RegNext(btb_entry(index_r).btb_type, init = false.B)
  io.valid_r := RegNext(valid(index_r), init = false.B)

  when (reset.asBool || io.fence) {
    for (i <- 0 until BTB_ENTRY) {
      valid(i) := false.B
    }
  }
}

class PHT extends Module {
  val io = IO(new Bundle {
    val inc = Input(Bool())
    val dec = Input(Bool())
    val index_w = Input(UInt(PHT_INDEX_WIDTH.W))
    val index_r = Input(UInt(PHT_INDEX_WIDTH.W))
    val fence = Input(Bool())
    val br_taken = Output(Bool())
  })

  val index_w = io.index_w
  val index_r = io.index_r
  val pht_entry = RegInit(VecInit(Seq.fill(PHT_ENTRY)(0.U(2.W))))

  when (reset.asBool || io.fence) {
    for (i <- 0 until PHT_ENTRY) {
      pht_entry(i) := "b10".U
    }
  }

  when (io.inc) {
    pht_entry(index_w) := Mux(pht_entry(index_w) === "b11".U, "b11".U, pht_entry(index_w) + 1.U)
  } .elsewhen (io.dec) {
    pht_entry(index_w) := Mux(pht_entry(index_w) === "b00".U, "b00".U, pht_entry(index_w) - 1.U)
  }

  io.br_taken := pht_entry(index_r)(1)
}

class RAS extends Module with Config{
  val io = IO(new Bundle {
    val call = Input(Bool())
    val ret = Input(Bool())
    val call_count = Input(UInt(log2Up(RAS_ENTRY).W))
    val ret_count = Input(UInt(log2Up(RAS_ENTRY).W))
    val addr_w = Input(UInt(32.W))
    val addr_r = Output(UInt(32.W))
    val reflush = Input(Bool())
    val fence = Input(Bool())
  })

  val ras_entry = RegInit(VecInit(Seq.fill(RAS_ENTRY)(RESET_VECTOR.U(32.W))))
  val wrong_call = WireInit(false.B)
  val wrong_ret = WireInit(false.B)
  val wrong_count = WireInit(0.U(log2Up(RAS_ENTRY).W))

  wrong_call := io.call_count > io.ret_count
  wrong_ret := io.ret_count > io.call_count

  wrong_count := Mux(wrong_call, io.call_count - io.ret_count, io.ret_count - io.call_count)

  val ras_counter = RegInit(0.U(log2Up(RAS_ENTRY).W))
  val call_prev_reg = RegInit(0.U(log2Up(RAS_ENTRY).W))
  val ras_counter_prev = WireInit(0.U(log2Up(RAS_ENTRY).W))
  val ras_counter_next = WireInit(0.U(log2Up(RAS_ENTRY).W))
  val ras_counter_prev2 = WireInit(0.U(log2Up(RAS_ENTRY).W))
  val ras_counter_next2 = WireInit(0.U(log2Up(RAS_ENTRY).W))

  ras_counter_prev := ras_counter - 1.U
  ras_counter_next := ras_counter + 1.U
  ras_counter_prev2 := ras_counter - 2.U
  ras_counter_next2 := ras_counter + 2.U

  when (reset.asBool || io.fence) {
    for (i <- 0 until RAS_ENTRY) {
      ras_entry(i) := "h80000000".U
    }
    ras_counter := 0.U
    call_prev_reg := 0.U
  }

  when (io.call) {
    ras_counter := ras_counter_next
    call_prev_reg := ras_entry(ras_counter)
    ras_entry(ras_counter) := io.addr_w
  } .elsewhen (io.ret) {
    ras_counter := ras_counter_prev
  }

  when (io.reflush && wrong_call) {
    ras_counter := ras_counter - wrong_count
  } .elsewhen (io.reflush) {
    ras_counter := ras_counter + wrong_count
  }

  io.addr_r := ras_entry(ras_counter_prev)

}

class BPU extends Module {
  val io = IO(new Bundle {
    val ifu = Flipped(new IF_BPU_Bus)
    val exu = Flipped(new EX_BPU_Bus)
  })

  val ifu = io.ifu
  val exu = io.exu

  def get_btb_index(pc: UInt) = pc(BPU_OFFSET_WIDTH + BTB_INDEX_WIDTH - 1, BPU_OFFSET_WIDTH)
  def get_btb_tag(pc: UInt) = pc(31, BPU_OFFSET_WIDTH + BTB_INDEX_WIDTH)
  def get_btb_offset(pc: UInt) = pc(2 + BTB_OFFSET_WIDTH - 1, 2)
  def get_btb_uncache(pc: UInt) = !pc(31)
  def get_pht_index(pc: UInt) = pc(BPU_OFFSET_WIDTH + PHT_INDEX_WIDTH - 1, BPU_OFFSET_WIDTH)

  val ifu_pc_reg = RegInit(0.U(32.W))
  val exu_pc_reg = RegInit(0.U(32.W))
  val exu_bp_taken_reg = RegInit(false.B)
  val exu_bp_target_reg = RegInit(0.U(32.W))
  val exu_bp_type_reg = RegInit(0.U(BTB_TYPE_WIDTH.W))
  val exu_bp_wrong_reg = RegInit(false.B)
  val exu_bp_wrong_type_reg = RegInit(0.U(BTB_TYPE_WIDTH.W))

  when (ifu.valid) {
    ifu_pc_reg := ifu.pc
  }

  when (exu.valid) {
    exu_pc_reg := exu.pc
    exu_bp_taken_reg := exu.bp_taken
    exu_bp_target_reg := exu.bp_target
    exu_bp_type_reg := exu.bp_type
    exu_bp_wrong_reg := exu.bp_wrong
    exu_bp_wrong_type_reg := exu.bp_wrong_type
  }

  val btb = for (i <- 0 until 4) yield {
    val btb = Module(new BTB)
    btb
  }

  btb.map { case b => {
    b.io.wen := false.B
    b.io.index_r := 0.U
    b.io.index_w := 0.U
    b.io.in := 0.U.asTypeOf(new BTB_Entry)
    b.io.fence := exu.fence
  }}

  val pht = Module(new PHT)
  pht.io.inc := false.B
  pht.io.dec := false.B
  pht.io.index_w := 0.U
  pht.io.index_r := 0.U
  pht.io.fence := exu.fence

  val ras = Module(new RAS)
  ras.io.call := false.B
  ras.io.ret := false.B
  ras.io.addr_w := 0.U
  ras.io.fence := exu.fence
  ras.io.reflush := ifu.is_reflush
  ras.io.call_count := ifu.call_count - exu.call_count
  ras.io.ret_count := ifu.ret_count - exu.ret_count

  val ifu_hit = WireInit(VecInit(Seq.fill(4)(false.B)))
  val exu_hit = WireInit(VecInit(Seq.fill(4)(false.B)))
  val ifu_btb_hit = Wire(Bool())
  val exu_btb_hit = Wire(Bool())

  val plru0 = RegInit(VecInit(Seq.fill(BTB_ENTRY)(0.U)))
  val plru1 = RegInit(VecInit(Seq.fill(BTB_ENTRY)(0.U)))
  val plru2 = RegInit(VecInit(Seq.fill(BTB_ENTRY)(0.U)))
  val replace_way = Wire(UInt(2.W))

  val tag = WireInit(VecInit(Seq.fill(4)(0.U(BTB_TAG_WIDTH.W))))
  val offset = WireInit(VecInit(Seq.fill(4)(0.U(BTB_OFFSET_WIDTH.W))))
  val btb_type = WireInit(VecInit(Seq.fill(4)(0.U(BTB_TYPE_WIDTH.W))))
  val target = WireInit(VecInit(Seq.fill(4)(0.U(32.W))))
  val valid = WireInit(VecInit(Seq.fill(4)(false.B)))

  val offset_real = WireInit(0.U((BTB_OFFSET_WIDTH + 2).W))
  val bp_taken = WireInit(false.B)
  val bp_static_target = WireInit(0.U(32.W))

  val ifu_idle :: ifu_search :: ifu_conflict :: Nil = Enum(3)
  val exu_idle :: exu_write_btb :: exu_check :: Nil = Enum(3)

  val ifu_state = RegInit(ifu_idle)
  val exu_state = RegInit(exu_idle)

  (ifu_hit zip (tag zip valid)).map { case (h, (t, v)) => {
    h := (t === get_btb_tag(ifu_pc_reg)) && v
  }}
  ifu_btb_hit := Cat(ifu_hit).orR

  (exu_hit zip (tag zip valid)).map { case (h, (t, v)) => {
    h := (t === get_btb_tag(exu_pc_reg)) && v
  }}
  exu_btb_hit := Cat(exu_hit).orR

  when ((exu_state === exu_write_btb) && exu_btb_hit) {
    plru0(get_btb_index(exu_pc_reg)) := exu_hit(0) || exu_hit(1)
    when (exu_hit(0)) {
      plru1(get_btb_index(exu_pc_reg)) := 1.U
    } .elsewhen (exu_hit(1)) {
      plru1(get_btb_index(exu_pc_reg)) := 0.U
    } .elsewhen (exu_hit(2)) {
      plru2(get_btb_index(exu_pc_reg)) := 1.U
    } .elsewhen (exu_hit(3)) {
      plru2(get_btb_index(exu_pc_reg)) := 0.U
    }
  }

  when ((ifu_state === ifu_search) && ifu_btb_hit) {
    plru0(get_btb_index(ifu_pc_reg)) := ifu_hit(0) || ifu_hit(1)
    when (ifu_hit(0)) {
      plru1(get_btb_index(ifu_pc_reg)) := 1.U
    } .elsewhen (ifu_hit(1)) {
      plru1(get_btb_index(ifu_pc_reg)) := 0.U
    } .elsewhen (ifu_hit(2)) {
      plru2(get_btb_index(ifu_pc_reg)) := 1.U
    } .elsewhen (ifu_hit(3)) {
      plru2(get_btb_index(ifu_pc_reg)) := 0.U
    }
  }

  replace_way := Cat(plru0(get_btb_index(exu_pc_reg)),
    Mux(plru0(get_btb_index(exu_pc_reg)) === 0.U, plru1(get_btb_index(exu_pc_reg)), plru2(get_btb_index(exu_pc_reg))))

  (tag zip btb).map { case (t, b) => t := b.io.out.tag}
  (offset zip btb).map { case (o, b) => o := b.io.out.offset}
  (btb_type zip btb).map { case (t, b) => t := b.io.out.btb_type}
  (target zip btb).map { case (t, b) => t := b.io.out.target}
  (valid zip btb).map { case (v, b) => v := b.io.valid_r}

  switch (exu_state) {
    is (exu_idle) {
      when (exu.valid && exu.bp_wrong) {
        exu_state := exu_write_btb
        for (i <- 0 until 4) {
          btb(i).io.index_r := get_btb_index(exu.pc)
        }
      } .elsewhen (exu.valid) {
        exu_state := exu_check
      }
    }
    is (exu_write_btb) {
      when (exu_btb_hit) {
        when (exu_bp_type_reg === BTB_BRANCH) {
          pht.io.index_w := get_pht_index(exu_pc_reg)
          pht.io.inc := exu_bp_taken_reg
          pht.io.dec := !exu_bp_taken_reg
        }

        exu_state := exu_idle

      } .otherwise {
        for (i <- 0 until 4) {
          when (replace_way === i.U) {
            btb(i).io.wen := true.B
            btb(i).io.index_w := get_btb_index(exu_pc_reg)
            btb(i).io.in.tag := get_btb_tag(exu_pc_reg)
            btb(i).io.in.offset := get_btb_offset(exu_pc_reg)
            btb(i).io.in.btb_type := exu_bp_type_reg
            btb(i).io.in.target := exu_bp_target_reg
          }
        }
        when (exu_bp_type_reg === BTB_BRANCH) {
          pht.io.index_w := get_pht_index(exu_pc_reg)
          pht.io.inc := exu_bp_taken_reg
          pht.io.dec := !exu_bp_taken_reg
        }

        exu_state := exu_idle

      }

      when (exu_bp_type_reg === BTB_CALL) {
        ras.io.call := true.B
        ras.io.addr_w := exu_pc_reg + 4.U
      } .elsewhen (exu_bp_type_reg === BTB_RET) {
        ras.io.ret := true.B
      }

    }
    is (exu_check) {
      when (exu_bp_type_reg === BTB_BRANCH) {
        pht.io.index_w := get_pht_index(exu_pc_reg)
        pht.io.inc := exu_bp_taken_reg
        pht.io.dec := !exu_bp_taken_reg
      }

      when (exu.valid && exu.bp_wrong) {
        exu_state := exu_write_btb
        for (i <- 0 until 4) {
          btb(i).io.index_r := get_btb_index(exu.pc)
        }
      } .elsewhen (exu.valid) {
        exu_state := exu_check
      } .otherwise {
        exu_state := exu_idle
      }
    }
  }

  io.ifu.bp_taken := false.B
  bp_static_target := Mux(get_btb_uncache(ifu_pc_reg), ifu_pc_reg + 4.U, Cat(ifu_pc_reg(31, 4), Fill(4, 0.U)) + 16.U)
  io.ifu.bp_target := bp_static_target
  io.ifu.bp_offset := 0.U
  io.ifu.bp_ok := false.B
  io.ifu.bp_type := BTB_JUMP

  switch (ifu_state) {
    is (ifu_idle) {
      when (ifu.valid && !ifu.is_reflush) {
        ifu_state := ifu_search
        for (i <- 0 until 4) {
          btb(i).io.index_r := get_btb_index(ifu.pc)
        }
      } .elsewhen (ifu.valid) {
        ifu_state := ifu_conflict
      }
    }
    is (ifu_search) {
      io.ifu.bp_ok := true.B

      when (ifu_btb_hit && !ifu.is_reflush) {
        for (i <- 0 until 4) {
          when (ifu_hit(i)) {
            io.ifu.bp_type := btb_type(i)
            io.ifu.bp_offset := offset(i)
            offset_real := (offset(i) << 2.U).asUInt
            bp_taken := Mux(Mux(get_btb_uncache(ifu_pc_reg),
              get_btb_offset(ifu_pc_reg) === offset(i),
              get_btb_offset(ifu_pc_reg) <= offset(i)), true.B, false.B)

            when (btb_type(i) === BTB_CALL) {
              io.ifu.bp_taken := bp_taken
              io.ifu.bp_target := Mux(io.ifu.bp_taken, target(i), bp_static_target)
              ras.io.call := bp_taken
              ras.io.addr_w := (Cat(ifu_pc_reg(31, 4), Fill(4, 0.U)) + offset_real) + 4.U
            } .elsewhen (btb_type(i) === BTB_RET) {
              io.ifu.bp_taken := bp_taken
              ras.io.ret := bp_taken
              io.ifu.bp_target := Mux(io.ifu.bp_taken, ras.io.addr_r, bp_static_target)
            } .elsewhen (btb_type(i) === BTB_BRANCH) {
              pht.io.index_r := get_pht_index(ifu_pc_reg)
              io.ifu.bp_taken := Mux(bp_taken, pht.io.br_taken, false.B)
              io.ifu.bp_target := Mux(io.ifu.bp_taken, target(i), bp_static_target)
            } .elsewhen (btb_type(i) === BTB_JUMP) {
              io.ifu.bp_taken := bp_taken
              io.ifu.bp_target := Mux(io.ifu.bp_taken, target(i), bp_static_target)
            }
          }
        }
      } .otherwise {
        io.ifu.bp_taken := false.B
        io.ifu.bp_target := bp_static_target
      }

      when (ifu.valid && !ifu.is_reflush) {
        ifu_state := ifu_search
        for (i <- 0 until 4) {
          btb(i).io.index_r := get_btb_index(ifu.pc)
        }
      } .elsewhen (ifu.valid) {
        ifu_state := ifu_conflict
      } .otherwise {
        ifu_state := ifu_idle
      }
    }
    is (ifu_conflict) {
      io.ifu.bp_ok := true.B

      when (ifu.valid && !ifu.is_reflush) {
        ifu_state := ifu_search
        for (i <- 0 until 4) {
          btb(i).io.index_r := get_btb_index(ifu.pc)
        }
      } .elsewhen (ifu.valid) {
        ifu_state := ifu_conflict
      } .otherwise {
        ifu_state := ifu_idle
      }
    }
  }
}




