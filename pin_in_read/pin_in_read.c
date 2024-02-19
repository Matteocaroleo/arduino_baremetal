#include <avr/io.h>
#include <util/delay.h>


//reads from pin 5 if high -> turn in built-in led
int main (void){
	//Sets built-led as output
	DDRB |= _BV (DDB5);	
	
	//BV converts value to byte, in Data Direction Register 0 = input
	DDRD &= ~_BV (DDD5);
	
	//use pull-up resistor from board, 1 = use pull-up
	PORTD |= _BV (PORTD5);
 
	while (1){
		_delay_ms (50);
		//Read from Port D Pin Input Register
		uint8_t pin_value = PIND & _BV (DDD5);

		//Because there is pull-up, when switch is off -> pin_value is high
		if (pin_value == 0)

			//Turn on built-in led
			PORTB |= _BV (DDB5);
		else 
			//Turn off built-in led
			PORTB &= ~_BV (DDB5);
	}
	return 0;
} 

