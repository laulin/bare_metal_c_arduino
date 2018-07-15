installation
============
sudo apt-get install gcc-avr binutils-avr avr-libc
sudo apt-get install avrdude

compilation et upload
=====================
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o main.c
avr-gcc -mmcu=atmega328p main.o -o bin
avr-objcopy -O ihex -R .eeprom bin bin.hex
sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:bin.hex

test 1 : clignotement de led
============================

Pour les lib std il faut declarer 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

Permet par exemple le calcul du temps.

#include <avr/io.h>
#include <util/delay.h>

io pour les ports
delay pour delay_ms

DDRX == conf
PORTX == ecriture
PINDX == lecture

digital 13 => led embedded
digital 13 => PB5 => 0x20 (1= output, 0= read)

test 2 : lire un bouton et allumer une led
==========================================

mettre 1 dans DDRB pour PB4 (0x10)
mettre 1 dans PORTB pour avoir un pullup
