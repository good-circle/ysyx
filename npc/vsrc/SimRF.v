module SimRF(
  input         clock,
  input  [4:0]  rf_bus_0_raddr1,
  input  [4:0]  rf_bus_0_raddr2,
  output [63:0] rf_bus_0_rdata1,
  output [63:0] rf_bus_0_rdata2,
  input  [4:0]  rf_bus_0_waddr,
  input  [63:0] rf_bus_0_wdata,
  input         rf_bus_0_wen,
  input  [4:0]  rf_bus_1_raddr1,
  input  [4:0]  rf_bus_1_raddr2,
  output [63:0] rf_bus_1_rdata1,
  output [63:0] rf_bus_1_rdata2,
  input  [4:0]  rf_bus_1_waddr,
  input  [63:0] rf_bus_1_wdata,
  input         rf_bus_1_wen
);

reg [63:0] rf [31:0];

always @(posedge clock) begin
    if (rf_bus_0_wen) rf[rf_bus_0_waddr] <= rf_bus_0_wdata;
    if (rf_bus_1_wen) rf[rf_bus_1_waddr] <= rf_bus_1_wdata;
end

assign rf_bus_0_rdata1 = (rf_bus_0_raddr1 == 5'b0) ? 64'b0 : rf[rf_bus_0_raddr1];
assign rf_bus_0_rdata2 = (rf_bus_0_raddr2 == 5'b0) ? 64'b0 : rf[rf_bus_0_raddr2];
assign rf_bus_1_rdata1 = (rf_bus_1_raddr1 == 5'b0) ? 64'b0 : rf[rf_bus_1_raddr1];
assign rf_bus_1_rdata2 = (rf_bus_1_raddr2 == 5'b0) ? 64'b0 : rf[rf_bus_1_raddr2];

import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
initial set_gpr_ptr(rf);

endmodule
