module top(
    input clk,
    input rst,
    input [31:0] inst,
    output reg [31:0] pc,
);

always @(posedge clk) begin
    pc <= pc + 4;
end


wire addi;  
assign addi = (inst[14:12] == 3'b000 && inst[6:0] == 7'b0010011);

assign funct7  = inst[31:25];
assign rs2     = inst[24:20];
assign rs1     = inst[19:15];
assign funct3  = inst[14:12];
assign rd      = inst[11:7];
assign opcode  = inst[6:2];

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

module reg_file(
	input         clk   ,
	input         rst   ,
	input  [5 :0] waddr ,
	input  [5 :0] raddr1,
	input  [5 :0] raddr2,
	input         wen   ,
	input  [63:0] wdata ,
	output [63:0] rdata1,
	output [63:0] rdata2
);

reg [31:0] r [31:0];

always @(posedge clk) begin
	if (rst == 1) begin
		r[0] <= 64'b0;
	end
    if (wen == 1 && rst != 1 && waddr != 5'b0) begin
		r[waddr] <= wdata;
	end
end

assign rdata1 = (raddr1 == 5'b0) ? 64'b0 : r[raddr1];
assign rdata2 = (raddr2 == 5'b0) ? 64'b0 : r[raddr2];

endmodule