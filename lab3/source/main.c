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
	//DDRB=0x00;
	DDRC=0xFF;
	PORTA=0xFF;
	//PORTB=0xFF;
	PORTC=0x00;
	unsigned char PenTmpA;
    /* Insert your solution below */

    while (1) {
	PenTmpA= PINA & 0x0F;

	if(PenTmpA==0x00){
	PORTC=0x00;

	}else if((PenTmpA==0x01)||(PenTmpA==0x02)){
	PORTC=0x60;

	}else if((PenTmpA==0x03)||(PenTmpA==0x04)){
	PORTC=0x70;

	}else if((PenTmpA==0x05)||(PenTmpA==0x06)){
	PORTC=0x38;
	
	}else if((PenTmpA>=0x07)&&(PenTmpA<=0x09)){
	PORTC=0x24;
	
	}else if((PenTmpA>=0x0A)&&(PenTmpA<=0x0C)){
	PORTC=0x3E;

	}else if((PenTmpA>= 0x0D) && (PenTmpA<=0x0F)){
	PORTC=0x1F;
}

	
}
 
 
    return 1;
}
