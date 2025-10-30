/*
 * sw_timer.h
 *
 *  Created on: Oct 25, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_SW_TIMER_H_
#define INC_SW_TIMER_H_
#define TICK 10
#include "global.h"

void initTimer(SoftwareTimer *t);
void initAllTimer();
void setTimer(SoftwareTimer *t, uint32_t duration);
void timerRun(SoftwareTimer *t);
uint8_t isTimerExpired();
#endif /* INC_SW_TIMER_H_ */
