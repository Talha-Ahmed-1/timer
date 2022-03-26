// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VProtocol_H_
#define _VProtocol_H_

#include "verilated.h"
class VProtocol__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VProtocol) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_intr_cmp,0,0);
    VL_IN8(io_enable,0,0);
    VL_IN8(io_reset,0,0);
    //char	__VpadToAlign5[3];
    VL_IN(io_compare,31,0);
    VL_IN(io_prescalar,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(Protocol__DOT__pre_counter,31,0);
    VL_SIG(Protocol__DOT__timer_reg,31,0);
    VL_SIG(Protocol__DOT___pre_counter_T_1,31,0);
    VL_SIG(Protocol__DOT___timer_reg_T_1,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign41[3];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign52[4];
    VProtocol__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VProtocol& operator= (const VProtocol&);	///< Copying not allowed
    VProtocol(const VProtocol&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VProtocol(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VProtocol();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VProtocol__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VProtocol__Syms* symsp, bool first);
  private:
    static QData	_change_request(VProtocol__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__3(VProtocol__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VProtocol__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VProtocol__Syms* __restrict vlSymsp);
    static void	_eval_initial(VProtocol__Syms* __restrict vlSymsp);
    static void	_eval_settle(VProtocol__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VProtocol__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(VProtocol__Syms* __restrict vlSymsp);
    static void	traceChgThis(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
