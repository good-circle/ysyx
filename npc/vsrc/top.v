module top(
    input clk,
    input [31:0] inst,
    output reg [31:0] pc,
    output reg a
);

always @(posedge clk) begin
    pc <= pc + 4;
end


wire addi;  
assign addi = (inst[14:12] == 3'b000 && inst[6:0] == 7'b0010011);

always @(posedge clk) begin
    if (addi) begin
        a <= a + 1;
    end
end

export "DPI-C" task finish;
task finish;
    output bit is_finish;
    is_finish = (inst == 32'h0);
endtask

endmodule
