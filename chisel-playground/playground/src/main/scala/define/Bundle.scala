import chisel3._
import chisel3.util._
import Define._

class Reflush_Bus extends Bundle {
  val is_reflush = Output(Bool())
  val br_target = Output(UInt(32.W))
}

class Wb_Bus extends Bundle {
  val rf_wen = Output(Bool())
  val rf_waddr = Output(UInt(5.W))
  val rf_wdata = Output(UInt(64.W))
}

class Commit_Bus extends Bundle {
  val valid = Output(Bool())
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val wen = Output(Bool())
  val waddr = Output(UInt(5.W))
  val wdata = Output(UInt(64.W))

  /* For difftest */
  val mcycle = Output(Bool())
  val is_clint = Output(Bool())
  val is_mmio = Output(Bool())
}

class Forward_Bus extends Bundle {
  val blk_valid = Output(Bool())
  val fwd_valid = Output(Bool())
  val rf_waddr = Output(UInt(5.W))
  val rf_wdata = Output(UInt(64.W))
}

class IF_IO extends Bundle {
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(128.W))
  val uncache = Output(Bool())
  val offset = Output(UInt(BTB_OFFSET_WIDTH.W))
  val bp_br_offset = Output(UInt(BTB_OFFSET_WIDTH.W))
  val bp_br_taken = Output(Bool())
  val bp_br_target = Output(UInt(32.W))
  val bp_br_type = Output(UInt(BTB_TYPE_WIDTH.W))
}

class IQueue_IO extends Bundle {
  val valid = Output(Bool())
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val bp_br_taken = Output(Bool())
  val bp_br_target = Output(UInt(32.W))
  val bp_br_type = Output(UInt(BTB_TYPE_WIDTH.W))
}

class ID_IO extends Bundle {
  val valid = Output(Bool())
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val src1 = Output(UInt(SRCOP_WIDTH.W))
  val src2 = Output(UInt(SRCOP_WIDTH.W))
  val rs1 = Output(UInt(5.W))
  val rs2 = Output(UInt(5.W))
  val dest = Output(UInt(5.W))
  val imm = Output(UInt(64.W))
  val fu_type = Output(UInt(FUOP_WIDTH.W))
  val bru_op = Output(UInt(BRUOP_WIDTH.W))
  val alu_op = Output(UInt(ALUOP_WIDTH.W))
  val lsu_op = Output(UInt(LSUOP_WIDTH.W))
  val csr_op = Output(UInt(CSROP_WIDTH.W))
  val mdu_op = Output(UInt(MDUOP_WIDTH.W))
  val wen = Output(Bool())
  val rv64 = Output(Bool())
  val bp_br_taken = Output(Bool())
  val bp_br_target = Output(UInt(32.W))
  val bp_br_type = Output(UInt(BTB_TYPE_WIDTH.W))
}

class Issue_IO extends Bundle {
  val valid = Output(Bool())
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val src1_value = Output(UInt(64.W))
  val src2_value = Output(UInt(64.W))
  val rs2_value = Output(UInt(64.W))
  val imm = Output(UInt(64.W))
  val rs1 = Output(UInt(5.W))
  val dest = Output(UInt(5.W))
  val fu_type = Output(UInt(FUOP_WIDTH.W))
  val bru_op = Output(UInt(BRUOP_WIDTH.W))
  val alu_op = Output(UInt(ALUOP_WIDTH.W))
  val lsu_op = Output(UInt(LSUOP_WIDTH.W))
  val csr_op = Output(UInt(CSROP_WIDTH.W))
  val mdu_op = Output(UInt(MDUOP_WIDTH.W))
  val wen = Output(Bool())
  val rv64 = Output(Bool())
  val bp_br_taken = Output(Bool())
  val bp_br_target = Output(UInt(32.W))
  val bp_br_type = Output(UInt(BTB_TYPE_WIDTH.W))
}

class EX_IO extends Bundle {
  val valid = Output(Bool())
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val final_result = Output(UInt(64.W))
  val dest = Output(UInt(5.W))
  val wen = Output(Bool())

  /* For difftest */
  val mcycle = Output(Bool())
  val is_clint = Output(Bool())
  val is_mmio = Output(Bool())
}

class IF_BPU_Bus extends Bundle {
  val valid = Output(Bool())
  val pc = Output(UInt(32.W))
  val bp_ok = Input(Bool())
  val bp_taken = Input(Bool())
  val bp_target = Input(UInt(32.W))
  val bp_offset = Input(UInt(BTB_OFFSET_WIDTH.W))
  val is_reflush = Output(Bool())
  val bp_type = Input(UInt(BTB_TYPE_WIDTH.W))
  val call_count = Output(UInt(log2Up(RAS_ENTRY).W))
  val ret_count = Output(UInt(log2Up(RAS_ENTRY).W))
}

class EX_BPU_Bus extends Bundle {
  val valid = Output(Bool())
  val pc = Output(UInt(32.W))
  val bp_taken = Output(Bool())
  val bp_target = Output(UInt(32.W))
  val bp_type = Output(UInt(BTB_TYPE_WIDTH.W))
  val bp_wrong = Output(Bool())
  val bp_wrong_type = Output(UInt(BTB_TYPE_WIDTH.W))
  val fence = Output(Bool())
  val call_count = Output(UInt(log2Up(RAS_ENTRY).W))
  val ret_count = Output(UInt(log2Up(RAS_ENTRY).W))
}

class RF_BUS extends Bundle {
  val raddr1 = Input(UInt(5.W))
  val raddr2 = Input(UInt(5.W))
  val rdata1 = Output(UInt(64.W))
  val rdata2 = Output(UInt(64.W))
  val waddr = Input(UInt(5.W))
  val wdata = Input(UInt(64.W))
  val wen = Input(Bool())
}

