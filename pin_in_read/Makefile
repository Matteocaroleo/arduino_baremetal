objs = pin_in_read.o
source = pin_in_read.c
hex = pin_in_read.hex
binaries = pin_in_read.bin

default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $(objs) $(source)
	avr-gcc -o $(binaries) $(objs)
	avr-objcopy -O ihex -R .eeprom $(binaries) $(hex) 
	sudo avrdude -F -V -c arduino -p  ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$(hex)
