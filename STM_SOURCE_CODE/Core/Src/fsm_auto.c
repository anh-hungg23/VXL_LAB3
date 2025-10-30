/*
 * fsm_auto.c
 *
 *  Created on: Oct 26, 2025
 *      Author: anh_hungg23
 */

#include "fsm_auto.h"
#include "main.h"
#include "global.h"
#include "setTrafficLed.h"
#include "set7SEG.h"
#include "button.h"
//#include "mode_control.h"

int main_status = 0;
int sub_status = 0;

int timeRed   = 5000;
int timeYel   = 2000;
int timeGreen = 3000;


void fsm_auto_run_main() {
	switch(main_status) {
	case MAIN_INIT:
		turnOffMainLeds();
		if(isTimerExpired(&timer1)) {
			main_status = MAIN_RED;
			mainTimeRemain = timeRed/1000;
			setTimer(&timer1,timeRed);
		}

		break;

	case MAIN_RED:
		redOnMain();
		if(isTimerExpired(&timer1)) {
			main_status = MAIN_GREEN;
			mainTimeRemain = timeGreen/1000;
			setTimer(&timer1,timeGreen);
		}

		break;

	case MAIN_YEL:
		yellowOnMain();
		if(isTimerExpired(&timer1)) {
			main_status = MAIN_RED;
			mainTimeRemain = timeRed/1000;
			setTimer(&timer1,timeRed);
		}


		break;

	case MAIN_GREEN:
		greenOnMain();
		if(isTimerExpired(&timer1)) {
			main_status = MAIN_YEL;
			mainTimeRemain = timeYel/1000;
			setTimer(&timer1,timeYel);
		}
		break;

	default:
		break;
	}
}

void fsm_auto_run_sub() {
	switch(sub_status) {
	case SUB_INIT:
		turnOffSubLeds();
		if(isTimerExpired(&timer2)) {
			sub_status = SUB_GREEN;
			subTimeRemain = timeGreen/1000;
			setTimer(&timer2,timeGreen);
		}

		break;
	case SUB_RED:
		redOnSub();
		if(isTimerExpired(&timer2)) {
			sub_status = SUB_GREEN;
			subTimeRemain = timeGreen/1000;
			setTimer(&timer2,timeGreen);
		}

		break;
	case SUB_YEL:
		yellowOnSub();
		if(isTimerExpired(&timer2)) {
			sub_status = SUB_RED;
			subTimeRemain = timeRed/1000;
			setTimer(&timer2,timeRed);
		}
		break;
	case SUB_GREEN:
		greenOnSub();
		if(isTimerExpired(&timer2)) {
			sub_status = SUB_YEL;
			subTimeRemain = timeYel/1000;
			setTimer(&timer2,timeYel);
		}

		break;
	default:
		break;
	}
}

void fsm_auto_run() {
		fsm_auto_run_main();
		fsm_auto_run_sub();

		updateCountdown();
	}



