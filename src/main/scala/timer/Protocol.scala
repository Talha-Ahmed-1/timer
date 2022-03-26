package timer

import chisel3._
import chisel3.util._

class Protocol_IO extends Bundle{
    val intr_cmp = Output(Bool())
    val enable   = Input(Bool())
    val reset    = Input(Bool())
    val compare  = Input(UInt(32.W))
    val prescalar= Input(UInt(32.W))
}

class Protocol extends Module{
    val io = IO(new Protocol_IO)

    // val cmp_reg = RegInit(0.U(32.W))
    // cmp_reg := io.compare
    // val pre_reg = RegInit(0.U(32.W))
    // pre_reg := io.prescalar
    val pre_counter = RegInit(0.U(32.W))
    val timer_reg = RegInit(0.U(32.W))

    when(pre_counter === 0.U && io.enable){
        pre_counter := pre_counter + 1.U
    }.elsewhen(pre_counter === io.prescalar){
        timer_reg := timer_reg + 1.U
        pre_counter := 0.U
    }.otherwise{
        pre_counter := pre_counter + 1.U
    }

    when(timer_reg === io.compare){
        io.intr_cmp := true.B
        timer_reg := 0.U
    }.otherwise{
        io.intr_cmp := false.B
    }


}