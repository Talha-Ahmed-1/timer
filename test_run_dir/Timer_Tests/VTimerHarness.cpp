// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTimerHarness.h for the primary calling header

#include "VTimerHarness.h"     // For This
#include "VTimerHarness__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VTimerHarness) {
    VTimerHarness__Syms* __restrict vlSymsp = __VlSymsp = new VTimerHarness__Syms(this, name());
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VTimerHarness::__Vconfigure(VTimerHarness__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VTimerHarness::~VTimerHarness() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VTimerHarness::eval() {
    VTimerHarness__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VTimerHarness::eval\n"); );
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

void VTimerHarness::_eval_initial_loop(VTimerHarness__Syms* __restrict vlSymsp) {
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

void VTimerHarness::_initial__TOP__1(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_initial__TOP__1\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at TimerHarness.v:564
    vlTOPp->io_intr_cmp = 0U;
}

VL_INLINE_OPT void VTimerHarness::_sequent__TOP__2(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_sequent__TOP__2\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__TimerHarness__DOT__hostAdapter__DOT__stateReg,0,0);
    //char	__VpadToAlign25[3];
    // Body
    __Vdly__TimerHarness__DOT__hostAdapter__DOT__stateReg 
	= vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg;
    // ALWAYS at TimerHarness.v:103
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__errReg 
	= ((~ (IData)(vlTOPp->reset)) & ((~ ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack) 
					     & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err)))) 
					 & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_24)));
    // ALWAYS at TimerHarness.v:94
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__respReg 
	= ((~ (IData)(vlTOPp->reset)) & ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg)
					  ? ((~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg)) 
					     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_27))
					  : (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_27)));
    if (vlTOPp->reset) {
	__Vdly__TimerHarness__DOT__hostAdapter__DOT__stateReg = 0U;
    } else {
	if (vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg) {
	    if (vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg) {
		__Vdly__TimerHarness__DOT__hostAdapter__DOT__stateReg = 0U;
	    }
	} else {
	    __Vdly__TimerHarness__DOT__hostAdapter__DOT__stateReg 
		= ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack) 
		   | (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err));
	}
    }
    // ALWAYS at TimerHarness.v:126
    if (vlTOPp->reset) {
	vlTOPp->TimerHarness__DOT__hostAdapter__DOT__datReg = 0U;
    } else {
	if ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	      & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	     & (IData)(vlTOPp->io_req_valid))) {
	    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__datReg = 0U;
	} else {
	    if ((((IData)(vlTOPp->io_req_bits_isWrite) 
		  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
		 & (IData)(vlTOPp->io_req_valid))) {
		vlTOPp->TimerHarness__DOT__hostAdapter__DOT__datReg 
		    = vlTOPp->io_req_bits_dataRequest;
	    }
	}
    }
    // ALWAYS at TimerHarness.v:140
    if (vlTOPp->reset) {
	vlTOPp->TimerHarness__DOT__hostAdapter__DOT__selReg = 0U;
    } else {
	if ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	      & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	     & (IData)(vlTOPp->io_req_valid))) {
	    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__selReg 
		= vlTOPp->io_req_bits_activeByteLane;
	} else {
	    if ((((IData)(vlTOPp->io_req_bits_isWrite) 
		  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
		 & (IData)(vlTOPp->io_req_valid))) {
		vlTOPp->TimerHarness__DOT__hostAdapter__DOT__selReg 
		    = vlTOPp->io_req_bits_activeByteLane;
	    }
	}
    }
    // ALWAYS at TimerHarness.v:359
    vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_error_REG_1 
	= ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid) 
	   & (~ (((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
		  | (4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr))) 
		 | (8U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)))));
    // ALWAYS at TimerHarness.v:348
    vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_valid_REG 
	= vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid;
    // ALWAYS at TimerHarness.v:110
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stbReg 
	= ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_10));
    // ALWAYS at TimerHarness.v:115
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__cycReg 
	= ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_11));
    // ALWAYS at TimerHarness.v:119
    if (vlTOPp->reset) {
	vlTOPp->TimerHarness__DOT__hostAdapter__DOT__weReg = 0U;
    } else {
	if ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	      & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	     & (IData)(vlTOPp->io_req_valid))) {
	    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__weReg 
		= vlTOPp->io_req_bits_isWrite;
	} else {
	    if ((((IData)(vlTOPp->io_req_bits_isWrite) 
		  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
		 & (IData)(vlTOPp->io_req_valid))) {
		vlTOPp->TimerHarness__DOT__hostAdapter__DOT__weReg 
		    = vlTOPp->io_req_bits_isWrite;
	    }
	}
    }
    // ALWAYS at TimerHarness.v:133
    if (vlTOPp->reset) {
	vlTOPp->TimerHarness__DOT__hostAdapter__DOT__adrReg = 0U;
    } else {
	if ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	      & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	     & (IData)(vlTOPp->io_req_valid))) {
	    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__adrReg 
		= vlTOPp->io_req_bits_addrRequest;
	} else {
	    if ((((IData)(vlTOPp->io_req_bits_isWrite) 
		  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
		 & (IData)(vlTOPp->io_req_valid))) {
		vlTOPp->TimerHarness__DOT__hostAdapter__DOT__adrReg 
		    = vlTOPp->io_req_bits_addrRequest;
	    }
	}
    }
    // ALWAYS at TimerHarness.v:86
    if (vlTOPp->reset) {
	vlTOPp->TimerHarness__DOT__hostAdapter__DOT__dataReg = 0U;
    } else {
	if (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack) 
	     & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err)))) {
	    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__dataReg 
		= (((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
		    & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
		    ? 0U : (((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
			     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
			     ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
			     : (((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
				 & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
				 ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2
				 : (((8U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
				     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
				     ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
				     : (((8U == (0xfU 
						 & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					 & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
					 ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4
					 : vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5)))));
	} else {
	    if (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err) 
		 & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack)))) {
		vlTOPp->TimerHarness__DOT__hostAdapter__DOT__dataReg 
		    = (((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
			& (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
		        ? 0U : (((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
				 & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
				 ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
				 : (((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
				     & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
				     ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2
				     : (((8U == (0xfU 
						 & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					 & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
					 ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
					 : (((8U == 
					      (0xfU 
					       & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					     & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
					     ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4
					     : vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5)))));
	    }
	}
    }
    // ALWAYS at TimerHarness.v:78
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction 
	= ((~ (IData)(vlTOPp->reset)) & ((~ ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack) 
					     & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err)))) 
					 & ((~ ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err) 
						& (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack)))) 
					    & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_9))));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg 
	= __Vdly__TimerHarness__DOT__hostAdapter__DOT__stateReg;
    vlTOPp->io_rsp_bits_error = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__errReg;
    vlTOPp->io_rsp_valid = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__respReg;
    vlTOPp->TimerHarness__DOT__timer_io_rsp_valid = vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_valid_REG;
    // ALWAYS at TimerHarness.v:154
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg 
	= ((IData)(vlTOPp->reset) | (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_1));
    vlTOPp->io_rsp_bits_dataResponse = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__dataReg;
    // ALWAYS at TimerHarness.v:349
    vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1 
	= vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat;
    // ALWAYS at TimerHarness.v:357
    vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5 
	= vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr;
    // ALWAYS at TimerHarness.v:355
    vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4 
	= vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg;
    // ALWAYS at TimerHarness.v:351
    vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2 
	= vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg;
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)
	    ? (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__selReg)
	    : 0U);
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__cycReg));
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stbReg));
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)
	    ? vlTOPp->TimerHarness__DOT__hostAdapter__DOT__datReg
	    : 0U);
    vlTOPp->io_req_ready = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg;
    // ALWAYS at TimerHarness.v:339
    if (vlTOPp->reset) {
	vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg = 0U;
    } else {
	if ((1U & (~ ((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
		      & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))))) {
	    if ((1U & (~ ((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
			  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))))) {
		if ((1U & (~ ((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
			      & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))))) {
		    vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg 
			= vlTOPp->TimerHarness__DOT__timer__DOT___GEN_2;
		}
	    }
	}
    }
    // ALWAYS at TimerHarness.v:330
    if (vlTOPp->reset) {
	vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg = 0U;
    } else {
	if ((1U & (~ ((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
		      & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))))) {
	    if (((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
		 & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))) {
		if (vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid) {
		    vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg 
			= vlTOPp->TimerHarness__DOT__timer__DOT___ControlReg_T_1;
		}
	    }
	}
    }
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__weReg));
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)
	    ? vlTOPp->TimerHarness__DOT__hostAdapter__DOT__adrReg
	    : 0U);
}

