import chisel3._
import chisel3.util._
import chisel3.util.experimental._
import Define._

class CSR extends Module with Config {
  val io = IO(new Bundle() {
    val pc = Input(UInt(32.W))
    val csr_op = Input(UInt(3.W))
    val addr = Input(UInt(12.W))
    val src = Input(UInt(64.W))
    val rdata = Output(UInt(64.W))
    val is_reflush = Output(Bool())
    val csr_target = Output(UInt(32.W))
    val handle_int = Output(Bool())
    val valid = Input(Bool())
  })

  val pc = io.pc
  val csr_op = io.csr_op
  val addr = io.addr
  val src = io.src

  val wen = Wire(Bool())
  val csr_taken = WireInit(false.B)
  val csr_target = WireInit(0.U(32.W))

  val mcycle = RegInit(0.U(64.W))
  val mepc = RegInit(0.U(64.W))
  val mcause = RegInit(0.U(64.W))
  val mstatus = RegInit("ha00001800".U(64.W))
  val mtvec = RegInit(0.U(64.W))
  val mip = RegInit(0.U(64.W))
  val mie = RegInit(0.U(64.W))
  val mscratch = RegInit(0.U(64.W))

  val rdata = WireInit(0.U(64.W))
  val wdata = Wire(UInt(64.W))

  val has_int = WireInit(false.B)
  val handle_int = WireInit(false.B)

  wen := (csr_op === csr_csrrw) || (csr_op === csr_csrrs) || (csr_op === csr_csrrc)

  def mstatusSideEffect(mstatus: UInt): UInt = {
    val mstatus_new = Cat((mstatus(16, 15) === "b11".U) || (mstatus(14, 13) === "b11".U), mstatus(62, 0))
    mstatus_new
  }

  val csr_map = Map(
    CSRRegMap(mcycle_addr  , mcycle                                            ),
    CSRRegMap(mepc_addr    , mepc    , "hfffffffffffffffc".U                   ),
    CSRRegMap(mcause_addr  , mcause                                            ),
    CSRRegMap(mstatus_addr , mstatus , "hffffffffffffffff".U, mstatusSideEffect),
    CSRRegMap(mtvec_addr   , mtvec                                             ),
    CSRRegMap(mip_addr     , mip     , "h0000000000000000".U                   ),
    CSRRegMap(mie_addr     , mie                                               ),
    CSRRegMap(mscratch_addr, mscratch                                          )
  )

  wdata := MuxLookup(csr_op, 0.U, Array(
    csr_csrrw -> src,
    csr_csrrs -> (rdata | src),
    csr_csrrc -> (rdata & (~src).asUInt)
  ))

  when (csr_op === csr_ecall) {
    mepc := pc
    mcause := 11.U
    mstatus := Cat(mstatus(63, 8), mstatus(3), mstatus(6, 4), 0.U, mstatus(2, 0))
    csr_taken := true.B
    csr_target := Cat(mtvec(31, 2), Fill(2, 0.U))
  }

  when(handle_int) {
    mip := 0.U
    mepc := pc
    mcause := "h8000000000000007".U
    mstatus := Cat(mstatus(63, 8), mstatus(3), mstatus(6, 4), 0.U, mstatus(2, 0))
    csr_taken := true.B
    csr_target := Cat(mtvec(31, 2), Fill(2, 0.U))
  }

  when (csr_op === csr_mret) {
    mstatus := Cat(mstatus(63, 8), 1.U, mstatus(6, 4), mstatus(7), mstatus(2, 0))
    csr_taken := true.B
    csr_target := mepc(31, 0)
  }

  mcycle := mcycle + 1.U

  CSRRegMap.access(csr_map, addr, rdata, wdata, wen)

  BoringUtils.addSink(has_int, "clint_has_int")

  when(has_int && mstatus(3) && mie(7) && io.valid) {
    handle_int := true.B
  }

  when(has_int) {
    mip := Cat(mip(63, 8), 1.U, mip(6, 0))
  }

  io.rdata := rdata
  io.is_reflush := csr_taken
  io.csr_target := csr_target
  io.handle_int := handle_int

  if (Difftest) {
    import difftest._
    val dt_cs = Module(new DifftestCSRState)
    dt_cs.io.clock          := clock
    dt_cs.io.coreid         := 0.U
    dt_cs.io.priviledgeMode := 3.U  // Machine mode
    dt_cs.io.mstatus        := RegNext(mstatus)
    dt_cs.io.sstatus        := RegNext(mstatus & "h80000003000de122".U)
    dt_cs.io.mepc           := RegNext(mepc)
    dt_cs.io.sepc           := 0.U
    dt_cs.io.mtval          := 0.U
    dt_cs.io.stval          := 0.U
    dt_cs.io.mtvec          := RegNext(mtvec)
    dt_cs.io.stvec          := 0.U
    dt_cs.io.mcause         := RegNext(mcause)
    dt_cs.io.scause         := 0.U
    dt_cs.io.satp           := 0.U
    dt_cs.io.mip            := 0.U
    dt_cs.io.mie            := RegNext(mie)
    dt_cs.io.mscratch       := RegNext(mscratch)
    dt_cs.io.sscratch       := 0.U
    dt_cs.io.mideleg        := 0.U
    dt_cs.io.medeleg        := 0.U

    val difftest_handle_int = RegInit(Bool(), 0.B)
    difftest_handle_int := handle_int

    val dt_ae = Module(new DifftestArchEvent)
    dt_ae.io.clock        := clock
    dt_ae.io.coreid       := 0.U
    dt_ae.io.intrNO       := Mux(RegNext(difftest_handle_int), 7.U, 0.U)
    dt_ae.io.cause        := 0.U
    dt_ae.io.exceptionPC  := Mux(RegNext(difftest_handle_int), mepc, 0.U)
  }
}

