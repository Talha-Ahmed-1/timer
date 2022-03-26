// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTimerHarness__Syms.h"


//======================

void VTimerHarness::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VTimerHarness* t=(VTimerHarness*)userthis;
    VTimerHarness__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VTimerHarness::traceChgThis(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VTimerHarness::traceChgThis__2(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb));
	vcdp->chgBit  (c+2,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc));
	vcdp->chgBit  (c+3,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we));
	vcdp->chgBus  (c+4,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr),32);
	vcdp->chgBus  (c+5,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat),32);
	vcdp->chgBus  (c+6,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel),4);
	vcdp->chgBus  (c+7,((((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
			      & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
			      ? 0U : (((4U == (0xfU 
					       & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
				       & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
				       ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
				       : (((4U == (0xfU 
						   & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					   & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
					   ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2
					   : (((8U 
						== 
						(0xfU 
						 & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					       & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
					       ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
					       : ((
						   (8U 
						    == 
						    (0xfU 
						     & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
						   & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
						   ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4
						   : vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5)))))),32);
	vcdp->chgBit  (c+8,(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid));
	vcdp->chgBus  (c+9,(((1U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			      ? 0xffU : 0U)),8);
	vcdp->chgBus  (c+10,(((2U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			       ? 0xffU : 0U)),8);
	vcdp->chgBus  (c+11,(((4U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			       ? 0xffU : 0U)),8);
	vcdp->chgBus  (c+12,(((8U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			       ? 0xffU : 0U)),8);
	vcdp->chgBit  (c+13,((1U & (~ (((0U == (0xfU 
						& vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					| (4U == (0xfU 
						  & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr))) 
				       | (8U == (0xfU 
						 & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)))))));
    }
}

void VTimerHarness::traceChgThis__3(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+14,(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack));
	vcdp->chgBit  (c+15,(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err));
	vcdp->chgBit  (c+16,(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid));
	vcdp->chgBit  (c+17,(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error));
    }
}

void VTimerHarness::traceChgThis__4(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+18,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg));
	vcdp->chgBit  (c+19,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__respReg));
	vcdp->chgBus  (c+20,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__dataReg),32);
	vcdp->chgBit  (c+21,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__errReg));
	vcdp->chgBit  (c+22,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction));
	vcdp->chgBit  (c+23,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stbReg));
	vcdp->chgBit  (c+24,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__cycReg));
	vcdp->chgBit  (c+25,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__weReg));
	vcdp->chgBus  (c+26,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__datReg),32);
	vcdp->chgBus  (c+27,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__adrReg),32);
	vcdp->chgBus  (c+28,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__selReg),4);
	vcdp->chgBit  (c+29,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg));
	vcdp->chgBus  (c+30,(vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg),32);
	vcdp->chgBus  (c+31,(vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg),32);
	vcdp->chgBit  (c+32,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_valid_REG));
	vcdp->chgBus  (c+33,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1),32);
	vcdp->chgBus  (c+34,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2),32);
	vcdp->chgBus  (c+35,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4),32);
	vcdp->chgBus  (c+36,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5),32);
	vcdp->chgBit  (c+37,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_error_REG_1));
    }
}

void VTimerHarness::traceChgThis__5(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+38,(vlTOPp->clock));
	vcdp->chgBit  (c+39,(vlTOPp->reset));
	vcdp->chgBit  (c+40,(vlTOPp->io_req_ready));
	vcdp->chgBit  (c+41,(vlTOPp->io_req_valid));
	vcdp->chgBus  (c+42,(vlTOPp->io_req_bits_addrRequest),32);
	vcdp->chgBus  (c+43,(vlTOPp->io_req_bits_dataRequest),32);
	vcdp->chgBus  (c+44,(vlTOPp->io_req_bits_activeByteLane),4);
	vcdp->chgBit  (c+45,(vlTOPp->io_req_bits_isWrite));
	vcdp->chgBit  (c+46,(vlTOPp->io_rsp_ready));
	vcdp->chgBit  (c+47,(vlTOPp->io_rsp_valid));
	vcdp->chgBus  (c+48,(vlTOPp->io_rsp_bits_dataResponse),32);
	vcdp->chgBit  (c+49,(vlTOPp->io_rsp_bits_error));
	vcdp->chgBit  (c+50,(vlTOPp->io_intr_cmp));
    }
}
