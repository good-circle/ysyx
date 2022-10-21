import chisel3._
import chisel3.util._
import Define._
import chisel3.util.experimental.BoringUtils

class Issue_Entry extends Module {
  val io = IO(new Bundle {
    val in = Flipped(new ID_IO)
    val out = new Issue_IO
    val rs1_value = Input(UInt(64.W))
    val rs2_value = Input(UInt(64.W))
  })

  val in = io.in
  val out = io.out
  val rs1_value = io.rs1_value
  val rs2_value = io.rs2_value

  val valid = in.valid
  val pc = in.pc
  val inst = in.inst
  val imm = in.imm
  val src1 = in.src1
  val src2 = in.src2
  val rs1 = in.rs1
  val rs2 = in.rs2
  val dest = in.dest

  val src1_value = Wire(UInt(64.W))
  val src2_value = Wire(UInt(64.W))

  src1_value := MuxLookup(src1, 0.U, Array(
    src_pc -> pc,
    src_rf -> rs1_value,
    src_imm -> Cat(Fill(59, 0.U), rs1) // for csr
  ))
  src2_value := MuxLookup(src2, 0.U, Array(
    src_rf -> rs2_value,
    src_imm -> imm
  ))

  out.valid := valid
  out.pc := pc
  out.inst := inst
  out.src1_value := src1_value
  out.src2_value := src2_value
  out.rs2_value := rs2_value
  out.imm := imm
  out.rs1 := rs1
  out.dest := dest
  out.fu_type := io.in.fu_type
  out.alu_op := io.in.alu_op
  out.bru_op := io.in.bru_op
  out.lsu_op := io.in.lsu_op
  out.csr_op := io.in.csr_op
  out.mdu_op := io.in.mdu_op
  out.wen := io.in.wen
  out.rv64 := io.in.rv64
  out.bp_br_taken := io.in.bp_br_taken
  out.bp_br_target := io.in.bp_br_target
  out.bp_br_type := io.in.bp_br_type
}

class Issue extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(Vec(2, new ID_IO)))
    val out = Decoupled(Vec(2, new Issue_IO))
    val wb_bus = Flipped(Vec(2, new Wb_Bus))
    val ex_fwd = Flipped(Vec(2, new Forward_Bus))
  })

  val rf_wen = WireInit(VecInit(Seq.fill(2)(false.B)))
  val rf_waddr = WireInit(VecInit(Seq.fill(2)(0.U(5.W))))
  val rf_wdata = WireInit(VecInit(Seq.fill(2)(0.U(64.W))))
  val rf_raddr1 = WireInit(VecInit(Seq.fill(2)(0.U(5.W))))
  val rf_raddr2 = WireInit(VecInit(Seq.fill(2)(0.U(5.W))))
  val rs1_value = WireInit(VecInit(Seq.fill(2)(0.U(64.W))))
  val rs2_value = WireInit(VecInit(Seq.fill(2)(0.U(64.W))))

  val need_blk = WireInit(VecInit(Seq.fill(2)(false.B)))

  val issue_entry = for (i <- 0 until 2) yield {
    val issue_entry = Module(new Issue_Entry)
    issue_entry
  }

  for (i <- 0 until 2) {
    issue_entry(i).io.in <> io.in.bits(i)
    issue_entry(i).io.out <> io.out.bits(i)
    issue_entry(i).io.rs1_value <> rs1_value(i)
    issue_entry(i).io.rs2_value <> rs2_value(i)
  }

  val rf = Module(new RegFile)
  for (i <- 0 until 2) {
    rf.rf_bus(i).raddr1 := rf_raddr1(i)
    rf.rf_bus(i).raddr2 := rf_raddr2(i)
    rf.rf_bus(i).waddr := rf_waddr(i)
    rf.rf_bus(i).wdata := rf_wdata(i)
    rf.rf_bus(i).wen := rf_wen(i)
  }

  for(i <- 0 until 2) {
    rf_raddr1(i) := io.in.bits(i).rs1
    rf_raddr2(i) := io.in.bits(i).rs2
    rf_waddr(i) := io.wb_bus(i).rf_waddr
    rf_wdata(i) := io.wb_bus(i).rf_wdata
    rf_wen(i) := io.wb_bus(i).rf_wen
  }

  for(i <- 0 until 2) {
    rs1_value(i) := Mux(io.ex_fwd(1).fwd_valid && io.ex_fwd(1).rf_waddr === rf_raddr1(i), io.ex_fwd(1).rf_wdata,
      Mux(io.ex_fwd(0).fwd_valid && io.ex_fwd(0).rf_waddr === rf_raddr1(i), io.ex_fwd(0).rf_wdata,
        Mux(rf_wen(1) && rf_waddr(1) === rf_raddr1(i), rf_wdata(1),
          Mux(rf_wen(0) && rf_waddr(0) === rf_raddr1(i), rf_wdata(0), rf.rf_bus(i).rdata1))))

    rs2_value(i) := Mux(io.ex_fwd(1).fwd_valid && io.ex_fwd(1).rf_waddr === rf_raddr2(i), io.ex_fwd(1).rf_wdata,
      Mux(io.ex_fwd(0).fwd_valid && io.ex_fwd(0).rf_waddr === rf_raddr2(i), io.ex_fwd(0).rf_wdata,
        Mux(rf_wen(1) && rf_waddr(1) === rf_raddr2(i), rf_wdata(1),
          Mux(rf_wen(0) && rf_waddr(0) === rf_raddr2(i), rf_wdata(0), rf.rf_bus(i).rdata2))))

    need_blk(i) := (io.ex_fwd(0).blk_valid && ((io.ex_fwd(0).rf_waddr === rf_raddr1(i)) && (io.in.bits(i).src1 === src_rf) ||
      (io.ex_fwd(0).rf_waddr === rf_raddr2(i)) && (io.in.bits(i).src2 === src_rf))) ||
      (io.ex_fwd(1).blk_valid && ((io.ex_fwd(1).rf_waddr === rf_raddr1(i)) && (io.in.bits(i).src1 === src_rf) ||
        (io.ex_fwd(1).rf_waddr === rf_raddr2(i)) && (io.in.bits(i).src2 === src_rf)))
  }

  val is_reflush = WireInit(false.B)
  BoringUtils.addSink(is_reflush, "frontend_reflush")

  io.out.valid := io.in.valid && !Cat(need_blk).orR && !is_reflush
  io.in.ready := (io.out.ready && !Cat(need_blk).orR) || !io.in.valid
}
