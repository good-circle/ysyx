import chisel3._
import chisel3.util._

class IFU extends Module {
  val io = IO(new Bundle {
    val imem = new RomIO
    val out = Decoupled(new IF_IO)
    val br_bus = Flipped(new Br_Bus)
    val csr_br_bus = Flipped(new CSR_Br_Bus)
  })

  val pc_en = RegInit(false.B)
  val pc = RegInit("h7ffffffc".U(32.W))
  val next_pc = Wire(UInt(32.W))

  val br_taken = io.br_bus.br_taken
  val br_target = io.br_bus.br_target
  val is_reflush = io.csr_br_bus.is_reflush
  val csr_br_target = io.csr_br_bus.br_target

  val if_valid = RegInit(false.B)
  if_valid := true.B

  pc_en := true.B
  next_pc := Mux(is_reflush, csr_br_target, Mux(br_taken, br_target, pc + 4.U))
  pc := Mux(io.out.ready, next_pc, pc)

  io.imem.en := if_valid
  io.imem.addr := pc.asUInt

  io.out.bits.pc := Mux(pc_en, pc, 0.U)
  io.out.bits.inst := Mux(pc_en, io.imem.rdata(31, 0), 0.U)
  io.out.valid := !br_taken && pc_en
}