// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTimerHarness_H_
#define _VTimerHarness_H_

#include "verilated.h"
class VTimerHarness__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VTimerHarness) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_req_ready,0,0);
    VL_IN8(io_req_valid,0,0);
    VL_IN8(io_req_bits_activeByteLane,3,0);
    VL_IN8(io_req_bits_isWrite,0,0);
    VL_IN8(io_rsp_ready,0,0);
    VL_OUT8(io_rsp_valid,0,0);
    VL_OUT8(io_rsp_bits_error,0,0);
    VL_OUT8(io_intr_cmp,0,0);
    //char	__VpadToAlign10[2];
    VL_IN(io_req_bits_addrRequest,31,0);
    VL_IN(io_req_bits_dataRequest,31,0);
    VL_OUT(io_rsp_bits_dataResponse,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel,3,0);
    VL_SIG8(TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack,0,0);
    VL_SIG8(TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err,0,0);
    VL_SIG8(TimerHarness__DOT__deviceAdapter_io_reqOut_valid,0,0);
    VL_SIG8(TimerHarness__DOT__timer_io_rsp_valid,0,0);
    VL_SIG8(TimerHarness__DOT__timer_io_rsp_bits_error,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__startWBTransaction,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__respReg,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__errReg,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__stbReg,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__cycReg,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__weReg,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__selReg,3,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__stateReg,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT__readyReg,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT___GEN_1,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT___GEN_9,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT___GEN_10,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT___GEN_11,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT___GEN_24,0,0);
    VL_SIG8(TimerHarness__DOT__hostAdapter__DOT___GEN_27,0,0);
    VL_SIG8(TimerHarness__DOT__timer__DOT__io_rsp_valid_REG,0,0);
    VL_SIG8(TimerHarness__DOT__timer__DOT__io_rsp_bits_error_REG_1,0,0);
    //char	__VpadToAlign54[2];
    VL_SIG(TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr,31,0);
    VL_SIG(TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat,31,0);
    VL_SIG(TimerHarness__DOT__hostAdapter__DOT__dataReg,31,0);
    VL_SIG(TimerHarness__DOT__hostAdapter__DOT__datReg,31,0);
    VL_SIG(TimerHarness__DOT__hostAdapter__DOT__adrReg,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT__ControlReg,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT__CompareReg,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT___ControlReg_T_1,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5,31,0);
    VL_SIG(TimerHarness__DOT__timer__DOT___GEN_2,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign113[3];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign124[4];
    VTimerHarness__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VTimerHarness& operator= (const VTimerHarness&);	///< Copying not allowed
    VTimerHarness(const VTimerHarness&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VTimerHarness(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VTimerHarness();
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
    static void _eval_initial_loop(VTimerHarness__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VTimerHarness__Syms* symsp, bool first);
  private:
    static QData	_change_request(VTimerHarness__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__4(VTimerHarness__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VTimerHarness__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_eval_initial(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_eval_settle(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__5(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__7(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(VTimerHarness__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(VTimerHarness__Syms* __restrict vlSymsp);
    static void	traceChgThis(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
