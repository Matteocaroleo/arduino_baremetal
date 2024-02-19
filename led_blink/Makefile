default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led_blink.o led_blink.c
	avr-gcc -o led_blink.bin led_blink.o
	avr-objcopy -O ihex -R .eeprom led_blink.bin led_blink.hex
	sudo avrdude -F -V -c arduino -p  ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led_blink.hex
