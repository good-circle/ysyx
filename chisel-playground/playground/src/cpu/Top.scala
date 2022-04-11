import chisel3._
import chisel3.util._
import Instructions._
import Define._

class Top extends Module {
  val io = IO(new Bundle {
    val pc = Output(UInt(64.W))
  })

  val pc = RegInit("x80000000".U(64.W))
  val next_pc = Wire(UInt(64.W))
  val inst = Wire(UInt(32.W))

  val imm = Wire(UInt(64.W))

  val imm_i = Cat(Fill(52, inst(31)), inst(31, 20))
  val imm_s = Cat(Fill(52, inst(31)), inst(31, 25), inst(11, 7))
  val imm_b = Cat(Fill(52, inst(31)), inst(7), inst(30, 25), inst(11, 8), 0.U)
  val imm_u = Cat(Fill(32, inst(31)), inst(31, 12), Fill(12, 0.U))
  val imm_j = Cat(Fill(44, inst(31)), inst(19, 12), inst(20), inst(30, 21), 0.U)

  val src1_value = Wire(UInt(64.W))
  val src2_value = Wire(UInt(64.W))

  val br_taken = Wire(Bool())
  val br_target = Wire(UInt(64.W))

  val alu_result = Wire(UInt(64.W))

  val rf_waddr = Wire(UInt(5.W))
  val rf_wdata = Wire(UInt(64.W))
  val rf_raddr1 = Wire(UInt(5.W))
  val rf_raddr2 = Wire(UInt(5.W))
  val rs1_value = Wire(UInt(64.W))
  val rs2_value = Wire(UInt(64.W))

  val mem_read = Wire(Bool())
  val mem_raddr = Wire(UInt(64.W))
  val mem_rdata = Wire(UInt(64.W))

  val mem_write = Wire(Bool())
  val mem_waddr = Wire(UInt(64.W))
  val mem_wmask = Wire(UInt(8.W))
  val mem_wdata = Wire(UInt(64.W))

  val inst_ready = Wire(Bool())
  val inst_2 = Wire(UInt(64.W))

  val ebreak = Wire(Bool())

  val sb_wmask = Wire(UInt(8.W))
  val sh_wmask = Wire(UInt(8.W))
  val sw_wmask = Wire(UInt(8.W))
  val sd_wmask = Wire(UInt(8.W))
  val sb_wdata = Wire(UInt(64.W))
  val sh_wdata = Wire(UInt(64.W))
  val sw_wdata = Wire(UInt(64.W))
  val sd_wdata = Wire(UInt(64.W))

  val waddr_low = Wire(UInt(3.W))

  val raddr_low = Wire(UInt(3.W))
  val lb_rdata = Wire(UInt(64.W))
  val lbu_rdata = Wire(UInt(64.W))
  val lh_rdata = Wire(UInt(64.W))
  val lhu_rdata = Wire(UInt(64.W))
  val lw_rdata = Wire(UInt(64.W))
  val lwu_rdata = Wire(UInt(64.W))
  val ld_rdata = Wire(UInt(64.W))
  val load_rdata = Wire(UInt(64.W))

