/*	Author: lmuri005
 *  Partner(s) Name: Emilio
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */

DDRA = 0x00;
	DDRB = 0x00;
	DDRC = 0xFF; 
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
    /* Insert your solution below */
unsigned short counter = 0x00;	
    while (1) {
	
counter = 0;
	
	counter= (PORTA & 0x01) + ((PORTA & 0x02) >> 1) + ((PORTA & 0x04) >> 2) + ((PORTA & 0x08) >> 3) + ((PORTA & 0x10) >> 4) + ((PORTA & 0x20) >> 5) + ((PORTA & 0x40) >> 6) + ((PORTA & 0x80) >> 7)	+ (PORTB & 0x01) + ((PORTB & 0x02) >> 1) + ((PORTB & 0x04) >> 2) + ((PORTB & 0x08) >> 3) + ((PORTB & 0x10) >> 4) + ((PORTB & 0x20) >> 5) + ((PORTB & 0x40) >> 6) + ((PORTB & 0x80) >> 7);

		PORTC = counter; 
}
    return 1;
}
