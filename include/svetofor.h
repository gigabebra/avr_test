#ifndef SVETOFOR_H
#define SVETOFOR_H

#include "main.h"
void led_ini(void); //инициализирует два светодиода
void red(void); // включает красный, выключает зеленый
void green(void); // включает зеленый, выключает красный
void blink(uint8_t led); // переключает состояние данного светодиода

#endif
