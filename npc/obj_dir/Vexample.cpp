// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vexample.h"
#include "Vexample__Syms.h"

//============================================================
// Constructors

Vexample::Vexample(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vexample__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
}

Vexample::Vexample(const char* _vcname__)
    : Vexample(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vexample::~Vexample() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vexample___024root___eval_initial(Vexample___024root* vlSelf);
void Vexample___024root___eval_settle(Vexample___024root* vlSelf);
void Vexample___024root___eval(Vexample___024root* vlSelf);
QData Vexample___024root___change_request(Vexample___024root* vlSelf);
#ifdef VL_DEBUG
void Vexample___024root___eval_debug_assertions(Vexample___024root* vlSelf);
#endif  // VL_DEBUG
void Vexample___024root___final(Vexample___024root* vlSelf);

static void _eval_initial_loop(Vexample__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vexample___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vexample___024root___eval_settle(&(vlSymsp->TOP));
        Vexample___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vexample___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/example.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vexample___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vexample::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vexample::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vexample___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vexample___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vexample___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/example.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vexample___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vexample::final() {
    Vexample___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vexample::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vexample::name() const {
    return vlSymsp->name();
}
