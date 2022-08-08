module Commit(
    input        valid  ,
    input [31:0] pc     ,
    input        ebreak ,
    input        is_mmio
);

export "DPI-C" function export_finish;
function byte export_finish();
    return ebreak;
endfunction

export "DPI-C" function export_commit;
function byte export_commit();
    return valid;
endfunction

export "DPI-C" function export_mmio;
function byte export_mmio();
    return is_mmio;
endfunction

import "DPI-C" function void set_pc(input longint pc);
always begin
    set_pc(pc);
end

endmodule
