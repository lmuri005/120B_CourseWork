/*	Author: lmuri005
 *  Partner(s) Name: Emilio Gonzales
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
	
DDRB=0xFF;
DDRA=0x00;

PORTB=0x00;
PORTA=0xFF;


unsigned char PenTmpA;


while (1)
{
	
	PenTmpA= ~PINA & 0x0F;
	

	if(PenTmpA==0x00){ // LED stay on for some reason

		PORTB=0x00;


		}else if((PenTmpA==0x01)||(PenTmpA==0x02)){

		PORTB=0x60;


		}else if((PenTmpA==0x03)||(PenTmpA==0x04)){

		PORTB=0x70;



		}else if((PenTmpA>=0x05)&&(PenTmpA<=0x06)){

		PORTB=0x38;


		}else if((PenTmpA>=0x07)&&(PenTmpA<=0x09)){

		PORTB=0x3c;

		

		}else if((PenTmpA>=0x0A)&&(PenTmpA<=0x0C)){

		PORTB=0x3E;



		}else if((PenTmpA>= 0x0D) && (PenTmpA<=0x0F)){

		PORTB=0x3F;
		
	}
	
	
}

return 0;
}

