#ifndef TIMER_H
#define TIMER_H

#include "main.h"
void timer_ini(void); //инициализирует таймер0 с делением на 64
                      //так же сдвигает TCNT0 на 6, чтобы была 1000Гц в секунду
ISR(TIMER0_OVF_vect); //просто таймер

#endif
