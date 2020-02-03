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
volatile unsigned char TimerFlag = 0;

unsigned long _avr_timer_M = 1;

unsigned long _avr_timer_cntcurr = 0;

unsigned char tmpB = 0x00;

unsigned char number = 0;



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

	if(_avr_timer_cntcurr == 0) {

		TimerISR();

		_avr_timer_cntcurr = _avr_timer_M;

	}

}



void TimerSet(unsigned long M) {

	_avr_timer_M = M;

	_avr_timer_cntcurr = _avr_timer_M;

}

signed char i = 0;

enum states {start, wait_1, initial, increment, hold_increment, decrement, hold_decrement, Reset, hold_Reset} state;



void Tick() {

	unsigned char A0 = ~PINA & 0x01;

	unsigned char A1 = ~PINA & 0x02;

	

	switch(state) {

		case start:

		state = initial;

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

		

		case initial:

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

			state = initial;

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

	case initial:

number = 0;


		LCD_Cursor(1);

		LCD_WriteData(number + '0');

		i = 0;

		break;

		case increment:

		if (number < 9) {

			++number;

			LCD_Cursor(1);

			LCD_WriteData(number + '0');

			i = 0;

		}
break;

		

		case hold_increment:

		if(!(i < 10)) {

			if (number < 9) {

				++number;

				LCD_Cursor(1);

				LCD_WriteData(number + '0');

				

			}

			i = 0;

		}

		

		break;

		

		case decrement:

		if (number > 0) {

			number-1;

			LCD_Cursor(1);

			LCD_WriteData(number + '0');

			

			i = 0;

			break;

			

			case hold_decrement:

			if(!(i < 10)) {

				if (number > 0) {

					number-1;

					LCD_Cursor(1);

					LCD_WriteData(number + '0');


				}

				i =0;

			}

			break;

			case Reset:

			number = 0x00;

			LCD_Cursor(1);

			LCD_WriteData(number + '0');

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

		DDRC = 0xFF; PORTC = 0x00;

		DDRD = 0xFF; PORTD = 0x00;
		state = start;

		LCD_init();

		TimerSet(100);

		TimerOn();

    while (1) {
	Tick();

			while(!TimerFlag);

			TimerFlag = 0;
    }
    return 1;
}
