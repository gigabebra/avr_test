#include "../include/main.h"

volatile uint16_t tiki = 0;

int main(void){
  led_ini();
  but_ini();
  timer_ini();

  uint8_t status=0;
  uint8_t migalka=0;

  while(1){
    switch (status) {
      case 0:
        red();
        tiki=2000;
        status=1;
        break;
      case 1:
        if(!tiki || button()) {status=2; migalka=4; tiki=500;}
        break;
      case 2:
        if(!tiki){
          blink(RED_LED);
          if(migalka){
            migalka--;
            tiki=500;
          }
          else {
            status=10;
          }
        }
        break;
      case 10:
        green();
        tiki=1000;
        status=11;
        break;
      case 11:
        if(!tiki) {status=12; migalka=4; tiki=400;}
        break;
      case 12:
        if(!tiki){
          blink(GREEN_LED);
          if(migalka){
            migalka--;
            tiki=400;
          }
          else {
            status=0;
          }
        }
        break;
        
    }
  }
  return 0;
}
