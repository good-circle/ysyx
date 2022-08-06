import chisel3._
import chisel3.util._
import Instructions._
import Define._

class IDU extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IF_IO))
    val out = Decoupled(new ID_IO)
    val br_bus = new Br_Bus
    val wb_bus = Flipped(new Wb_Bus)
    val ex_fwd = Flipped(new Forward_Bus)
  })

  val pc = io.in.bits.pc
  val inst = io.in.bits.inst

  val imm = Wire(UInt(64.W))
  val imm_i = Cat(Fill(52, inst(31)), inst(31, 20))
  val imm_s = Cat(Fill(52, inst(31)), inst(31, 25), inst(11, 7))
  val imm_b = Cat(Fill(52, inst(31)), inst(7), inst(30, 25), inst(11, 8), 0.U)
  val imm_u = Cat(Fill(32, inst(31)), inst(31, 12), Fill(12, 0.U))
  val imm_j = Cat(Fill(44, inst(31)), inst(19, 12), inst(20), inst(30, 21), 0.U)

  val src1_value = Wire(UInt(64.W))
  val src2_value = Wire(UInt(64.W))

  val rs1 = Wire(UInt(5.W))
  val rs2 = Wire(UInt(5.W))
  val dest = Wire(UInt(5.W))

  val rf_wen = Wire(Bool())
  val rf_waddr = Wire(UInt(5.W))
  val rf_wdata = Wire(UInt(64.W))
  val rf_raddr1 = Wire(UInt(5.W))
  val rf_raddr2 = Wire(UInt(5.W))
  val rs1_value = Wire(UInt(64.W))
  val rs2_value = Wire(UInt(64.W))

  // List(valid, inst_type, fu_type, alu_op, bru_op, lsu_op, csr_op, src1, src2, wen, rv64)
  val information = ListLookup(inst, List(n, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, n, n), Array(
    // RV32I
    LUI    ->  List(y, u_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , src_x   , src_imm, y, n),
    AUIPC  ->  List(y, u_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , src_pc  , src_imm, y, n),
    JAL    ->  List(y, j_type, fu_bru, alu_x     , bru_jal , lsu_x  , csr_x    , src_pc  , src_imm, y, n),
    JALR   ->  List(y, i_type, fu_bru, alu_x     , bru_jalr, lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    BEQ    ->  List(y, b_type, fu_bru, alu_x     , bru_beq , lsu_x  , csr_x    , src_rf  , src_rf , n, n),
    BNE    ->  List(y, b_type, fu_bru, alu_x     , bru_bne , lsu_x  , csr_x    , src_rf  , src_rf , n, n),
    BLT    ->  List(y, b_type, fu_bru, alu_x     , bru_blt , lsu_x  , csr_x    , src_rf  , src_rf , n, n),
    BGE    ->  List(y, b_type, fu_bru, alu_x     , bru_bge , lsu_x  , csr_x    , src_rf  , src_rf , n, n),
    BLTU   ->  List(y, b_type, fu_bru, alu_x     , bru_bltu, lsu_x  , csr_x    , src_rf  , src_rf , n, n),
    BGEU   ->  List(y, b_type, fu_bru, alu_x     , bru_bgeu, lsu_x  , csr_x    , src_rf  , src_rf , n, n),
    LB     ->  List(y, i_type, fu_lsu, alu_add   , bru_x   , lsu_lb , csr_x    , src_rf  , src_imm, y, n),
    LH     ->  List(y, i_type, fu_lsu, alu_add   , bru_x   , lsu_lh , csr_x    , src_rf  , src_imm, y, n),
    LW     ->  List(y, i_type, fu_lsu, alu_add   , bru_x   , lsu_lw , csr_x    , src_rf  , src_imm, y, n),
    LBU    ->  List(y, i_type, fu_lsu, alu_add   , bru_x   , lsu_lbu, csr_x    , src_rf  , src_imm, y, n),
    LHU    ->  List(y, i_type, fu_lsu, alu_add   , bru_x   , lsu_lhu, csr_x    , src_rf  , src_imm, y, n),
    SB     ->  List(y, s_type, fu_lsu, alu_add   , bru_x   , lsu_sb , csr_x    , src_rf  , src_imm, n, n),
    SH     ->  List(y, s_type, fu_lsu, alu_add   , bru_x   , lsu_sh , csr_x    , src_rf  , src_imm, n, n),
    SW     ->  List(y, s_type, fu_lsu, alu_add   , bru_x   , lsu_sw , csr_x    , src_rf  , src_imm, n, n),
    ADDI   ->  List(y, i_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    SLTI   ->  List(y, i_type, fu_alu, alu_slt   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    SLTIU  ->  List(y, i_type, fu_alu, alu_sltu  , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    XORI   ->  List(y, i_type, fu_alu, alu_xor   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    ORI    ->  List(y, i_type, fu_alu, alu_or    , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    ANDI   ->  List(y, i_type, fu_alu, alu_and   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    SLLI   ->  List(y, i_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    SRLI   ->  List(y, i_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    SRAI   ->  List(y, i_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, n),
    ADD    ->  List(y, r_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    SUB    ->  List(y, r_type, fu_alu, alu_sub   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    SLL    ->  List(y, r_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    SLT    ->  List(y, r_type, fu_alu, alu_slt   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    SLTU   ->  List(y, r_type, fu_alu, alu_sltu  , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    XOR    ->  List(y, r_type, fu_alu, alu_xor   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    SRL    ->  List(y, r_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    SRA    ->  List(y, r_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    OR     ->  List(y, r_type, fu_alu, alu_or    , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    AND    ->  List(y, r_type, fu_alu, alu_and   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),

    // RV64I
    ADDIW  ->  List(y, i_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, y),
    SLLIW  ->  List(y, i_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, y),
    SRLIW  ->  List(y, i_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, y),
    SRAIW  ->  List(y, i_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , src_rf  , src_imm, y, y),
    ADDW   ->  List(y, r_type, fu_alu, alu_add   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    SUBW   ->  List(y, r_type, fu_alu, alu_sub   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    SLLW   ->  List(y, r_type, fu_alu, alu_sll   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    SRLW   ->  List(y, r_type, fu_alu, alu_srl   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    SRAW   ->  List(y, r_type, fu_alu, alu_sra   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    LWU    ->  List(y, i_type, fu_lsu, alu_add   , bru_x   , lsu_lwu, csr_x    , src_rf  , src_imm, y, n),
    LD     ->  List(y, i_type, fu_lsu, alu_add   , bru_x   , lsu_ld , csr_x    , src_rf  , src_imm, y, n),
    SD     ->  List(y, s_type, fu_lsu, alu_add   , bru_x   , lsu_sd , csr_x    , src_rf  , src_imm, n, n),

    // RV32W
    MUL    ->  List(y, r_type, fu_alu, alu_mul   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    MULH   ->  List(y, r_type, fu_alu, alu_mulh  , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    MULHSU ->  List(y, r_type, fu_alu, alu_mulhsu, bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    MULHU  ->  List(y, r_type, fu_alu, alu_mulhu , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    DIV    ->  List(y, r_type, fu_alu, alu_div   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    DIVU   ->  List(y, r_type, fu_alu, alu_divu  , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    REM    ->  List(y, r_type, fu_alu, alu_rem   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),
    REMU   ->  List(y, r_type, fu_alu, alu_remu  , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, n),

    // RV64M
    MULW   ->  List(y, r_type, fu_alu, alu_mul   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    DIVW   ->  List(y, r_type, fu_alu, alu_div   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    DIVUW  ->  List(y, r_type, fu_alu, alu_divu  , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    REMW   ->  List(y, r_type, fu_alu, alu_rem   , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),
    REMUW  ->  List(y, r_type, fu_alu, alu_remu  , bru_x   , lsu_x  , csr_x    , src_rf  , src_rf , y, y),

    // CSR
    CSRRW   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrw, src_rf  , src_x  , y, n),
    CSRRS   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrs, src_rf  , src_x  , y, n),
    CSRRC   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrc, src_rf  , src_x  , y, n),
    CSRRWI  -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrw, src_imm , src_x  , y, n),
    CSRRSI  -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrs, src_imm , src_x  , y, n),
    CSRRCI  -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_csrrc, src_imm , src_x  , y, n),
    ECALL   -> List(y, i_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_ecall, src_x   , src_x  , n, n),
    MRET    -> List(y, r_type, fu_csr, alu_x     , bru_x   , lsu_x  , csr_mret , src_x   , src_x  , n, n),

    HALT   ->  List(n, r_type, fu_alu, alu_x     , bru_x   , lsu_x  , csr_x    , src_x   , src_x  , n, n),
    PUTCH  ->  List(n, r_type, fu_alu, alu_x     , bru_x   , lsu_x  , csr_x    , src_x   , src_x  , n, n)
  ))

  val (inst_valid: Bool) :: inst_type ::  fu_type     :: information0                  = information
  val  alu_op            :: bru_op    ::  lsu_op      :: csr_op        :: information1 = information0
  val  src1              :: src2      :: (wen : Bool) :: (rv64 : Bool) :: Nil          = information1

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

  src1_value := MuxLookup(src1, 0.U, Array(
    src_pc -> pc,
    src_rf -> rs1_value,
    src_imm -> Cat(Fill(59, 0.U), rs1) // for csr
  ))
  src2_value := MuxLookup(src2, 0.U, Array(
    src_rf -> rs2_value,
    src_imm -> imm
  ))

  val bru = Module(new BRU)
  io.br_bus.br_taken := bru.io.br_taken && io.in.valid
  io.br_bus.br_target := bru.io.br_target

  bru.io.bru_op := bru_op
  bru.io.src1 := src1_value
  bru.io.src2 := src2_value
  bru.io.pc := pc
  bru.io.imm := imm

  val rf = Module(new RegFile)
  rf.io.raddr1 := rf_raddr1
  rf.io.raddr2 := rf_raddr2
  rf.io.waddr := rf_waddr
  rf.io.wdata := rf_wdata
  rf.io.wen := rf_wen

  rf_raddr1 := rs1
  rf_raddr2 := rs2
  rf_waddr := io.wb_bus.rf_waddr
  rf_wdata := io.wb_bus.rf_wdata
  rf_wen := io.wb_bus.rf_wen

  rs1_value := Mux(io.ex_fwd.fwd_valid && io.ex_fwd.rf_waddr === rf_raddr1, io.ex_fwd.rf_wdata,
               Mux(rf_wen              && rf_waddr           === rf_raddr1, rf_wdata, rf.io.rdata1))
  rs2_value := Mux(io.ex_fwd.fwd_valid && io.ex_fwd.rf_waddr === rf_raddr2, io.ex_fwd.rf_wdata,
               Mux(rf_wen              && rf_waddr           === rf_raddr2, rf_wdata, rf.io.rdata2))
  
  io.out.bits.pc := pc
  io.out.bits.inst := inst
  io.out.bits.src1_value := src1_value
  io.out.bits.src2_value := src2_value
  io.out.bits.rs2_value := rs2_value
  io.out.bits.dest := dest
  io.out.bits.fu_type := fu_type
  io.out.bits.alu_op := alu_op
  io.out.bits.lsu_op := lsu_op
  io.out.bits.csr_op := csr_op
  io.out.bits.wen := wen
  io.out.bits.rv64 := rv64
  io.out.valid := io.in.valid

  io.in.ready := io.out.ready
}
