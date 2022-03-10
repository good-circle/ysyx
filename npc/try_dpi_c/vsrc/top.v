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

export "DPI-C" task finish;
task finish;
    output is_finish;
    is_finish = (inst == 32'h0);
endtask

endmodule
