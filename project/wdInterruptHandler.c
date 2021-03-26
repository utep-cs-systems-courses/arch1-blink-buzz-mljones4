#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  
  if(switch4_state_down){
    if (++blink_count == 125) {
      state_advance();
      blink_count = 0;
    }
  }else{
    blink_count = 0;
  }
  
}
