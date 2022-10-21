import chisel3._
import chisel3.util._
import Instructions._
import Define._
import chisel3.util.experimental.BoringUtils

class Decode_Entry extends Module {
  val io = IO(new Bundle {
    val in = Flipped(new IQueue_IO)
    val out = new ID_IO
  })

  val in = io.in
  val out = io.out

  val pc = in.pc
  val inst = in.inst

  val imm = Wire(UInt(64.W))
  val imm_i = Cat(Fill(52, inst(31)), inst(31, 20))
  val imm_s = Cat(Fill(52, inst(31)), inst(31, 25), inst(11, 7))
  val imm_b = Cat(Fill(52, inst(31)), inst(7), inst(30, 25), inst(11, 8), 0.U)
  val imm_u = Cat(Fill(32, inst(31)), inst(31, 12), Fill(12, 0.U))
  val imm_j = Cat(Fill(44, inst(31)), inst(19, 12), inst(20), inst(30, 21), 0.U)

  val rs1 = Wire(UInt(5.W))
  val rs2 = Wire(UInt(5.W))
  val dest = Wire(UInt(5.W))

  // List(valid, inst_type, fu_type, alu_op, bru_op, lsu_op, csr_op, mdu_op, src1, src2, wen, rv64)
  val information = ListLookup(inst, List(n, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, n, n), Array(
    // RV32I
    LUI    ->  List(y, u_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_x   , src_imm, y, n),
    AUIPC  ->  List(y, u_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_pc  , src_imm, y, n),
    JAL    ->  List(y, j_type, fu_bru, alu_x     , bru_jal , lsu_x  , csr_x    , mdu_x     , src_pc  , src_imm, y, n),
    JALR   ->  List(y, i_type, fu_bru, alu_x     , bru_jalr, lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    BEQ    ->  List(y, b_type, fu_bru, alu_x     , bru_beq , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , n, n),
    BNE    ->  List(y, b_type, fu_bru, alu_x     , bru_bne , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , n, n),
    BLT    ->  List(y, b_type, fu_bru, alu_x     , bru_blt , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , n, n),
    BGE    ->  List(y, b_type, fu_bru, alu_x     , bru_bge , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , n, n),
    BLTU   ->  List(y, b_type, fu_bru, alu_x     , bru_bltu, lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , n, n),
    BGEU   ->  List(y, b_type, fu_bru, alu_x     , bru_bgeu, lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , n, n),
    LB     ->  List(y, i_type, fu_lsu, alu_x     , bru_x   , lsu_lb , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    LH     ->  List(y, i_type, fu_lsu, alu_x     , bru_x   , lsu_lh , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    LW     ->  List(y, i_type, fu_lsu, alu_x     , bru_x   , lsu_lw , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    LBU    ->  List(y, i_type, fu_lsu, alu_x     , bru_x   , lsu_lbu, csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    LHU    ->  List(y, i_type, fu_lsu, alu_x     , bru_x   , lsu_lhu, csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    SB     ->  List(y, s_type, fu_lsu, alu_x     , bru_x   , lsu_sb , csr_x    , mdu_x     , src_rf  , src_imm, n, n),
    SH     ->  List(y, s_type, fu_lsu, alu_x     , bru_x   , lsu_sh , csr_x    , mdu_x     , src_rf  , src_imm, n, n),
    SW     ->  List(y, s_type, fu_lsu, alu_x     , bru_x   , lsu_sw , csr_x    , mdu_x     , src_rf  , src_imm, n, n),
    ADDI   ->  List(y, i_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    SLTI   ->  List(y, i_type, fu_alu, alu_slt   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    SLTIU  ->  List(y, i_type, fu_alu, alu_sltu  , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    XORI   ->  List(y, i_type, fu_alu, alu_xor   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    ORI    ->  List(y, i_type, fu_alu, alu_or    , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    ANDI   ->  List(y, i_type, fu_alu, alu_and   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    SLLI   ->  List(y, i_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    SRLI   ->  List(y, i_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    SRAI   ->  List(y, i_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    ADD    ->  List(y, r_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    SUB    ->  List(y, r_type, fu_alu, alu_sub   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    SLL    ->  List(y, r_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    SLT    ->  List(y, r_type, fu_alu, alu_slt   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    SLTU   ->  List(y, r_type, fu_alu, alu_sltu  , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    XOR    ->  List(y, r_type, fu_alu, alu_xor   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    SRL    ->  List(y, r_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    SRA    ->  List(y, r_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    OR     ->  List(y, r_type, fu_alu, alu_or    , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),
    AND    ->  List(y, r_type, fu_alu, alu_and   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, n),

    // RV64I
    ADDIW  ->  List(y, i_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, y),
    SLLIW  ->  List(y, i_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, y),
    SRLIW  ->  List(y, i_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, y),
    SRAIW  ->  List(y, i_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_imm, y, y),
    ADDW   ->  List(y, r_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, y),
    SUBW   ->  List(y, r_type, fu_alu, alu_sub   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, y),
    SLLW   ->  List(y, r_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, y),
    SRLW   ->  List(y, r_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, y),
    SRAW   ->  List(y, r_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , mdu_x     , src_rf  , src_rf , y, y),
    LWU    ->  List(y, i_type, fu_lsu, alu_x     , bru_x   , lsu_lwu, csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    LD     ->  List(y, i_type, fu_lsu, alu_x     , bru_x   , lsu_ld , csr_x    , mdu_x     , src_rf  , src_imm, y, n),
    SD     ->  List(y, s_type, fu_lsu, alu_x     , bru_x   , lsu_sd , csr_x    , mdu_x     , src_rf  , src_imm, n, n),

    // RV32M
    MUL    ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_mul   , src_rf  , src_rf , y, n),
    MULH   ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_mulh  , src_rf  , src_rf , y, n),
    MULHSU ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_mulhsu, src_rf  , src_rf , y, n),
    MULHU  ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_mulhu , src_rf  , src_rf , y, n),
    DIV    ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_div   , src_rf  , src_rf , y, n),
    DIVU   ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_divu  , src_rf  , src_rf , y, n),
    REM    ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_rem   , src_rf  , src_rf , y, n),
    REMU   ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_remu  , src_rf  , src_rf , y, n),

    // RV64M
    MULW   ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_mul   , src_rf  , src_rf , y, y),
    DIVW   ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_div   , src_rf  , src_rf , y, y),
    DIVUW  ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_divu  , src_rf  , src_rf , y, y),
    REMW   ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_rem   , src_rf  , src_rf , y, y),
    REMUW  ->  List(y, r_type, fu_mdu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_remu  , src_rf  , src_rf , y, y),

    // CSR
    FENCE_I -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_fence, mdu_x     , src_x   , src_x  , n, n),
    CSRRW   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrw, mdu_x     , src_rf  , src_x  , y, n),
    CSRRS   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrs, mdu_x     , src_rf  , src_x  , y, n),
    CSRRC   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrc, mdu_x     , src_rf  , src_x  , y, n),
    CSRRWI  -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrw, mdu_x     , src_imm , src_x  , y, n),
    CSRRSI  -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrs, mdu_x     , src_imm , src_x  , y, n),
    CSRRCI  -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrc, mdu_x     , src_imm , src_x  , y, n),
    ECALL   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_ecall, mdu_x     , src_x   , src_x  , n, n),
    MRET    -> List(y, r_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_mret , mdu_x     , src_x   , src_x  , n, n),

    HALT   ->  List(n, r_type, fu_alu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_x     , src_x   , src_x  , n, n),
    PUTCH  ->  List(n, r_type, fu_alu, alu_x     , bru_x   , lsu_x  , csr_x    , mdu_x     , src_x   , src_x  , n, n)
  ))

  val (inst_valid: Bool) :: inst_type :: fu_type :: information0 = information
  val alu_op :: bru_op :: lsu_op :: csr_op :: mdu_op :: information1 = information0
  val src1 :: src2 :: (wen : Bool) :: (rv64 : Bool) :: Nil = information1

  rs1 := inst(19, 15)
  rs2 := inst(24, 20)
  dest := inst(11, 7)

  imm := MuxLookup(inst_type, 0.U, Array(
    i_type -> imm_i,
    s_type -> imm_s,
    b_type -> imm_b,
    u_type -> imm_u,
    j_type -> imm_j
  ))

  out.valid := in.valid
  out.pc := pc
  out.inst := inst
  out.src1 := src1
  out.src2 := src2
  out.rs1 := rs1
  out.rs2 := rs2
  out.dest := dest
  out.imm := imm
  out.fu_type := fu_type
  out.alu_op := alu_op
  out.bru_op := bru_op
  out.lsu_op := lsu_op
  out.csr_op := csr_op
  out.mdu_op := mdu_op
  out.wen := wen
  out.rv64 := rv64
  out.bp_br_taken := in.bp_br_taken
  out.bp_br_target := in.bp_br_target
  out.bp_br_type := in.bp_br_type

}

class IDU extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(Vec(2, new IQueue_IO)))
    val out = Decoupled(Vec(2, new ID_IO))
  })

