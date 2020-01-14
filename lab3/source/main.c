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
	DDRA=0x00;
	DDRB=0x00;
	DDRC=0xFF;
	PORTA=0xFF;
	PORTB=0xFF;
	PORTC=0x00;
	unsigned char PenA1;
	unsigned char PenB1;
	unsigned char counter;
    /* Insert your solution below */
    while (1) 
	PenA1=PORTA&0x01;
	if((PenA1==0x01)||(PenB1==0x01)){
	counter ++;
}

PORTC=counter; 
    }
    return 1;
}
