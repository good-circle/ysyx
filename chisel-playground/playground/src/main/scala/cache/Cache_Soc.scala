import chisel3._
import chisel3.util._
import Define._

class Cache_Soc extends Module with Config{
  val io = IO(new Bundle() {
    val in = Flipped(new Cpu_Cache_IO)
    val out = new Cache_Bridge_IO
    val sram = Vec(4, new SRAMIO_Cache)
  })

  val in = io.in
  val out = io.out
  val sram = io.sram

  sram.map { case s => {
    s.en := false.B
    s.wen := false.B
    s.addr := 0.U
    s.wdata := 0.U
  }}

  val meta = for (i <- 0 until 4) yield {
    val meta = Module(new META)
    meta
  }

  meta.map { case m => {
    m.io.index := 0.U
    m.io.tag_w := 0.U
    m.io.tag_wen := false.B
    m.io.dirty_w := false.B
    m.io.dirty_wen := false.B
    m.io.fence := false.B
  }}

  val idle :: lookup :: miss :: replace :: refill :: Nil = Enum(5)
  val wb_idle :: wb_write :: Nil = Enum(2)
  val fence_idle :: fence_start :: fence_check_dirty :: fence_wb_dirty :: fence_wait_ok :: fence_finish :: Nil = Enum(6)

  val state = RegInit(idle)
  val wb_state = RegInit(wb_idle)
  val fence_state = RegInit(fence_idle)

  val cache_hit = Wire(Bool())
  val conflict = Wire(Bool())
  val addr_ok = Wire(Bool())

  val in_uncache = !in.addr(31)
  if (MyEnv) in_uncache := !in.addr(31) || in.addr(31) && in.addr(29)
  val in_index = in.addr(9, 4)
  val in_tag = in.addr(31, 10)
  val in_offset = in.addr(3, 0)

  // request buffer
  val rb_op = RegInit(false.B)
  val rb_uncache = RegInit(false.B)
  val rb_index = RegInit(0.U(INDEX_WIDTH.W))
  val rb_tag = RegInit(0.U(TAG_WIDTH.W))
  val rb_offset = RegInit(0.U(OFFSET_WIDTH.W))
  val rb_wstrb = RegInit(0.U(8.W))
  val rb_wdata = RegInit(0.U(64.W))

  // write buffer
  val wb_hitway = RegInit(0.U(2.W))
  val wb_index = RegInit(0.U(INDEX_WIDTH.W))
  val wb_tag = RegInit(0.U(TAG_WIDTH.W))
  val wb_offset = RegInit(0.U(OFFSET_WIDTH.W))
  val wb_wstrb = RegInit(0.U(8.W))
  val wb_wdata = RegInit(0.U(64.W))

  // miss buffer
  val replace_valid = RegInit(false.B)
  val replace_dirty = RegInit(false.B)
  val replace_tag = RegInit(0.U(TAG_WIDTH.W))
  val replace_data = RegInit(0.U(SRAM_BITS.W))

  val tag = WireInit(VecInit(Seq.fill(4)(0.U(TAG_WIDTH.W))))
  val valid = WireInit(VecInit(Seq.fill(4)(false.B)))
  val dirty = WireInit(VecInit(Seq.fill(4)(false.B)))
  val sram_rdata = WireInit(VecInit(Seq.fill(4)(0.U(SRAM_BITS.W))))

  val hit = WireInit(VecInit(Seq.fill(4)(false.B)))

  (hit zip (tag zip valid)).map { case (h, (t, v)) => {
    h := (t === rb_tag) && v
  }}
  cache_hit := Cat(hit).orR && !rb_uncache

  val plru0 = RegInit(VecInit(Seq.fill(64)(0.U)))
  val plru1 = RegInit(VecInit(Seq.fill(64)(0.U)))
  val plru2 = RegInit(VecInit(Seq.fill(64)(0.U)))
  val replace_way = Wire(UInt(2.W))

  when ((state === lookup) && cache_hit) {
    plru0(rb_index) := hit(0) || hit(1)
    when (hit(0)) {
      plru1(rb_index) := 1.U
    } .elsewhen (hit(1)) {
      plru1(rb_index) := 0.U
    } .elsewhen (hit(2)) {
      plru2(rb_index) := 1.U
    } .elsewhen (hit(3)) {
      plru2(rb_index) := 0.U
    }
  }
  when ((state === refill) && out.ret_valid && !rb_uncache) {
    plru0(rb_index) := replace_way === 0.U || replace_way === 1.U
    when (replace_way === 0.U) {
      plru1(rb_index) := 1.U
    } .elsewhen (replace_way === 1.U) {
      plru1(rb_index) := 0.U
    } .elsewhen (replace_way === 2.U) {
      plru2(rb_index) := 1.U
    } .elsewhen (replace_way === 3.U) {
      plru2(rb_index) := 0.U
    }
  }

