/*
 * setTrafficLed.c
 *
 *  Created on: Oct 26, 2025
 *      Author: anh_hungg23
 */
#include "main.h"
#include "global.h"
#include "setTrafficLed.h"
#include "sw_timer.h"

void turnOffMainLeds() {
	HAL_GPIO_WritePin(YEL1_GPIO_Port, YEL1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YEL3_GPIO_Port, YEL3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN3_GPIO_Port, GREEN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED3_GPIO_Port, RED3_Pin, GPIO_PIN_SET);
}

void turnOffSubLeds() {
	HAL_GPIO_WritePin(YEL2_GPIO_Port, YEL2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YEL4_GPIO_Port, YEL4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN4_GPIO_Port, GREEN4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED4_GPIO_Port, RED4_Pin, GPIO_PIN_SET);
}
void blinkyLedMain(	GPIO_TypeDef * port1, uint16_t pin1,
					GPIO_TypeDef * port2, uint16_t pin2 ){
	if(isTimerExpired(&timerBlinky1)) {
		HAL_GPIO_TogglePin(port1,pin1);
		HAL_GPIO_TogglePin(port2,pin2);
		setTimer(&timerBlinky1, 500);
	}
}

void blinkyLedSub(	GPIO_TypeDef * port1, uint16_t pin1,
					GPIO_TypeDef * port2, uint16_t pin2 ){
	if(isTimerExpired(&timerBlinky2)) {
		HAL_GPIO_TogglePin(port1,pin1);
		HAL_GPIO_TogglePin(port2,pin2);
		setTimer(&timerBlinky2, 500);
	}
}

//=====================================================MAIN LED FUNCTION==============================================================
void redOnMain(void) {
	blinkyLedMain(RED_MAIN_1,RED_MAIN_3);


	HAL_GPIO_WritePin(YEL_MAIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YEL_MAIN_3, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GREEN_MAIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_MAIN_3, GPIO_PIN_SET);

}

void yellowOnMain(void) {
	blinkyLedMain(YEL_MAIN_1,YEL_MAIN_3);

	HAL_GPIO_WritePin(GREEN_MAIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_MAIN_3, GPIO_PIN_SET);

	HAL_GPIO_WritePin(RED_MAIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_MAIN_3, GPIO_PIN_SET);
}

void greenOnMain(void) {
	blinkyLedMain(GREEN_MAIN_1,GREEN_MAIN_3);

	HAL_GPIO_WritePin(RED_MAIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_MAIN_3, GPIO_PIN_SET);

	HAL_GPIO_WritePin(YEL_MAIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YEL_MAIN_3, GPIO_PIN_SET);
}

//=====================================================SUB LED FUNCTION===============================================================
void redOnSub(void) {

	blinkyLedSub(RED_SUB_2, RED_SUB_4);

	HAL_GPIO_WritePin(YEL_SUB_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YEL_SUB_4, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GREEN_SUB_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_SUB_4, GPIO_PIN_SET);
}

void yellowOnSub(void) {
	blinkyLedSub(YEL_SUB_2, YEL_SUB_4);

	HAL_GPIO_WritePin(GREEN_SUB_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_SUB_4, GPIO_PIN_SET);

	HAL_GPIO_WritePin(RED_SUB_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_SUB_4, GPIO_PIN_SET);
}

void greenOnSub(void) {
	blinkyLedSub(GREEN_SUB_2, GREEN_SUB_4);

	HAL_GPIO_WritePin(YEL_SUB_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YEL_SUB_4, GPIO_PIN_SET);

	HAL_GPIO_WritePin(RED_SUB_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_SUB_4, GPIO_PIN_SET);
}

//==========================================================BLINK FUNCTION============================================================

