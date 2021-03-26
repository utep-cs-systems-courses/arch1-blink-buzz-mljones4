#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

unsigned char limit = 1;

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  static char state = 0;
  
  if(switch1_state_down){
    limit = 1;
    state = 0;
    red_on = 1;
    buzzer_set_period(2000);
    
  }else if(switch2_state_down){
    limit = 1;
    state = 0;
    green_on = 1;
    buzzer_set_period(500);
    
  }else if(switch3_state_down){
    limit = 175;
    
    switch(state){
    case 0: buzzer_set_period(500); red_on = 1; green_on = 0; state++; break;
    case 1: buzzer_set_period(1500); red_on = 0; green_on = 1; state++; break;
    case 2: buzzer_set_period(750); red_on = 1; green_on = 0; state++; break;
    case 3: buzzer_set_period(1750); red_on = 0; green_on = 1; state++; break;
    case 4: buzzer_set_period(1000); red_on = 1; green_on = 0; state++; break;
    case 5: buzzer_set_period(2000); red_on = 0; green_on = 1; state = 0; break;
    default: state = 0;
    }
    
  }else if(switch4_state_down){
    limit = 100;
    
    switch(state){
    case 0: buzzer_set_period(2000); red_on = 1; green_on = 0; state++; break;
    case 1: buzzer_set_period(1750); red_on = 0; green_on = 1; state++; break;
    case 2: buzzer_set_period(1500); red_on = 1; green_on = 0; state++; break;
    case 3: buzzer_set_period(1000); red_on = 0; green_on = 1; state++; break;
    case 4: buzzer_set_period(1000); red_on = 0; green_on = 1; state++; break;
    case 5: buzzer_set_period(900); red_on = 1; green_on = 0; state++; break;
    case 6: buzzer_set_period(1008); red_on = 0; green_on = 1; state++; break;
    case 7: buzzer_set_period(1500); red_on = 1; green_on = 0; state = 0; break;
    default: state = 0;
    }
    
  }else{
    limit = 1;
    state = 0;
    red_on = 0;
    green_on = 0;
    buzzer_set_period(0);
  }
  
  led_changed = 1;
  led_update();
}



