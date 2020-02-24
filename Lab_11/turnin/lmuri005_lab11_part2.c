/*	Author: lmuri005
 *  Partner(s) Name: Emilio
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original wo
 }

*/


#include <asf.h>

#include <avr/io.h>

#include <avr/interrupt.h>

#ifdef _SIMULATE_

#include "simAVRHeader.h"

#endif
#include <bit.h>
#include <timer.h>
#include <keypad.h>
#include <scheduler.h>
#include <io.c>



unsigned char k = 0;



enum Cursor_States {Start_initial, increment } Cursor_State;

int MoveCursor(int state) {

	switch (state) {

		case Start_initial:

		state = increment ;

		break;

		case increment :

		if (k <= 51) {

			state = increment ;

		}

		else {

			state = Start_initial;

		}

		break;

	}

	

	switch (state) {

		case Start_initial:

		k = 0;

		break;

		case increment :

		++k;

		break;

		default:

		k = 0;

		break;

	}

	return state;

}



enum LCD_States {display} LCD_State;

int Display(int state) {

	static unsigned char statement[69] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'S', '1', '2', '0', 'B', ' ', 'i', 's', ' ', 'L', 'e', 'g', 'e', 'n', 'd', '.', '.', '.', ' ', 'w', 'a', 'i', 't', ' ', 'f', 'o', 'r', ' ', 'i', 't', ' ', 'D', 'A', 'R', 'Y', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

	static unsigned char j, temp;

	temp = k;

	switch(state) {

		case display:

		state = display;

		break;

		default:

		state = display;

		break;

	}

	

	switch (state) {

		case display:

		for (j = 1; j <= 16; ++j) {

			LCD_Cursor(j);

			LCD_WriteData(statement[temp]);

			++temp;

		}

		break;

	}

	return state;

}



int main(void)

{

	DDRC = 0xFF; PORTC = 0x00;

	DDRD = 0xFF; PORTD = 0x00;

	//_task struct declared in scheduler.h

	static _task task_1, task_2; //only one SM

	_task *tasks[] = {&task_1, &task_2}; //task array with one task

	const unsigned short numTasks = sizeof(tasks)/sizeof(_task*); //number of arrays divided by number of tasks?

	

	task_1.state = Start_initial;

	task_1.period = 500;

	task_1.elapsedTime = task_1.period;

	task_1.TickFct = &MoveCursor;

	

	task_2.state = display;

	task_2.period = 500;

	task_2.elapsedTime = task_1.period;

	task_2.TickFct = &Display;

	

	TimerSet(500);

	TimerOn();

	

	LCD_init();

	LCD_ClearScreen();

	

	unsigned char i;

	/* Replace with your application code */

	while (1)

	{

		for (i = 0; i < numTasks; ++i) {

			if (tasks[i]->elapsedTime == tasks[i]->period) {

				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);

				tasks[i]->elapsedTime = 0;

			}

			tasks[i]->elapsedTime += 500;

		}

		while(!TimerFlag);

		TimerFlag = 0;

	}

	return 0;

}
