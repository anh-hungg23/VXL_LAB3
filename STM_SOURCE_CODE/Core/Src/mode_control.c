/*
 * changeMode.c
 *
 *  Created on: Oct 29, 2025
 *      Author: anh_hungg23
 */

#include "main.h"
#include "global.h"
#include "button.h"
#include "mode_control.h"
#include "sw_timer.h"

int mode 		= 0;
int tempRed 	= 0;
int tempYel 	= 0;
int tempGreen 	= 0;

int backupRed = 0;
int backupYel = 0;
int backupGreen = 0;
uint8_t isEditted;

void switchManualState() {
	if(manual_status == MAN_RED) manual_status = MAN_YEL;
	else if (manual_status == MAN_YEL) manual_status = MAN_GREEN;
	else if (manual_status == MAN_GREEN) {
		mode = MODE_AUTO;
		main_status = MAIN_INIT;
		sub_status = SUB_INIT;
	}
}

int clamp(int value){
	if(value < 1) return 1;
	if(value > 99) return 1;
	return value;
}

void entryState(int state) {
	manual_status = state;

	tempRed   = timeRed / 1000;
	tempYel   = timeYel / 1000;
	tempGreen = timeGreen / 1000;

	backupRed = tempRed;
	backupYel = tempYel;
	backupGreen = tempGreen;

	isEditted = 0;

	setTimer(&timeNoReact,10000);
}

void restoreBackup() {
	tempRed = backupRed;
	tempYel = backupYel;
	tempGreen = backupGreen;

	isEditted = 0;
}

void checkMode() {
	if(isButtonPressed(&button1)) {
		if(mode == MODE_AUTO){
			mode = MODE_MANUAL;

			entryState(MAN_RED);
		} else {
			if(isEditted == 1) {
				restoreBackup();
			}
			switchManualState();
		}
	}
}

void updateManualTime() {
	if(isButtonPressed(&button2) && (mode == MODE_MANUAL)) {
		isEditted = 1;

		setTimer(&timeNoReact,10000);

		switch(manual_status) {
		case MAN_RED:
			tempRed   += 1;
			tempGreen = tempRed - tempYel;
			break;

		case MAN_YEL:
			tempYel		+= 1;
			tempGreen 	= tempRed - tempYel;
			break;

		case MAN_GREEN:
			tempGreen	+= 1;
			tempYel		= tempRed - tempGreen;
			break;

		default:
			break;
		}
		tempRed    = clamp(tempRed);
		tempGreen  = clamp(tempGreen);
		tempYel    = clamp(tempYel);

	}
}

void saveManualTime(){
	if(isButtonPressed(&button3) && mode == MODE_MANUAL){
		if(tempRed != (tempYel + tempGreen)) {
			tempRed = CONST_RED;
			tempYel = CONST_YEL;
			tempGreen = CONST_GREEN;
		}
		switch(manual_status) {
		case MAN_RED:
			timeRed   = tempRed   * 1000;
			timeGreen = tempGreen * 1000;
			break;
		case MAN_YEL:
			timeYel	  = tempYel   * 1000;
			timeRed   = tempRed   * 1000;
			break;
		case MAN_GREEN:
			timeGreen = tempGreen * 1000;
			timeRed   = tempRed   * 1000;
			break;
		default:
			break;

		}
		isEditted = 0;

        backupRed   = tempRed;
        backupYel   = tempYel;
        backupGreen = tempGreen;
	}
}
