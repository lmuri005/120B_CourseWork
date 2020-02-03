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
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


volatile unsigned char TimerFlag = 0;
unsigned long _avr_timer_M = 1;
unsigned long _avr_timer_cntcurr = 0;
unsigned char tmpB = 0x00;

unsigned char button=(~PINA&0x01);
void TimerOn() {
	TCCR1B = 0x0B;
	OCR1A = 125;
	TIMSK1 = 0x02;
	TCNT1 = 0;

	_avr_timer_cntcurr = _avr_timer_M;

	SREG |= 0x80;
}
void TimerOff() {
	TCCR1B = 0x00;
}

void TimerISR() {
	TimerFlag = 1;
}
ISR(TIMER1_COMPA_vect) {
	_avr_timer_cntcurr--;
	if (_avr_timer_cntcurr == 0) {
		TimerISR();
		_avr_timer_cntcurr = _avr_timer_M;
	}
}


enum states {start, initial, toggle1, wait1, toggle2, wait2, toggle3, wait3, reset} state;



void Tick() {

	
	switch(state) {

		case start:

		state = initial;

		break;

		case initial:

		state = toggle1;

		break;

		case toggle1:

		if(button) {

			state = wait1;

		}

		else {

			state = toggle2;

		}

		break;

		case wait1:

		if(button) {

			state = reset;

		}

		else if(!button) {

			state = wait1;

		}

		break;

		case toggle2:

		if(button) {

			state = wait2;

		}

		else {

			state = toggle3;

		}

		break;

		case wait2:

		if(button) {

			state = reset;

		}

		else if(!button){

			state = wait2;

		}

		break;

		case toggle3:

		if(button) {

			state = wait3;

		}

		else {

			state = toggle1;

		}

		break;

		case wait3:

		if(button) {

			state = reset;

		}

		else if(!button){

			state = wait3;

		}

		break;

		case reset:

		state = on1;
		
		if(button) {
		
		state = toggle1;
		
		}
		
	        else if(!button) {
		
	        state = reset;
		
		}
		
		break;
		
		default:
		
		state = initial;
		
																								break;
																							}
																							switch(state) {
		
																							case start:
		break;
case initial:


		tmpB = 0x00;

		PORTB = ~tmpB;

		break;

		case toggle1:
		tmpB = 0x01;

		PORTB = ~tmpB;

		break;

		case wait1:

		break;

		case toggle2:

		tmpB = 0x02;

		PORTB = ~tmpB;

		break;
		case wait2:

		break;

		case toggle3:

		tmpB = 0x04;

		PORTB = ~tmpB;

		break;

		case wait3:

		break;

		default:

		break;

	}

}

int main(void) {
    
	DDRA = 0x00; PORTA = 0xFF;

	DDRB = 0xFF; PORTB = 0x00;

	TimerSet(300);

	TimerOn();

	state = start;

    
    while (1) {
     Tick();
	//led = ~led;
	//PORTB = led;
	while(!TimerFlag){}
        TimerFlag = 0;
    }
    return 1;
}
