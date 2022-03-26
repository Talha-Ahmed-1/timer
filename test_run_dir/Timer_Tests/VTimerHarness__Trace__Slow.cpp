// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTimerHarness__Syms.h"


//======================

void VTimerHarness::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VTimerHarness::traceInit, &VTimerHarness::traceFull, &VTimerHarness::traceChg, this);
}
void VTimerHarness::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VTimerHarness* t=(VTimerHarness*)userthis;
    VTimerHarness__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VTimerHarness::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VTimerHarness* t=(VTimerHarness*)userthis;
    VTimerHarness__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VTimerHarness::traceInitThis(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VTimerHarness::traceFullThis(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VTimerHarness::traceInitThis__1(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+47,"clock",-1);
	vcdp->declBit  (c+48,"reset",-1);
	vcdp->declBit  (c+49,"io_req_ready",-1);
	vcdp->declBit  (c+50,"io_req_valid",-1);
	vcdp->declBus  (c+51,"io_req_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+52,"io_req_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+53,"io_req_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+54,"io_req_bits_isWrite",-1);
	vcdp->declBit  (c+55,"io_rsp_ready",-1);
	vcdp->declBit  (c+56,"io_rsp_valid",-1);
	vcdp->declBus  (c+57,"io_rsp_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+58,"io_rsp_bits_error",-1);
	vcdp->declBit  (c+59,"io_intr_cmp",-1);
	vcdp->declBit  (c+60,"io_intr_ovf",-1);
	vcdp->declBit  (c+47,"TimerHarness clock",-1);
	vcdp->declBit  (c+48,"TimerHarness reset",-1);
	vcdp->declBit  (c+49,"TimerHarness io_req_ready",-1);
	vcdp->declBit  (c+50,"TimerHarness io_req_valid",-1);
	vcdp->declBus  (c+51,"TimerHarness io_req_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+52,"TimerHarness io_req_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+53,"TimerHarness io_req_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+54,"TimerHarness io_req_bits_isWrite",-1);
	vcdp->declBit  (c+55,"TimerHarness io_rsp_ready",-1);
	vcdp->declBit  (c+56,"TimerHarness io_rsp_valid",-1);
	vcdp->declBus  (c+57,"TimerHarness io_rsp_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+58,"TimerHarness io_rsp_bits_error",-1);
	vcdp->declBit  (c+59,"TimerHarness io_intr_cmp",-1);
	vcdp->declBit  (c+60,"TimerHarness io_intr_ovf",-1);
	vcdp->declBit  (c+47,"TimerHarness hostAdapter_clock",-1);
	vcdp->declBit  (c+48,"TimerHarness hostAdapter_reset",-1);
	vcdp->declBit  (c+61,"TimerHarness hostAdapter_io_wbMasterTransmitter_ready",-1);
	vcdp->declBit  (c+1,"TimerHarness hostAdapter_io_wbMasterTransmitter_valid",-1);
	vcdp->declBit  (c+2,"TimerHarness hostAdapter_io_wbMasterTransmitter_bits_cyc",-1);
	vcdp->declBit  (c+1,"TimerHarness hostAdapter_io_wbMasterTransmitter_bits_stb",-1);
	vcdp->declBit  (c+3,"TimerHarness hostAdapter_io_wbMasterTransmitter_bits_we",-1);
	vcdp->declBus  (c+4,"TimerHarness hostAdapter_io_wbMasterTransmitter_bits_adr",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness hostAdapter_io_wbMasterTransmitter_bits_dat",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness hostAdapter_io_wbMasterTransmitter_bits_sel",-1,3,0);
	vcdp->declBit  (c+61,"TimerHarness hostAdapter_io_wbSlaveReceiver_ready",-1);
	vcdp->declBit  (c+15,"TimerHarness hostAdapter_io_wbSlaveReceiver_bits_ack",-1);
	vcdp->declBus  (c+7,"TimerHarness hostAdapter_io_wbSlaveReceiver_bits_dat",-1,31,0);
	vcdp->declBit  (c+16,"TimerHarness hostAdapter_io_wbSlaveReceiver_bits_err",-1);
	vcdp->declBit  (c+19,"TimerHarness hostAdapter_io_reqIn_ready",-1);
	vcdp->declBit  (c+50,"TimerHarness hostAdapter_io_reqIn_valid",-1);
	vcdp->declBus  (c+51,"TimerHarness hostAdapter_io_reqIn_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+52,"TimerHarness hostAdapter_io_reqIn_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+53,"TimerHarness hostAdapter_io_reqIn_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+54,"TimerHarness hostAdapter_io_reqIn_bits_isWrite",-1);
	vcdp->declBit  (c+20,"TimerHarness hostAdapter_io_rspOut_valid",-1);
	vcdp->declBus  (c+21,"TimerHarness hostAdapter_io_rspOut_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+22,"TimerHarness hostAdapter_io_rspOut_bits_error",-1);
	vcdp->declBit  (c+61,"TimerHarness deviceAdapter_io_wbSlaveTransmitter_ready",-1);
	vcdp->declBit  (c+15,"TimerHarness deviceAdapter_io_wbSlaveTransmitter_bits_ack",-1);
	vcdp->declBus  (c+7,"TimerHarness deviceAdapter_io_wbSlaveTransmitter_bits_dat",-1,31,0);
	vcdp->declBit  (c+16,"TimerHarness deviceAdapter_io_wbSlaveTransmitter_bits_err",-1);
	vcdp->declBit  (c+61,"TimerHarness deviceAdapter_io_wbMasterReceiver_ready",-1);
	vcdp->declBit  (c+1,"TimerHarness deviceAdapter_io_wbMasterReceiver_valid",-1);
	vcdp->declBit  (c+2,"TimerHarness deviceAdapter_io_wbMasterReceiver_bits_cyc",-1);
	vcdp->declBit  (c+1,"TimerHarness deviceAdapter_io_wbMasterReceiver_bits_stb",-1);
	vcdp->declBit  (c+3,"TimerHarness deviceAdapter_io_wbMasterReceiver_bits_we",-1);
	vcdp->declBus  (c+4,"TimerHarness deviceAdapter_io_wbMasterReceiver_bits_adr",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness deviceAdapter_io_wbMasterReceiver_bits_dat",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness deviceAdapter_io_wbMasterReceiver_bits_sel",-1,3,0);
	vcdp->declBit  (c+17,"TimerHarness deviceAdapter_io_reqOut_valid",-1);
	vcdp->declBus  (c+4,"TimerHarness deviceAdapter_io_reqOut_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness deviceAdapter_io_reqOut_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness deviceAdapter_io_reqOut_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+3,"TimerHarness deviceAdapter_io_reqOut_bits_isWrite",-1);
	vcdp->declBit  (c+8,"TimerHarness deviceAdapter_io_rspIn_valid",-1);
	vcdp->declBus  (c+7,"TimerHarness deviceAdapter_io_rspIn_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+18,"TimerHarness deviceAdapter_io_rspIn_bits_error",-1);
	vcdp->declBit  (c+47,"TimerHarness timer_clock",-1);
	vcdp->declBit  (c+48,"TimerHarness timer_reset",-1);
	vcdp->declBit  (c+17,"TimerHarness timer_io_req_valid",-1);
	vcdp->declBus  (c+4,"TimerHarness timer_io_req_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness timer_io_req_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness timer_io_req_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+3,"TimerHarness timer_io_req_bits_isWrite",-1);
	vcdp->declBit  (c+8,"TimerHarness timer_io_rsp_valid",-1);
	vcdp->declBus  (c+7,"TimerHarness timer_io_rsp_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+18,"TimerHarness timer_io_rsp_bits_error",-1);
	vcdp->declBit  (c+23,"TimerHarness timer_io_intr_cmp",-1);
	vcdp->declBit  (c+24,"TimerHarness timer_io_intr_ovf",-1);
	vcdp->declBit  (c+47,"TimerHarness hostAdapter clock",-1);
	vcdp->declBit  (c+48,"TimerHarness hostAdapter reset",-1);
	vcdp->declBit  (c+61,"TimerHarness hostAdapter io_wbMasterTransmitter_ready",-1);
	vcdp->declBit  (c+1,"TimerHarness hostAdapter io_wbMasterTransmitter_valid",-1);
	vcdp->declBit  (c+2,"TimerHarness hostAdapter io_wbMasterTransmitter_bits_cyc",-1);
	vcdp->declBit  (c+1,"TimerHarness hostAdapter io_wbMasterTransmitter_bits_stb",-1);
	vcdp->declBit  (c+3,"TimerHarness hostAdapter io_wbMasterTransmitter_bits_we",-1);
	vcdp->declBus  (c+4,"TimerHarness hostAdapter io_wbMasterTransmitter_bits_adr",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness hostAdapter io_wbMasterTransmitter_bits_dat",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness hostAdapter io_wbMasterTransmitter_bits_sel",-1,3,0);
	vcdp->declBit  (c+61,"TimerHarness hostAdapter io_wbSlaveReceiver_ready",-1);
	vcdp->declBit  (c+15,"TimerHarness hostAdapter io_wbSlaveReceiver_bits_ack",-1);
	vcdp->declBus  (c+7,"TimerHarness hostAdapter io_wbSlaveReceiver_bits_dat",-1,31,0);
	vcdp->declBit  (c+16,"TimerHarness hostAdapter io_wbSlaveReceiver_bits_err",-1);
	vcdp->declBit  (c+19,"TimerHarness hostAdapter io_reqIn_ready",-1);
	vcdp->declBit  (c+50,"TimerHarness hostAdapter io_reqIn_valid",-1);
	vcdp->declBus  (c+51,"TimerHarness hostAdapter io_reqIn_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+52,"TimerHarness hostAdapter io_reqIn_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+53,"TimerHarness hostAdapter io_reqIn_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+54,"TimerHarness hostAdapter io_reqIn_bits_isWrite",-1);
	vcdp->declBit  (c+20,"TimerHarness hostAdapter io_rspOut_valid",-1);
	vcdp->declBus  (c+21,"TimerHarness hostAdapter io_rspOut_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+22,"TimerHarness hostAdapter io_rspOut_bits_error",-1);
	vcdp->declBit  (c+25,"TimerHarness hostAdapter startWBTransaction",-1);
	vcdp->declBus  (c+21,"TimerHarness hostAdapter dataReg",-1,31,0);
	vcdp->declBit  (c+20,"TimerHarness hostAdapter respReg",-1);
	vcdp->declBit  (c+22,"TimerHarness hostAdapter errReg",-1);
	vcdp->declBit  (c+26,"TimerHarness hostAdapter stbReg",-1);
	vcdp->declBit  (c+27,"TimerHarness hostAdapter cycReg",-1);
	vcdp->declBit  (c+28,"TimerHarness hostAdapter weReg",-1);
	vcdp->declBus  (c+29,"TimerHarness hostAdapter datReg",-1,31,0);
	vcdp->declBus  (c+30,"TimerHarness hostAdapter adrReg",-1,31,0);
	vcdp->declBus  (c+31,"TimerHarness hostAdapter selReg",-1,3,0);
	vcdp->declBit  (c+32,"TimerHarness hostAdapter stateReg",-1);
	vcdp->declBit  (c+19,"TimerHarness hostAdapter readyReg",-1);
	// Tracing: TimerHarness hostAdapter _T_2 // Ignored: Inlined leading underscore at TimerHarness.v:52
	// Tracing: TimerHarness hostAdapter _GEN_0 // Ignored: Inlined leading underscore at TimerHarness.v:53
	// Tracing: TimerHarness hostAdapter _GEN_1 // Ignored: Inlined leading underscore at TimerHarness.v:54
	// Tracing: TimerHarness hostAdapter _GEN_2 // Ignored: Inlined leading underscore at TimerHarness.v:55
	// Tracing: TimerHarness hostAdapter _GEN_3 // Ignored: Inlined leading underscore at TimerHarness.v:56
	// Tracing: TimerHarness hostAdapter _GEN_4 // Ignored: Inlined leading underscore at TimerHarness.v:57
	// Tracing: TimerHarness hostAdapter _GEN_9 // Ignored: Inlined leading underscore at TimerHarness.v:58
	// Tracing: TimerHarness hostAdapter _GEN_10 // Ignored: Inlined leading underscore at TimerHarness.v:59
	// Tracing: TimerHarness hostAdapter _GEN_11 // Ignored: Inlined leading underscore at TimerHarness.v:60
	// Tracing: TimerHarness hostAdapter _GEN_23 // Ignored: Inlined leading underscore at TimerHarness.v:61
	// Tracing: TimerHarness hostAdapter _GEN_24 // Ignored: Inlined leading underscore at TimerHarness.v:62
	// Tracing: TimerHarness hostAdapter _GEN_27 // Ignored: Inlined leading underscore at TimerHarness.v:63
	vcdp->declBit  (c+61,"TimerHarness deviceAdapter io_wbSlaveTransmitter_ready",-1);
	vcdp->declBit  (c+15,"TimerHarness deviceAdapter io_wbSlaveTransmitter_bits_ack",-1);
	vcdp->declBus  (c+7,"TimerHarness deviceAdapter io_wbSlaveTransmitter_bits_dat",-1,31,0);
	vcdp->declBit  (c+16,"TimerHarness deviceAdapter io_wbSlaveTransmitter_bits_err",-1);
	vcdp->declBit  (c+61,"TimerHarness deviceAdapter io_wbMasterReceiver_ready",-1);
	vcdp->declBit  (c+1,"TimerHarness deviceAdapter io_wbMasterReceiver_valid",-1);
	vcdp->declBit  (c+2,"TimerHarness deviceAdapter io_wbMasterReceiver_bits_cyc",-1);
	vcdp->declBit  (c+1,"TimerHarness deviceAdapter io_wbMasterReceiver_bits_stb",-1);
	vcdp->declBit  (c+3,"TimerHarness deviceAdapter io_wbMasterReceiver_bits_we",-1);
	vcdp->declBus  (c+4,"TimerHarness deviceAdapter io_wbMasterReceiver_bits_adr",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness deviceAdapter io_wbMasterReceiver_bits_dat",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness deviceAdapter io_wbMasterReceiver_bits_sel",-1,3,0);
	vcdp->declBit  (c+17,"TimerHarness deviceAdapter io_reqOut_valid",-1);
	vcdp->declBus  (c+4,"TimerHarness deviceAdapter io_reqOut_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness deviceAdapter io_reqOut_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness deviceAdapter io_reqOut_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+3,"TimerHarness deviceAdapter io_reqOut_bits_isWrite",-1);
	vcdp->declBit  (c+8,"TimerHarness deviceAdapter io_rspIn_valid",-1);
	vcdp->declBus  (c+7,"TimerHarness deviceAdapter io_rspIn_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+18,"TimerHarness deviceAdapter io_rspIn_bits_error",-1);
	// Tracing: TimerHarness deviceAdapter _T_1 // Ignored: Inlined leading underscore at TimerHarness.v:246
	// Tracing: TimerHarness deviceAdapter _T_4 // Ignored: Inlined leading underscore at TimerHarness.v:247
	// Tracing: TimerHarness deviceAdapter _T_5 // Ignored: Inlined leading underscore at TimerHarness.v:248
	// Tracing: TimerHarness deviceAdapter _GEN_5 // Ignored: Inlined leading underscore at TimerHarness.v:249
	// Tracing: TimerHarness deviceAdapter _GEN_18 // Ignored: Inlined leading underscore at TimerHarness.v:250
	// Tracing: TimerHarness deviceAdapter _GEN_19 // Ignored: Inlined leading underscore at TimerHarness.v:251
	vcdp->declBit  (c+47,"TimerHarness timer clock",-1);
	vcdp->declBit  (c+48,"TimerHarness timer reset",-1);
	vcdp->declBit  (c+17,"TimerHarness timer io_req_valid",-1);
	vcdp->declBus  (c+4,"TimerHarness timer io_req_bits_addrRequest",-1,31,0);
	vcdp->declBus  (c+5,"TimerHarness timer io_req_bits_dataRequest",-1,31,0);
	vcdp->declBus  (c+6,"TimerHarness timer io_req_bits_activeByteLane",-1,3,0);
	vcdp->declBit  (c+3,"TimerHarness timer io_req_bits_isWrite",-1);
	vcdp->declBit  (c+8,"TimerHarness timer io_rsp_valid",-1);
	vcdp->declBus  (c+7,"TimerHarness timer io_rsp_bits_dataResponse",-1,31,0);
	vcdp->declBit  (c+18,"TimerHarness timer io_rsp_bits_error",-1);
	vcdp->declBit  (c+23,"TimerHarness timer io_intr_cmp",-1);
	vcdp->declBit  (c+24,"TimerHarness timer io_intr_ovf",-1);
	vcdp->declBus  (c+33,"TimerHarness timer TimerReg",-1,31,0);
	vcdp->declBus  (c+34,"TimerHarness timer ControlReg",-1,31,0);
	vcdp->declBus  (c+35,"TimerHarness timer CompareReg",-1,31,0);
	vcdp->declBus  (c+36,"TimerHarness timer PreCountReg",-1,31,0);
	vcdp->declBus  (c+9,"TimerHarness timer maskedData_0",-1,7,0);
	vcdp->declBus  (c+10,"TimerHarness timer maskedData_1",-1,7,0);
	vcdp->declBus  (c+11,"TimerHarness timer maskedData_2",-1,7,0);
	vcdp->declBus  (c+12,"TimerHarness timer maskedData_3",-1,7,0);
	// Tracing: TimerHarness timer _T_13 // Ignored: Inlined leading underscore at TimerHarness.v:306
	// Tracing: TimerHarness timer _T_14 // Ignored: Inlined leading underscore at TimerHarness.v:307
	vcdp->declBus  (c+37,"TimerHarness timer io_rsp_bits_dataResponse_REG",-1,31,0);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_valid_REG",-1);
	// Tracing: TimerHarness timer _T_17 // Ignored: Inlined leading underscore at TimerHarness.v:310
	// Tracing: TimerHarness timer _ControlReg_T // Ignored: Inlined leading underscore at TimerHarness.v:311
	// Tracing: TimerHarness timer _ControlReg_T_1 // Ignored: Inlined leading underscore at TimerHarness.v:312
	vcdp->declBus  (c+39,"TimerHarness timer io_rsp_bits_dataResponse_REG_1",-1,31,0);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_valid_REG_1",-1);
	vcdp->declBus  (c+40,"TimerHarness timer io_rsp_bits_dataResponse_REG_2",-1,31,0);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_valid_REG_2",-1);
	// Tracing: TimerHarness timer _T_25 // Ignored: Inlined leading underscore at TimerHarness.v:317
	// Tracing: TimerHarness timer _CompareReg_T_2 // Ignored: Inlined leading underscore at TimerHarness.v:318
	vcdp->declBus  (c+39,"TimerHarness timer io_rsp_bits_dataResponse_REG_3",-1,31,0);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_valid_REG_3",-1);
	// Tracing: TimerHarness timer _T_31 // Ignored: Inlined leading underscore at TimerHarness.v:321
	vcdp->declBus  (c+41,"TimerHarness timer io_rsp_bits_dataResponse_REG_4",-1,31,0);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_valid_REG_4",-1);
	vcdp->declBus  (c+42,"TimerHarness timer io_rsp_bits_dataResponse_REG_5",-1,31,0);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_valid_REG_5",-1);
	vcdp->declBus  (c+43,"TimerHarness timer io_rsp_bits_dataResponse_REG_6",-1,31,0);
	// Tracing: TimerHarness timer _GEN_0 // Ignored: Inlined leading underscore at TimerHarness.v:327
	// Tracing: TimerHarness timer _GEN_2 // Ignored: Inlined leading underscore at TimerHarness.v:328
	// Tracing: TimerHarness timer _GEN_3 // Ignored: Inlined leading underscore at TimerHarness.v:329
	// Tracing: TimerHarness timer _GEN_4 // Ignored: Inlined leading underscore at TimerHarness.v:330
	// Tracing: TimerHarness timer _GEN_5 // Ignored: Inlined leading underscore at TimerHarness.v:331
	// Tracing: TimerHarness timer _GEN_6 // Ignored: Inlined leading underscore at TimerHarness.v:333
	// Tracing: TimerHarness timer _GEN_7 // Ignored: Inlined leading underscore at TimerHarness.v:334
	// Tracing: TimerHarness timer _GEN_8 // Ignored: Inlined leading underscore at TimerHarness.v:335
	// Tracing: TimerHarness timer _GEN_11 // Ignored: Inlined leading underscore at TimerHarness.v:336
	// Tracing: TimerHarness timer _GEN_12 // Ignored: Inlined leading underscore at TimerHarness.v:338
	vcdp->declBit  (c+44,"TimerHarness timer enable",-1);
	vcdp->declBus  (c+45,"TimerHarness timer prescalar",-1,30,0);
	// Tracing: TimerHarness timer _PreCountReg_T_1 // Ignored: Inlined leading underscore at TimerHarness.v:341
	// Tracing: TimerHarness timer _T_38 // Ignored: Inlined leading underscore at TimerHarness.v:342
	// Tracing: TimerHarness timer _GEN_26 // Ignored: Inlined leading underscore at TimerHarness.v:343
	// Tracing: TimerHarness timer _TimerReg_T_1 // Ignored: Inlined leading underscore at TimerHarness.v:344
	vcdp->declBit  (c+13,"TimerHarness timer addr_hit_3",-1);
	vcdp->declBit  (c+14,"TimerHarness timer addr_miss",-1);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_bits_error_REG",-1);
	vcdp->declBit  (c+38,"TimerHarness timer io_rsp_bits_error_REG_1",-1);
	vcdp->declBit  (c+46,"TimerHarness timer io_rsp_bits_error_REG_2",-1);
	// Tracing: TimerHarness timer _GEN_24 // Ignored: Inlined leading underscore at TimerHarness.v:350
    }
}

void VTimerHarness::traceFullThis__1(VTimerHarness__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTimerHarness* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_stb));
	vcdp->fullBit  (c+2,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_cyc));
	vcdp->fullBit  (c+3,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we));
	vcdp->fullBus  (c+4,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr),32);
	vcdp->fullBus  (c+5,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_dat),32);
	vcdp->fullBus  (c+6,(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel),4);
	vcdp->fullBus  (c+7,((((0U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
			       & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
			       ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG
			       : (((4U == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
				   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
				   ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
				   : (((4U == (0xfU 
					       & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
				       & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
				       ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2
				       : (((8U == (0xfU 
						   & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					   & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we))
					   ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1
					   : (((8U 
						== 
						(0xfU 
						 & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					       & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
					       ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4
					       : ((
						   (8U 
						    == 
						    (0xfU 
						     & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
						   & (~ (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_we)))
						   ? vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5
						   : vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_6))))))),32);
	vcdp->fullBit  (c+8,(vlTOPp->TimerHarness__DOT__timer_io_rsp_valid));
	vcdp->fullBus  (c+9,(((1U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			       ? 0xffU : 0U)),8);
	vcdp->fullBus  (c+10,(((2U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			        ? 0xffU : 0U)),8);
	vcdp->fullBus  (c+11,(((4U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			        ? 0xffU : 0U)),8);
	vcdp->fullBus  (c+12,(((8U & (IData)(vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_sel))
			        ? 0xffU : 0U)),8);
	vcdp->fullBit  (c+13,((0xcU == (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr))));
	vcdp->fullBit  (c+14,((1U & (~ ((((0U == (0xfU 
						  & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)) 
					  | (4U == 
					     (0xfU 
					      & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr))) 
					 | (8U == (0xfU 
						   & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr))) 
					| (0xcU == 
					   (0xfU & vlTOPp->TimerHarness__DOT__hostAdapter_io_wbMasterTransmitter_bits_adr)))))));
	vcdp->fullBit  (c+15,(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_ack));
	vcdp->fullBit  (c+16,(vlTOPp->TimerHarness__DOT__deviceAdapter_io_wbSlaveTransmitter_bits_err));
	vcdp->fullBit  (c+17,(vlTOPp->TimerHarness__DOT__deviceAdapter_io_reqOut_valid));
	vcdp->fullBit  (c+18,(vlTOPp->TimerHarness__DOT__timer_io_rsp_bits_error));
	vcdp->fullBit  (c+19,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__readyReg));
	vcdp->fullBit  (c+20,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__respReg));
	vcdp->fullBus  (c+21,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__dataReg),32);
	vcdp->fullBit  (c+22,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__errReg));
	vcdp->fullBit  (c+23,((vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg 
			       & (vlTOPp->TimerHarness__DOT__timer__DOT__TimerReg 
				  == vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg))));
	vcdp->fullBit  (c+24,((vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg 
			       & (0xffffffffU == vlTOPp->TimerHarness__DOT__timer__DOT__TimerReg))));
	vcdp->fullBit  (c+25,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__startWBTransaction));
	vcdp->fullBit  (c+26,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stbReg));
	vcdp->fullBit  (c+27,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__cycReg));
	vcdp->fullBit  (c+28,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__weReg));
	vcdp->fullBus  (c+29,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__datReg),32);
	vcdp->fullBus  (c+30,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__adrReg),32);
	vcdp->fullBus  (c+31,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__selReg),4);
	vcdp->fullBit  (c+32,(vlTOPp->TimerHarness__DOT__hostAdapter__DOT__stateReg));
	vcdp->fullBus  (c+33,(vlTOPp->TimerHarness__DOT__timer__DOT__TimerReg),32);
	vcdp->fullBus  (c+34,(vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg),32);
	vcdp->fullBus  (c+35,(vlTOPp->TimerHarness__DOT__timer__DOT__CompareReg),32);
	vcdp->fullBus  (c+36,(vlTOPp->TimerHarness__DOT__timer__DOT__PreCountReg),32);
	vcdp->fullBus  (c+37,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG),32);
	vcdp->fullBit  (c+38,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_valid_REG));
	vcdp->fullBus  (c+39,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_1),32);
	vcdp->fullBus  (c+40,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_2),32);
	vcdp->fullBus  (c+41,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_4),32);
	vcdp->fullBus  (c+42,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_5),32);
	vcdp->fullBus  (c+43,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_dataResponse_REG_6),32);
	vcdp->fullBit  (c+44,((1U & vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg)));
	vcdp->fullBus  (c+45,((0x7fffffffU & (vlTOPp->TimerHarness__DOT__timer__DOT__ControlReg 
					      >> 1U))),31);
	vcdp->fullBit  (c+46,(vlTOPp->TimerHarness__DOT__timer__DOT__io_rsp_bits_error_REG_2));
	vcdp->fullBit  (c+47,(vlTOPp->clock));
	vcdp->fullBit  (c+48,(vlTOPp->reset));
	vcdp->fullBit  (c+49,(vlTOPp->io_req_ready));
	vcdp->fullBit  (c+50,(vlTOPp->io_req_valid));
	vcdp->fullBus  (c+51,(vlTOPp->io_req_bits_addrRequest),32);
	vcdp->fullBus  (c+52,(vlTOPp->io_req_bits_dataRequest),32);
	vcdp->fullBus  (c+53,(vlTOPp->io_req_bits_activeByteLane),4);
	vcdp->fullBit  (c+54,(vlTOPp->io_req_bits_isWrite));
	vcdp->fullBit  (c+55,(vlTOPp->io_rsp_ready));
	vcdp->fullBit  (c+56,(vlTOPp->io_rsp_valid));
	vcdp->fullBus  (c+57,(vlTOPp->io_rsp_bits_dataResponse),32);
	vcdp->fullBit  (c+58,(vlTOPp->io_rsp_bits_error));
	vcdp->fullBit  (c+59,(vlTOPp->io_intr_cmp));
	vcdp->fullBit  (c+60,(vlTOPp->io_intr_ovf));
	vcdp->fullBit  (c+61,(1U));
    }
}
