import chisel3._
import Define._

class Br_Bus extends Bundle {
  val br_taken = Output(Bool())
  val br_target = Output(UInt(32.W))
}

class CSR_Br_Bus extends Bundle {
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

  val mcycle = Output(Bool())
  val is_clint = Output(Bool())
}

class Forward_Bus extends Bundle {
  val is_reflush = Output(Bool())
  val fwd_valid = Output(Bool())
  val rf_waddr = Output(UInt(5.W))
  val rf_wdata = Output(UInt(64.W))
}

class IF_IO extends Bundle {
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
}

class ID_IO extends Bundle {
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val src1_value = Output(UInt(64.W))
  val src2_value = Output(UInt(64.W))
  val rs2_value = Output(UInt(64.W))
  val dest = Output(UInt(5.W))
  val fu_type = Output(UInt(FUOP_WIDTH.W))
  val alu_op = Output(UInt(ALUOP_WIDTH.W))
  val lsu_op = Output(UInt(LSUOP_WIDTH.W))
  val csr_op = Output(UInt(CSROP_WIDTH.W))
  val wen = Output(Bool())
  val rv64 = Output(Bool())
}

class EX_IO extends Bundle {
  val pc = Output(UInt(32.W))
  val inst = Output(UInt(32.W))
  val final_result = Output(UInt(64.W))
  val dest = Output(UInt(5.W))
  val wen = Output(Bool())

  val mcycle = Output(Bool())
  val is_clint = Output(Bool())
}


