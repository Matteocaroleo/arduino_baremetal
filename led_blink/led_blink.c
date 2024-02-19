#include <avr/io.h>
#include <util/delay.h>


int main (void)  {
	//SET PORTB5 AS OUTPUT
	DDRB =0b00100000;

	//startup function
	for (int i = 0; i < 10; i = i+1){
		PORTB = 0b00100000;
		_delay_ms (50);
		PORTB = 0b00000000;
		_delay_ms (50);
	}

	int c = 2;
	while (c > 0){
		PORTB = 0b00100000;
		_delay_ms (1000); // from util lib
		PORTB = 0b00000000;
		_delay_ms (1000);
		c = c-1;
	}
}