void VTimerHarness::_settle__TOP__3(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_settle__TOP__3\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_rsp_bits_error = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__errReg;
    vlTOPp->io_rsp_valid = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__respReg;
    vlTOPp->TimerHarness__DOT__timer_io_rsp_valid = vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_valid_REG;
    vlTOPp->io_rsp_bits_dataResponse = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__dataReg;
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)
	    ? (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__selReg)
	    : 0U);
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__cycReg));
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stbReg));
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)
	    ? vlTOPp->TimerHarness__DOT__hostAdapter__DOT__datReg
	    : 0U);
    vlTOPp->io_req_ready = vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg;
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_1 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg) 
	   | ((~ (IData)(vlTOPp->io_req_valid)) & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_9 
	= ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	    & (IData)(vlTOPp->io_req_valid)) | ((((IData)(vlTOPp->io_req_bits_isWrite) 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
						 & (IData)(vlTOPp->io_req_valid)) 
						| (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_10 
	= ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	    & (IData)(vlTOPp->io_req_valid)) | ((((IData)(vlTOPp->io_req_bits_isWrite) 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
						 & (IData)(vlTOPp->io_req_valid)) 
						| (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stbReg)));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_11 
	= ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	    & (IData)(vlTOPp->io_req_valid)) | ((((IData)(vlTOPp->io_req_bits_isWrite) 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
						 & (IData)(vlTOPp->io_req_valid)) 
						| (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__cycReg)));
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__weReg));
    vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)
	    ? vlTOPp->TimerHarness__DOT__hostAdapter__DOT__adrReg
	    : 0U);
    vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid 
	= (((IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb) 
	    & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc)) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb));
    vlTOPp->TimerHarness__DOT__timer__DOT___ControlReg_T_1 
	= (vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat 
	   & ((((8U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
		 ? 0xffU : 0U) << 0x18U) | ((((4U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
					       ? 0xffU
					       : 0U) 
					     << 0x10U) 
					    | ((((2U 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
						  ? 0xffU
						  : 0U) 
						<< 8U) 
					       | ((1U 
						   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
						   ? 0xffU
						   : 0U)))));
    vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error 
	= (((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
	    & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
	    ? (IData)(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_valid_REG)
	    : (IData)(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_error_REG_1));
}

VL_INLINE_OPT void VTimerHarness::_combo__TOP__4(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_combo__TOP__4\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_1 
	= ((IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg) 
	   | ((~ (IData)(vlTOPp->io_req_valid)) & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_9 
	= ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	    & (IData)(vlTOPp->io_req_valid)) | ((((IData)(vlTOPp->io_req_bits_isWrite) 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
						 & (IData)(vlTOPp->io_req_valid)) 
						| (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction)));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_10 
	= ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	    & (IData)(vlTOPp->io_req_valid)) | ((((IData)(vlTOPp->io_req_bits_isWrite) 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
						 & (IData)(vlTOPp->io_req_valid)) 
						| (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stbReg)));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_11 
	= ((((~ (IData)(vlTOPp->io_req_bits_isWrite)) 
	     & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
	    & (IData)(vlTOPp->io_req_valid)) | ((((IData)(vlTOPp->io_req_bits_isWrite) 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg)) 
						 & (IData)(vlTOPp->io_req_valid)) 
						| (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__cycReg)));
}

VL_INLINE_OPT void VTimerHarness::_sequent__TOP__5(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_sequent__TOP__5\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid 
	= (((IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb) 
	    & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc)) 
	   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb));
    vlTOPp->TimerHarness__DOT__timer__DOT___ControlReg_T_1 
	= (vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat 
	   & ((((8U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
		 ? 0xffU : 0U) << 0x18U) | ((((4U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
					       ? 0xffU
					       : 0U) 
					     << 0x10U) 
					    | ((((2U 
						  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
						  ? 0xffU
						  : 0U) 
						<< 8U) 
					       | ((1U 
						   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
						   ? 0xffU
						   : 0U)))));
    vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error 
	= (((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
	    & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
	    ? (IData)(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_valid_REG)
	    : (IData)(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_error_REG_1));
    vlTOPp->TimerHarness__DOT__timer__DOT___GEN_2 = 
	(((8U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
	  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
	  ? ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid)
	      ? vlTOPp->TimerHarness__DOT__timer__DOT___ControlReg_T_1
	      : vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg)
	  : vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg);
    vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack 
	= ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid) 
	   & ((IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid) 
	      & (~ (IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error))));
    vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err 
	= ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid) 
	   & ((~ ((IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid) 
		  & (~ (IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error)))) 
	      & ((IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid) 
		 & (IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error))));
}

void VTimerHarness::_settle__TOP__6(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_settle__TOP__6\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TimerHarness__DOT__timer__DOT___GEN_2 = 
	(((8U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
	  & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
	  ? ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid)
	      ? vlTOPp->TimerHarness__DOT__timer__DOT___ControlReg_T_1
	      : vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg)
	  : vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg);
    vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack 
	= ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid) 
	   & ((IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid) 
	      & (~ (IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error))));
    vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err 
	= ((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid) 
	   & ((~ ((IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid) 
		  & (~ (IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error)))) 
	      & ((IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid) 
		 & (IData)(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error))));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_24 
	= (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err) 
	    & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack))) 
	   | (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__errReg));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_27 
	= (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack) 
	    & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err))) 
	   | (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err) 
	       & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack))) 
	      | (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__respReg)));
}

