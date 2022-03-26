module Protocol(
  input         clock,
  input         reset,
  output        io_intr_cmp,
  input         io_enable,
  input         io_reset,
  input  [31:0] io_compare,
  input  [31:0] io_prescalar
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] pre_counter; // @[Protocol.scala 21:30]
  reg [31:0] timer_reg; // @[Protocol.scala 22:28]
  wire [31:0] _pre_counter_T_1 = pre_counter + 32'h1; // @[Protocol.scala 25:36]
  wire [31:0] _timer_reg_T_1 = timer_reg + 32'h1; // @[Protocol.scala 27:32]
  assign io_intr_cmp = timer_reg == io_compare; // @[Protocol.scala 33:20]
  always @(posedge clock) begin
    if (reset) begin // @[Protocol.scala 21:30]
      pre_counter <= 32'h0; // @[Protocol.scala 21:30]
    end else if (pre_counter == 32'h0 & io_enable) begin // @[Protocol.scala 24:43]
      pre_counter <= _pre_counter_T_1; // @[Protocol.scala 25:21]
    end else if (pre_counter == io_prescalar) begin // @[Protocol.scala 26:45]
      pre_counter <= 32'h0; // @[Protocol.scala 28:21]
    end else begin
      pre_counter <= _pre_counter_T_1; // @[Protocol.scala 30:21]
    end
    if (reset) begin // @[Protocol.scala 22:28]
      timer_reg <= 32'h0; // @[Protocol.scala 22:28]
    end else if (!(pre_counter == 32'h0 & io_enable)) begin // @[Protocol.scala 24:43]
      if (pre_counter == io_prescalar) begin // @[Protocol.scala 26:45]
        timer_reg <= _timer_reg_T_1; // @[Protocol.scala 27:19]
      end
    end
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
  pre_counter = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  timer_reg = _RAND_1[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
