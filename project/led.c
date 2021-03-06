#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  //  led_update();
}

void led_update(){
    if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }

}

/*void led_update_switches()
{
  if (switch_state_changed) {
    char ledFlags = 0;

    ledFlags |= switch1_state_down ? LED_RED : 0;
    ledFlags |= switch2_state_down ? LED_GREEN : 0; 
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    }
    }*/

