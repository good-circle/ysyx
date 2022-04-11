// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at vsrc/blackbox.v:19:14
    extern svBit finish();

    // DPI IMPORTS
    // DPI import at vsrc/blackbox.v:23:38
    extern void pmem_read(long long mem_raddr, long long* mem_rdata, svBit mem_read);
    // DPI import at vsrc/blackbox.v:25:38
    extern void pmem_write(long long mem_waddr, long long mem_wdata, char mem_wmask, svBit mem_write);
    // DPI import at vsrc/regfile.v:24:30
    extern void set_gpr_ptr(const svOpenArrayHandle a);

#ifdef __cplusplus
}
#endif
