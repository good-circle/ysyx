module regfile(
    input         clk,

    input  [ 4:0] raddr1,
    output [63:0] rdata1,

    input  [ 4:0] raddr2,
    output [63:0] rdata2,

    input         we    ,      
    input  [ 4:0] waddr ,
    input  [63:0] wdata
);

reg [63:0] rf [31:0];

always @(posedge clk) begin
    if (we) rf[waddr] <= wdata;
end

assign rdata1 = (raddr1 == 5'b0) ? 64'b0 : rf[raddr1];
assign rdata2 = (raddr2 == 5'b0) ? 64'b0 : rf[raddr2];

import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
initial set_gpr_ptr(rf); 

endmodule
