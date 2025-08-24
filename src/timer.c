#include "../include/timer.h"


void timer_ini(void){
  TCCR0B |= (1 << CS01) | (1 << CS00);
  TCCR0B &= ~(1 << CS02);
  TIMSK0 |= (1 << TOIE0);
  TCNT0 = 6; // 1600000МГц/64/(256-6)=1000Гц/в секунду
  // 64 -- это из даташита CS0n 
  // 256 -- потому что таймер 8 бит
  // -6 -- это для удобства, чтобы красивое число Гц в се
  sei();
}

ISR(TIMER0_OVF_vect){
  if(tiki)tiki--;
  TCNT0 = 6;
}
