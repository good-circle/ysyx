import chisel3._
import chisel3.util._
import chisel3.util.experimental._
import Instructions._

class Core extends Module {
  val io = IO(new Bundle {
    val imem = new RomIO
    val dmem = new RamIO
  })

  val ifu = Module(new IFU)
  val idu = Module(new IDU)
  val exu = Module(new EXU)
  val wbu = Module(new WBU)

  ifu.io.imem <> io.imem
  ifu.io.br_bus <> idu.io.br_bus
  ifu.io.csr_br_bus <> exu.io.br_bus

  Connect(ifu.io.out, idu.io.in, idu.io.out.fire, ifu.io.csr_br_bus.is_reflush)
  idu.io.wb_bus <> wbu.io.wb_bus
  idu.io.ex_fwd <> exu.io.forward

  Connect(idu.io.out, exu.io.in, exu.io.out.fire, idu.io.ex_fwd.is_reflush)

  exu.io.dmem <> io.dmem
  Connect(exu.io.out, wbu.io.in, true.B, false.B)

  val commit = Module(new Commit)
  commit.io.valid := wbu.io.commit.valid
  commit.io.pc := wbu.io.commit.pc
  commit.io.ebreak := wbu.io.commit.inst === "h00100073".U
  commit.io.is_mmio := wnu.io.commit.is_clint

  class Commit extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val valid = Input(Bool())
    val pc = Input(UInt(32.W))
    val ebreak = Input(Bool())
    val is_mmio = Input(Bool())
  })

  setInline("Commit.v",
    """module Commit(
      |    input        valid  ,
      |    input [31:0] pc     ,
      |    input        ebreak ,
      |    input        is_mmio
      |);
      |
      |export "DPI-C" function export_finish;
      |function byte export_finish();
      |    return ebreak;
      |endfunction
      |
      |export "DPI-C" function export_commit;
      |function byte export_commit();
      |    return valid;
      |endfunction
      |
      |export "DPI-C" function export_mmio;
      |function byte export_mmio();
      |    return is_mmio;
      |endfunction
      |
      |import "DPI-C" function void set_pc(input longint pc);
      |always begin
      |    set_pc(pc);
      |end
      |
      |endmodule
      |""".stripMargin)
}

}
