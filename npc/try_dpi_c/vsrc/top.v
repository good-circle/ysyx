module top(
  input [31:0] inst,
  output reg [31:0] pc,
  input clk,
  output reg [31:0] a
);

always @(posedge clk) begin
    pc <= pc + 4;
end


wire addi;  
assign addi = (inst == 32'h44332211);

always @(posedge clk) begin
    if (addi) begin
        a <= a + 1;
    end
end

import "DPI-C" function int add (input int a, input int b);
initial begin
$display("%x + %x = %x", 1, 2, add(1,2));
end

endmodule
