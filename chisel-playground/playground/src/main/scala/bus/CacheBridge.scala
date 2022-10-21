import chisel3._
import chisel3.util._
import Define._

class CacheBridge extends Module {
  val io = IO(new Bundle() {
    val icache = Flipped(new Cache_Bridge_IO)
    val dcache = Flipped(new Cache_Bridge_IO)
    val out = new AXIIO
  })
  val icache = io.icache
  val dcache = io.dcache
  val out = io.out
  val aw = out.aw
  val w = out.w
  val b = out.b
  val ar = out.ar
  val r = out.r

  val ar_idle :: ar_finish :: Nil = Enum(2)
  val w_idle :: w_addr :: w_data :: Nil = Enum(3)
  val b_idle :: b_finish :: Nil = Enum(2)

  val ar_state = RegInit(ar_idle)
  val w_state = RegInit(w_idle)
  val b_state = RegInit(b_idle)

  val arid = RegInit(0.U(4.W))
  val araddr = RegInit(0.U(32.W))
  val arlen = RegInit(0.U(8.W))
  val arsize = RegInit(0.U(3.W))

  val awaddr = RegInit(0.U(32.W))
  val awlen = RegInit(0.U(8.W))
  val awsize = RegInit(0.U(3.W))
  val wstrb = RegInit(0.U(8.W))

  val inst_rdata = RegInit(0.U(SRAM_BITS.W))
  val data_rdata = RegInit(0.U(SRAM_BITS.W))
  val data_wdata = RegInit(0.U(SRAM_BITS.W))
  val inst_rvalid = RegInit(false.B)
  val data_rvalid = RegInit(false.B)
  val wlast = RegInit(false.B)

  inst_rvalid := false.B
  data_rvalid := false.B

  when(r.valid && r.ready) {
    when(r.bits.id === 0.U) {
      when(r.bits.last) {
        inst_rdata := Cat(r.bits.data, inst_rdata(63, 0))
        inst_rvalid := true.B
      }.otherwise {
        inst_rdata := Cat(inst_rdata(127, 64), r.bits.data)
      }
    }.otherwise {
      when(r.bits.last) {
        data_rdata := Cat(r.bits.data, data_rdata(63, 0))
        data_rvalid := true.B
      }.otherwise {
        data_rdata := Cat(data_rdata(127, 64), r.bits.data)
      }
    }
  }

  switch(ar_state) {
    is(ar_idle) {
      when(dcache.rd_req && dcache.rd_rdy) {
        ar_state := ar_finish
        arid := 1.U
        araddr := dcache.rd_addr
        arlen := Mux(dcache.rd_size === SIZE_W, 0.U, 1.U)
        arsize := dcache.rd_size
      }.elsewhen(icache.rd_req && icache.rd_rdy) {
        ar_state := ar_finish
        arid := 0.U
        araddr := icache.rd_addr
        arlen := Mux(icache.rd_size === SIZE_W, 0.U, 1.U)
        arsize := icache.rd_size
      }
    }
    is(ar_finish) {
      when(ar.valid && ar.ready) {
        ar_state := ar_idle
      }
    }
  }

  switch(w_state) {
    is(w_idle) {
      when(dcache.wr_req && dcache.wr_rdy) {
        w_state := w_addr
        awaddr := dcache.wr_addr
        awlen := Mux(dcache.wr_size === SIZE_W, 0.U, 1.U)
        awsize := dcache.wr_size
        wstrb := Mux(dcache.wr_size === SIZE_W, dcache.wr_wstrb, "b11111111".U)
        data_wdata := dcache.wr_data
      }
    }
    is(w_addr) {
      when(aw.valid && aw.ready) {
        w_state := w_data
      }
    }
    is(w_data) {
      when(w.valid && w.ready && !wlast) {
        w_state := w_data
        wlast := true.B
      }.elsewhen(w.valid && w.ready && wlast) {
        w_state := w_idle
        wlast := false.B
      }
    }
  }

  switch(b_state) {
    is(b_idle) {
      when(b.valid && b.ready) {
        b_state := b_finish
      }
    }
    is(b_finish) {
      b_state := b_idle
    }
  }

  aw.bits.addr := awaddr
  aw.bits.prot := 0.U
  aw.bits.id := 1.U
  aw.bits.user := 0.U
  aw.bits.len := awlen
  aw.bits.size := awsize
  aw.bits.burst := 1.U
  aw.bits.lock := false.B
  aw.bits.cache := 0.U
  aw.bits.qos := 0.U
  aw.valid := (w_state === w_addr)

  w.bits.data := Mux(wlast, data_wdata(127, 64), data_wdata(63, 0))
  w.bits.strb := wstrb
  w.bits.last := wlast
  w.valid := (w_state === w_data)

  ar.bits.addr := araddr
  ar.bits.prot := 0.U
  ar.bits.id := arid
  ar.bits.user := 0.U
  ar.bits.len := arlen
  ar.bits.size := arsize
  ar.bits.burst := 1.U
  ar.bits.lock := false.B
  ar.bits.cache := 0.U
  ar.bits.qos := 0.U
  ar.valid := (ar_state === ar_finish)

  r.ready := 1.U

  b.ready := (b_state === b_idle)

  icache.rd_rdy := (ar_state === ar_idle) && !dcache.rd_req
  icache.ret_valid := inst_rvalid
  icache.ret_data := inst_rdata
  icache.wr_rdy := true.B
  icache.wr_ok := true.B

  dcache.rd_rdy := (ar_state === ar_idle)
  dcache.ret_valid := data_rvalid
  dcache.ret_data := data_rdata
  dcache.wr_rdy := (w_state === w_idle)
  dcache.wr_ok := (b_state === b_finish)
}
