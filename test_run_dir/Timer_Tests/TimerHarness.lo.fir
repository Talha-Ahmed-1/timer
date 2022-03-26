circuit TimerHarness :
  module WishboneHost :
    input clock : Clock
    input reset : UInt<1>
    input io_wbMasterTransmitter_ready : UInt<1>
    output io_wbMasterTransmitter_valid : UInt<1>
    output io_wbMasterTransmitter_bits_cyc : UInt<1>
    output io_wbMasterTransmitter_bits_stb : UInt<1>
    output io_wbMasterTransmitter_bits_we : UInt<1>
    output io_wbMasterTransmitter_bits_adr : UInt<32>
    output io_wbMasterTransmitter_bits_dat : UInt<32>
    output io_wbMasterTransmitter_bits_sel : UInt<4>
    output io_wbSlaveReceiver_ready : UInt<1>
    input io_wbSlaveReceiver_valid : UInt<1>
    input io_wbSlaveReceiver_bits_ack : UInt<1>
    input io_wbSlaveReceiver_bits_dat : UInt<32>
    input io_wbSlaveReceiver_bits_err : UInt<1>
    output io_reqIn_ready : UInt<1>
    input io_reqIn_valid : UInt<1>
    input io_reqIn_bits_addrRequest : UInt<32>
    input io_reqIn_bits_dataRequest : UInt<32>
    input io_reqIn_bits_activeByteLane : UInt<4>
    input io_reqIn_bits_isWrite : UInt<1>
    input io_rspOut_ready : UInt<1>
    output io_rspOut_valid : UInt<1>
    output io_rspOut_bits_dataResponse : UInt<32>
    output io_rspOut_bits_error : UInt<1>

    node _T = asUInt(reset) @[WishboneHost.scala 30:20]
    node _T_1 = eq(_T, UInt<1>("h1")) @[WishboneHost.scala 30:23]
    reg startWBTransaction : UInt<1>, clock with :
      reset => (UInt<1>("h0"), startWBTransaction) @[WishboneHost.scala 39:35]
    reg dataReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), dataReg) @[WishboneHost.scala 41:24]
    reg respReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), respReg) @[WishboneHost.scala 42:24]
    reg errReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), errReg) @[WishboneHost.scala 43:23]
    reg stbReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), stbReg) @[WishboneHost.scala 45:23]
    reg cycReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), cycReg) @[WishboneHost.scala 46:23]
    reg weReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), weReg) @[WishboneHost.scala 47:22]
    reg datReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), datReg) @[WishboneHost.scala 48:23]
    reg adrReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), adrReg) @[WishboneHost.scala 49:23]
    reg selReg : UInt<4>, clock with :
      reset => (UInt<1>("h0"), selReg) @[WishboneHost.scala 50:23]
    reg stateReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), stateReg) @[WishboneHost.scala 55:25]
    reg readyReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), readyReg) @[WishboneHost.scala 61:25]
    node _T_2 = and(io_reqIn_valid, io_wbMasterTransmitter_ready) @[WishboneHost.scala 18:37]
    node _GEN_0 = mux(_T_2, UInt<1>("h0"), readyReg) @[WishboneHost.scala 62:14 WishboneHost.scala 63:14 WishboneHost.scala 61:25]
    node _T_3 = eq(stateReg, UInt<1>("h1")) @[WishboneHost.scala 65:17]
    node _GEN_1 = mux(_T_3, UInt<1>("h1"), _GEN_0) @[WishboneHost.scala 65:33 WishboneHost.scala 66:14]
    node _T_4 = eq(io_reqIn_bits_isWrite, UInt<1>("h0")) @[WishboneHost.scala 76:32]
    node _T_5 = eq(readyReg, UInt<1>("h1")) @[WishboneHost.scala 76:56]
    node _T_6 = and(_T_4, _T_5) @[WishboneHost.scala 76:44]
    node _T_7 = and(_T_6, io_reqIn_valid) @[WishboneHost.scala 76:67]
    node _T_8 = eq(io_reqIn_bits_isWrite, UInt<1>("h1")) @[WishboneHost.scala 84:39]
    node _T_9 = eq(readyReg, UInt<1>("h1")) @[WishboneHost.scala 84:62]
    node _T_10 = and(_T_8, _T_9) @[WishboneHost.scala 84:50]
    node _T_11 = and(_T_10, io_reqIn_valid) @[WishboneHost.scala 84:73]
    node _GEN_2 = mux(_T_11, UInt<1>("h1"), startWBTransaction) @[WishboneHost.scala 84:92 WishboneHost.scala 85:26 WishboneHost.scala 39:35]
    node _GEN_3 = mux(_T_11, UInt<1>("h1"), stbReg) @[WishboneHost.scala 84:92 WishboneHost.scala 86:14 WishboneHost.scala 45:23]
    node _GEN_4 = mux(_T_11, UInt<1>("h1"), cycReg) @[WishboneHost.scala 84:92 WishboneHost.scala 87:14 WishboneHost.scala 46:23]
    node _GEN_5 = mux(_T_11, io_reqIn_bits_isWrite, weReg) @[WishboneHost.scala 84:92 WishboneHost.scala 88:13 WishboneHost.scala 47:22]
    node _GEN_6 = mux(_T_11, io_reqIn_bits_addrRequest, adrReg) @[WishboneHost.scala 84:92 WishboneHost.scala 89:14 WishboneHost.scala 49:23]
    node _GEN_7 = mux(_T_11, io_reqIn_bits_dataRequest, datReg) @[WishboneHost.scala 84:92 WishboneHost.scala 90:14 WishboneHost.scala 48:23]
    node _GEN_8 = mux(_T_11, io_reqIn_bits_activeByteLane, selReg) @[WishboneHost.scala 84:92 WishboneHost.scala 91:14 WishboneHost.scala 50:23]
    node _GEN_9 = mux(_T_7, UInt<1>("h1"), _GEN_2) @[WishboneHost.scala 76:86 WishboneHost.scala 77:26]
    node _GEN_10 = mux(_T_7, UInt<1>("h1"), _GEN_3) @[WishboneHost.scala 76:86 WishboneHost.scala 78:14]
    node _GEN_11 = mux(_T_7, UInt<1>("h1"), _GEN_4) @[WishboneHost.scala 76:86 WishboneHost.scala 79:14]
    node _GEN_12 = mux(_T_7, io_reqIn_bits_isWrite, _GEN_5) @[WishboneHost.scala 76:86 WishboneHost.scala 80:13]
    node _GEN_13 = mux(_T_7, io_reqIn_bits_addrRequest, _GEN_6) @[WishboneHost.scala 76:86 WishboneHost.scala 81:14]
    node _GEN_14 = mux(_T_7, UInt<1>("h0"), _GEN_7) @[WishboneHost.scala 76:86 WishboneHost.scala 82:14]
    node _GEN_15 = mux(_T_7, io_reqIn_bits_activeByteLane, _GEN_8) @[WishboneHost.scala 76:86 WishboneHost.scala 83:14]
    node _T_12 = eq(startWBTransaction, UInt<1>("h0")) @[WishboneHost.scala 101:10]
    node _GEN_16 = mux(_T_12, UInt<1>("h0"), selReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 99:37]
    node _GEN_17 = mux(_T_12, UInt<1>("h0"), datReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 98:37]
    node _GEN_18 = mux(_T_12, UInt<1>("h0"), adrReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 97:37]
    node _GEN_19 = mux(_T_12, UInt<1>("h0"), weReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 96:36]
    node _GEN_20 = mux(_T_12, UInt<1>("h0"), stbReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 94:37]
    node _GEN_21 = mux(_T_12, UInt<1>("h0"), cycReg) @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 95:37]
    node _T_13 = eq(io_wbSlaveReceiver_bits_err, UInt<1>("h0")) @[WishboneHost.scala 105:41]
    node _T_14 = and(io_wbSlaveReceiver_bits_ack, _T_13) @[WishboneHost.scala 105:38]
    node _T_15 = eq(io_wbSlaveReceiver_bits_ack, UInt<1>("h0")) @[WishboneHost.scala 111:48]
    node _T_16 = and(io_wbSlaveReceiver_bits_err, _T_15) @[WishboneHost.scala 111:45]
    node _GEN_22 = mux(_T_16, io_wbSlaveReceiver_bits_dat, dataReg) @[WishboneHost.scala 111:78 WishboneHost.scala 112:15 WishboneHost.scala 41:24]
    node _GEN_23 = mux(_T_16, UInt<1>("h1"), respReg) @[WishboneHost.scala 111:78 WishboneHost.scala 113:15 WishboneHost.scala 42:24]
    node _GEN_24 = mux(_T_16, UInt<1>("h1"), errReg) @[WishboneHost.scala 111:78 WishboneHost.scala 114:14 WishboneHost.scala 43:23]
    node _GEN_25 = mux(_T_16, UInt<1>("h0"), _GEN_9) @[WishboneHost.scala 111:78 WishboneHost.scala 115:26]
    node _GEN_26 = mux(_T_14, io_wbSlaveReceiver_bits_dat, _GEN_22) @[WishboneHost.scala 105:71 WishboneHost.scala 106:15]
    node _GEN_27 = mux(_T_14, UInt<1>("h1"), _GEN_23) @[WishboneHost.scala 105:71 WishboneHost.scala 107:15]
    node _GEN_28 = mux(_T_14, UInt<1>("h0"), _GEN_24) @[WishboneHost.scala 105:71 WishboneHost.scala 108:14]
    node _GEN_29 = mux(_T_14, UInt<1>("h0"), _GEN_25) @[WishboneHost.scala 105:71 WishboneHost.scala 110:26]
    node _T_17 = eq(stateReg, UInt<1>("h0")) @[WishboneHost.scala 118:19]
    node _stateReg_T = or(io_wbSlaveReceiver_bits_ack, io_wbSlaveReceiver_bits_err) @[WishboneHost.scala 119:51]
    node _stateReg_T_1 = mux(_stateReg_T, UInt<1>("h1"), UInt<1>("h0")) @[WishboneHost.scala 119:22]
    node _T_18 = eq(stateReg, UInt<1>("h1")) @[WishboneHost.scala 120:26]
    node _GEN_30 = mux(_T_18, UInt<1>("h0"), _GEN_27) @[WishboneHost.scala 120:42 WishboneHost.scala 121:15]
    node _GEN_31 = mux(_T_18, UInt<1>("h0"), stateReg) @[WishboneHost.scala 120:42 WishboneHost.scala 122:16 WishboneHost.scala 55:25]
    node _GEN_32 = mux(_T_17, _stateReg_T_1, _GEN_31) @[WishboneHost.scala 118:29 WishboneHost.scala 119:16]
    node _GEN_33 = mux(_T_17, _GEN_27, _GEN_30) @[WishboneHost.scala 118:29]
    io_wbMasterTransmitter_valid <= io_wbMasterTransmitter_bits_stb @[WishboneHost.scala 23:32]
    io_wbMasterTransmitter_bits_cyc <= _GEN_21
    io_wbMasterTransmitter_bits_stb <= _GEN_20
    io_wbMasterTransmitter_bits_we <= _GEN_19
    io_wbMasterTransmitter_bits_adr <= _GEN_18
    io_wbMasterTransmitter_bits_dat <= _GEN_17
    io_wbMasterTransmitter_bits_sel <= _GEN_16
    io_wbSlaveReceiver_ready <= UInt<1>("h1") @[WishboneHost.scala 26:28]
    io_reqIn_ready <= readyReg @[WishboneHost.scala 75:20]
    io_rspOut_valid <= respReg @[WishboneHost.scala 127:21]
    io_rspOut_bits_dataResponse <= dataReg @[WishboneHost.scala 128:33]
    io_rspOut_bits_error <= errReg @[WishboneHost.scala 129:26]
    startWBTransaction <= mux(reset, UInt<1>("h0"), _GEN_29) @[WishboneHost.scala 39:35 WishboneHost.scala 39:35]
    dataReg <= mux(reset, UInt<32>("h0"), _GEN_26) @[WishboneHost.scala 41:24 WishboneHost.scala 41:24]
    respReg <= mux(reset, UInt<1>("h0"), _GEN_33) @[WishboneHost.scala 42:24 WishboneHost.scala 42:24]
    errReg <= mux(reset, UInt<1>("h0"), _GEN_28) @[WishboneHost.scala 43:23 WishboneHost.scala 43:23]
    stbReg <= mux(reset, UInt<1>("h0"), _GEN_10) @[WishboneHost.scala 45:23 WishboneHost.scala 45:23]
    cycReg <= mux(reset, UInt<1>("h0"), _GEN_11) @[WishboneHost.scala 46:23 WishboneHost.scala 46:23]
    weReg <= mux(reset, UInt<1>("h0"), _GEN_12) @[WishboneHost.scala 47:22 WishboneHost.scala 47:22]
    datReg <= mux(reset, UInt<1>("h0"), _GEN_14) @[WishboneHost.scala 48:23 WishboneHost.scala 48:23]
    adrReg <= mux(reset, UInt<1>("h0"), _GEN_13) @[WishboneHost.scala 49:23 WishboneHost.scala 49:23]
    selReg <= mux(reset, UInt<1>("h0"), _GEN_15) @[WishboneHost.scala 50:23 WishboneHost.scala 50:23]
    stateReg <= mux(reset, UInt<1>("h0"), _GEN_32) @[WishboneHost.scala 55:25 WishboneHost.scala 55:25]
    readyReg <= mux(reset, UInt<1>("h1"), _GEN_1) @[WishboneHost.scala 61:25 WishboneHost.scala 61:25]

  module WishboneDevice :
    input clock : Clock
    input reset : UInt<1>
    input io_wbSlaveTransmitter_ready : UInt<1>
    output io_wbSlaveTransmitter_valid : UInt<1>
    output io_wbSlaveTransmitter_bits_ack : UInt<1>
    output io_wbSlaveTransmitter_bits_dat : UInt<32>
    output io_wbSlaveTransmitter_bits_err : UInt<1>
    output io_wbMasterReceiver_ready : UInt<1>
    input io_wbMasterReceiver_valid : UInt<1>
    input io_wbMasterReceiver_bits_cyc : UInt<1>
    input io_wbMasterReceiver_bits_stb : UInt<1>
    input io_wbMasterReceiver_bits_we : UInt<1>
    input io_wbMasterReceiver_bits_adr : UInt<32>
    input io_wbMasterReceiver_bits_dat : UInt<32>
    input io_wbMasterReceiver_bits_sel : UInt<4>
    input io_reqOut_ready : UInt<1>
    output io_reqOut_valid : UInt<1>
    output io_reqOut_bits_addrRequest : UInt<32>
    output io_reqOut_bits_dataRequest : UInt<32>
    output io_reqOut_bits_activeByteLane : UInt<4>
    output io_reqOut_bits_isWrite : UInt<1>
    output io_rspIn_ready : UInt<1>
    input io_rspIn_valid : UInt<1>
    input io_rspIn_bits_dataResponse : UInt<32>
    input io_rspIn_bits_error : UInt<1>

    node _T = and(io_wbMasterReceiver_valid, io_wbMasterReceiver_bits_cyc) @[WishboneDevice.scala 16:48]
    node _T_1 = and(_T, io_wbMasterReceiver_bits_stb) @[WishboneDevice.scala 16:80]
    node _T_2 = eq(io_wbMasterReceiver_bits_we, UInt<1>("h0")) @[WishboneDevice.scala 26:10]
    node _T_3 = eq(io_rspIn_bits_error, UInt<1>("h0")) @[WishboneDevice.scala 36:30]
    node _T_4 = and(io_rspIn_valid, _T_3) @[WishboneDevice.scala 36:27]
    node _T_5 = and(io_rspIn_valid, io_rspIn_bits_error) @[WishboneDevice.scala 42:34]
    node _GEN_0 = mux(_T_5, UInt<1>("h1"), UInt<1>("h0")) @[WishboneDevice.scala 42:58 WishboneDevice.scala 43:37 WishboneDevice.scala 48:37]
    node _GEN_1 = mux(_T_5, UInt<1>("h0"), UInt<1>("h0")) @[WishboneDevice.scala 42:58 WishboneDevice.scala 44:13 WishboneDevice.scala 49:13]
    node _GEN_2 = validif(_T_5, io_rspIn_bits_dataResponse) @[WishboneDevice.scala 42:58 WishboneDevice.scala 46:40]
    node _GEN_3 = mux(_T_4, UInt<1>("h1"), _GEN_0) @[WishboneDevice.scala 36:52 WishboneDevice.scala 38:37]
    node _GEN_4 = mux(_T_4, UInt<1>("h1"), _GEN_1) @[WishboneDevice.scala 36:52 WishboneDevice.scala 39:13]
    node _GEN_5 = mux(_T_4, UInt<1>("h0"), _GEN_0) @[WishboneDevice.scala 36:52 WishboneDevice.scala 40:40]
    node _GEN_6 = mux(_T_4, io_rspIn_bits_dataResponse, _GEN_2) @[WishboneDevice.scala 36:52 WishboneDevice.scala 41:40]
    node _T_6 = eq(io_rspIn_bits_error, UInt<1>("h0")) @[WishboneDevice.scala 60:30]
    node _T_7 = and(io_rspIn_valid, _T_6) @[WishboneDevice.scala 60:27]
    node _T_8 = and(io_rspIn_valid, io_rspIn_bits_error) @[WishboneDevice.scala 65:34]
    node _GEN_7 = mux(_T_8, UInt<1>("h1"), UInt<1>("h0")) @[WishboneDevice.scala 65:58 WishboneDevice.scala 66:37 WishboneDevice.scala 71:37]
    node _GEN_8 = mux(_T_8, UInt<1>("h0"), UInt<1>("h0")) @[WishboneDevice.scala 65:58 WishboneDevice.scala 67:13 WishboneDevice.scala 72:13]
    node _GEN_9 = mux(_T_7, UInt<1>("h1"), _GEN_7) @[WishboneDevice.scala 60:52 WishboneDevice.scala 61:37]
    node _GEN_10 = mux(_T_7, UInt<1>("h1"), _GEN_8) @[WishboneDevice.scala 60:52 WishboneDevice.scala 62:13]
    node _GEN_11 = mux(_T_7, UInt<1>("h0"), _GEN_7) @[WishboneDevice.scala 60:52 WishboneDevice.scala 63:40]
    node _GEN_12 = mux(_T_2, UInt<1>("h1"), UInt<1>("h1")) @[WishboneDevice.scala 26:40 WishboneDevice.scala 31:23 WishboneDevice.scala 55:23]
    node _GEN_13 = mux(_T_2, io_wbMasterReceiver_bits_adr, io_wbMasterReceiver_bits_adr) @[WishboneDevice.scala 26:40 WishboneDevice.scala 32:34 WishboneDevice.scala 56:34]
    node _GEN_14 = validif(eq(_T_2, UInt<1>("h0")), io_wbMasterReceiver_bits_dat) @[WishboneDevice.scala 26:40 WishboneDevice.scala 57:34]
    node _GEN_15 = mux(_T_2, io_wbMasterReceiver_bits_sel, io_wbMasterReceiver_bits_sel) @[WishboneDevice.scala 26:40 WishboneDevice.scala 34:37 WishboneDevice.scala 58:37]
    node _GEN_16 = mux(_T_2, UInt<1>("h0"), io_wbMasterReceiver_bits_we) @[WishboneDevice.scala 26:40 WishboneDevice.scala 35:30 WishboneDevice.scala 59:30]
    node _GEN_17 = mux(_T_2, _GEN_3, _GEN_9) @[WishboneDevice.scala 26:40]
    node _GEN_18 = mux(_T_2, _GEN_4, _GEN_10) @[WishboneDevice.scala 26:40]
    node _GEN_19 = mux(_T_2, _GEN_5, _GEN_11) @[WishboneDevice.scala 26:40]
    node _GEN_20 = validif(_T_2, _GEN_6) @[WishboneDevice.scala 26:40]
    node _GEN_21 = mux(_T_1, _GEN_12, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 81:21]
    node _GEN_22 = validif(_T_1, _GEN_13) @[WishboneDevice.scala 25:16]
    node _GEN_23 = validif(_T_1, _GEN_14) @[WishboneDevice.scala 25:16]
    node _GEN_24 = validif(_T_1, _GEN_15) @[WishboneDevice.scala 25:16]
    node _GEN_25 = validif(_T_1, _GEN_16) @[WishboneDevice.scala 25:16]
    node _GEN_26 = mux(_T_1, _GEN_17, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 87:33]
    node _GEN_27 = mux(_T_1, _GEN_18, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 88:9]
    node _GEN_28 = mux(_T_1, _GEN_19, UInt<1>("h0")) @[WishboneDevice.scala 25:16 WishboneDevice.scala 89:36]
    node _GEN_29 = validif(_T_1, _GEN_20) @[WishboneDevice.scala 25:16]
    node ack = _GEN_27
    io_wbSlaveTransmitter_valid <= _GEN_26
    io_wbSlaveTransmitter_bits_ack <= ack @[WishboneDevice.scala 93:34]
    io_wbSlaveTransmitter_bits_dat <= _GEN_29
    io_wbSlaveTransmitter_bits_err <= _GEN_28
    io_wbMasterReceiver_ready <= UInt<1>("h1") @[WishboneDevice.scala 19:29]
    io_reqOut_valid <= _GEN_21
    io_reqOut_bits_addrRequest <= _GEN_22
    io_reqOut_bits_dataRequest <= _GEN_23
    io_reqOut_bits_activeByteLane <= _GEN_24
    io_reqOut_bits_isWrite <= _GEN_25
    io_rspIn_ready <= UInt<1>("h1") @[WishboneDevice.scala 23:18]

  module Timer :
    input clock : Clock
    input reset : UInt<1>
    output io_req_ready : UInt<1>
    input io_req_valid : UInt<1>
    input io_req_bits_addrRequest : UInt<32>
    input io_req_bits_dataRequest : UInt<32>
    input io_req_bits_activeByteLane : UInt<4>
    input io_req_bits_isWrite : UInt<1>
    input io_rsp_ready : UInt<1>
    output io_rsp_valid : UInt<1>
    output io_rsp_bits_dataResponse : UInt<32>
    output io_rsp_bits_error : UInt<1>
    output io_intr_cmp : UInt<1>
    output io_intr_ovf : UInt<1>

    reg TimerReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), TimerReg) @[Timer.scala 23:29]
    reg ControlReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), ControlReg) @[Timer.scala 24:29]
    reg CompareReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), CompareReg) @[Timer.scala 25:29]
    reg PreCountReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), PreCountReg) @[Timer.scala 26:29]
    node _WIRE_1 = io_req_bits_activeByteLane
    node _T = bits(_WIRE_1, 0, 0) @[Timer.scala 29:54]
    node _T_1 = bits(_WIRE_1, 1, 1) @[Timer.scala 29:54]
    node _T_2 = bits(_WIRE_1, 2, 2) @[Timer.scala 29:54]
    node _T_3 = bits(_WIRE_1, 3, 3) @[Timer.scala 29:54]
    node _WIRE__0 = _T @[Timer.scala 29:54 Timer.scala 29:54]
    node _T_4 = bits(_WIRE__0, 0, 0) @[Bitwise.scala 72:15]
    node _T_5 = mux(_T_4, UInt<8>("hff"), UInt<8>("h0")) @[Bitwise.scala 72:12]
    node _WIRE__1 = _T_1 @[Timer.scala 29:54 Timer.scala 29:54]
    node _T_6 = bits(_WIRE__1, 0, 0) @[Bitwise.scala 72:15]
    node _T_7 = mux(_T_6, UInt<8>("hff"), UInt<8>("h0")) @[Bitwise.scala 72:12]
    node _WIRE__2 = _T_2 @[Timer.scala 29:54 Timer.scala 29:54]
    node _T_8 = bits(_WIRE__2, 0, 0) @[Bitwise.scala 72:15]
    node _T_9 = mux(_T_8, UInt<8>("hff"), UInt<8>("h0")) @[Bitwise.scala 72:12]
    node _WIRE__3 = _T_3 @[Timer.scala 29:54 Timer.scala 29:54]
    node _T_10 = bits(_WIRE__3, 0, 0) @[Bitwise.scala 72:15]
    node _T_11 = mux(_T_10, UInt<8>("hff"), UInt<8>("h0")) @[Bitwise.scala 72:12]
    node _T_12 = bits(io_req_bits_addrRequest, 3, 0) @[Timer.scala 36:34]
    node _T_13 = eq(_T_12, UInt<1>("h0")) @[Timer.scala 36:40]
    node _T_14 = eq(io_req_bits_isWrite, UInt<1>("h0")) @[Timer.scala 36:71]
    node _T_15 = and(_T_13, _T_14) @[Timer.scala 36:48]
    node _io_rsp_bits_dataResponse_T = mux(io_rsp_ready, TimerReg, UInt<1>("h0")) @[Timer.scala 37:48]
    reg io_rsp_bits_dataResponse_REG : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_dataResponse_REG) @[Timer.scala 37:44]
    reg io_rsp_valid_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_valid_REG) @[Timer.scala 38:32]
    node _T_16 = bits(io_req_bits_addrRequest, 3, 0) @[Timer.scala 40:39]
    node _T_17 = eq(_T_16, UInt<3>("h4")) @[Timer.scala 40:45]
    node _T_18 = eq(io_req_bits_isWrite, UInt<1>("h1")) @[Timer.scala 40:76]
    node _T_19 = and(_T_17, _T_18) @[Timer.scala 40:53]
    node maskedData_1 = _T_7 @[Timer.scala 28:26 Timer.scala 29:16]
    node maskedData_0 = _T_5 @[Timer.scala 28:26 Timer.scala 29:16]
    node ControlReg_lo = cat(maskedData_1, maskedData_0) @[Timer.scala 41:78]
    node maskedData_3 = _T_11 @[Timer.scala 28:26 Timer.scala 29:16]
    node maskedData_2 = _T_9 @[Timer.scala 28:26 Timer.scala 29:16]
    node ControlReg_hi = cat(maskedData_3, maskedData_2) @[Timer.scala 41:78]
    node _ControlReg_T = cat(ControlReg_hi, ControlReg_lo) @[Timer.scala 41:78]
    node _ControlReg_T_1 = and(io_req_bits_dataRequest, _ControlReg_T) @[Timer.scala 41:65]
    node _ControlReg_T_2 = mux(io_req_valid, _ControlReg_T_1, ControlReg) @[Timer.scala 41:26]
    node _io_rsp_bits_dataResponse_T_1 = mux(io_rsp_ready, io_req_bits_dataRequest, UInt<1>("h0")) @[Timer.scala 43:48]
    reg io_rsp_bits_dataResponse_REG_1 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_dataResponse_REG_1) @[Timer.scala 43:44]
    reg io_rsp_valid_REG_1 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_valid_REG_1) @[Timer.scala 44:32]
    node _T_20 = bits(io_req_bits_addrRequest, 3, 0) @[Timer.scala 46:39]
    node _T_21 = eq(_T_20, UInt<3>("h4")) @[Timer.scala 46:45]
    node _T_22 = eq(io_req_bits_isWrite, UInt<1>("h0")) @[Timer.scala 46:76]
    node _T_23 = and(_T_21, _T_22) @[Timer.scala 46:53]
    node _io_rsp_bits_dataResponse_T_2 = mux(io_rsp_ready, ControlReg, UInt<1>("h0")) @[Timer.scala 47:48]
    reg io_rsp_bits_dataResponse_REG_2 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_dataResponse_REG_2) @[Timer.scala 47:44]
    reg io_rsp_valid_REG_2 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_valid_REG_2) @[Timer.scala 48:32]
    node _T_24 = bits(io_req_bits_addrRequest, 3, 0) @[Timer.scala 50:39]
    node _T_25 = eq(_T_24, UInt<4>("h8")) @[Timer.scala 50:45]
    node _T_26 = eq(io_req_bits_isWrite, UInt<1>("h1")) @[Timer.scala 50:76]
    node _T_27 = and(_T_25, _T_26) @[Timer.scala 50:53]
    node CompareReg_lo = cat(maskedData_1, maskedData_0) @[Timer.scala 51:78]
    node CompareReg_hi = cat(maskedData_3, maskedData_2) @[Timer.scala 51:78]
    node _CompareReg_T = cat(CompareReg_hi, CompareReg_lo) @[Timer.scala 51:78]
    node _CompareReg_T_1 = and(io_req_bits_dataRequest, _CompareReg_T) @[Timer.scala 51:65]
    node _CompareReg_T_2 = mux(io_req_valid, _CompareReg_T_1, CompareReg) @[Timer.scala 51:26]
    node _io_rsp_bits_dataResponse_T_3 = mux(io_rsp_ready, io_req_bits_dataRequest, UInt<1>("h0")) @[Timer.scala 53:48]
    reg io_rsp_bits_dataResponse_REG_3 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_dataResponse_REG_3) @[Timer.scala 53:44]
    reg io_rsp_valid_REG_3 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_valid_REG_3) @[Timer.scala 54:32]
    node _T_28 = bits(io_req_bits_addrRequest, 3, 0) @[Timer.scala 56:39]
    node _T_29 = eq(_T_28, UInt<4>("h8")) @[Timer.scala 56:45]
    node _T_30 = eq(io_req_bits_isWrite, UInt<1>("h0")) @[Timer.scala 56:76]
    node _T_31 = and(_T_29, _T_30) @[Timer.scala 56:53]
    node _io_rsp_bits_dataResponse_T_4 = mux(io_rsp_ready, CompareReg, UInt<1>("h0")) @[Timer.scala 57:48]
    reg io_rsp_bits_dataResponse_REG_4 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_dataResponse_REG_4) @[Timer.scala 57:44]
    reg io_rsp_valid_REG_4 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_valid_REG_4) @[Timer.scala 58:32]
    node _T_32 = bits(io_req_bits_addrRequest, 3, 0) @[Timer.scala 60:39]
    node _T_33 = eq(_T_32, UInt<4>("h8")) @[Timer.scala 60:45]
    node _T_34 = eq(io_req_bits_isWrite, UInt<1>("h0")) @[Timer.scala 60:76]
    node _T_35 = and(_T_33, _T_34) @[Timer.scala 60:53]
    node _io_rsp_bits_dataResponse_T_5 = mux(io_rsp_ready, PreCountReg, UInt<1>("h0")) @[Timer.scala 61:48]
    reg io_rsp_bits_dataResponse_REG_5 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_dataResponse_REG_5) @[Timer.scala 61:44]
    reg io_rsp_valid_REG_5 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_valid_REG_5) @[Timer.scala 62:32]
    reg io_rsp_bits_dataResponse_REG_6 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_dataResponse_REG_6) @[Timer.scala 66:44]
    node _GEN_0 = mux(_T_35, io_rsp_bits_dataResponse_REG_5, io_rsp_bits_dataResponse_REG_6) @[Timer.scala 60:84 Timer.scala 61:34 Timer.scala 66:34]
    node _GEN_1 = validif(_T_35, io_rsp_valid_REG_5) @[Timer.scala 60:84 Timer.scala 62:22]
    node _GEN_2 = mux(_T_31, io_rsp_bits_dataResponse_REG_4, _GEN_0) @[Timer.scala 56:84 Timer.scala 57:34]
    node _GEN_3 = mux(_T_31, io_rsp_valid_REG_4, _GEN_1) @[Timer.scala 56:84 Timer.scala 58:22]
    node _GEN_4 = mux(_T_27, _CompareReg_T_2, CompareReg) @[Timer.scala 50:84 Timer.scala 51:20 Timer.scala 25:29]
    node _GEN_5 = mux(_T_27, io_rsp_bits_dataResponse_REG_3, _GEN_2) @[Timer.scala 50:84 Timer.scala 53:34]
    node _GEN_6 = mux(_T_27, io_rsp_valid_REG_3, _GEN_3) @[Timer.scala 50:84 Timer.scala 54:22]
    node _GEN_7 = mux(_T_23, io_rsp_bits_dataResponse_REG_2, _GEN_5) @[Timer.scala 46:84 Timer.scala 47:34]
    node _GEN_8 = mux(_T_23, io_rsp_valid_REG_2, _GEN_6) @[Timer.scala 46:84 Timer.scala 48:22]
    node _GEN_9 = mux(_T_23, CompareReg, _GEN_4) @[Timer.scala 46:84 Timer.scala 25:29]
    node _GEN_10 = mux(_T_19, _ControlReg_T_2, ControlReg) @[Timer.scala 40:84 Timer.scala 41:20 Timer.scala 24:29]
    node _GEN_11 = mux(_T_19, io_rsp_bits_dataResponse_REG_1, _GEN_7) @[Timer.scala 40:84 Timer.scala 43:34]
    node _GEN_12 = mux(_T_19, io_rsp_valid_REG_1, _GEN_8) @[Timer.scala 40:84 Timer.scala 44:22]
    node _GEN_13 = mux(_T_19, CompareReg, _GEN_9) @[Timer.scala 40:84 Timer.scala 25:29]
    node _GEN_14 = mux(_T_15, io_rsp_bits_dataResponse_REG, _GEN_11) @[Timer.scala 36:79 Timer.scala 37:34]
    node _GEN_15 = mux(_T_15, io_rsp_valid_REG, _GEN_12) @[Timer.scala 36:79 Timer.scala 38:22]
    node _GEN_16 = mux(_T_15, ControlReg, _GEN_10) @[Timer.scala 36:79 Timer.scala 24:29]
    node _GEN_17 = mux(_T_15, CompareReg, _GEN_13) @[Timer.scala 36:79 Timer.scala 25:29]
    node _enable_T = bits(ControlReg, 0, 0) @[Timer.scala 69:37]
    node _prescalar_T = bits(ControlReg, 31, 1) @[Timer.scala 70:40]
    node _T_36 = eq(PreCountReg, UInt<1>("h0")) @[Timer.scala 73:22]
    node enable = _enable_T
    node _T_37 = and(_T_36, enable) @[Timer.scala 73:30]
    node _PreCountReg_T = add(PreCountReg, UInt<1>("h1")) @[Timer.scala 74:36]
    node _PreCountReg_T_1 = tail(_PreCountReg_T, 1) @[Timer.scala 74:36]
    node _T_38 = eq(TimerReg, CompareReg) @[Timer.scala 76:24]
    node _T_39 = eq(TimerReg, UInt<32>("hffffffff")) @[Timer.scala 76:51]
    node _T_40 = or(_T_38, _T_39) @[Timer.scala 76:39]
    node prescalar = _prescalar_T
    node _T_41 = eq(PreCountReg, prescalar) @[Timer.scala 79:27]
    node _T_42 = and(_T_41, enable) @[Timer.scala 79:41]
    node _TimerReg_T = add(TimerReg, UInt<1>("h1")) @[Timer.scala 80:30]
    node _TimerReg_T_1 = tail(_TimerReg_T, 1) @[Timer.scala 80:30]
    node _T_43 = lt(PreCountReg, prescalar) @[Timer.scala 82:28]
    node _PreCountReg_T_2 = add(PreCountReg, UInt<1>("h1")) @[Timer.scala 83:36]
    node _PreCountReg_T_3 = tail(_PreCountReg_T_2, 1) @[Timer.scala 83:36]
    node _GEN_18 = mux(_T_43, _PreCountReg_T_3, PreCountReg) @[Timer.scala 82:40 Timer.scala 83:21 Timer.scala 26:29]
    node _GEN_19 = mux(_T_42, _TimerReg_T_1, TimerReg) @[Timer.scala 79:51 Timer.scala 80:18 Timer.scala 23:29]
    node _GEN_20 = mux(_T_42, UInt<1>("h0"), _GEN_18) @[Timer.scala 79:51 Timer.scala 81:21]
    node _GEN_21 = mux(_T_40, UInt<1>("h0"), _GEN_19) @[Timer.scala 76:69 Timer.scala 77:18]
    node _GEN_22 = mux(_T_40, PreCountReg, _GEN_20) @[Timer.scala 76:69 Timer.scala 26:29]
    node _GEN_23 = mux(_T_37, _PreCountReg_T_1, _GEN_22) @[Timer.scala 73:40 Timer.scala 74:21]
    node _GEN_24 = mux(_T_37, TimerReg, _GEN_21) @[Timer.scala 73:40 Timer.scala 23:29]
    node _io_intr_cmp_T = eq(TimerReg, CompareReg) @[Timer.scala 87:41]
    node _io_intr_cmp_T_1 = mux(enable, _io_intr_cmp_T, UInt<1>("h0")) @[Timer.scala 87:23]
    node _io_intr_ovf_T = eq(TimerReg, UInt<32>("hffffffff")) @[Timer.scala 88:41]
    node _io_intr_ovf_T_1 = mux(enable, _io_intr_ovf_T, UInt<1>("h0")) @[Timer.scala 88:23]
    node _wireAddr_T = bits(io_req_bits_addrRequest, 3, 0) @[Timer.scala 95:52]
    node wireAddr = _wireAddr_T
    node _addr_hit_0_T = eq(wireAddr, UInt<1>("h0")) @[Timer.scala 102:39]
    node _addr_hit_1_T = eq(wireAddr, UInt<3>("h4")) @[Timer.scala 102:39]
    node _addr_hit_2_T = eq(wireAddr, UInt<4>("h8")) @[Timer.scala 102:39]
    node _addr_hit_3_T = eq(wireAddr, UInt<4>("hc")) @[Timer.scala 102:39]
    node addr_hit_0 = _addr_hit_0_T @[Timer.scala 93:24 Timer.scala 102:27]
    node addr_hit_1 = _addr_hit_1_T @[Timer.scala 93:24 Timer.scala 102:27]
    node _addr_miss_T = or(addr_hit_0, addr_hit_1) @[Timer.scala 110:37]
    node addr_hit_2 = _addr_hit_2_T @[Timer.scala 93:24 Timer.scala 102:27]
    node _addr_miss_T_1 = or(_addr_miss_T, addr_hit_2) @[Timer.scala 110:37]
    node addr_hit_3 = _addr_hit_3_T @[Timer.scala 93:24 Timer.scala 102:27]
    node _addr_miss_T_2 = or(_addr_miss_T_1, addr_hit_3) @[Timer.scala 110:37]
    node _addr_miss_T_3 = not(_addr_miss_T_2) @[Timer.scala 110:18]
    node _T_44 = eq(wireAddr, UInt<1>("h0")) @[Timer.scala 111:19]
    node _T_45 = and(_T_44, io_req_bits_isWrite) @[Timer.scala 111:27]
    reg io_rsp_bits_error_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_error_REG) @[Timer.scala 111:78]
    node _T_46 = eq(wireAddr, UInt<4>("hc")) @[Timer.scala 112:24]
    node _T_47 = and(_T_46, io_req_bits_isWrite) @[Timer.scala 112:33]
    reg io_rsp_bits_error_REG_1 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_error_REG_1) @[Timer.scala 112:84]
    node addr_miss = _addr_miss_T_3 @[Timer.scala 96:25 Timer.scala 110:15]
    node _io_rsp_bits_error_T = and(io_req_valid, addr_miss) @[Timer.scala 113:58]
    reg io_rsp_bits_error_REG_2 : UInt<1>, clock with :
      reset => (UInt<1>("h0"), io_rsp_bits_error_REG_2) @[Timer.scala 113:44]
    node _GEN_25 = mux(_T_47, io_rsp_bits_error_REG_1, io_rsp_bits_error_REG_2) @[Timer.scala 112:55 Timer.scala 112:74 Timer.scala 113:34]
    node _GEN_26 = mux(_T_45, io_rsp_bits_error_REG, _GEN_25) @[Timer.scala 111:49 Timer.scala 111:68]
    io_req_ready <= UInt<1>("h1") @[Timer.scala 31:18]
    io_rsp_valid <= _GEN_15
    io_rsp_bits_dataResponse <= _GEN_14
    io_rsp_bits_error <= _GEN_26
    io_intr_cmp <= _io_intr_cmp_T_1 @[Timer.scala 87:17]
    io_intr_ovf <= _io_intr_ovf_T_1 @[Timer.scala 88:17]
    TimerReg <= mux(reset, UInt<32>("h0"), _GEN_24) @[Timer.scala 23:29 Timer.scala 23:29]
    ControlReg <= mux(reset, UInt<32>("h0"), _GEN_16) @[Timer.scala 24:29 Timer.scala 24:29]
    CompareReg <= mux(reset, UInt<32>("h0"), _GEN_17) @[Timer.scala 25:29 Timer.scala 25:29]
    PreCountReg <= mux(reset, UInt<32>("h0"), _GEN_23) @[Timer.scala 26:29 Timer.scala 26:29]
    io_rsp_bits_dataResponse_REG <= _io_rsp_bits_dataResponse_T @[Timer.scala 37:44]
    io_rsp_valid_REG <= io_req_valid @[Timer.scala 38:32]
    io_rsp_bits_dataResponse_REG_1 <= _io_rsp_bits_dataResponse_T_1 @[Timer.scala 43:44]
    io_rsp_valid_REG_1 <= io_req_valid @[Timer.scala 44:32]
    io_rsp_bits_dataResponse_REG_2 <= _io_rsp_bits_dataResponse_T_2 @[Timer.scala 47:44]
    io_rsp_valid_REG_2 <= io_req_valid @[Timer.scala 48:32]
    io_rsp_bits_dataResponse_REG_3 <= _io_rsp_bits_dataResponse_T_3 @[Timer.scala 53:44]
    io_rsp_valid_REG_3 <= io_req_valid @[Timer.scala 54:32]
    io_rsp_bits_dataResponse_REG_4 <= _io_rsp_bits_dataResponse_T_4 @[Timer.scala 57:44]
    io_rsp_valid_REG_4 <= io_req_valid @[Timer.scala 58:32]
    io_rsp_bits_dataResponse_REG_5 <= _io_rsp_bits_dataResponse_T_5 @[Timer.scala 61:44]
    io_rsp_valid_REG_5 <= io_req_valid @[Timer.scala 62:32]
    io_rsp_bits_dataResponse_REG_6 <= io_req_bits_addrRequest @[Timer.scala 66:44]
    io_rsp_bits_error_REG <= io_req_valid @[Timer.scala 111:78]
    io_rsp_bits_error_REG_1 <= io_req_valid @[Timer.scala 112:84]
    io_rsp_bits_error_REG_2 <= _io_rsp_bits_error_T @[Timer.scala 113:44]

  module TimerHarness :
    input clock : Clock
    input reset : UInt<1>
    output io_req_ready : UInt<1>
    input io_req_valid : UInt<1>
    input io_req_bits_addrRequest : UInt<32>
    input io_req_bits_dataRequest : UInt<32>
    input io_req_bits_activeByteLane : UInt<4>
    input io_req_bits_isWrite : UInt<1>
    input io_rsp_ready : UInt<1>
    output io_rsp_valid : UInt<1>
    output io_rsp_bits_dataResponse : UInt<32>
    output io_rsp_bits_error : UInt<1>
    output io_intr_cmp : UInt<1>
    output io_intr_ovf : UInt<1>

    inst hostAdapter of WishboneHost @[TimerHarness.scala 21:27]
    inst deviceAdapter of WishboneDevice @[TimerHarness.scala 22:29]
    inst timer of Timer @[TimerHarness.scala 23:21]
    io_req_ready <= hostAdapter.io_reqIn_ready @[TimerHarness.scala 25:24]
    io_rsp_valid <= hostAdapter.io_rspOut_valid @[TimerHarness.scala 26:10]
    io_rsp_bits_dataResponse <= hostAdapter.io_rspOut_bits_dataResponse @[TimerHarness.scala 26:10]
    io_rsp_bits_error <= hostAdapter.io_rspOut_bits_error @[TimerHarness.scala 26:10]
    io_intr_cmp <= timer.io_intr_cmp @[TimerHarness.scala 33:15]
    io_intr_ovf <= timer.io_intr_ovf @[TimerHarness.scala 34:15]
    hostAdapter.clock <= clock
    hostAdapter.reset <= reset
    hostAdapter.io_wbMasterTransmitter_ready <= deviceAdapter.io_wbMasterReceiver_ready @[TimerHarness.scala 27:38]
    hostAdapter.io_wbSlaveReceiver_valid <= deviceAdapter.io_wbSlaveTransmitter_valid @[TimerHarness.scala 28:34]
    hostAdapter.io_wbSlaveReceiver_bits_ack <= deviceAdapter.io_wbSlaveTransmitter_bits_ack @[TimerHarness.scala 28:34]
    hostAdapter.io_wbSlaveReceiver_bits_dat <= deviceAdapter.io_wbSlaveTransmitter_bits_dat @[TimerHarness.scala 28:34]
    hostAdapter.io_wbSlaveReceiver_bits_err <= deviceAdapter.io_wbSlaveTransmitter_bits_err @[TimerHarness.scala 28:34]
    hostAdapter.io_reqIn_valid <= io_req_valid @[TimerHarness.scala 25:24]
    hostAdapter.io_reqIn_bits_addrRequest <= io_req_bits_addrRequest @[TimerHarness.scala 25:24]
    hostAdapter.io_reqIn_bits_dataRequest <= io_req_bits_dataRequest @[TimerHarness.scala 25:24]
    hostAdapter.io_reqIn_bits_activeByteLane <= io_req_bits_activeByteLane @[TimerHarness.scala 25:24]
    hostAdapter.io_reqIn_bits_isWrite <= io_req_bits_isWrite @[TimerHarness.scala 25:24]
    hostAdapter.io_rspOut_ready <= io_rsp_ready @[TimerHarness.scala 26:10]
    deviceAdapter.clock <= clock
    deviceAdapter.reset <= reset
    deviceAdapter.io_wbSlaveTransmitter_ready <= hostAdapter.io_wbSlaveReceiver_ready @[TimerHarness.scala 28:34]
    deviceAdapter.io_wbMasterReceiver_valid <= hostAdapter.io_wbMasterTransmitter_valid @[TimerHarness.scala 27:38]
    deviceAdapter.io_wbMasterReceiver_bits_cyc <= hostAdapter.io_wbMasterTransmitter_bits_cyc @[TimerHarness.scala 27:38]
    deviceAdapter.io_wbMasterReceiver_bits_stb <= hostAdapter.io_wbMasterTransmitter_bits_stb @[TimerHarness.scala 27:38]
    deviceAdapter.io_wbMasterReceiver_bits_we <= hostAdapter.io_wbMasterTransmitter_bits_we @[TimerHarness.scala 27:38]
    deviceAdapter.io_wbMasterReceiver_bits_adr <= hostAdapter.io_wbMasterTransmitter_bits_adr @[TimerHarness.scala 27:38]
    deviceAdapter.io_wbMasterReceiver_bits_dat <= hostAdapter.io_wbMasterTransmitter_bits_dat @[TimerHarness.scala 27:38]
    deviceAdapter.io_wbMasterReceiver_bits_sel <= hostAdapter.io_wbMasterTransmitter_bits_sel @[TimerHarness.scala 27:38]
    deviceAdapter.io_reqOut_ready <= timer.io_req_ready @[TimerHarness.scala 30:16]
    deviceAdapter.io_rspIn_valid <= timer.io_rsp_valid @[TimerHarness.scala 31:16]
    deviceAdapter.io_rspIn_bits_dataResponse <= timer.io_rsp_bits_dataResponse @[TimerHarness.scala 31:16]
    deviceAdapter.io_rspIn_bits_error <= timer.io_rsp_bits_error @[TimerHarness.scala 31:16]
    timer.clock <= clock
    timer.reset <= reset
    timer.io_req_valid <= deviceAdapter.io_reqOut_valid @[TimerHarness.scala 30:16]
    timer.io_req_bits_addrRequest <= deviceAdapter.io_reqOut_bits_addrRequest @[TimerHarness.scala 30:16]
    timer.io_req_bits_dataRequest <= deviceAdapter.io_reqOut_bits_dataRequest @[TimerHarness.scala 30:16]
    timer.io_req_bits_activeByteLane <= deviceAdapter.io_reqOut_bits_activeByteLane @[TimerHarness.scala 30:16]
    timer.io_req_bits_isWrite <= deviceAdapter.io_reqOut_bits_isWrite @[TimerHarness.scala 30:16]
    timer.io_rsp_ready <= deviceAdapter.io_rspIn_ready @[TimerHarness.scala 31:16]
