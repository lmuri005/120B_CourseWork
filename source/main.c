/*le (1) {
 *
 *     }
 *     Author: lmuri005
 *  Partner(s) Name: 
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
	DDRA=0x00; PORTA=0xFF;
	DDRB=0xFF; PORTB=0x00;	
         unsigned char PUTOA0=(PINA & 0xFE);
        unsigned char PUTOA1=(PINA & 0xFD);
    /* Insert your solution below */
	//unsigned char temp_input=0x00;

    while (1) {
	//temp_input=PINA;
	//PORTB=temp_input;
	 
	if((PUTOA0==0x00&&PUTOA1==0x00)){
	PORTB=0x00;
    } else if((PUTOA1==0x00&&PUTOA0==0x01)){
        PORTB=0X01;

    }else if((PUTOA1==0X01&&PUTOA0==0x00)){
	PORTB=0X00;
    }else if((PUTOA1==0x01&&PUTOA0==0x01)){
	PORTB=0x00;
}

    }
    return 1;
}
