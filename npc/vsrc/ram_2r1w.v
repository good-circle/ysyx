module ram_2r1w(
    input         clk,
    input         imem_en,
    input  [63:0] imem_addr,

    input         dmem_en,
    input  [63:0] dmem_addr,
    output [63:0] dmem_rdata,
    input  [63:0] dmem_wdata,

    input  [63:0] dmem_wmask,
    input         dmem_wen  

);

import "DPI-C" context function void pmem_read(
  input longint mem_raddr, input bit mem_read);
import "DPI-C" context function void pmem_write(
  input longint mem_waddr, input longint mem_wdata, input byte mem_wmask, input bit mem_write);

always @(posedge clk) begin
  pmem_write(dmem_addr, dmem_wdata, dmem_wmask, dmem_wen);
end

wire [63:0] inst_2 = pmem_read(imem_addr, imem_en);
assign imem_data = imem_addr[2] ? inst_2[63:32] : inst_2[31:0];
assign dmem_rdata = pmem_read(dmem_addr, dmem_en);


endmodule
