build:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o main.c
	avr-gcc -mmcu=atmega328p main.o -o bin.bin
	avr-objcopy -O ihex -R .eeprom bin.bin bin.hex

upload:
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:bin.hex