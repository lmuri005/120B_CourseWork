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
enum states {start, stateOne, stateTwo, stateThree} state;

void Tick() {
	PORTB = ~PINB;

	switch (state) { //transitions
		case start:
		state = stateOne;
		break;

		case stateOne:
		state = stateTwo;
		break;

		case stateTwo:
		state = stateThree;
		break;

		case stateThree:
		state = stateOne;
		break;

		default:
		state = start;
		break;
	}

	switch (state){ //actions
		case start:
		led = led & 0x00;
		PORTB = 0x07;
		break;
		case stateOne:
		led = led & 0x06;
		PORTB = 0x01;
		break;
		case stateTwo:
		led = led & 0x05;
		PORTB = 0x02;																				break;			

		case stateThree:
		led=led&0x03;																				//led = led & 0x03;
		PORTB = 0x04;																				break;
																							default:
																							state = start;
																						        break;
																						}
		
																					}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;

	state = start;

	TimerSet(100);
	TimerOn();


    /* Insert your solution below */
    while (1) {
     Tick();
	led = ~led;
	PORTB = led;
	while(!TimerFlag){}
        TimerFlag = 0;
    }
    return 1;
}
