import chisel3._
import chisel3.util._
import Define._
import chisel3.util.random.XOR

class MDU extends Module with Config {
  val io = IO(new Bundle {
    val mdu_op = Input(UInt(MDUOP_WIDTH.W))
    val rv64 = Input(Bool())
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val result_ok = Output(Bool())
    val result = Output(UInt(64.W))
  })

  val src1 = io.src1
  val src2 = io.src2
  val mdu_op = io.mdu_op

  val src1_is_neg = src1(63)
  val src2_is_neg = src2(63)
  val src1_abs = Mux(src1_is_neg, (~src1).asUInt + 1.U, src1)
  val src2_abs = Mux(src2_is_neg, (~src2).asUInt + 1.U, src2)
  val src1_need_neg = Wire(Bool())
  val src2_need_neg = Wire(Bool())
  val result_is_neg = Wire(Bool())
  val is_mul = (mdu_op === mdu_mul) || (mdu_op === mdu_mulh) || (mdu_op === mdu_mulhsu) || (mdu_op === mdu_mulhu)
  val is_div = (mdu_op === mdu_div) || (mdu_op === mdu_divu) || (mdu_op === mdu_rem) || (mdu_op === mdu_remu)
  val src1_final = Mux(src1_need_neg, src1_abs, src1)
  val src2_final = Mux(src1_need_neg, src2_abs, src2)

  src1_need_neg := MuxLookup(mdu_op, 0.U, Array(
    mdu_mul -> false.B,
    mdu_mulh -> src1_is_neg,
    mdu_mulhsu -> src1_is_neg,
    mdu_mulhu -> false.B,
    mdu_div -> src1_is_neg,
    mdu_divu -> false.B,
    mdu_rem -> src1_is_neg,
    mdu_remu -> false.B
  ))

  src2_need_neg := MuxLookup(mdu_op, 0.U, Array(
    mdu_mul -> false.B,
    mdu_mulh -> src2_is_neg,
    mdu_mulhsu -> false.B,
    mdu_mulhu -> false.B,
    mdu_div -> src2_is_neg,
    mdu_divu -> false.B,
    mdu_rem -> src2_is_neg,
    mdu_remu -> false.B
  ))

  result_is_neg := XOR(src1_need_neg, src2_need_neg)

  val idle :: mul_calc :: div_calc :: finish :: Nil = Enum(4)

  val state = RegInit(idle)
  val count = RegInit(0.U(6.W))
  val count_reverse = 63.U - count
  val result_reg = RegInit(0.U(128.W))
  val divisor_reg = RegInit(0.U(128.W))
  val div_result_reg = RegInit(0.U(64.W))
  val tmp_result = WireInit(0.U(64.W))

  switch (state) {
    is (idle) {
      when (is_mul) {
        state := mul_calc
        result_reg := 0.U
      } .elsewhen (is_div) {
        state := div_calc
        result_reg := Cat(Fill(64, 0.U), src1_final) << 1.U
        divisor_reg := Cat(src2_final, Fill(64, 0.U))
        div_result_reg := 0.U
      }
    }
    is (mul_calc) {
      when (src2_final(count_reverse) === 1.U) {
        result_reg := (result_reg << 1.U).asUInt + src1_final
      } .otherwise {
        result_reg := result_reg << 1.U
      }
      when (count === 63.U) {
        state := finish
      }.otherwise {
        count := count + 1.U
      }
    }
    is (div_calc) {
      when (count === 63.U) {
        state := finish
        when(result_reg(127, 64) >= divisor_reg(127, 64)) {
          result_reg := result_reg - divisor_reg
          div_result_reg := (div_result_reg << 1.U).asUInt + 1.U
        }.otherwise {
          div_result_reg := div_result_reg << 1.U
        }
      } .otherwise {
        count := count + 1.U
        when(result_reg(127, 64) >= divisor_reg(127, 64)) {
          result_reg := (result_reg - divisor_reg) << 1.U
          div_result_reg := (div_result_reg << 1.U).asUInt + 1.U
        }.otherwise {
          result_reg := result_reg << 1.U
          div_result_reg := div_result_reg << 1.U
        }
      }
    }
    is (finish) {
      state := idle
      count := 0.U
    }
  }

  io.result_ok := state === finish
  tmp_result := MuxLookup(mdu_op, 0.U, Array(
    mdu_mul -> Mux(result_is_neg, (~result_reg(63, 0)).asUInt + 1.U, result_reg(63, 0)),
    mdu_mulh -> Mux(result_is_neg, (~result_reg(127, 64)).asUInt + 1.U, result_reg(127, 64)),
    mdu_mulhsu -> Mux(result_is_neg, (~result_reg(127, 64)).asUInt + 1.U, result_reg(127, 64)),
    mdu_mulhu -> Mux(result_is_neg, (~result_reg(127, 64)).asUInt + 1.U, result_reg(127, 64)),
    mdu_div -> Mux(result_is_neg, (~div_result_reg).asUInt + 1.U, div_result_reg),
    mdu_divu -> Mux(result_is_neg, (~div_result_reg).asUInt + 1.U, div_result_reg),
    mdu_rem -> Mux(result_is_neg, (~result_reg(127, 64)).asUInt + 1.U, result_reg(127, 64)),
    mdu_remu -> Mux(result_is_neg, (~result_reg(127, 64)).asUInt + 1.U, result_reg(127, 64))
  ))
  io.result := Mux(io.rv64, Cat(Fill(32, tmp_result(31)), tmp_result(31, 0)), tmp_result)

  if (SocDebug) {
    val golden_result = WireInit(0.U(64.W))
    golden_result := MuxLookup(mdu_op, 0.U, Array(
      mdu_mul -> (src1 * src2).asUInt,
      mdu_mulh -> (src1.asSInt * src2.asSInt >> 64).asUInt,
      mdu_mulhsu -> (src1.asSInt * src2.asUInt >> 64).asUInt,
      mdu_mulhu -> (src1.asUInt * src2.asUInt >> 64).asUInt,
      mdu_div -> (src1.asSInt / src2.asSInt).asUInt,
      mdu_divu -> (src1.asUInt / src2.asUInt).asUInt,
      mdu_rem -> (src1.asSInt % src2.asSInt).asUInt,
      mdu_remu -> (src1.asUInt % src2.asUInt).asUInt
    ))
    when(io.result_ok) {
      assert(golden_result === tmp_result)
    }
  }
}

