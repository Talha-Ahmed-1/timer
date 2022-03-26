;buildInfoPackage: chisel3, version: 3.4.3, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit Protocol : 
  module Protocol : 
    input clock : Clock
    input reset : UInt<1>
    output io : {intr_cmp : UInt<1>, flip enable : UInt<1>, flip reset : UInt<1>, flip compare : UInt<32>, flip prescalar : UInt<32>}
    
    reg pre_counter : UInt<32>, clock with : (reset => (reset, UInt<32>("h00"))) @[Protocol.scala 21:30]
    reg timer_reg : UInt<32>, clock with : (reset => (reset, UInt<32>("h00"))) @[Protocol.scala 22:28]
    node _T = eq(pre_counter, UInt<1>("h00")) @[Protocol.scala 24:22]
    node _T_1 = and(_T, io.enable) @[Protocol.scala 24:30]
    when _T_1 : @[Protocol.scala 24:43]
      node _pre_counter_T = add(pre_counter, UInt<1>("h01")) @[Protocol.scala 25:36]
      node _pre_counter_T_1 = tail(_pre_counter_T, 1) @[Protocol.scala 25:36]
      pre_counter <= _pre_counter_T_1 @[Protocol.scala 25:21]
      skip @[Protocol.scala 24:43]
    else : @[Protocol.scala 26:45]
      node _T_2 = eq(pre_counter, io.prescalar) @[Protocol.scala 26:28]
      when _T_2 : @[Protocol.scala 26:45]
        node _timer_reg_T = add(timer_reg, UInt<1>("h01")) @[Protocol.scala 27:32]
        node _timer_reg_T_1 = tail(_timer_reg_T, 1) @[Protocol.scala 27:32]
        timer_reg <= _timer_reg_T_1 @[Protocol.scala 27:19]
        pre_counter <= UInt<1>("h00") @[Protocol.scala 28:21]
        skip @[Protocol.scala 26:45]
      else : @[Protocol.scala 29:16]
        node _pre_counter_T_2 = add(pre_counter, UInt<1>("h01")) @[Protocol.scala 30:36]
        node _pre_counter_T_3 = tail(_pre_counter_T_2, 1) @[Protocol.scala 30:36]
        pre_counter <= _pre_counter_T_3 @[Protocol.scala 30:21]
        skip @[Protocol.scala 29:16]
    node _T_3 = eq(timer_reg, io.compare) @[Protocol.scala 33:20]
    when _T_3 : @[Protocol.scala 33:35]
      io.intr_cmp <= UInt<1>("h01") @[Protocol.scala 34:21]
      timer_reg <= UInt<1>("h00") @[Protocol.scala 35:19]
      skip @[Protocol.scala 33:35]
    else : @[Protocol.scala 36:16]
      io.intr_cmp <= UInt<1>("h00") @[Protocol.scala 37:21]
      skip @[Protocol.scala 36:16]
    
