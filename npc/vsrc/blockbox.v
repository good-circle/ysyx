module blackbox(
    input [63:0] mem_raddr,
    input mem_read,
    input [63:0] mem_waddr,
    input [63:0] mem_wdata,
    input [7:0] mem_wmask,
    input mem_write,
    output mem_rdata,

    input inst_ready,
    input [63:0] pc;
    output [63:0] inst_2;

)