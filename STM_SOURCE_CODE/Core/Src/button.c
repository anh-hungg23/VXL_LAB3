/*
 * button.c
 *
 *  Created on: Oct 26, 2025
 *      Author: anh_hungg23
 */


#include "global.h"
#include "button.h"

Button button1;
Button button2;
Button button3;


void initButton (Button * btn, GPIO_TypeDef * port, uint16_t pin) {
	btn -> PORT = port;
	btn -> PIN  = pin;
	btn -> keyReg0 = btn -> keyReg1 = btn -> keyReg2 = NORMAL_STATE;
	btn -> keyReg3 = NORMAL_STATE;
	btn -> timerForPress = 200;
	btn -> pressFlag = 0;
}

void getKeyInput(Button * btn) {
	btn -> keyReg0 = btn -> keyReg1;
	btn -> keyReg1 = btn -> keyReg2;
	btn -> keyReg2 = HAL_GPIO_ReadPin(btn -> PORT, btn -> PIN);
	if ((btn -> keyReg0 == btn -> keyReg1) && (btn -> keyReg1 == btn -> keyReg2) ) {
		if (btn -> keyReg3 != btn -> keyReg2) {
			btn -> keyReg3 = btn -> keyReg2;
			if(btn -> keyReg2 == PRESSED_STATE) {
				//TODO

				btn -> pressFlag = 1;
				btn -> timerForPress = 200;
			}
		} else {
			btn -> timerForPress --;
			if (btn -> timerForPress == 0) {
				if(btn -> keyReg2 == PRESSED_STATE) {
					//TODO

					btn -> pressFlag = 1;
					btn -> timerForPress = 200;
				}
			}
		}
	}
}

void initAllButtons() {
	initButton(&button1, but_1_GPIO_Port, but_1_Pin);
	initButton(&button2, but_2_GPIO_Port, but_2_Pin);
	initButton(&button3, but_3_GPIO_Port, but_3_Pin);
}

uint8_t isButtonPressed(Button* btn) {
	if (btn -> pressFlag == 1) {
		btn -> pressFlag = 0;
		return 1;
	}
	return 0;
}

