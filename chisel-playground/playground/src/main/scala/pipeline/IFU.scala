import chisel3._
import chisel3.util._
import Define._
import chisel3.util.experimental.BoringUtils

class IFU extends Module with Config {
  val io = IO(new Bundle {
    val imem = new Cpu_Cache_IO
    val out = Decoupled(new IF_IO)
    val reflush_bus = Flipped(new Reflush_Bus)
    val bpu = new IF_BPU_Bus
  })

  val pc = RegInit(RESET_VECTOR.U(32.W))
  val bp_pc = Wire(UInt(32.W))
  val bp_pc_reg = RegInit(0.U(32.W))
  val bp_taken = Wire(Bool())
  val bp_taken_reg = RegInit(false.B)
  val bp_type = Wire(UInt(BTB_TYPE_WIDTH.W))
  val bp_type_reg = RegInit(0.U(BTB_TYPE_WIDTH.W))
  val bp_offset = Wire(UInt(BTB_OFFSET_WIDTH.W))
  val bp_offset_reg = RegInit(0.U(BTB_OFFSET_WIDTH.W))

  val bpu_reg_pc = RegInit(0.U(32.W))
  val imem_reg_valid = RegInit(false.B)

  val is_reflush = io.reflush_bus.is_reflush
  val reflush_target = io.reflush_bus.br_target
  val has_int = WireInit(false.B)

  val fence = WireInit(false.B)
  BoringUtils.addSink(fence, "fence_i")
  val icache_fence_finish = Wire(Bool())
  icache_fence_finish := io.imem.fence_finish
  BoringUtils.addSource(icache_fence_finish, "icache_fence_finish")

  val dcache_fence_finish = WireInit(false.B)
  BoringUtils.addSink(dcache_fence_finish, "dcache_fence_finish")

  bp_taken := Mux(io.bpu.bp_ok, io.bpu.bp_taken, bp_taken_reg)
  bp_pc := Mux(io.bpu.bp_ok, io.bpu.bp_target, bp_pc_reg)
  bp_type := Mux(io.bpu.bp_ok, io.bpu.bp_type, bp_type_reg)
  bp_offset := Mux(io.bpu.bp_ok, io.bpu.bp_offset, bp_offset_reg)
  pc := Mux(is_reflush, reflush_target,
    Mux(io.out.valid && io.out.ready, bp_pc, pc))

  io.imem.valid := false.B
  io.imem.addr := pc
  io.imem.op := READ
  io.imem.wstrb := 0.U
  io.imem.wdata := 0.U
  io.imem.fence := false.B

  val idle :: data_ok :: cancle :: stop :: icache_fence :: wait_dfence :: wait_ifence :: Nil = Enum(7)
  val state = RegInit(idle)

  val inst_buff = RegInit(0.U(128.W))

  when (io.bpu.bp_ok) {
    bp_taken_reg := io.bpu.bp_taken
    bp_pc_reg := io.bpu.bp_target
    bp_type_reg := io.bpu.bp_type
    bp_offset_reg := io.bpu.bp_offset
  }

  switch (state) {
    is (idle) {
      when (fence) {
        state := icache_fence
        io.imem.valid := false.B
      } .elsewhen (!is_reflush) {
        state := data_ok
        io.imem.valid := true.B
        io.imem.addr := pc
      }.otherwise {
        state := data_ok
        io.imem.valid := true.B
        io.imem.addr := reflush_target
      }
    }
    is (data_ok) {
      io.imem.valid := true.B
      when (fence) {
        state := icache_fence
        io.imem.valid := false.B
      } .elsewhen (is_reflush && !io.imem.data_ok) {
        state := cancle
      } .elsewhen (is_reflush && io.imem.data_ok) {
        state := data_ok
        io.imem.valid := true.B
        io.imem.addr := reflush_target
      } .elsewhen (io.imem.data_ok && io.out.ready) {
        state := data_ok
        io.imem.valid := true.B
        io.imem.addr := bp_pc
      } .elsewhen (io.imem.data_ok && !io.out.ready) {
        state := stop
        io.imem.valid := false.B
      }
    }
    is (cancle) {
      when (fence) {
        state := icache_fence
        io.imem.valid := false.B
      } .elsewhen(io.imem.data_ok) {
        state := data_ok
        io.imem.valid := true.B
        io.imem.addr := pc
      }
    }
    is (stop) {
      when (fence) {
        state := icache_fence
        io.imem.valid := false.B
      } .elsewhen (is_reflush) {
        state := data_ok
        io.imem.valid := true.B
        io.imem.addr := reflush_target
      } .elsewhen (io.out.ready) {
        state := data_ok
        io.imem.valid := true.B
        io.imem.addr := bp_pc
      }
    }
    is (icache_fence) {
      io.imem.fence := true.B
      when (icache_fence_finish && dcache_fence_finish) {
        io.imem.fence := false.B
        state := idle
      } .elsewhen (icache_fence_finish) {
        io.imem.fence := false.B
        state := wait_dfence
      } .elsewhen (dcache_fence_finish) {
        state := wait_ifence
      }
    }
    is (wait_dfence) {
      when (dcache_fence_finish) {
        state := idle
      }
    }
    is (wait_ifence) {
      when (icache_fence_finish) {
        io.imem.fence := false.B
        state := idle
      }
    }
  }

  val call_count = RegInit(0.U(log2Up(RAS_ENTRY).W))
  val ret_count = RegInit(0.U(log2Up(RAS_ENTRY).W))

  when (is_reflush) {
    call_count := 0.U
    ret_count := 0.U
  } .elsewhen (io.out.fire) {
    call_count := call_count + ((bp_type === BTB_CALL) && bp_taken)
    ret_count := ret_count + ((bp_type === BTB_RET) && bp_taken)
  }

  bpu_reg_pc := io.bpu.pc
  imem_reg_valid := io.imem.valid

  io.bpu.valid := io.imem.valid && ((bpu_reg_pc =/= io.bpu.pc) || !imem_reg_valid)
  io.bpu.is_reflush := is_reflush
  io.bpu.pc := io.imem.addr
  io.bpu.call_count := call_count + ((bp_type === BTB_CALL) && bp_taken)
  io.bpu.ret_count := ret_count + ((bp_type === BTB_RET) && bp_taken)

  when (io.imem.data_ok) {
    inst_buff := io.imem.inst
  }

  def pc_uncache(pc: UInt) = !pc(31)
  def pc_offset(pc: UInt) = pc(3, 2)

  io.out.bits.pc := pc
  io.out.bits.inst := Mux((state === data_ok) && io.imem.data_ok,
    io.imem.inst,
    Mux(state === stop, inst_buff, 0.U))
  io.out.bits.uncache := pc_uncache(pc)
  io.out.bits.offset := pc_offset(pc)
  io.out.bits.bp_br_taken := bp_taken
  io.out.bits.bp_br_target := bp_pc
  io.out.bits.bp_br_type := bp_type
  io.out.bits.bp_br_offset := bp_offset
  io.out.valid := ((state === data_ok) && io.imem.data_ok && !is_reflush) || (state === stop && !is_reflush)
}
