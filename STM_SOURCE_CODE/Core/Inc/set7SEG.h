/*
 * set7SEG.h
 *
 *  Created on: Oct 27, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_SET7SEG_H_
#define INC_SET7SEG_H_

#include "main.h"
#include "global.h"
#include "fsm_auto.h"


void display7SEG (int num);

void showTime(int num);

void updateCountTime(int mainTime, int subTime);

void showMode();

void updateCountdown();

#endif /* INC_SET7SEG_H_ */
