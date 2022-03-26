# Timer

Timer is implemented in chisel and it has generic interface which can be easily attached with any System on Chip (SoC) by using [Jigsaw](https://github.com/talha-ahmed-1/jigsaw) framework and it also depends upon [Caravan](https://github.com/merledu/caravan).

#### Jigsaw
Jigsaw aims to be a helpful utility that provides the designers with pre-made useful peripherals + other ip blocks that provides re-usability and agile development of System On Chips.

#### Caravan
Caravan intends to be equipped with a fully fledged API for easily creating open source bus protocols in Chisel based designs.

### Timer Interupts

1. **cio_timer_intr_ovf**  ## when timer register is equal to 0xFFFFFFFF it goes high.
2. **cio_timer_intr_cmp** ## when timer register is equal to CompareReg it goes high.

### Timer Registers

| Registers         | Offsets | Type | Description
| ----------------- | ------- | ---- | ------------------------------------------------------------------------------------------------------------------ |
| TimerReg[31:0]    | 0x0     | RO   | It is basically a counter register which counts up and generate interrupt when it gets equal to CompareReg.        |
| ControlReg[31:0]  | 0x4     | RW   | It is controll reg which helps to get control over the timer.                                                      |
| CompareReg[31:0]  | 0x8     | RW   | It is used to run timer until timer reached at max level which is stored in CompareReg.                            |
| PreCountReg[31:0] | 0xc     | RO   | It is prescalar register, prescalar values are stored in it and it helps to run the timer counter according to it. |

1. **ControlReg[0]**    = Enable/Disable
2. **ControlReg[31:1]** = Prescalar

### Running program after connecting it with SoC

```
li x15 0x40002000 # load TIMER base address
li x8 10          # load CompareReg value
li x9 0b11001     # load prescalar value along with enable bit

sw x8 0x8(x15)    # configure CompareReg
sw x9 0x4(x15)    # configure ControlReg
```
