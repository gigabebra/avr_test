#include "../include/svetofor.h"

void led_ini(void){
  DDRL |= (1<<GREEN_LED) | (1<<RED_LED);
}



void red(void){
  PORTL &=~(1<<GREEN_LED);
  PORTL |= (1<<RED_LED);
}

void green(void){
  PORTL &=~(1<<RED_LED);
  PORTL |= (1<<GREEN_LED);
}


void blink(uint8_t led){
  PORTL^=(1<<led);
}
