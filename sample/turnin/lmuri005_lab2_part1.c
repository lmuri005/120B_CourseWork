/*	Author: lmuri005
 *  Partner(s) Name: none
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
DDRA=0x00;
DDRB=0xFF;
PORTA=0xFF;
PORTB=0x00;
	unsigned char PenA0=0x00;
        unsigned char PenA1=PINA&0x02;
    /* Insert your solution below */
    while (1) {
	PenA0=PINA&0x01;
	PenA1=PINA&0x02;
	
	if((PenA1==0x0)&&(PenA0==0x01)){
	PORTB=0x01;	
	}

    else {
PORTB=0x00;
}
}
    return 1;
}
