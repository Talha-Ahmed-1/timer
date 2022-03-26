package jigsaw
import caravan.bus.tilelink.{TLRequest, TLResponse, TilelinkConfig, TilelinkDevice, TilelinkHost}
import caravan.bus.wishbone.{WBRequest, WBResponse, WishboneConfig, WishboneDevice, WishboneHost}
import chisel3._
import chisel3.stage.ChiselStage
import chisel3.util.Decoupled
// import jigsaw.peripherals.spiflash.{Config,Spi}
// import jigsaw.rams.sram._

class TimerHarness(implicit val config: WishboneConfig ) extends Module {
  val io = IO(new Bundle {

    // bus interconnect interfaces
    val req = Flipped(Decoupled(new WBRequest()))
    val rsp = Decoupled(new WBResponse())

    val intr_cmp = Output(Bool())
  })
  val hostAdapter = Module(new WishboneHost())
  val deviceAdapter = Module(new WishboneDevice())
  val timer = Module(new Timer(new WBRequest(), new WBResponse()))

  hostAdapter.io.reqIn <> io.req
  io.rsp <> hostAdapter.io.rspOut
  hostAdapter.io.wbMasterTransmitter <> deviceAdapter.io.wbMasterReceiver
  hostAdapter.io.wbSlaveReceiver <> deviceAdapter.io.wbSlaveTransmitter

  timer.io.req <> deviceAdapter.io.reqOut
  timer.io.rsp <> deviceAdapter.io.rspIn

  timer.io.intr_cmp := timer.io.intr_cmp
}

object TimerDriverWB extends App {
  implicit val config = WishboneConfig(32,32)
//   implicit val spiConfig = Config()
  (new ChiselStage).emitVerilog(new TimerHarness())
}




class TimerHarnessTL(implicit val config: TilelinkConfig ) extends Module {
  val io = IO(new Bundle {

    // bus interconnect interfaces
    val req = Flipped(Decoupled(new TLRequest()))
    val rsp = Decoupled(new TLResponse())

    val intr_cmp = Output(Bool())

  })
  val hostAdapter = Module(new TilelinkHost())
  val deviceAdapter = Module(new TilelinkDevice())
  val timer = Module(new Timer(new TLRequest(), new TLResponse()))

  hostAdapter.io.reqIn <> io.req
  io.rsp <> hostAdapter.io.rspOut
  hostAdapter.io.tlMasterTransmitter <> deviceAdapter.io.tlMasterReceiver
  hostAdapter.io.tlSlaveReceiver <> deviceAdapter.io.tlSlaveTransmitter

  timer.io.req <> deviceAdapter.io.reqOut
  timer.io.rsp <> deviceAdapter.io.rspIn

  timer.io.intr_cmp := timer.io.intr_cmp

}

object TimerDriverTL extends App {
  implicit val config = TilelinkConfig()
//   implicit val spiConfig = Config()
  (new ChiselStage).emitVerilog(new TimerHarnessTL())
}
