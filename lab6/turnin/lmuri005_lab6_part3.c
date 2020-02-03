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


unsigned char i = 0;

enum state {start, wait_1, initialization, increment, hold_increment, decrement, hold_decrement, Reset, hold_Reset} state;

void TickFct_Latch() {

	unsigned char A0 = ~PINA & 0x01;

	unsigned char A1 = ~PINA & 0x02;

	

	switch(state) {

		case start:

		state = initialization;

		break;

		

		case wait_1:

		if (!A0 && !A1) {

			state = wait_1;

		}

		else if (A0 && !A1) {

			state = increment;

		}

		else if (!A0 && A1) {

			state = decrement;

		}

		else if (A0 && A1) {

			state = Reset;

		}

		break;

		case initialization:

		if (A0 && !A1) {

			state = increment;

		}

		else if (!A0 && A1) {

			state = decrement;

		}

		else if (A0 && A1) {

			state = Reset;

		}

		else if (!A0 && !A1) {

			state = initialization;

		}

		break;

		

		case increment:

		if (A0 && !A1) {

			state = hold_increment;

		}

		else if (A0 && A1) {

			state = Reset;

		}

		else if (!A0 && !A1) {

			state = wait_1;

		}

		break;

		

		case hold_increment:

		if (A0 && !A1) {

			state = hold_increment;

		}

		else if (A0 && A1) {

			state = Reset;

		}

		else if (!A0 && !A1) {

			state = wait_1;

		}

		break;

		

		case decrement:

		if (!A0 && A1) {

			state = hold_decrement;

		}

		else if (!A0 && !A1) {

			state = wait_1;

		}

		else if (A0 && A1) {

			state = Reset;

		}

		break;

		

		case hold_decrement:

		if (!A0 && A1) {

			state = hold_decrement;

		}

		else if (!A0 && !A1) {

			state = wait_1;

		}

		else if (A0 && A1) {

			state = Reset;

		}

		break;

		

		case Reset:

		if (A0 && A1) {

			state = hold_Reset;

		}

		else if (!A0 && !A1) {

			state = wait_1;

		}

		

		case hold_Reset:

		if (A0 && A1) {

			state = hold_Reset;

		}

		else if (!A0 && !A1) {

			state = wait_1;

		}

		break;

	}

	

	switch (state) {

		case wait_1:

		i = 0;

		break;

		

		case initialization:

		PORTB = 0x07;

		i=0;

		break;
		case increment:

		if (PORTB < 9) {

			PORTB = PORTB + 0x01;

			i=0;

		}

		break;
		case hold_increment:

		if(!(i < 10)) {

			if (PORTB < 9) {

				PORTB = PORTB + 0x01;
			}

			i=0;

		}

		

		break;

		

		case decrement:

		if (PORTC > 0) {

			PORTB = PORTB - 0x01;

			i=0;

		}

		break;
		case hold_decrement:

		if(!(i < 10)) {

			if (PORTB > 0) {

				PORTB = PORTB - 0x01;

				

			}

			i=0;

		}

		break;
		case Reset:

		PORTB = 0x00;

		i = 0;

		break;
		case hold_Reset:

		i=0;

		break;
		default:

		break;

	}

	++i;

}
int main(void) {
    
	DDRA = 0x00; PORTA = 0xFF;

	DDRB = 0xFF; PORTB = 0x00;

	TimerSet(100);

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
