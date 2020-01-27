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
enum states{start,initial,reset,increment, decrement, wait_1,wait_2} state;

void tictoc(){
	unsigned char tmpA;
	
	tmpA=~PINA&0x03;
	
	switch (state){
		case start:
		state=initial;
		break;
		
		case initial:
		if((tmpA&0x03)==0x03){
			state=reset;
			}else if ((tmpA&0x03)==0x02){
			state=decrement;
			}else if((tmpA&0x03)==0x01){
			state=increment;
		}
		break;
		
		case reset:
		if((tmpA&0x03)==0x03){
			state=reset;
			}else if((tmpA&0x03)==0x02){
			state=decrement;
			}else if((tmpA&0x03)==0x01){
			state=increment;
		}else
		state=initial;
		break;
		
		case increment:
		state=wait_1;
		break;
		
		case decrement:
		state=wait_2;
		break;
		
		case wait_1:
		if((tmpA&0x03)==0x01){
			state=increment;
			}else if((tmpA&0x03)==0x02){
			state=decrement;
			}else if((tmpA&0x03)==0x03){
			state=reset;
			}else{
			state=wait_1;
		}
		break;
		
		case wait_2:
		if((tmpA&0x03)==0x02){
			state=decrement;
			}else if((tmpA&0x03)==0x01){
			state=increment;
			}else if((tmpA&0x03)==0x03){
			state=reset;
			}else{
			state=wait_2;
		}
		break;
		
		default:
		state=initial;
		break;
	}
	
	switch(state){
		case start:
		break;
		
		case initial:
		PORTC=0x00;
		break;
		
		case increment:
		if(PORTC<0x09){
			PORTC++;
			}else{
			PORTC=PORTC;
		}
		break;
		
		case decrement:
		if(PORTC>0x00){
			PORTC--;
			}else{
			PORTC=PORTC;
		}
		break;
		
		case wait_1:
		break;
		
		case wait_2:
		break;
		
		case reset:
		PORTC=0x00;
		break;
		
		default:
		break;
	}
}
int main(void) {
	/* Insert DDR and PORT initializations */
	

	DDRA=0x00;
	DDRC=0xFF;

	PORTC=0x00;
	PORTA=0xFF;



	state=start;

	while (1)
	{
		tictoc();
		
		
	}

	return 0;
}