  // List(valid, inst_type, fu_type, alu_op, bru_op, mem_op, src1, src2, wen, rv64)
  val information = ListLookup(inst, List(n, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, 0.U, n, n), Array(
    // RV32I
    LUI    ->  List(y, u_type, fu_alu, alu_add   , bru_x   , mem_x  , src_x   , src_imm, y, n),
    AUIPC  ->  List(y, u_type, fu_alu, alu_add   , bru_x   , mem_x  , src_pc  , src_imm, y, n),
    JAL    ->  List(y, j_type, fu_bru, alu_x     , bru_jal , mem_x  , src_pc  , src_imm, y, n),
    JALR   ->  List(y, i_type, fu_bru, alu_x     , bru_jalr, mem_x  , src_rf  , src_imm, y, n),
    BEQ    ->  List(y, b_type, fu_bru, alu_x     , bru_beq , mem_x  , src_rf  , src_rf , n, n),
    BNE    ->  List(y, b_type, fu_bru, alu_x     , bru_bne , mem_x  , src_rf  , src_rf , n, n),
    BLT    ->  List(y, b_type, fu_bru, alu_x     , bru_blt , mem_x  , src_rf  , src_rf , n, n),
    BGE    ->  List(y, b_type, fu_bru, alu_x     , bru_bge , mem_x  , src_rf  , src_rf , n, n),
    BLTU   ->  List(y, b_type, fu_bru, alu_x     , bru_bltu, mem_x  , src_rf  , src_rf , n, n),
    BGEU   ->  List(y, b_type, fu_bru, alu_x     , bru_bgeu, mem_x  , src_rf  , src_rf , n, n),
    LB     ->  List(y, i_type, fu_mem, alu_add   , bru_x   , mem_lb , src_rf  , src_imm, y, n),
    LH     ->  List(y, i_type, fu_mem, alu_add   , bru_x   , mem_lh , src_rf  , src_imm, y, n),
    LW     ->  List(y, i_type, fu_mem, alu_add   , bru_x   , mem_lw , src_rf  , src_imm, y, n),
    LBU    ->  List(y, i_type, fu_mem, alu_add   , bru_x   , mem_lbu, src_rf  , src_imm, y, n),
    LHU    ->  List(y, i_type, fu_mem, alu_add   , bru_x   , mem_lhu, src_rf  , src_imm, y, n),
    SB     ->  List(y, s_type, fu_mem, alu_add   , bru_x   , mem_sb , src_rf  , src_imm, n, n),
    SH     ->  List(y, s_type, fu_mem, alu_add   , bru_x   , mem_sh , src_rf  , src_imm, n, n),
    SW     ->  List(y, s_type, fu_mem, alu_add   , bru_x   , mem_sw , src_rf  , src_imm, n, n),
    ADDI   ->  List(y, i_type, fu_alu, alu_add   , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    SLTI   ->  List(y, i_type, fu_alu, alu_slt   , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    SLTIU  ->  List(y, i_type, fu_alu, alu_sltu  , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    XORI   ->  List(y, i_type, fu_alu, alu_xor   , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    ORI    ->  List(y, i_type, fu_alu, alu_or    , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    ANDI   ->  List(y, i_type, fu_alu, alu_and   , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    SLLI   ->  List(y, i_type, fu_alu, alu_sll   , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    SRLI   ->  List(y, i_type, fu_alu, alu_srl   , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    SRAI   ->  List(y, i_type, fu_alu, alu_sra   , bru_x   , mem_x  , src_rf  , src_imm, y, n),
    ADD    ->  List(y, r_type, fu_alu, alu_add   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    SUB    ->  List(y, r_type, fu_alu, alu_sub   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    SLL    ->  List(y, r_type, fu_alu, alu_sll   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    SLT    ->  List(y, r_type, fu_alu, alu_slt   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    SLTU   ->  List(y, r_type, fu_alu, alu_sltu  , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    XOR    ->  List(y, r_type, fu_alu, alu_xor   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    SRL    ->  List(y, r_type, fu_alu, alu_srl   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    SRA    ->  List(y, r_type, fu_alu, alu_sra   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    OR     ->  List(y, r_type, fu_alu, alu_or    , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    AND    ->  List(y, r_type, fu_alu, alu_and   , bru_x   , mem_x  , src_rf  , src_rf , y, n),

    // RV64I
    ADDIW  ->  List(y, i_type, fu_alu, alu_add   , bru_x   , mem_x  , src_rf  , src_imm, y, y),
    SLLIW  ->  List(y, i_type, fu_alu, alu_sll   , bru_x   , mem_x  , src_rf  , src_imm, y, y),
    SRLIW  ->  List(y, i_type, fu_alu, alu_srl   , bru_x   , mem_x  , src_rf  , src_imm, y, y),
    SRAIW  ->  List(y, i_type, fu_alu, alu_sra   , bru_x   , mem_x  , src_rf  , src_imm, y, y),
    ADDW   ->  List(y, r_type, fu_alu, alu_add   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    SUBW   ->  List(y, r_type, fu_alu, alu_sub   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    SLLW   ->  List(y, r_type, fu_alu, alu_sll   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    SRLW   ->  List(y, r_type, fu_alu, alu_srl   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    SRAW   ->  List(y, r_type, fu_alu, alu_sra   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    LWU    ->  List(y, i_type, fu_mem, alu_add   , bru_x   , mem_lwu, src_rf  , src_imm, y, n),
    LD     ->  List(y, i_type, fu_mem, alu_add   , bru_x   , mem_ld , src_rf  , src_imm, y, n),
    SD     ->  List(y, s_type, fu_mem, alu_add   , bru_x   , mem_sd , src_rf  , src_imm, n, n),

    // RV32W
    MUL    ->  List(y, r_type, fu_alu, alu_mul   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    MULH   ->  List(y, r_type, fu_alu, alu_mulh  , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    MULHSU ->  List(y, r_type, fu_alu, alu_mulhsu, bru_x   , mem_x  , src_rf  , src_rf , y, n),
    MULHU  ->  List(y, r_type, fu_alu, alu_mulhu , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    DIV    ->  List(y, r_type, fu_alu, alu_div   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    DIVU   ->  List(y, r_type, fu_alu, alu_divu  , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    REM    ->  List(y, r_type, fu_alu, alu_rem   , bru_x   , mem_x  , src_rf  , src_rf , y, n),
    REMU   ->  List(y, r_type, fu_alu, alu_remu  , bru_x   , mem_x  , src_rf  , src_rf , y, n),

    // RV64M
    MULW   ->  List(y, r_type, fu_alu, alu_mul   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    DIVW   ->  List(y, r_type, fu_alu, alu_div   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    DIVUW  ->  List(y, r_type, fu_alu, alu_divu  , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    REMW   ->  List(y, r_type, fu_alu, alu_rem   , bru_x   , mem_x  , src_rf  , src_rf , y, y),
    REMUW  ->  List(y, r_type, fu_alu, alu_remu  , bru_x   , mem_x  , src_rf  , src_rf , y, y),

    // temporarily let ebreak valid n
    EBREAK ->  List(n, i_type, fu_alu, alu_x     , bru_x   , mem_x  , 0.U     , 0.U    , y, y)
  ))

  val (inst_valid: Bool) :: inst_type :: fu_type :: alu_op :: bru_op :: mem_op :: src1 :: src2 :: (wen : Bool) :: (rv64 : Bool) :: Nil = information

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
  ))
  src2_value := MuxLookup(src2, 0.U, Array(
    src_rf -> rs2_value,
    src_imm -> imm
  ))

  /* bru */
  val bru = Module(new BRU)

  br_taken := bru.io.br_taken
  br_target := bru.io.br_target

  bru.io.bruop := bru_op
  bru.io.src1 := src1_value
  bru.io.src2 := src2_value
  bru.io.pc := pc
  bru.io.imm := imm

  /* alu */
  val alu = Module(new ALU)


  alu_result := alu.io.result
  alu.io.aluop := alu_op
  alu.io.rv64 := rv64
  alu.io.src1 := src1_value
  alu.io.src2 := src2_value

  /* regfile */
  val regfile = Module(new Blackregfile)

  rf_waddr := inst(11, 7)
  rf_wdata := MuxLookup(fu_type, 0.U, Array(
    fu_alu -> alu_result,
    fu_bru -> (pc + 4.U),
    fu_mem -> load_rdata
  ))
  rf_raddr1 := inst(19, 15)
  rf_raddr2 := inst(24, 20)

  rs1_value := regfile.io.rdata1
  rs2_value := regfile.io.rdata2

  regfile.io.raddr1 := rf_raddr1
  regfile.io.raddr2 := rf_raddr2
  regfile.io.waddr := rf_waddr
  regfile.io.wdata := rf_wdata
  regfile.io.wen := wen
  regfile.io.clock := clock

  io.pc := pc
  next_pc := Mux(br_taken, br_target, pc + 4.U)
  pc := next_pc
  inst := Mux(pc(2), inst_2(63, 32), inst_2(31, 0))

  /* blackbox */
  val blackbox = Module(new Blackbox)

  waddr_low := mem_waddr(2, 0)

  sb_wmask := MuxLookup(waddr_low, 0.U, Array(
    0.U -> "b00000001".U,
    1.U -> "b00000010".U,
    2.U -> "b00000100".U,
    3.U -> "b00001000".U,
    4.U -> "b00010000".U,
    5.U -> "b00100000".U,
    6.U -> "b01000000".U,
    7.U -> "b10000000".U
  ))
  sh_wmask := MuxLookup(waddr_low, 0.U, Array(
    0.U -> "b00000011".U,
    2.U -> "b00001100".U,
    4.U -> "b00110000".U,
    6.U -> "b11000000".U
  ))
  sw_wmask := MuxLookup(waddr_low, 0.U, Array(
    0.U -> "b00001111".U,
    4.U -> "b11110000".U
  ))
  sd_wmask := "b11111111".U

  sb_wdata := Fill(8, rs2_value(7, 0))
  sh_wdata := Fill(4, rs2_value(15, 0))
  sw_wdata := Fill(2, rs2_value(31, 0))
  sd_wdata := rs2_value(63, 0)

  raddr_low := mem_raddr(2, 0)

  lb_rdata := MuxLookup(raddr_low, 0.U, Array(
    0.U -> Cat(Fill(56, mem_rdata(7)), mem_rdata(7, 0)),
    1.U -> Cat(Fill(56, mem_rdata(15)), mem_rdata(15, 8)),
    2.U -> Cat(Fill(56, mem_rdata(23)), mem_rdata(23, 16)),
    3.U -> Cat(Fill(56, mem_rdata(31)), mem_rdata(31, 24)),
    4.U -> Cat(Fill(56, mem_rdata(39)), mem_rdata(39, 32)),
    5.U -> Cat(Fill(56, mem_rdata(47)), mem_rdata(47, 40)),
    6.U -> Cat(Fill(56, mem_rdata(55)), mem_rdata(55, 48)),
    7.U -> Cat(Fill(56, mem_rdata(63)), mem_rdata(63, 56))
  ))

  lbu_rdata := MuxLookup(raddr_low, 0.U, Array(
    0.U -> Cat(Fill(56, 0.U), mem_rdata(7, 0)),
    1.U -> Cat(Fill(56, 0.U), mem_rdata(15, 8)),
    2.U -> Cat(Fill(56, 0.U), mem_rdata(23, 16)),
    3.U -> Cat(Fill(56, 0.U), mem_rdata(31, 24)),
    4.U -> Cat(Fill(56, 0.U), mem_rdata(39, 32)),
    5.U -> Cat(Fill(56, 0.U), mem_rdata(47, 40)),
    6.U -> Cat(Fill(56, 0.U), mem_rdata(55, 48)),
    7.U -> Cat(Fill(56, 0.U), mem_rdata(63, 56))
  ))
  lh_rdata := MuxLookup(raddr_low, 0.U, Array(
    0.U -> Cat(Fill(48, mem_rdata(15)), mem_rdata(15, 0)),
    2.U -> Cat(Fill(48, mem_rdata(31)), mem_rdata(31, 16)),
    4.U -> Cat(Fill(48, mem_rdata(47)), mem_rdata(47, 32)),
    6.U -> Cat(Fill(48, mem_rdata(63)), mem_rdata(63, 48))
  ))
  lhu_rdata := MuxLookup(raddr_low, 0.U, Array(
    0.U -> Cat(Fill(48, 0.U), mem_rdata(15, 0)),
    2.U -> Cat(Fill(48, 0.U), mem_rdata(31, 16)),
    4.U -> Cat(Fill(48, 0.U), mem_rdata(47, 32)),
    6.U -> Cat(Fill(48, 0.U), mem_rdata(63, 48))
  ))
  lw_rdata := MuxLookup(raddr_low, 0.U, Array(
    0.U -> Cat(Fill(32, mem_rdata(31)), mem_rdata(31, 0)),
    4.U -> Cat(Fill(32, mem_rdata(63)), mem_rdata(63, 32)),
  ))
  lwu_rdata := MuxLookup(raddr_low, 0.U, Array(
    0.U -> Cat(Fill(32, 0.U), mem_rdata(31, 0)),
    4.U -> Cat(Fill(32, 0.U), mem_rdata(63, 32)),
  ))
  ld_rdata := mem_rdata
  load_rdata := MuxLookup(mem_op, 0.U, Array(
    mem_lb -> lb_rdata,
    mem_lbu -> lbu_rdata,
    mem_lh -> lh_rdata,
    mem_lhu -> lhu_rdata,
    mem_lw -> lw_rdata,
    mem_lwu -> lwu_rdata,
    mem_ld -> ld_rdata
  ))

  mem_read := (fu_type === fu_mem) && (wen === y)
  mem_raddr := alu_result
  mem_rdata := blackbox.io.mem_rdata

  mem_write := (fu_type === fu_mem) && (wen === n)
  mem_waddr := alu_result
  mem_wmask := MuxLookup(mem_op, 0.U, Array(
    mem_sb -> sb_wmask,
    mem_sh -> sh_wmask,
    mem_sw -> sw_wmask,
    mem_sd -> sd_wmask
  ))
  mem_wdata :=  MuxLookup(mem_op, 0.U, Array(
    mem_sb -> sb_wdata,
    mem_sh -> sh_wdata,
    mem_sw -> sw_wdata,
    mem_sd -> sd_wdata
  ))

  ebreak := (inst_valid === n)
  inst_ready := !(reset.asBool)

  blackbox.io.mem_raddr := mem_raddr
  blackbox.io.mem_read := mem_read

  blackbox.io.mem_waddr := mem_waddr
  blackbox.io.mem_write := mem_write
  blackbox.io.mem_wmask := mem_wmask
  blackbox.io.mem_wdata := mem_wdata

  blackbox.io.inst_ready := inst_ready
  blackbox.io.pc := pc
  inst_2 := blackbox.io.inst_2

  blackbox.io.ebreak := ebreak
}


