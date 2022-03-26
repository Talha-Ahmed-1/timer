module WishboneHost(
  input         clock,
  input         reset,
  input         io_wbMasterTransmitter_ready,
  output        io_wbMasterTransmitter_valid,
  output        io_wbMasterTransmitter_bits_cyc,
  output        io_wbMasterTransmitter_bits_stb,
  output        io_wbMasterTransmitter_bits_we,
  output [31:0] io_wbMasterTransmitter_bits_adr,
  output [31:0] io_wbMasterTransmitter_bits_dat,
  output [3:0]  io_wbMasterTransmitter_bits_sel,
  output        io_wbSlaveReceiver_ready,
  input         io_wbSlaveReceiver_bits_ack,
  input  [31:0] io_wbSlaveReceiver_bits_dat,
  input         io_wbSlaveReceiver_bits_err,
  output        io_reqIn_ready,
  input         io_reqIn_valid,
  input  [31:0] io_reqIn_bits_addrRequest,
  input  [31:0] io_reqIn_bits_dataRequest,
  input  [3:0]  io_reqIn_bits_activeByteLane,
  input         io_reqIn_bits_isWrite,
  output        io_rspOut_valid,
  output [31:0] io_rspOut_bits_dataResponse,
  output        io_rspOut_bits_error
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
`endif // RANDOMIZE_REG_INIT
  reg  startWBTransaction; // @[WishboneHost.scala 39:35]
  reg [31:0] dataReg; // @[WishboneHost.scala 41:24]
  reg  respReg; // @[WishboneHost.scala 42:24]
  reg  errReg; // @[WishboneHost.scala 43:23]
  reg  stbReg; // @[WishboneHost.scala 45:23]
  reg  cycReg; // @[WishboneHost.scala 46:23]
  reg  weReg; // @[WishboneHost.scala 47:22]
  reg [31:0] datReg; // @[WishboneHost.scala 48:23]
  reg [31:0] adrReg; // @[WishboneHost.scala 49:23]
  reg [3:0] selReg; // @[WishboneHost.scala 50:23]
  reg  stateReg; // @[WishboneHost.scala 55:25]
  reg  readyReg; // @[WishboneHost.scala 61:25]
  wire  _T_2 = io_reqIn_valid & io_wbMasterTransmitter_ready; // @[WishboneHost.scala 18:37]
  wire  _GEN_0 = _T_2 ? 1'h0 : readyReg; // @[WishboneHost.scala 62:14 WishboneHost.scala 63:14 WishboneHost.scala 61:25]
  wire  _GEN_1 = stateReg | _GEN_0; // @[WishboneHost.scala 65:33 WishboneHost.scala 66:14]
  wire  _GEN_2 = io_reqIn_bits_isWrite & readyReg & io_reqIn_valid | startWBTransaction; // @[WishboneHost.scala 84:92 WishboneHost.scala 85:26 WishboneHost.scala 39:35]
  wire  _GEN_3 = io_reqIn_bits_isWrite & readyReg & io_reqIn_valid | stbReg; // @[WishboneHost.scala 84:92 WishboneHost.scala 86:14 WishboneHost.scala 45:23]
  wire  _GEN_4 = io_reqIn_bits_isWrite & readyReg & io_reqIn_valid | cycReg; // @[WishboneHost.scala 84:92 WishboneHost.scala 87:14 WishboneHost.scala 46:23]
  wire  _GEN_9 = ~io_reqIn_bits_isWrite & readyReg & io_reqIn_valid | _GEN_2; // @[WishboneHost.scala 76:86 WishboneHost.scala 77:26]
  wire  _GEN_10 = ~io_reqIn_bits_isWrite & readyReg & io_reqIn_valid | _GEN_3; // @[WishboneHost.scala 76:86 WishboneHost.scala 78:14]
  wire  _GEN_11 = ~io_reqIn_bits_isWrite & readyReg & io_reqIn_valid | _GEN_4; // @[WishboneHost.scala 76:86 WishboneHost.scala 79:14]
  wire  _GEN_23 = io_wbSlaveReceiver_bits_err & ~io_wbSlaveReceiver_bits_ack | respReg; // @[WishboneHost.scala 111:78 WishboneHost.scala 113:15 WishboneHost.scala 42:24]
  wire  _GEN_24 = io_wbSlaveReceiver_bits_err & ~io_wbSlaveReceiver_bits_ack | errReg; // @[WishboneHost.scala 111:78 WishboneHost.scala 114:14 WishboneHost.scala 43:23]
  wire  _GEN_27 = io_wbSlaveReceiver_bits_ack & ~io_wbSlaveReceiver_bits_err | _GEN_23; // @[WishboneHost.scala 105:71 WishboneHost.scala 107:15]
  assign io_wbMasterTransmitter_valid = io_wbMasterTransmitter_bits_stb; // @[WishboneHost.scala 23:32]
  assign io_wbMasterTransmitter_bits_cyc = ~startWBTransaction ? 1'h0 : cycReg; // @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 95:37]
  assign io_wbMasterTransmitter_bits_stb = ~startWBTransaction ? 1'h0 : stbReg; // @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 94:37]
  assign io_wbMasterTransmitter_bits_we = ~startWBTransaction ? 1'h0 : weReg; // @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 96:36]
  assign io_wbMasterTransmitter_bits_adr = ~startWBTransaction ? 32'h0 : adrReg; // @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 97:37]
  assign io_wbMasterTransmitter_bits_dat = ~startWBTransaction ? 32'h0 : datReg; // @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 98:37]
  assign io_wbMasterTransmitter_bits_sel = ~startWBTransaction ? 4'h0 : selReg; // @[WishboneHost.scala 101:31 WishboneHost.scala 102:118 WishboneHost.scala 99:37]
  assign io_wbSlaveReceiver_ready = 1'h1; // @[WishboneHost.scala 26:28]
  assign io_reqIn_ready = readyReg; // @[WishboneHost.scala 75:20]
  assign io_rspOut_valid = respReg; // @[WishboneHost.scala 127:21]
  assign io_rspOut_bits_dataResponse = dataReg; // @[WishboneHost.scala 128:33]
  assign io_rspOut_bits_error = errReg; // @[WishboneHost.scala 129:26]
  always @(posedge clock) begin
    if (reset) begin // @[WishboneHost.scala 39:35]
      startWBTransaction <= 1'h0; // @[WishboneHost.scala 39:35]
    end else if (io_wbSlaveReceiver_bits_ack & ~io_wbSlaveReceiver_bits_err) begin // @[WishboneHost.scala 105:71]
      startWBTransaction <= 1'h0; // @[WishboneHost.scala 110:26]
    end else if (io_wbSlaveReceiver_bits_err & ~io_wbSlaveReceiver_bits_ack) begin // @[WishboneHost.scala 111:78]
      startWBTransaction <= 1'h0; // @[WishboneHost.scala 115:26]
    end else begin
      startWBTransaction <= _GEN_9;
    end
    if (reset) begin // @[WishboneHost.scala 41:24]
      dataReg <= 32'h0; // @[WishboneHost.scala 41:24]
    end else if (io_wbSlaveReceiver_bits_ack & ~io_wbSlaveReceiver_bits_err) begin // @[WishboneHost.scala 105:71]
      dataReg <= io_wbSlaveReceiver_bits_dat; // @[WishboneHost.scala 106:15]
    end else if (io_wbSlaveReceiver_bits_err & ~io_wbSlaveReceiver_bits_ack) begin // @[WishboneHost.scala 111:78]
      dataReg <= io_wbSlaveReceiver_bits_dat; // @[WishboneHost.scala 112:15]
    end
    if (reset) begin // @[WishboneHost.scala 42:24]
      respReg <= 1'h0; // @[WishboneHost.scala 42:24]
    end else if (~stateReg) begin // @[WishboneHost.scala 118:29]
      respReg <= _GEN_27;
    end else if (stateReg) begin // @[WishboneHost.scala 120:42]
      respReg <= 1'h0; // @[WishboneHost.scala 121:15]
    end else begin
      respReg <= _GEN_27;
    end
    if (reset) begin // @[WishboneHost.scala 43:23]
      errReg <= 1'h0; // @[WishboneHost.scala 43:23]
    end else if (io_wbSlaveReceiver_bits_ack & ~io_wbSlaveReceiver_bits_err) begin // @[WishboneHost.scala 105:71]
      errReg <= 1'h0; // @[WishboneHost.scala 108:14]
    end else begin
      errReg <= _GEN_24;
    end
    if (reset) begin // @[WishboneHost.scala 45:23]
      stbReg <= 1'h0; // @[WishboneHost.scala 45:23]
    end else begin
      stbReg <= _GEN_10;
    end
    if (reset) begin // @[WishboneHost.scala 46:23]
      cycReg <= 1'h0; // @[WishboneHost.scala 46:23]
    end else begin
      cycReg <= _GEN_11;
    end
    if (reset) begin // @[WishboneHost.scala 47:22]
      weReg <= 1'h0; // @[WishboneHost.scala 47:22]
    end else if (~io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 76:86]
      weReg <= io_reqIn_bits_isWrite; // @[WishboneHost.scala 80:13]
    end else if (io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 84:92]
      weReg <= io_reqIn_bits_isWrite; // @[WishboneHost.scala 88:13]
    end
    if (reset) begin // @[WishboneHost.scala 48:23]
      datReg <= 32'h0; // @[WishboneHost.scala 48:23]
    end else if (~io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 76:86]
      datReg <= 32'h0; // @[WishboneHost.scala 82:14]
    end else if (io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 84:92]
      datReg <= io_reqIn_bits_dataRequest; // @[WishboneHost.scala 90:14]
    end
    if (reset) begin // @[WishboneHost.scala 49:23]
      adrReg <= 32'h0; // @[WishboneHost.scala 49:23]
    end else if (~io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 76:86]
      adrReg <= io_reqIn_bits_addrRequest; // @[WishboneHost.scala 81:14]
    end else if (io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 84:92]
      adrReg <= io_reqIn_bits_addrRequest; // @[WishboneHost.scala 89:14]
    end
    if (reset) begin // @[WishboneHost.scala 50:23]
      selReg <= 4'h0; // @[WishboneHost.scala 50:23]
    end else if (~io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 76:86]
      selReg <= io_reqIn_bits_activeByteLane; // @[WishboneHost.scala 83:14]
    end else if (io_reqIn_bits_isWrite & readyReg & io_reqIn_valid) begin // @[WishboneHost.scala 84:92]
      selReg <= io_reqIn_bits_activeByteLane; // @[WishboneHost.scala 91:14]
    end
    if (reset) begin // @[WishboneHost.scala 55:25]
      stateReg <= 1'h0; // @[WishboneHost.scala 55:25]
    end else if (~stateReg) begin // @[WishboneHost.scala 118:29]
      stateReg <= io_wbSlaveReceiver_bits_ack | io_wbSlaveReceiver_bits_err; // @[WishboneHost.scala 119:16]
    end else if (stateReg) begin // @[WishboneHost.scala 120:42]
      stateReg <= 1'h0; // @[WishboneHost.scala 122:16]
    end
    readyReg <= reset | _GEN_1; // @[WishboneHost.scala 61:25 WishboneHost.scala 61:25]
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  startWBTransaction = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  dataReg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  respReg = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  errReg = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  stbReg = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  cycReg = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  weReg = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  datReg = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  adrReg = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  selReg = _RAND_9[3:0];
  _RAND_10 = {1{`RANDOM}};
  stateReg = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  readyReg = _RAND_11[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module WishboneDevice(
  input         io_wbSlaveTransmitter_ready,
  output        io_wbSlaveTransmitter_bits_ack,
  output [31:0] io_wbSlaveTransmitter_bits_dat,
  output        io_wbSlaveTransmitter_bits_err,
  output        io_wbMasterReceiver_ready,
  input         io_wbMasterReceiver_valid,
  input         io_wbMasterReceiver_bits_cyc,
  input         io_wbMasterReceiver_bits_stb,
  input         io_wbMasterReceiver_bits_we,
  input  [31:0] io_wbMasterReceiver_bits_adr,
  input  [31:0] io_wbMasterReceiver_bits_dat,
  input  [3:0]  io_wbMasterReceiver_bits_sel,
  output        io_reqOut_valid,
  output [31:0] io_reqOut_bits_addrRequest,
  output [31:0] io_reqOut_bits_dataRequest,
  output [3:0]  io_reqOut_bits_activeByteLane,
  output        io_reqOut_bits_isWrite,
  input         io_rspIn_valid,
  input  [31:0] io_rspIn_bits_dataResponse,
  input         io_rspIn_bits_error
);
  wire  _T_1 = io_wbMasterReceiver_valid & io_wbMasterReceiver_bits_cyc & io_wbMasterReceiver_bits_stb; // @[WishboneDevice.scala 16:80]
  wire  _T_4 = io_rspIn_valid & ~io_rspIn_bits_error; // @[WishboneDevice.scala 36:27]
  wire  _T_5 = io_rspIn_valid & io_rspIn_bits_error; // @[WishboneDevice.scala 42:34]
  wire  _GEN_5 = io_rspIn_valid & ~io_rspIn_bits_error ? 1'h0 : _T_5; // @[WishboneDevice.scala 36:52 WishboneDevice.scala 40:40]
  wire  _GEN_18 = ~io_wbMasterReceiver_bits_we ? _T_4 : _T_4; // @[WishboneDevice.scala 26:40]
  wire  _GEN_19 = ~io_wbMasterReceiver_bits_we ? _GEN_5 : _GEN_5; // @[WishboneDevice.scala 26:40]
  assign io_wbSlaveTransmitter_bits_ack = _T_1 & _GEN_18; // @[WishboneDevice.scala 25:16 WishboneDevice.scala 88:9]
  assign io_wbSlaveTransmitter_bits_dat = io_rspIn_bits_dataResponse; // @[WishboneDevice.scala 36:52 WishboneDevice.scala 41:40]
  assign io_wbSlaveTransmitter_bits_err = _T_1 & _GEN_19; // @[WishboneDevice.scala 25:16 WishboneDevice.scala 89:36]
  assign io_wbMasterReceiver_ready = 1'h1; // @[WishboneDevice.scala 19:29]
  assign io_reqOut_valid = io_wbMasterReceiver_valid & io_wbMasterReceiver_bits_cyc & io_wbMasterReceiver_bits_stb; // @[WishboneDevice.scala 16:80]
  assign io_reqOut_bits_addrRequest = io_wbMasterReceiver_bits_adr; // @[WishboneDevice.scala 26:40 WishboneDevice.scala 32:34 WishboneDevice.scala 56:34]
  assign io_reqOut_bits_dataRequest = io_wbMasterReceiver_bits_dat; // @[WishboneDevice.scala 26:40 WishboneDevice.scala 57:34]
  assign io_reqOut_bits_activeByteLane = io_wbMasterReceiver_bits_sel; // @[WishboneDevice.scala 26:40 WishboneDevice.scala 34:37 WishboneDevice.scala 58:37]
  assign io_reqOut_bits_isWrite = ~io_wbMasterReceiver_bits_we ? 1'h0 : io_wbMasterReceiver_bits_we; // @[WishboneDevice.scala 26:40 WishboneDevice.scala 35:30 WishboneDevice.scala 59:30]
endmodule
module Timer(
  input         clock,
  input         reset,
  input         io_req_valid,
  input  [31:0] io_req_bits_addrRequest,
  input  [31:0] io_req_bits_dataRequest,
  input  [3:0]  io_req_bits_activeByteLane,
  input         io_req_bits_isWrite,
  output        io_rsp_valid,
  output [31:0] io_rsp_bits_dataResponse,
  output        io_rsp_bits_error
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] ControlReg; // @[Timer.scala 23:29]
  reg [31:0] CompareReg; // @[Timer.scala 24:29]
  wire [7:0] maskedData_0 = io_req_bits_activeByteLane[0] ? 8'hff : 8'h0; // @[Bitwise.scala 72:12]
  wire [7:0] maskedData_1 = io_req_bits_activeByteLane[1] ? 8'hff : 8'h0; // @[Bitwise.scala 72:12]
  wire [7:0] maskedData_2 = io_req_bits_activeByteLane[2] ? 8'hff : 8'h0; // @[Bitwise.scala 72:12]
  wire [7:0] maskedData_3 = io_req_bits_activeByteLane[3] ? 8'hff : 8'h0; // @[Bitwise.scala 72:12]
  wire  _T_13 = io_req_bits_addrRequest[3:0] == 4'h0; // @[Timer.scala 34:40]
  wire  _T_14 = ~io_req_bits_isWrite; // @[Timer.scala 34:71]
  reg  io_rsp_valid_REG; // @[Timer.scala 36:32]
  wire  _T_17 = io_req_bits_addrRequest[3:0] == 4'h4; // @[Timer.scala 38:45]
  wire [31:0] _ControlReg_T = {maskedData_3,maskedData_2,maskedData_1,maskedData_0}; // @[Timer.scala 39:78]
  wire [31:0] _ControlReg_T_1 = io_req_bits_dataRequest & _ControlReg_T; // @[Timer.scala 39:65]
  reg [31:0] io_rsp_bits_dataResponse_REG_1; // @[Timer.scala 41:44]
  reg  io_rsp_valid_REG_1; // @[Timer.scala 42:32]
  reg [31:0] io_rsp_bits_dataResponse_REG_2; // @[Timer.scala 45:44]
  reg  io_rsp_valid_REG_2; // @[Timer.scala 46:32]
  wire  _T_25 = io_req_bits_addrRequest[3:0] == 4'h8; // @[Timer.scala 48:45]
  wire [31:0] _CompareReg_T_2 = io_req_valid ? _ControlReg_T_1 : CompareReg; // @[Timer.scala 49:26]
  reg [31:0] io_rsp_bits_dataResponse_REG_3; // @[Timer.scala 51:44]
  reg  io_rsp_valid_REG_3; // @[Timer.scala 52:32]
  reg [31:0] io_rsp_bits_dataResponse_REG_4; // @[Timer.scala 55:44]
  reg  io_rsp_valid_REG_4; // @[Timer.scala 56:32]
  reg [31:0] io_rsp_bits_dataResponse_REG_5; // @[Timer.scala 60:44]
  wire [31:0] _GEN_0 = _T_25 & _T_14 ? io_rsp_bits_dataResponse_REG_4 : io_rsp_bits_dataResponse_REG_5; // @[Timer.scala 54:84 Timer.scala 55:34 Timer.scala 60:34]
  wire [31:0] _GEN_2 = io_req_bits_addrRequest[3:0] == 4'h8 & io_req_bits_isWrite ? _CompareReg_T_2 : CompareReg; // @[Timer.scala 48:84 Timer.scala 49:20 Timer.scala 24:29]
  wire [31:0] _GEN_3 = io_req_bits_addrRequest[3:0] == 4'h8 & io_req_bits_isWrite ? io_rsp_bits_dataResponse_REG_3 :
    _GEN_0; // @[Timer.scala 48:84 Timer.scala 51:34]
  wire  _GEN_4 = io_req_bits_addrRequest[3:0] == 4'h8 & io_req_bits_isWrite ? io_rsp_valid_REG_3 : io_rsp_valid_REG_4; // @[Timer.scala 48:84 Timer.scala 52:22]
  wire [31:0] _GEN_5 = _T_17 & _T_14 ? io_rsp_bits_dataResponse_REG_2 : _GEN_3; // @[Timer.scala 44:84 Timer.scala 45:34]
  wire  _GEN_6 = _T_17 & _T_14 ? io_rsp_valid_REG_2 : _GEN_4; // @[Timer.scala 44:84 Timer.scala 46:22]
  wire [31:0] _GEN_9 = io_req_bits_addrRequest[3:0] == 4'h4 & io_req_bits_isWrite ? io_rsp_bits_dataResponse_REG_1 :
    _GEN_5; // @[Timer.scala 38:84 Timer.scala 41:34]
  wire  _GEN_10 = io_req_bits_addrRequest[3:0] == 4'h4 & io_req_bits_isWrite ? io_rsp_valid_REG_1 : _GEN_6; // @[Timer.scala 38:84 Timer.scala 42:22]
  wire  addr_miss = ~(_T_13 | _T_17 | _T_25); // @[Timer.scala 85:18]
  reg  io_rsp_bits_error_REG; // @[Timer.scala 86:78]
  reg  io_rsp_bits_error_REG_1; // @[Timer.scala 87:44]
  assign io_rsp_valid = io_req_bits_addrRequest[3:0] == 4'h0 & ~io_req_bits_isWrite ? io_rsp_valid_REG : _GEN_10; // @[Timer.scala 34:79 Timer.scala 36:22]
  assign io_rsp_bits_dataResponse = io_req_bits_addrRequest[3:0] == 4'h0 & ~io_req_bits_isWrite ? 32'h0 : _GEN_9; // @[Timer.scala 34:79 Timer.scala 35:34]
  assign io_rsp_bits_error = _T_13 & io_req_bits_isWrite ? io_rsp_bits_error_REG : io_rsp_bits_error_REG_1; // @[Timer.scala 86:49 Timer.scala 86:68 Timer.scala 87:34]
  always @(posedge clock) begin
    if (reset) begin // @[Timer.scala 23:29]
      ControlReg <= 32'h0; // @[Timer.scala 23:29]
    end else if (!(io_req_bits_addrRequest[3:0] == 4'h0 & ~io_req_bits_isWrite)) begin // @[Timer.scala 34:79]
      if (io_req_bits_addrRequest[3:0] == 4'h4 & io_req_bits_isWrite) begin // @[Timer.scala 38:84]
        if (io_req_valid) begin // @[Timer.scala 39:26]
          ControlReg <= _ControlReg_T_1;
        end
      end
    end
    if (reset) begin // @[Timer.scala 24:29]
      CompareReg <= 32'h0; // @[Timer.scala 24:29]
    end else if (!(io_req_bits_addrRequest[3:0] == 4'h0 & ~io_req_bits_isWrite)) begin // @[Timer.scala 34:79]
      if (!(io_req_bits_addrRequest[3:0] == 4'h4 & io_req_bits_isWrite)) begin // @[Timer.scala 38:84]
        if (!(_T_17 & _T_14)) begin // @[Timer.scala 44:84]
          CompareReg <= _GEN_2;
        end
      end
    end
    io_rsp_valid_REG <= io_req_valid; // @[Timer.scala 36:32]
    io_rsp_bits_dataResponse_REG_1 <= io_req_bits_dataRequest; // @[Timer.scala 41:48]
    io_rsp_valid_REG_1 <= io_req_valid; // @[Timer.scala 42:32]
    io_rsp_bits_dataResponse_REG_2 <= ControlReg; // @[Timer.scala 45:48]
    io_rsp_valid_REG_2 <= io_req_valid; // @[Timer.scala 46:32]
    io_rsp_bits_dataResponse_REG_3 <= io_req_bits_dataRequest; // @[Timer.scala 51:48]
    io_rsp_valid_REG_3 <= io_req_valid; // @[Timer.scala 52:32]
    io_rsp_bits_dataResponse_REG_4 <= CompareReg; // @[Timer.scala 55:48]
    io_rsp_valid_REG_4 <= io_req_valid; // @[Timer.scala 56:32]
    io_rsp_bits_dataResponse_REG_5 <= io_req_bits_addrRequest; // @[Timer.scala 60:44]
    io_rsp_bits_error_REG <= io_req_valid; // @[Timer.scala 86:78]
    io_rsp_bits_error_REG_1 <= io_req_valid & addr_miss; // @[Timer.scala 87:58]
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  ControlReg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  CompareReg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  io_rsp_valid_REG = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  io_rsp_bits_dataResponse_REG_1 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  io_rsp_valid_REG_1 = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  io_rsp_bits_dataResponse_REG_2 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  io_rsp_valid_REG_2 = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  io_rsp_bits_dataResponse_REG_3 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  io_rsp_valid_REG_3 = _RAND_8[0:0];
  _RAND_9 = {1{`RANDOM}};
  io_rsp_bits_dataResponse_REG_4 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  io_rsp_valid_REG_4 = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  io_rsp_bits_dataResponse_REG_5 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  io_rsp_bits_error_REG = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  io_rsp_bits_error_REG_1 = _RAND_13[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module TimerHarness(
  input         clock,
  input         reset,
  output        io_req_ready,
  input         io_req_valid,
  input  [31:0] io_req_bits_addrRequest,
  input  [31:0] io_req_bits_dataRequest,
  input  [3:0]  io_req_bits_activeByteLane,
  input         io_req_bits_isWrite,
  input         io_rsp_ready,
  output        io_rsp_valid,
  output [31:0] io_rsp_bits_dataResponse,
  output        io_rsp_bits_error,
  output        io_intr_cmp
);
  wire  hostAdapter_clock; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_reset; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbMasterTransmitter_ready; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbMasterTransmitter_valid; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbMasterTransmitter_bits_cyc; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbMasterTransmitter_bits_stb; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbMasterTransmitter_bits_we; // @[TimerHarness.scala 20:27]
  wire [31:0] hostAdapter_io_wbMasterTransmitter_bits_adr; // @[TimerHarness.scala 20:27]
  wire [31:0] hostAdapter_io_wbMasterTransmitter_bits_dat; // @[TimerHarness.scala 20:27]
  wire [3:0] hostAdapter_io_wbMasterTransmitter_bits_sel; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbSlaveReceiver_ready; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbSlaveReceiver_bits_ack; // @[TimerHarness.scala 20:27]
  wire [31:0] hostAdapter_io_wbSlaveReceiver_bits_dat; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_wbSlaveReceiver_bits_err; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_reqIn_ready; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_reqIn_valid; // @[TimerHarness.scala 20:27]
  wire [31:0] hostAdapter_io_reqIn_bits_addrRequest; // @[TimerHarness.scala 20:27]
  wire [31:0] hostAdapter_io_reqIn_bits_dataRequest; // @[TimerHarness.scala 20:27]
  wire [3:0] hostAdapter_io_reqIn_bits_activeByteLane; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_reqIn_bits_isWrite; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_rspOut_valid; // @[TimerHarness.scala 20:27]
  wire [31:0] hostAdapter_io_rspOut_bits_dataResponse; // @[TimerHarness.scala 20:27]
  wire  hostAdapter_io_rspOut_bits_error; // @[TimerHarness.scala 20:27]
  wire  deviceAdapter_io_wbSlaveTransmitter_ready; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_wbSlaveTransmitter_bits_ack; // @[TimerHarness.scala 21:29]
  wire [31:0] deviceAdapter_io_wbSlaveTransmitter_bits_dat; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_wbSlaveTransmitter_bits_err; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_wbMasterReceiver_ready; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_wbMasterReceiver_valid; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_wbMasterReceiver_bits_cyc; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_wbMasterReceiver_bits_stb; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_wbMasterReceiver_bits_we; // @[TimerHarness.scala 21:29]
  wire [31:0] deviceAdapter_io_wbMasterReceiver_bits_adr; // @[TimerHarness.scala 21:29]
  wire [31:0] deviceAdapter_io_wbMasterReceiver_bits_dat; // @[TimerHarness.scala 21:29]
  wire [3:0] deviceAdapter_io_wbMasterReceiver_bits_sel; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_reqOut_valid; // @[TimerHarness.scala 21:29]
  wire [31:0] deviceAdapter_io_reqOut_bits_addrRequest; // @[TimerHarness.scala 21:29]
  wire [31:0] deviceAdapter_io_reqOut_bits_dataRequest; // @[TimerHarness.scala 21:29]
  wire [3:0] deviceAdapter_io_reqOut_bits_activeByteLane; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_reqOut_bits_isWrite; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_rspIn_valid; // @[TimerHarness.scala 21:29]
  wire [31:0] deviceAdapter_io_rspIn_bits_dataResponse; // @[TimerHarness.scala 21:29]
  wire  deviceAdapter_io_rspIn_bits_error; // @[TimerHarness.scala 21:29]
  wire  timer_clock; // @[TimerHarness.scala 22:21]
  wire  timer_reset; // @[TimerHarness.scala 22:21]
  wire  timer_io_req_valid; // @[TimerHarness.scala 22:21]
  wire [31:0] timer_io_req_bits_addrRequest; // @[TimerHarness.scala 22:21]
  wire [31:0] timer_io_req_bits_dataRequest; // @[TimerHarness.scala 22:21]
  wire [3:0] timer_io_req_bits_activeByteLane; // @[TimerHarness.scala 22:21]
  wire  timer_io_req_bits_isWrite; // @[TimerHarness.scala 22:21]
  wire  timer_io_rsp_valid; // @[TimerHarness.scala 22:21]
  wire [31:0] timer_io_rsp_bits_dataResponse; // @[TimerHarness.scala 22:21]
  wire  timer_io_rsp_bits_error; // @[TimerHarness.scala 22:21]
  WishboneHost hostAdapter ( // @[TimerHarness.scala 20:27]
    .clock(hostAdapter_clock),
    .reset(hostAdapter_reset),
    .io_wbMasterTransmitter_ready(hostAdapter_io_wbMasterTransmitter_ready),
    .io_wbMasterTransmitter_valid(hostAdapter_io_wbMasterTransmitter_valid),
    .io_wbMasterTransmitter_bits_cyc(hostAdapter_io_wbMasterTransmitter_bits_cyc),
    .io_wbMasterTransmitter_bits_stb(hostAdapter_io_wbMasterTransmitter_bits_stb),
    .io_wbMasterTransmitter_bits_we(hostAdapter_io_wbMasterTransmitter_bits_we),
    .io_wbMasterTransmitter_bits_adr(hostAdapter_io_wbMasterTransmitter_bits_adr),
    .io_wbMasterTransmitter_bits_dat(hostAdapter_io_wbMasterTransmitter_bits_dat),
    .io_wbMasterTransmitter_bits_sel(hostAdapter_io_wbMasterTransmitter_bits_sel),
    .io_wbSlaveReceiver_ready(hostAdapter_io_wbSlaveReceiver_ready),
    .io_wbSlaveReceiver_bits_ack(hostAdapter_io_wbSlaveReceiver_bits_ack),
    .io_wbSlaveReceiver_bits_dat(hostAdapter_io_wbSlaveReceiver_bits_dat),
    .io_wbSlaveReceiver_bits_err(hostAdapter_io_wbSlaveReceiver_bits_err),
    .io_reqIn_ready(hostAdapter_io_reqIn_ready),
    .io_reqIn_valid(hostAdapter_io_reqIn_valid),
    .io_reqIn_bits_addrRequest(hostAdapter_io_reqIn_bits_addrRequest),
    .io_reqIn_bits_dataRequest(hostAdapter_io_reqIn_bits_dataRequest),
    .io_reqIn_bits_activeByteLane(hostAdapter_io_reqIn_bits_activeByteLane),
    .io_reqIn_bits_isWrite(hostAdapter_io_reqIn_bits_isWrite),
    .io_rspOut_valid(hostAdapter_io_rspOut_valid),
    .io_rspOut_bits_dataResponse(hostAdapter_io_rspOut_bits_dataResponse),
    .io_rspOut_bits_error(hostAdapter_io_rspOut_bits_error)
  );
  WishboneDevice deviceAdapter ( // @[TimerHarness.scala 21:29]
    .io_wbSlaveTransmitter_ready(deviceAdapter_io_wbSlaveTransmitter_ready),
    .io_wbSlaveTransmitter_bits_ack(deviceAdapter_io_wbSlaveTransmitter_bits_ack),
    .io_wbSlaveTransmitter_bits_dat(deviceAdapter_io_wbSlaveTransmitter_bits_dat),
    .io_wbSlaveTransmitter_bits_err(deviceAdapter_io_wbSlaveTransmitter_bits_err),
    .io_wbMasterReceiver_ready(deviceAdapter_io_wbMasterReceiver_ready),
    .io_wbMasterReceiver_valid(deviceAdapter_io_wbMasterReceiver_valid),
    .io_wbMasterReceiver_bits_cyc(deviceAdapter_io_wbMasterReceiver_bits_cyc),
    .io_wbMasterReceiver_bits_stb(deviceAdapter_io_wbMasterReceiver_bits_stb),
    .io_wbMasterReceiver_bits_we(deviceAdapter_io_wbMasterReceiver_bits_we),
    .io_wbMasterReceiver_bits_adr(deviceAdapter_io_wbMasterReceiver_bits_adr),
    .io_wbMasterReceiver_bits_dat(deviceAdapter_io_wbMasterReceiver_bits_dat),
    .io_wbMasterReceiver_bits_sel(deviceAdapter_io_wbMasterReceiver_bits_sel),
    .io_reqOut_valid(deviceAdapter_io_reqOut_valid),
    .io_reqOut_bits_addrRequest(deviceAdapter_io_reqOut_bits_addrRequest),
    .io_reqOut_bits_dataRequest(deviceAdapter_io_reqOut_bits_dataRequest),
    .io_reqOut_bits_activeByteLane(deviceAdapter_io_reqOut_bits_activeByteLane),
    .io_reqOut_bits_isWrite(deviceAdapter_io_reqOut_bits_isWrite),
    .io_rspIn_valid(deviceAdapter_io_rspIn_valid),
    .io_rspIn_bits_dataResponse(deviceAdapter_io_rspIn_bits_dataResponse),
    .io_rspIn_bits_error(deviceAdapter_io_rspIn_bits_error)
  );
  Timer timer ( // @[TimerHarness.scala 22:21]
    .clock(timer_clock),
    .reset(timer_reset),
    .io_req_valid(timer_io_req_valid),
    .io_req_bits_addrRequest(timer_io_req_bits_addrRequest),
    .io_req_bits_dataRequest(timer_io_req_bits_dataRequest),
    .io_req_bits_activeByteLane(timer_io_req_bits_activeByteLane),
    .io_req_bits_isWrite(timer_io_req_bits_isWrite),
    .io_rsp_valid(timer_io_rsp_valid),
    .io_rsp_bits_dataResponse(timer_io_rsp_bits_dataResponse),
    .io_rsp_bits_error(timer_io_rsp_bits_error)
  );
  assign io_req_ready = hostAdapter_io_reqIn_ready; // @[TimerHarness.scala 24:24]
  assign io_rsp_valid = hostAdapter_io_rspOut_valid; // @[TimerHarness.scala 25:10]
  assign io_rsp_bits_dataResponse = hostAdapter_io_rspOut_bits_dataResponse; // @[TimerHarness.scala 25:10]
  assign io_rsp_bits_error = hostAdapter_io_rspOut_bits_error; // @[TimerHarness.scala 25:10]
  assign io_intr_cmp = 1'h0; // @[TimerHarness.scala 32:15]
  assign hostAdapter_clock = clock;
  assign hostAdapter_reset = reset;
  assign hostAdapter_io_wbMasterTransmitter_ready = deviceAdapter_io_wbMasterReceiver_ready; // @[TimerHarness.scala 26:38]
  assign hostAdapter_io_wbSlaveReceiver_bits_ack = deviceAdapter_io_wbSlaveTransmitter_bits_ack; // @[TimerHarness.scala 27:34]
  assign hostAdapter_io_wbSlaveReceiver_bits_dat = deviceAdapter_io_wbSlaveTransmitter_bits_dat; // @[TimerHarness.scala 27:34]
  assign hostAdapter_io_wbSlaveReceiver_bits_err = deviceAdapter_io_wbSlaveTransmitter_bits_err; // @[TimerHarness.scala 27:34]
  assign hostAdapter_io_reqIn_valid = io_req_valid; // @[TimerHarness.scala 24:24]
  assign hostAdapter_io_reqIn_bits_addrRequest = io_req_bits_addrRequest; // @[TimerHarness.scala 24:24]
  assign hostAdapter_io_reqIn_bits_dataRequest = io_req_bits_dataRequest; // @[TimerHarness.scala 24:24]
  assign hostAdapter_io_reqIn_bits_activeByteLane = io_req_bits_activeByteLane; // @[TimerHarness.scala 24:24]
  assign hostAdapter_io_reqIn_bits_isWrite = io_req_bits_isWrite; // @[TimerHarness.scala 24:24]
  assign deviceAdapter_io_wbSlaveTransmitter_ready = hostAdapter_io_wbSlaveReceiver_ready; // @[TimerHarness.scala 27:34]
  assign deviceAdapter_io_wbMasterReceiver_valid = hostAdapter_io_wbMasterTransmitter_valid; // @[TimerHarness.scala 26:38]
  assign deviceAdapter_io_wbMasterReceiver_bits_cyc = hostAdapter_io_wbMasterTransmitter_bits_cyc; // @[TimerHarness.scala 26:38]
  assign deviceAdapter_io_wbMasterReceiver_bits_stb = hostAdapter_io_wbMasterTransmitter_bits_stb; // @[TimerHarness.scala 26:38]
  assign deviceAdapter_io_wbMasterReceiver_bits_we = hostAdapter_io_wbMasterTransmitter_bits_we; // @[TimerHarness.scala 26:38]
  assign deviceAdapter_io_wbMasterReceiver_bits_adr = hostAdapter_io_wbMasterTransmitter_bits_adr; // @[TimerHarness.scala 26:38]
  assign deviceAdapter_io_wbMasterReceiver_bits_dat = hostAdapter_io_wbMasterTransmitter_bits_dat; // @[TimerHarness.scala 26:38]
  assign deviceAdapter_io_wbMasterReceiver_bits_sel = hostAdapter_io_wbMasterTransmitter_bits_sel; // @[TimerHarness.scala 26:38]
  assign deviceAdapter_io_rspIn_valid = timer_io_rsp_valid; // @[TimerHarness.scala 30:16]
  assign deviceAdapter_io_rspIn_bits_dataResponse = timer_io_rsp_bits_dataResponse; // @[TimerHarness.scala 30:16]
  assign deviceAdapter_io_rspIn_bits_error = timer_io_rsp_bits_error; // @[TimerHarness.scala 30:16]
  assign timer_clock = clock;
  assign timer_reset = reset;
  assign timer_io_req_valid = deviceAdapter_io_reqOut_valid; // @[TimerHarness.scala 29:16]
  assign timer_io_req_bits_addrRequest = deviceAdapter_io_reqOut_bits_addrRequest; // @[TimerHarness.scala 29:16]
  assign timer_io_req_bits_dataRequest = deviceAdapter_io_reqOut_bits_dataRequest; // @[TimerHarness.scala 29:16]
  assign timer_io_req_bits_activeByteLane = deviceAdapter_io_reqOut_bits_activeByteLane; // @[TimerHarness.scala 29:16]
  assign timer_io_req_bits_isWrite = deviceAdapter_io_reqOut_bits_isWrite; // @[TimerHarness.scala 29:16]
endmodule