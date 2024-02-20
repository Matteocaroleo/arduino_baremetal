#ifndef UART_COMM_H
#define UART_COMM_H
#include <avr/io.h>

//initializes uart connection
void uart_init (uint32_t baud);
void uart_init (uint32_t baud, bool double_speed);
//sends frames with nine data bits
void uart_send (unsigned char data);
void uart_send (unsigned int data);
//reads frames 
unsigned char uart_read();

#endif
