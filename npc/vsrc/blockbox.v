module blackbox(
    input [63:0] mem_raddr,
    input mem_read,
    input [63:0] mem_waddr,
    input [63:0] mem_wdata,
    input [7:0] mem_wmask,
    input mem_write,
    output mem_rdata,

    input inst_ready,
    input [63:0] pc,
    output [63:0] inst_2,

    input ebreak
);

export "DPI-C" task finish;
task finish;
    output bit is_finish;
    is_finish = ebreak;
endtask

import "DPI-C" function void pmem_read(
  input longint mem_raddr, output longint mem_rdata, input bit mem_read);
import "DPI-C" function void pmem_write(
  input longint mem_waddr, input longint mem_wdata, input byte mem_wmask, input bit mem_write);

always @(*) begin
  pmem_read(mem_raddr, mem_rdata, mem_read);
  pmem_write(mem_waddr, mem_wdata, mem_wmask, mem_write);
end

always @(*) begin
    pmem_read(pc, inst_2, inst_ready);
end
