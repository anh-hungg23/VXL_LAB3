/*
 * mode_control.h
 *
 *  Created on: Oct 29, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_MODE_CONTROL_H_
#define INC_MODE_CONTROL_H_

#include "main.h"
#include "button.h"
#include "global.h"
void entryState(int state);
void checkMode();
void updateManualTime();
void saveManualTime();
int clamp(int value);
void switchManualMode();

#endif /* INC_MODE_CONTROL_H_ */
