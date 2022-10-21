import chisel3._
import chisel3.util._
import Define._

class META extends Module {
  val io = IO(new Bundle {
    val index = Input(UInt(INDEX_WIDTH.W))
    val tag_r = Output(UInt(TAG_WIDTH.W))
    val tag_w = Input(UInt(TAG_WIDTH.W))
    val tag_wen = Input(Bool())
    val dirty_r = Output(Bool())
    val dirty_w = Input(Bool())
    val dirty_wen = Input(Bool())
    val valid_r = Output(Bool())
    val fence = Input(Bool())
    val fence_dirty = Output(Bool())
  })
  val index = io.index

  val tag = RegInit(VecInit(Seq.fill(64)(0.U(TAG_WIDTH.W))))

  val valid = RegInit(VecInit(Seq.fill(64)(false.B)))
  val dirty = RegInit(VecInit(Seq.fill(64)(false.B)))

  when (io.tag_wen) {
    tag(index) := io.tag_w
    valid(index) := true.B
  }
  io.tag_r := RegNext(tag(index))

  io.dirty_r := RegNext(dirty(index), init = false.B)
  io.valid_r := RegNext(valid(index), init = false.B)
  io.fence_dirty := dirty(index) && valid(index)

  when (io.dirty_wen) {
    dirty(index) := io.dirty_w
  }

  when (reset.asBool) {
    for (i <- 0 until 64) {
      tag(i) := 0.U
    }
  }

  when (io.fence) {
    for (i <- 0 until 64) {
      dirty(i) := false.B
      valid(i) := false.B
    }
  }
}
