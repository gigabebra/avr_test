#ifndef MAIN_H
#define MAIN_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include "button.h"
#include "timer.h"
#include "svetofor.h"

#define GREEN_LED   PL7
#define RED_LED     PL6
#define BUTTON      PL5

extern volatile uint16_t tiki;

#endif
