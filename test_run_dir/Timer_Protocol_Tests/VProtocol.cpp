// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProtocol.h for the primary calling header

#include "VProtocol.h"         // For This
#include "VProtocol__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VProtocol) {
    VProtocol__Syms* __restrict vlSymsp = __VlSymsp = new VProtocol__Syms(this, name());
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VProtocol::__Vconfigure(VProtocol__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VProtocol::~VProtocol() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VProtocol::eval() {
    VProtocol__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VProtocol::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VProtocol::_eval_initial_loop(VProtocol__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VProtocol::_sequent__TOP__1(VProtocol__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_sequent__TOP__1\n"); );
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG(__Vdly__Protocol__DOT__pre_counter,31,0);
    // Body
    __Vdly__Protocol__DOT__pre_counter = vlTOPp->Protocol__DOT__pre_counter;
    // ALWAYS at Protocol.v:19
    __Vdly__Protocol__DOT__pre_counter = ((IData)(vlTOPp->reset)
					   ? 0U : (
						   ((0U 
						     == vlTOPp->Protocol__DOT__pre_counter) 
						    & (IData)(vlTOPp->io_enable))
						    ? vlTOPp->Protocol__DOT___pre_counter_T_1
						    : 
						   ((vlTOPp->Protocol__DOT__pre_counter 
						     == vlTOPp->io_prescalar)
						     ? 0U
						     : vlTOPp->Protocol__DOT___pre_counter_T_1)));
    if (vlTOPp->reset) {
	vlTOPp->Protocol__DOT__timer_reg = 0U;
    } else {
	if ((1U & (~ ((0U == vlTOPp->Protocol__DOT__pre_counter) 
		      & (IData)(vlTOPp->io_enable))))) {
	    if ((vlTOPp->Protocol__DOT__pre_counter 
		 == vlTOPp->io_prescalar)) {
		vlTOPp->Protocol__DOT__timer_reg = vlTOPp->Protocol__DOT___timer_reg_T_1;
	    }
	}
    }
    vlTOPp->Protocol__DOT__pre_counter = __Vdly__Protocol__DOT__pre_counter;
    vlTOPp->Protocol__DOT___pre_counter_T_1 = ((IData)(1U) 
					       + vlTOPp->Protocol__DOT__pre_counter);
    vlTOPp->Protocol__DOT___timer_reg_T_1 = ((IData)(1U) 
					     + vlTOPp->Protocol__DOT__timer_reg);
}

void VProtocol::_settle__TOP__2(VProtocol__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_settle__TOP__2\n"); );
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Protocol__DOT___pre_counter_T_1 = ((IData)(1U) 
					       + vlTOPp->Protocol__DOT__pre_counter);
    vlTOPp->Protocol__DOT___timer_reg_T_1 = ((IData)(1U) 
					     + vlTOPp->Protocol__DOT__timer_reg);
    vlTOPp->io_intr_cmp = (vlTOPp->Protocol__DOT__timer_reg 
			   == vlTOPp->io_compare);
}

VL_INLINE_OPT void VProtocol::_combo__TOP__3(VProtocol__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_combo__TOP__3\n"); );
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_intr_cmp = (vlTOPp->Protocol__DOT__timer_reg 
			   == vlTOPp->io_compare);
}

void VProtocol::_eval(VProtocol__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_eval\n"); );
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VProtocol::_eval_initial(VProtocol__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_eval_initial\n"); );
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VProtocol::final() {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::final\n"); );
    // Variables
    VProtocol__Syms* __restrict vlSymsp = this->__VlSymsp;
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VProtocol::_eval_settle(VProtocol__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_eval_settle\n"); );
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VProtocol::_change_request(VProtocol__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_change_request\n"); );
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VProtocol::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_intr_cmp = VL_RAND_RESET_I(1);
    io_enable = VL_RAND_RESET_I(1);
    io_reset = VL_RAND_RESET_I(1);
    io_compare = VL_RAND_RESET_I(32);
    io_prescalar = VL_RAND_RESET_I(32);
    Protocol__DOT__pre_counter = VL_RAND_RESET_I(32);
    Protocol__DOT__timer_reg = VL_RAND_RESET_I(32);
    Protocol__DOT___pre_counter_T_1 = VL_RAND_RESET_I(32);
    Protocol__DOT___timer_reg_T_1 = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VProtocol::_configure_coverage(VProtocol__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VProtocol::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
