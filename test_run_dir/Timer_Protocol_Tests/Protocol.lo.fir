circuit Protocol :
  module Protocol :
    input clock : Clock
    input reset : UInt<1>
    output io_intr_cmp : UInt<1>
    input io_enable : UInt<1>
    input io_reset : UInt<1>
    input io_compare : UInt<32>
    input io_prescalar : UInt<32>

    reg pre_counter : UInt<32>, clock with :
      reset => (UInt<1>("h0"), pre_counter) @[Protocol.scala 21:30]
    reg timer_reg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), timer_reg) @[Protocol.scala 22:28]
    node _T = eq(pre_counter, UInt<1>("h0")) @[Protocol.scala 24:22]
    node _T_1 = and(_T, io_enable) @[Protocol.scala 24:30]
    node _pre_counter_T = add(pre_counter, UInt<1>("h1")) @[Protocol.scala 25:36]
    node _pre_counter_T_1 = tail(_pre_counter_T, 1) @[Protocol.scala 25:36]
    node _T_2 = eq(pre_counter, io_prescalar) @[Protocol.scala 26:28]
    node _timer_reg_T = add(timer_reg, UInt<1>("h1")) @[Protocol.scala 27:32]
    node _timer_reg_T_1 = tail(_timer_reg_T, 1) @[Protocol.scala 27:32]
    node _pre_counter_T_2 = add(pre_counter, UInt<1>("h1")) @[Protocol.scala 30:36]
    node _pre_counter_T_3 = tail(_pre_counter_T_2, 1) @[Protocol.scala 30:36]
    node _GEN_0 = mux(_T_2, _timer_reg_T_1, timer_reg) @[Protocol.scala 26:45 Protocol.scala 27:19 Protocol.scala 22:28]
    node _GEN_1 = mux(_T_2, UInt<1>("h0"), _pre_counter_T_3) @[Protocol.scala 26:45 Protocol.scala 28:21 Protocol.scala 30:21]
    node _GEN_2 = mux(_T_1, _pre_counter_T_1, _GEN_1) @[Protocol.scala 24:43 Protocol.scala 25:21]
    node _GEN_3 = mux(_T_1, timer_reg, _GEN_0) @[Protocol.scala 24:43 Protocol.scala 22:28]
    node _T_3 = eq(timer_reg, io_compare) @[Protocol.scala 33:20]
    node _GEN_4 = mux(_T_3, UInt<1>("h1"), UInt<1>("h0")) @[Protocol.scala 33:35 Protocol.scala 34:21 Protocol.scala 37:21]
    node _GEN_5 = mux(_T_3, UInt<1>("h0"), _GEN_3) @[Protocol.scala 33:35 Protocol.scala 35:19]
    io_intr_cmp <= _GEN_4
    pre_counter <= mux(reset, UInt<32>("h0"), _GEN_2) @[Protocol.scala 21:30 Protocol.scala 21:30]
    timer_reg <= mux(reset, UInt<32>("h0"), _GEN_5) @[Protocol.scala 22:28 Protocol.scala 22:28]
