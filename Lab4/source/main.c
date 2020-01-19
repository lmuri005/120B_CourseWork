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

enum states{start,not_pressed,pressed_1,release_1,pressed_2}state;

void lightonfunc(){
unsigned char tmpA0;

tmpA0=PINA&0x01;

switch (state){
	case start:
	state=not_pressed;
	break;

	case not_pressed:
	if(tmpA0==0x01){
	state=pressed;
	}else if(tmpA0==0x00)
	state=release_1;
	}
	break;
	
	case pressed_1:
	if(tmpA0==0x01){
	state=pressed;
	}else if(tmpA0==0x01){
	state= release_2;
	}
	break;

	case release_1:
	if(tmpA0==0x01){
	state= release_2;
	}else if (tmpA0==0x00){
	state=release_1;
	}
	break;
	
	default:
	state=start;
	break; 
}
switch(state){
	case start:
	break;
	case not_pressed:
	PORTB=0x01;
	break;

	case pressed_1:
	PORTB=0x02;
	break;
 
	case release_1:
	PORTB=0x02;
	break;

	case release_2:
	PORTB=0x01;
	break; 	
	default:
	break;


}


}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA=0x00;
	DDRB=0xFF;
	PORTA=0xFF;
	PORTB=0x00;
    /* Insert your solution below */
    while (1) {
	state=start;
	lightonfunc();
    }
    return 1;
}
