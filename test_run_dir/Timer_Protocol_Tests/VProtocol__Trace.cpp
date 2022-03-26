// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VProtocol__Syms.h"


//======================

void VProtocol::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VProtocol* t=(VProtocol*)userthis;
    VProtocol__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VProtocol::traceChgThis(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VProtocol::traceChgThis__2(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->Protocol__DOT__pre_counter),32);
	vcdp->chgBus  (c+2,(vlTOPp->Protocol__DOT__timer_reg),32);
    }
}

void VProtocol::traceChgThis__3(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+3,(vlTOPp->clock));
	vcdp->chgBit  (c+4,(vlTOPp->reset));
	vcdp->chgBit  (c+5,(vlTOPp->io_intr_cmp));
	vcdp->chgBit  (c+6,(vlTOPp->io_enable));
	vcdp->chgBit  (c+7,(vlTOPp->io_reset));
	vcdp->chgBus  (c+8,(vlTOPp->io_compare),32);
	vcdp->chgBus  (c+9,(vlTOPp->io_prescalar),32);
    }
}
