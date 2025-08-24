MCU = atmega2560
AVRDUDE_MCU = m2560
F_CPU = 16000000
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

