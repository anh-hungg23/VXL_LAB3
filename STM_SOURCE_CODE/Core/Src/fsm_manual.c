/*
 * fsm_manual.c
 *
 *  Created on: Oct 26, 2025
 *      Author: anh_hungg23
 */


#include "main.h"
#include "fsm_auto.h"
#include "fsm_manual.h"
#include "button.h"
#include "setTrafficLed.h"
#include "sw_timer.h"
#include "mode_control.h"
#include "set7SEG.h"
int manual_status = 0;

void fsm_manual_run() {
	switch(manual_status) {
	case MAN_RED:
		redOnMain();
		redOnSub();
		mainTimeRemain = tempRed;
		subTimeRemain  = tempRed;
		updateCountTime(mainTimeRemain, subTimeRemain);
		if(isTimerExpired(&timeNoReact)) {
			mode = MODE_AUTO;
			main_status = MAIN_INIT;
			sub_status  = SUB_INIT;
			setTimer(&timeNoReact,100);
		}
		break;

	case MAN_YEL:
		yellowOnMain();
		yellowOnSub();
		mainTimeRemain = tempYel;
		subTimeRemain  = tempYel;
		updateCountTime(mainTimeRemain, subTimeRemain);
		if(isTimerExpired(&timeNoReact)) {
			mode = MODE_AUTO;
			main_status = MAIN_INIT;
			sub_status  = SUB_INIT;
			setTimer(&timeNoReact,100);
		}

		break;

	case MAN_GREEN:
		greenOnMain();
		greenOnSub();
		mainTimeRemain = tempGreen;
		subTimeRemain  = tempGreen;
		updateCountTime(mainTimeRemain, subTimeRemain);
		if(isTimerExpired(&timeNoReact)) {
			mode = MODE_AUTO;
			main_status = MAIN_INIT;
			sub_status  = SUB_INIT;
			setTimer(&timer1,100);
		}

		break;
	default:
		break;
	}
	updateManualTime();
	saveManualTime();
}

