import chisel3._
import chisel3.util._
import Define._
import chisel3.util.experimental.BoringUtils

class IQueue_Entry extends Bundle {
  val pc = UInt(32.W)
  val inst = UInt(32.W)
  val bp_br_taken = Bool()
  val bp_br_target = UInt(32.W)
  val bp_br_type = UInt(BTB_TYPE_WIDTH.W)
}

class IQueue extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IF_IO))
    val out = Decoupled(Vec(2, new IQueue_IO))
  })

  val is_reflush = WireInit(false.B)
  val full = WireInit(false.B)
  val in_counter = RegInit(0.U(log2Up(INST_QUEUE_ENTRY).W))
  val out_counter = RegInit(0.U(log2Up(INST_QUEUE_ENTRY).W))
  val inst_queue = RegInit(VecInit(Seq.fill(INST_QUEUE_ENTRY)(0.U.asTypeOf(new IQueue_Entry))))
  //val inst_queue = Mem(INST_QUEUE_ENTRY, new IQueue_Entry)
  val valid = RegInit(VecInit(Seq.fill(INST_QUEUE_ENTRY)(false.B)))

  val count = WireInit(0.U(BTB_OFFSET_WIDTH.W))
  val has_bp_taken = WireInit(false.B)
  has_bp_taken := io.in.bits.bp_br_taken && (io.in.bits.offset <= io.in.bits.bp_br_offset)
  count := Mux(!has_bp_taken, 3.U - io.in.bits.offset, io.in.bits.bp_br_offset - io.in.bits.offset)

  val in_inst = WireInit(VecInit(Seq.fill(4)(0.U(32.W))))
  in_inst(0) := io.in.bits.inst(31, 0)
  in_inst(1) := io.in.bits.inst(63, 32)
  in_inst(2) := io.in.bits.inst(95, 64)
  in_inst(3) := io.in.bits.inst(127,96)

  full := ((in_counter + 1.U) === out_counter) || ((in_counter + 2.U) === out_counter) ||
    ((in_counter + 3.U) === out_counter) || ((in_counter + 4.U) === out_counter)

  when (io.in.fire) {
    when (io.in.bits.uncache) {
      inst_queue(in_counter).pc := io.in.bits.pc
      inst_queue(in_counter).inst := io.in.bits.inst(31, 0)
      inst_queue(in_counter).bp_br_taken := io.in.bits.bp_br_taken
      inst_queue(in_counter).bp_br_target := io.in.bits.bp_br_target
      inst_queue(in_counter).bp_br_type := io.in.bits.bp_br_type
      valid(in_counter) := true.B
      in_counter := in_counter + 1.U
    } .otherwise {
      for (i <- 0 until 4) {
        when (i.U <= count) {
          inst_queue(in_counter + i.U).pc := io.in.bits.pc + (i << 2).U
          inst_queue(in_counter + i.U).inst := in_inst(io.in.bits.offset + i.U)
          inst_queue(in_counter + i.U).bp_br_taken := false.B
          inst_queue(in_counter + i.U).bp_br_target := 0.U
          inst_queue(in_counter + i.U).bp_br_type := 0.U
          valid(in_counter + i.U) := true.B
        }
        when (has_bp_taken) {
          inst_queue(in_counter + count).bp_br_taken := io.in.bits.bp_br_taken
          inst_queue(in_counter + count).bp_br_target := io.in.bits.bp_br_target
          inst_queue(in_counter + count).bp_br_type := io.in.bits.bp_br_type
        }
        in_counter := (in_counter + count) + 1.U
      }
    }
  }

  when (io.out.fire) {
    when (io.out.bits(1).valid) {
      out_counter := out_counter + 2.U
      for (i <- 0 until 2) {
        valid(out_counter + i.U) := false.B
      }
    } .otherwise {
      out_counter := out_counter + 1.U
      valid(out_counter) := false.B
    }
  }

  for (i <- 0 until 2) {
    io.out.bits(i).valid := valid(out_counter + i.U)
    io.out.bits(i).pc := inst_queue(out_counter + i.U).pc
    io.out.bits(i).inst := inst_queue(out_counter + i.U).inst
    io.out.bits(i).bp_br_taken := inst_queue(out_counter + i.U).bp_br_taken
    io.out.bits(i).bp_br_target := inst_queue(out_counter + i.U).bp_br_target
    io.out.bits(i).bp_br_type := inst_queue(out_counter + i.U).bp_br_type
  }

  io.out.valid := !is_reflush && io.out.bits(0).valid
  io.in.ready := !full

  BoringUtils.addSink(is_reflush, "frontend_reflush")
  when (reset.asBool || is_reflush) {
    in_counter := 0.U
    out_counter := 0.U
    for (i <- 0 until INST_QUEUE_ENTRY) {
      valid(i) := false.B
    }
  }

}
