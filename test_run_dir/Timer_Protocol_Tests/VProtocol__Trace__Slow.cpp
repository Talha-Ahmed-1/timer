// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VProtocol__Syms.h"


//======================

void VProtocol::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VProtocol::traceInit, &VProtocol::traceFull, &VProtocol::traceChg, this);
}
void VProtocol::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VProtocol* t=(VProtocol*)userthis;
    VProtocol__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VProtocol::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VProtocol* t=(VProtocol*)userthis;
    VProtocol__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VProtocol::traceInitThis(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VProtocol::traceFullThis(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VProtocol::traceInitThis__1(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+3,"clock",-1);
	vcdp->declBit  (c+4,"reset",-1);
	vcdp->declBit  (c+5,"io_intr_cmp",-1);
	vcdp->declBit  (c+6,"io_enable",-1);
	vcdp->declBit  (c+7,"io_reset",-1);
	vcdp->declBus  (c+8,"io_compare",-1,31,0);
	vcdp->declBus  (c+9,"io_prescalar",-1,31,0);
	vcdp->declBit  (c+3,"Protocol clock",-1);
	vcdp->declBit  (c+4,"Protocol reset",-1);
	vcdp->declBit  (c+5,"Protocol io_intr_cmp",-1);
	vcdp->declBit  (c+6,"Protocol io_enable",-1);
	vcdp->declBit  (c+7,"Protocol io_reset",-1);
	vcdp->declBus  (c+8,"Protocol io_compare",-1,31,0);
	vcdp->declBus  (c+9,"Protocol io_prescalar",-1,31,0);
	vcdp->declBus  (c+1,"Protocol pre_counter",-1,31,0);
	vcdp->declBus  (c+2,"Protocol timer_reg",-1,31,0);
	// Tracing: Protocol _pre_counter_T_1 // Ignored: Inlined leading underscore at Protocol.v:16
	// Tracing: Protocol _timer_reg_T_1 // Ignored: Inlined leading underscore at Protocol.v:17
    }
}

void VProtocol::traceFullThis__1(VProtocol__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VProtocol* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->Protocol__DOT__pre_counter),32);
	vcdp->fullBus  (c+2,(vlTOPp->Protocol__DOT__timer_reg),32);
	vcdp->fullBit  (c+3,(vlTOPp->clock));
	vcdp->fullBit  (c+4,(vlTOPp->reset));
	vcdp->fullBit  (c+5,(vlTOPp->io_intr_cmp));
	vcdp->fullBit  (c+6,(vlTOPp->io_enable));
	vcdp->fullBit  (c+7,(vlTOPp->io_reset));
	vcdp->fullBus  (c+8,(vlTOPp->io_compare),32);
	vcdp->fullBus  (c+9,(vlTOPp->io_prescalar),32);
    }
}
