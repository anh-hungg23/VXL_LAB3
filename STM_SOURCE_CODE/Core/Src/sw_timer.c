/*
 * sw_timer.c
 *
 *  Created on: Oct 25, 2025
 *      Author: anh_hungg23
 */
#include "sw_timer.h"

SoftwareTimer timer1;
SoftwareTimer timer2;
SoftwareTimer timer3;
SoftwareTimer timer4;
SoftwareTimer timerTestLed;
SoftwareTimer timeNoReact;
SoftwareTimer timerBlinky1;
SoftwareTimer timerBlinky2;

void initTimer(SoftwareTimer * t) {
	t->counter = 0;
	t->flag = 0;
}

void setTimer(SoftwareTimer *t, uint32_t duration) {
	t->counter = duration / TICK;
	t->flag = 0 ;
}

void timerRun(SoftwareTimer *t) {
	if (t->counter > 0) {
		t->counter -- ;
		if(t->counter == 0) {
			t->flag = 1;
		}
	}
}

uint8_t isTimerExpired(SoftwareTimer *t) {
	if(t->flag == 1) {
		t->flag = 0;
		return 1;
	}
	return 0;
}
void initAllTimer() {
	initTimer(&timer1);
	initTimer(&timer2);
	initTimer(&timer3);
	initTimer(&timer4);
	initTimer(&timerTestLed);
	initTimer(&timeNoReact);
	initTimer(&timerBlinky1);
	initTimer(&timerBlinky2);
}
