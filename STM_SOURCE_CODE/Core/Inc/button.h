/*
 * button.h
 *
 *  Created on: Oct 26, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET



void getKeyInput();
void initAllButtons();
uint8_t isButtonPressed(Button *btn);

#endif /* INC_BUTTON_H_ */
