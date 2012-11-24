#include "bfin_core.h"
#include "ccblkfn.h"
#include "sysreg.h"
#include "init.h"
#include "module.h"

//-------------------------------
// main function
int main(void) {
  // turn on execution counter
  // default .crt does this for us
  //  __asm__ __volatile__("R0 = 0x32; SYSCFG = R0; CSYNC;":::"R0");
  
  // intialize the sdram controller
  init_EBIU();
  // intialize the flash controller (which, weirdly, handles gpio)
  init_flash();
  // initialize the codec (spi in master, blast config regs, disable spi)
  init_1836();
  // intialize the sport0 for audio rx/tx
  init_sport0();
  // intialize the DMA to shove audio data around
  init_DMA();
  // put the spi back in slave mode to receive param changes from avr32
  init_spi_slave();
  // intialize the audio processing unit (assign memory)
  init_module();
  // assign interrupts
  init_interrupts();
  // start the audio engine
  enable_DMA_sport0();  

  // TEST
  *pFlashA_PortB_Data = 0x05;

  while(1) {
    
  }
}