VL_INLINE_OPT void VTimerHarness::_sequent__TOP__7(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_sequent__TOP__7\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_24 
	= (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err) 
	    & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack))) 
	   | (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__errReg));
    vlTOPp->TimerHarness__DOT__hostAdapter__DOT___GEN_27 
	= (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack) 
	    & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err))) 
	   | (((IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err) 
	       & (~ (IData)(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack))) 
	      | (IData)(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__respReg)));
}

void VTimerHarness::_eval(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_eval\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
	vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VTimerHarness::_eval_initial(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_eval_initial\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void VTimerHarness::final() {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::final\n"); );
    // Variables
    VTimerHarness__Syms* __restrict vlSymsp = this->__VlSymsp;
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTimerHarness::_eval_settle(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_eval_settle\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__6(vlSymsp);
}

VL_INLINE_OPT QData VTimerHarness::_change_request(VTimerHarness__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_change_request\n"); );
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VTimerHarness::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_req_ready = VL_RAND_RESET_I(1);
    io_req_valid = VL_RAND_RESET_I(1);
    io_req_bits_addrRequest = VL_RAND_RESET_I(32);
    io_req_bits_dataRequest = VL_RAND_RESET_I(32);
    io_req_bits_activeByteLane = VL_RAND_RESET_I(4);
    io_req_bits_isWrite = VL_RAND_RESET_I(1);
    io_rsp_ready = VL_RAND_RESET_I(1);
    io_rsp_valid = VL_RAND_RESET_I(1);
    io_rsp_bits_dataResponse = VL_RAND_RESET_I(32);
    io_rsp_bits_error = VL_RAND_RESET_I(1);
    io_intr_cmp = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr = VL_RAND_RESET_I(32);
    TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat = VL_RAND_RESET_I(32);
    TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel = VL_RAND_RESET_I(4);
    TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack = VL_RAND_RESET_I(1);
    TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err = VL_RAND_RESET_I(1);
    TimerHarness__DOT__deviceAdapter_io_reqOut_valid = VL_RAND_RESET_I(1);
    TimerHarness__DOT__timer_io_rsp_valid = VL_RAND_RESET_I(1);
    TimerHarness__DOT__timer_io_rsp_bits_error = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__startWBTransaction = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__dataReg = VL_RAND_RESET_I(32);
    TimerHarness__DOT__hostAdapter__DOT__respReg = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__errReg = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__stbReg = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__cycReg = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__weReg = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__datReg = VL_RAND_RESET_I(32);
    TimerHarness__DOT__hostAdapter__DOT__adrReg = VL_RAND_RESET_I(32);
    TimerHarness__DOT__hostAdapter__DOT__selReg = VL_RAND_RESET_I(4);
    TimerHarness__DOT__hostAdapter__DOT__stateReg = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT__readyReg = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT___GEN_1 = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT___GEN_9 = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT___GEN_10 = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT___GEN_11 = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT___GEN_24 = VL_RAND_RESET_I(1);
    TimerHarness__DOT__hostAdapter__DOT___GEN_27 = VL_RAND_RESET_I(1);
    TimerHarness__DOT__timer__DOT__ControlReg = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT__CompareReg = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT__io_rsp_valid_REG = VL_RAND_RESET_I(1);
    TimerHarness__DOT__timer__DOT___ControlReg_T_1 = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1 = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2 = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4 = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5 = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT___GEN_2 = VL_RAND_RESET_I(32);
    TimerHarness__DOT__timer__DOT__io_rsp_bits_error_REG_1 = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VTimerHarness::_configure_coverage(VTimerHarness__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VTimerHarness::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