  replace_way := Cat(plru0(rb_index), Mux(plru0(rb_index) === 0.U, plru1(rb_index), plru2(rb_index)))

  (sram_rdata zip sram).map { case (r, s) => r := s.rdata}
  (tag zip meta).map { case (t, m) => t := m.io.tag_r}
  (valid zip meta).map { case (v, m) => v := m.io.valid_r}
  (dirty zip meta).map { case (d, m) => d := m.io.dirty_r}

  // request buffer
  when (in.valid && addr_ok) {
    rb_op := in.op
    rb_uncache := in_uncache
    rb_index := in_index
    rb_tag := in_tag
    rb_offset := in_offset
    rb_wstrb := in.wstrb
    rb_wdata := in.wdata
  }

  // write buffer
  when ((state === lookup) && cache_hit && rb_op === WRITE) {
    wb_hitway := OHToUInt(hit)
    wb_index := rb_index
    wb_tag := rb_tag
    wb_offset := rb_offset
    wb_wstrb := rb_wstrb
    wb_wdata := rb_wdata
  }

  // miss buffer
  when (state === lookup && !cache_hit) {
    replace_valid := valid(replace_way)
    replace_dirty := dirty(replace_way)
    replace_tag := tag(replace_way)
    replace_data := sram_rdata(replace_way)
  }

  conflict := (wb_state === wb_write && in.valid)
  addr_ok := ((state === idle) || (state === lookup && cache_hit)) && in.valid && !conflict
  in.data_ok := ((state === lookup) && cache_hit) || ((state === refill) && ((rb_uncache && rb_op === WRITE && out.wr_ok) || out.ret_valid))
  val load_res = WireInit(0.U(64.W))
  val load_inst = WireInit(0.U(128.W))
  for (i <- 0 until 4) {
    when (hit(i)) {
      load_res := Mux(rb_offset(3), sram_rdata(i)(127, 64), sram_rdata(i)(63, 0))
      load_inst := sram_rdata(i)
    }
  }
  val rd_rdata = Wire(UInt(64.W))
  val rd_inst = Wire(UInt(128.W))
  rd_rdata := Mux(rb_offset(3) || rb_uncache, out.ret_data(127, 64), out.ret_data(63, 0))
  rd_inst := Mux(rb_uncache, Cat(out.ret_data(127, 64), out.ret_data(127, 64)), out.ret_data)
  in.rdata := Mux((state === lookup) && cache_hit, load_res, Mux(state === refill && out.ret_valid, rd_rdata, 0.U))
  in.inst := Mux((state === lookup) && cache_hit, load_inst, Mux(state === refill && out.ret_valid, rd_inst, 0.U))

  out.wr_req := false.B
  out.rd_req := false.B

  out.wr_size := Mux(rb_uncache, SIZE_W, SIZE_D)
  out.wr_addr := Mux(rb_uncache, Cat(rb_tag, rb_index, rb_offset), Cat(replace_tag, rb_index, Fill(4, 0.U)))
  out.wr_wstrb := Mux(rb_uncache, rb_wstrb, "b11111111".U)
  out.wr_data := Mux(rb_uncache, Cat(rb_wdata, rb_wdata), replace_data)

  out.rd_size := Mux(rb_uncache, SIZE_W, SIZE_D)
  out.rd_addr := Mux(rb_uncache, Cat(rb_tag, rb_index, rb_offset), Cat(rb_tag, rb_index, Fill(4, 0.U)))

