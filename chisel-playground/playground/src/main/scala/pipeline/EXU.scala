import chisel3._
import chisel3.util._
import Define._

class EXU extends Module {
  val io = IO(new Bundle {
    val dmem = new RamIO
    val in = Flipped(Decoupled(new ID_IO))
    val out = Decoupled(new EX_IO)
    val forward = new Forward_Bus
    val br_bus = new CSR_Br_Bus
  })

  val pc = io.in.bits.pc
  val inst = io.in.bits.inst
  val src1_value = io.in.bits.src1_value
  val src2_value = io.in.bits.src2_value
  val rs2_value = io.in.bits.rs2_value
  val dest = io.in.bits.dest
  val fu_type = io.in.bits.fu_type
  val alu_op = io.in.bits.alu_op
  val lsu_op = io.in.bits.lsu_op
  val csr_op = io.in.bits.csr_op
  val wen = io.in.bits.wen
  val rv64 = io.in.bits.rv64
  io.in.ready := io.out.ready

  val alu = Module(new ALU)
  val lsu = Module(new LSU)
  val csr = Module(new CSR)
  val clint = Module(new CLINT)

  val alu_result = Wire(UInt(64.W))
  val is_lsu = Wire(Bool())
  val lsu_rdata = Wire(UInt(64.W))
  val csr_rdata = Wire(UInt(64.W))
  val is_clint = Wire(Bool())
  val final_result = Wire(UInt(64.W))

  val is_reflush = Wire(Bool())
  val csr_target = Wire(UInt(64.W))
  val handle_int = Wire(Bool())

  /* ALU */
  alu_result := alu.io.result
  alu.io.alu_op := alu_op
  alu.io.rv64 := rv64
  alu.io.src1 := src1_value
  alu.io.src2 := src2_value

  /* LSU */
  is_lsu := (fu_type === fu_lsu)
  lsu.io.dmem <> io.dmem
  lsu.io.src1 := src1_value
  lsu.io.src2 := src2_value
  lsu.io.wdata := rs2_value
  lsu.io.is_lsu := is_lsu && !is_clint && io.in.valid
  lsu.io.wen := wen
  lsu.io.lsu_op := lsu_op
  lsu_rdata := Mux(is_clint, clint.io.rdata, lsu.io.rdata)

  /* CSR */
  csr.io.pc := pc
  csr.io.csr_op := csr_op & Fill(CSROP_WIDTH, io.in.valid)
  csr.io.addr := inst(31, 20)
  csr.io.src := src1_value
  csr.io.valid := io.in.valid
  csr_rdata := csr.io.rdata
  is_reflush := csr.io.is_reflush
  csr_target := csr.io.csr_target
  handle_int := csr.io.handle_int

  /* CLINT */
  clint.io.is_mtime := (alu_result === "h0200bff8".U(64.W))
  clint.io.is_mtimecmp := (alu_result === "h02004000".U(64.W))
  clint.io.is_clint := is_lsu && is_clint 
  clint.io.wen := wen
  clint.io.wdata := rs2_value
  is_clint := (clint.io.is_mtime || clint.io.is_mtimecmp) && io.in.valid

  final_result := MuxLookup(fu_type, 0.U, Array(
    fu_alu -> alu_result,
    fu_bru -> (pc + 4.U),
    fu_lsu -> lsu_rdata,
    fu_csr -> csr_rdata
  ))

  io.out.bits.pc := pc
  io.out.bits.inst := inst
  io.out.bits.final_result := final_result
  io.out.bits.dest := dest
  io.out.bits.wen := wen

  /* only for difftest */
  io.out.bits.mcycle := (csr.io.addr === mcycle_addr) && (fu_type === fu_csr)
  io.out.bits.is_clint := is_clint

  io.out.valid := io.in.valid && !handle_int

  io.forward.is_reflush := is_reflush
  io.forward.fwd_valid := wen && dest =/= 0.U && io.in.valid
  io.forward.rf_waddr := dest
  io.forward.rf_wdata := final_result

  io.br_bus.is_reflush := is_reflush
  io.br_bus.br_target := csr_target

}
