#include "../include/button.h"
void but_ini(void){
  DDRL &= ~(1<<BUTTON);
  PORTL |= (1<<BUTTON);
}

uint8_t button(void){
  if(!(PINL&(1<<BUTTON))) return 1;
  return 0;
}
