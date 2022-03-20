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

module regfile(
    input         clk,

    input  [ 4:0] raddr1,
    output [31:0] rdata1,

    input  [ 4:0] raddr2,
    output [31:0] rdata2,

    input         we    ,      
    input  [ 4:0] waddr ,
    input  [31:0] wdata
);

reg [31:0] rf [31:0];

always @(posedge clk) begin
    if (we) rf[waddr] <= wdata;
end

assign rdata1 = (raddr1 == 5'b0) ? 32'b0 : rf[raddr1];


assign rdata2 = (raddr2 == 5'b0) ? 32'b0 : rf[raddr2];

endmodule