  val decode_entry = for (i <- 0 until 2) yield {
    val decode_entry = Module(new Decode_Entry)
    decode_entry
  }

  for (i <- 0 until 2) {
    decode_entry(i).io.in <> io.in.bits(i)
    decode_entry(i).io.out <> io.out.bits(i)
  }

  val conflict_decode_entry = RegInit(0.U.asTypeOf(new ID_IO))
  val conflict = WireInit(false.B)
  val had_conflict = RegInit(false.B)

  val self_reg_conflict = WireInit(false.B)
  val self_fu_conflict = WireInit(false.B)
  val bpu_csr_conflict = WireInit(false.B)
  self_reg_conflict := (decode_entry(1).io.out.src1 === src_rf &&
    decode_entry(1).io.out.rs1 =/= 0.U &&
    decode_entry(1).io.out.rs1 === decode_entry(0).io.out.dest &&
    decode_entry(0).io.out.wen) ||
    ((decode_entry(1).io.out.src2 === src_rf || decode_entry(1).io.out.fu_type === fu_lsu) &&
      decode_entry(1).io.out.rs2 =/= 0.U &&
      decode_entry(1).io.out.rs2 === decode_entry(0).io.out.dest &&
      decode_entry(0).io.out.wen)

  self_fu_conflict := !((decode_entry(0).io.out.fu_type =/= decode_entry(1).io.out.fu_type) ||
    (decode_entry(0).io.out.fu_type === fu_alu && decode_entry(1).io.out.fu_type === fu_alu))

  bpu_csr_conflict := decode_entry(0).io.out.fu_type === fu_bru || decode_entry(0).io.out.fu_type === fu_csr || decode_entry(1).io.out.fu_type === fu_csr

  conflict := (decode_entry(1).io.out.valid && decode_entry(0).io.out.valid) && io.in.valid && !had_conflict &&
    (self_fu_conflict || self_reg_conflict || bpu_csr_conflict)

  io.out.bits(1).valid := decode_entry(1).io.out.valid && !conflict

  when (io.out.fire && conflict) {
    conflict_decode_entry := decode_entry(1).io.out
    had_conflict := true.B
  }

  when (io.out.fire && had_conflict) {
    had_conflict := false.B
    io.out.bits(0) := conflict_decode_entry
    io.out.bits(1).valid := false.B
  }

  val is_reflush = WireInit(false.B)
  BoringUtils.addSink(is_reflush, "frontend_reflush")

  when (is_reflush) {
    had_conflict := false.B
    io.out.bits(0).valid := false.B
    io.out.bits(1).valid := false.B
  }

  io.out.valid := (io.in.valid || had_conflict) && !is_reflush
  io.in.ready := (io.out.ready || !io.in.valid) && !conflict
}

