module alu(
    input [63:0] src1,
    input [63:0] src2,
    input [1:0] aluop,
    output [63:0] result
);

wire op_add;
wire op_sltu;

assign op_add = aluop[0];
assign op_sltu = aluop[1];

wire [63:0] add_result;
wire [63:0] sltu_result;

assign add_result = src1 + src2;
assign sltu_result = {63'b0, src1 < src2};

assign result = {64{op_add}} & add_result
              | {64{op_sltu}} & sltu_result;

endmodule
