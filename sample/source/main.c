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
PINA=0xFF;
PORTB=0x00;
	unsigned char PenA0=(PINA & 0xFE);
        unsigned char PenA1=(PINA & 0xFD);
    /* Insert your solution below */
    while (1) {
	if((PenA1==0x00&&PenA0==0x00)){
	PORTB=0x00;	
	}
else if((PenA1==0x00&&PenA0==0x01)){
        PORTB=0X01;
    }

    }
    return 1;
}
