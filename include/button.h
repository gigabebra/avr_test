#ifndef BUTTON_H
#define BUTTON_H

#include "main.h"
void but_ini(void); // инициализирует кнпоку BUTTON с внутренним подтягивающим резистором
uint8_t button(void); //возвращает 1 если кнопка нажата, иначе 0
#endif
