#include "uart_comm.h" 



void uart_init (uint32_t baud){
	int32_t ubrr = (F_CPU / (16 * baud)) -1
	//Sets baud rate inside register
 	UBRR0H = (unsigned char)(ubrr>>8);
 	UBRR0L = (unsigned char)ubrr;
 	//Enable receiver and transmitter 	
	UCSR0B |=(1 << RXEN0) | (1 << TXEN0);	
   	// Set frame format: 8data, 2stop bit 
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}


void uart_init (uint32_t baud, bool double_speed){
	int32_t ubrr;
	if (double_speed == true){
		UCSR0A |= (1 << U2X0);  
		ubrr = (F_CPU / (8 * baud)) - 1;
	}
	else{ 
	 	ubrr = (F_CPU / (16 * baud)) - 1;
	}
 	//Sets baud rate inside register
 	UBRR0H = (unsigned char)(ubrr>>8);
 	UBRR0L = (unsigned char)ubrr;
 	//Enable receiver and transmitter 	
	UCSR0B |=(1 << RXEN0) | (1 << TXEN0);	
   	// Set frame format: 8data, 2stop bit 
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
 
void uart_send(unsigned int data) {
	// Wait for empty transmit buffer 
   	while ( !( UCSR0A & (1<<UDRE0))){
   		;
    	}	
     	// Copy 9th bit to TXB8 
      	UCSR0B &= ~(1<<TXB80);
       	if ( data & 0x0100 ){
        	UCSR0B |= (1<<TXB80);
	}
        // Put data into buffer, sends the data 
         UDR0 = data;
         
}

void uart_send(unsigned char data){
	// Wait for empty transmit buffer 
	while ( !( UCSR0A & (1<<UDRE0))){
             ;
        }
        // Copy 9th bit to TXB8 
        UCSR0B &= ~(1<<TXB80);
        if ( data & 0x0100 ){
        	UCSR0B |= (1<<TXB80);
	}
        // Put data into buffer, sends the data 
      	UDR0 = data;
	
}

unsigned char uart_read (){

	//Waiting for data to be received	
	while ( !(UCSR0A & (1 << RXC0))){
		;
	}
	//Get and return received data from buffer
	return UDR0;
}
