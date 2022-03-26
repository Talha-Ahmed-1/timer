package timer

import chisel3._
import chisel3 . util._
import caravan.bus.tilelink._
import org.scalatest._
import chisel3.experimental._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation
import caravan.bus.wishbone.WishboneConfig
import caravan.bus.tilelink.TilelinkConfig
import timer._
// import TimerHarness

class TimerTester extends FreeSpec with ChiselScalatestTester {

  "Timer Tests" in {
    implicit val config = WishboneConfig(32,32)
    // implicit val config = TilelinkConfig()
    // implicit val spiConfig = jigsaw.peripherals.spiflash.Config()
    test(new TimerHarness()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
      // c.io.req.bits.addrRequest.poke(0.U)
      // c.io.req.bits.dataRequest.poke(0.U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // c.io.req.bits.isWrite.poke(1.B)
      // c.io.req.valid.poke(1.B)
      // c.clock.step(1)
      // c.io.req.valid.poke(0.B)
      // c.clock.step(1)
      // c.io.req.bits.dataRequest.poke(659.U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // // c.io.req.bits.dataRequest.poke("b00000011101110111011101110111011".U)
      // c.io.req.bits.addrRequest.poke(3.U)
      // c.io.req.bits.isWrite.poke(1.B)
      // c.io.req.valid.poke(1.B)
      // c.clock.step(5)
      // c.io.req.valid.poke(0.B)


    ///////////Set Control Register////////////
      // c.io.req.bits.addrRequest.poke(0.U)
      // c.io.req.bits.dataRequest.poke("b0000".U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // c.io.req.bits.isWrite.poke(1.B)
      // c.io.req.valid.poke(1.B)
      // c.io.rsp.ready.poke(1.B)
      // c.clock.step(2)
      // c.io.req.valid.poke(0.B)
    ///////////Read Control Register////////////
      // c.io.req.bits.addrRequest.poke(0.U)
      // c.io.req.bits.dataRequest.poke(3.U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // c.io.req.bits.isWrite.poke(0.B)
      // c.io.req.valid.poke(1.B)
      // c.io.rsp.ready.poke(1.B)
      // c.clock.step(2)
      // c.io.req.valid.poke(0.B)
    ///////////Set Tx Register////////////
      c.io.req.bits.addrRequest.poke(0.U)
      c.io.req.bits.dataRequest.poke(659.U)
      c.io.req.bits.activeByteLane.poke("b1111".U)
      c.io.req.bits.isWrite.poke(0.B)
      c.io.req.valid.poke(1.B)
      c.clock.step(1)
      c.io.req.valid.poke(0.B)
      c.clock.step(100)
    ///////////Set Control Register////////////
      // c.io.req.bits.addrRequest.poke(12.U)
      // c.io.req.bits.dataRequest.poke("b0000100".U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // c.io.req.bits.isWrite.poke(1.B)
      // c.io.req.valid.poke(1.B)
      // c.io.rsp.ready.poke(1.B)
      // c.clock.step(3)
      // c.io.req.bits.addrRequest.poke(0.U)
      // c.io.req.valid.poke(0.B)
      // c.io.req.bits.dataRequest.poke("b0000000".U)
      // c.io.req.bits.isWrite.poke(1.B)
      // c.io.req.valid.poke(1.B)
      // c.clock.step(3)
      // c.io.req.valid.poke(0.B)
    ///////////Read Tx Register////////////
      // c.io.req.bits.addrRequest.poke(3.U)
      // c.io.req.bits.dataRequest.poke(0.U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // c.io.req.bits.isWrite.poke(0.B)
      // c.io.req.valid.poke(1.B)
      // c.io.rsp.ready.poke(1.B)
      // c.clock.step(2)
      // c.io.req.valid.poke(0.B)
    ///////////Read Rx Register////////////
      // c.io.req.bits.addrRequest.poke(7.U)
      // c.io.req.bits.dataRequest.poke(0.U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // c.io.req.bits.isWrite.poke(0.B)
      // c.io.req.valid.poke(1.B)
      // c.io.rsp.ready.poke(1.B)
      // c.clock.step(20)
      // c.io.req.valid.poke(0.B)


    //   var count = 1
    //   while(count != 900) {
    //     //
    //     // c.io.req.bits.addrRequest.poke(8.U)
    //     // c.io.req.bits.isWrite.poke(0.B)
    //     // c.io.req.valid.poke(1.B)
    //     // c.io.rsp.ready.poke(1.B)
    //     //
    //       val mosi = c.io.mosi.peek()
    //       c.io.miso.poke(mosi)
    //       c.clock.step(1)
    //       count += 1
    //   }


    }
  }
}