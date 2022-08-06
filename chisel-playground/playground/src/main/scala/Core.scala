import chisel3._
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

  class commit extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val valid = Input(Bool())
    val pc = Input(UInt(32.W))
    val ebreak = Input(Bool())
  })

  setInline("commit.v",
    """module commit(
      |    input        valid ,
      |    input [31:0] pc    ,
      |    input        ebreak
      |);
      |
      |export "DPI-C" function finish;
      |function bit finish();
      |    return ebreak;
      |endfunction
      |
      |export "DPI-C" function commit;
      |function bit commit();
      |    return valid;
      |endfunction
      |
      |import "DPI-C" function void set_pc(input logic [31:0] a);
      |initial set_gpr_ptr(pc);
      |
      |endmodule
      |""".stripMargin)
}

}
