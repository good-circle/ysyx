// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTop.h"
#include "VTop__Syms.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VTop::VTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VTop__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_pc{vlSymsp->TOP.io_pc}
    , rootp{&(vlSymsp->TOP)}
{
}

VTop::VTop(const char* _vcname__)
    : VTop(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VTop::~VTop() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VTop___024root___eval_initial(VTop___024root* vlSelf);
void VTop___024root___eval_settle(VTop___024root* vlSelf);
void VTop___024root___eval(VTop___024root* vlSelf);
QData VTop___024root___change_request(VTop___024root* vlSelf);
#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf);
#endif  // VL_DEBUG
void VTop___024root___final(VTop___024root* vlSelf);

static void _eval_initial_loop(VTop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VTop___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VTop___024root___eval_settle(&(vlSymsp->TOP));
        VTop___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VTop___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/chisel/Top.v", 91, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VTop___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VTop___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VTop___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/chisel/Top.v", 91, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VTop___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VTop::final() {
    VTop___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VTop::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VTop::name() const {
    return vlSymsp->name();
}