  switch (state){
    is (idle) {
      when (in.valid && addr_ok) {
        state := lookup
        when (!in_uncache) {
          for (i <- 0 until 4) {
            sram(i).en := true.B
            sram(i).addr := in_index
            meta(i).io.index := in_index
          }
        }
      }
    }
    is (lookup) {
      when (cache_hit && (in.valid && addr_ok)) {
        state := lookup
        when (!in_uncache) {
          for (i <- 0 until 4) {
            sram(i).en := true.B
            sram(i).addr := in_index
            meta(i).io.index := in_index
          }
        }
      } .elsewhen (cache_hit) {
        state := idle
      } .otherwise {
        state := miss
      }
    }
    is (miss) {
      out.wr_req := true.B
      when ((!rb_uncache && !(replace_valid && replace_dirty)) || (rb_uncache && (rb_op === READ))) {
        state := replace
        out.wr_req := false.B
      } .elsewhen (out.wr_req && out.wr_rdy) {
        state := replace
      }
    }
    is (replace) {
      out.rd_req := true.B
      when (rb_uncache && (rb_op === WRITE)) {
        state := refill
        out.rd_req := false.B
      } .elsewhen (out.rd_req && out.rd_rdy) {
        state := refill
      }
    }
    /* Confirm out.wr_ok will be later than refill when uncache
     * miss -> replace -> refill (3)
     * w_idle -> w_addr -> w_data -> b_data_ok (4)
     * So we can make sure that each uncache write will wait until wr_ok,
     * then state -> idle and start to deal with next cache request
     */
    is (refill) {
      when (rb_uncache && rb_op === WRITE && out.wr_ok || out.ret_valid) {
        state := idle
      }

      for (i <- 0 until 4) {
        when (replace_way === i.U && out.ret_valid && !rb_uncache) {
          sram(i).en := true.B
          sram(i).wen := true.B
          sram(i).addr := rb_index
          when (rb_op === WRITE) {
            sram(i).wdata := Mux(rb_offset(3),
              Cat(MaskData(out.ret_data(127, 64), rb_wdata, MaskExpand(rb_wstrb)), out.ret_data(63, 0)),
              Cat(out.ret_data(127, 64), MaskData(out.ret_data(63, 0), rb_wdata, MaskExpand(rb_wstrb))))
          } .otherwise {
            sram(i).wdata := out.ret_data
          }

          meta(i).io.tag_w := rb_tag
          meta(i).io.tag_wen := true.B
          meta(i).io.index := rb_index
          meta(i).io.dirty_w := rb_op
          meta(i).io.dirty_wen := true.B
        }
      }
    }
  }

  switch (wb_state) {
    is (wb_idle) {
      when ((state === lookup) && cache_hit && (rb_op === WRITE)) {
        wb_state := wb_write
        for (i <- 0 until 4) {
          when (hit(i)) {
            sram(i).en := true.B
            sram(i).addr := rb_index
          }
        }
      }
    }
    is (wb_write) {
      wb_state := wb_idle
      for (i <- 0 until 4) {
        when (wb_hitway === i.U) {
          sram(i).en := true.B
          sram(i).wen := true.B
          sram(i).addr := wb_index
          sram(i).wdata := Mux(wb_offset(3),
            Cat(MaskData(sram_rdata(i)(127, 64), wb_wdata, MaskExpand(wb_wstrb)), sram_rdata(i)(63, 0)),
            Cat(sram_rdata(i)(127, 64), MaskData(sram_rdata(i)(63, 0), wb_wdata, MaskExpand(wb_wstrb))))

          meta(i).io.index := wb_index
          meta(i).io.dirty_w := true.B
          meta(i).io.dirty_wen := true.B
        }
      }
    }
  }

  val counter = RegInit(0.U(8.W))
  val check_finish = counter === 255.U
  val tag_counter = counter(7, 2)
  val way_counter = counter(1, 0)
  val is_dirty = WireInit(false.B)
  in.fence_finish := false.B

  switch (fence_state) {
    is (fence_idle) {
      when (in.fence) {
        fence_state := fence_start
      }
    }
    is (fence_start) {
      when ((state === idle) && (wb_state === wb_idle)) {
        fence_state := fence_check_dirty
      }
    }
    is (fence_check_dirty) {
      for (i <- 0 until 4) {
        when (way_counter === i.U) {
          meta(i).io.index := tag_counter
          is_dirty := meta(i).io.fence_dirty
        }

        when (is_dirty) {
          fence_state := fence_wb_dirty
          for (i <- 0 until 4) {
            when (way_counter === i.U) {
              sram(i).addr := tag_counter
              sram(i).en := true.B
            }
          }
        } .otherwise {
          counter := counter + 1.U
          fence_state := Mux(check_finish, fence_finish, fence_check_dirty)
        }
      }
    }
    is (fence_wb_dirty) {
      out.wr_req := true.B
      out.wr_size := SIZE_D
      out.wr_addr := Cat(tag(way_counter), tag_counter, Fill(4, 0.U))
      out.wr_wstrb := "b11111111".U
      out.wr_data := sram_rdata(way_counter)
      when (out.wr_req && out.wr_rdy) {
        fence_state := fence_wait_ok
      }
    }
    is (fence_wait_ok) {
      when (out.wr_ok) {
        counter := counter + 1.U
        fence_state := Mux(check_finish, fence_finish, fence_check_dirty)
      }
    }
    is (fence_finish) {
      for (i <- 0 until 4) {
        meta(i).io.fence := true.B
      }
      in.fence_finish := true.B
      fence_state := fence_idle
    }
  }

}
