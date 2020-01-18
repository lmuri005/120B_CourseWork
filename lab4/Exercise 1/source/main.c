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


//enum States{sm_start,not_pressed,pressed}state;	// list of states of the system
void Tick()
{

switch(state){
	case start:
	state=not_pressed;
	break;

	defualt:
	state=start;
}
switch(state){
	case not_pressed:
	PORTB=0x01
	break;
	case pressed:
	PORTB=0x02;
	break;
}

}



int main() {
    /* Insert DDR and PORT initializations */

	DDRA=0x00;
	DDRB=0xFF;
	PORTA=0xFF;
	PORTB=0x00;
    /* Insert your solution below */
    while (1) {
//	Tick();
    }
//    return 1;
}
