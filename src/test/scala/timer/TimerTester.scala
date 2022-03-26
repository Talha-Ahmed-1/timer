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

  // "Timer Protocol Tests" in {
  //   test(new Protocol()) { c =>

  //   c.io.enable.poke(1.B)
  //   c.io.prescalar.poke(2.U)
  //   c.io.compare.poke(10.U)
    
  //   c.clock.step(100)
  // }
  // }

  "Timer Tests" in {
    implicit val config = WishboneConfig(32,32)
    // implicit val config = TilelinkConfig()
    test(new TimerHarness()) { c =>
    ///////////Set Tx Register////////////
      c.io.req.bits.addrRequest.poke(8.U)
      c.io.req.bits.dataRequest.poke(1.U)
      c.io.req.bits.activeByteLane.poke("b1111".U)
      c.io.req.bits.isWrite.poke(1.B)
      c.io.req.valid.poke(1.B)
      c.clock.step(1)
      c.io.req.valid.poke(0.B)
      // c.clock.step(1)
      // c.io.req.bits.addrRequest.poke(4.U)
      // c.io.req.bits.dataRequest.poke("b11000".U)
      // c.io.req.bits.activeByteLane.poke("b1111".U)
      // c.io.req.bits.isWrite.poke(1.B)
      // c.io.req.valid.poke(1.B)
      c.clock.step(2)
      c.io.req.bits.addrRequest.poke(4.U)
      c.io.req.bits.dataRequest.poke("b11".U)
      c.io.req.bits.activeByteLane.poke("b1111".U)
      c.io.req.bits.isWrite.poke(1.B)
      c.io.req.valid.poke(1.B)
      // c.io.req.valid.poke(0.B)
      c.clock.step(200)
    }
  }
}