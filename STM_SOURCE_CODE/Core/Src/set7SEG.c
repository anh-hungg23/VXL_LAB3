/*
 * set7SEG.c
 *
 *  Created on: Oct 27, 2025
 *      Author: anh_hungg23
 */
#include "main.h"
#include "global.h"
#include "set7SEG.h"
#include "fsm_auto.h"
#include "mode_control.h"
#include "fsm_manual.h"

int time_buffer[6] ;
int led_idx = 0;

int mainTimeRemain = 0;
int subTimeRemain = 0;

void display7SEG (int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}

void updateCountTime (int mainTime, int subTime) {
	time_buffer[1] = mainTime / 10;
	time_buffer[2] = mainTime % 10;

	time_buffer[4] = subTime / 10;
	time_buffer[5] = subTime % 10;

	if(mode == MODE_AUTO) {
		time_buffer[0] = 1;
		time_buffer[3] = 1;
	}
	else {
		switch(manual_status) {
		case MAN_RED:   time_buffer[0] = 2; break;
		case MAN_YEL:   time_buffer[0] = 3; break;
		case MAN_GREEN: time_buffer[0] = 4; break;
		}
		time_buffer[3] = time_buffer[0];
	}
}
void showTime(int led_idx) {
	HAL_GPIO_WritePin(GPIOB,EN1_Pin| EN2_Pin | EN3_Pin | EN4_Pin | EN5_Pin | EN6_Pin, SET);
	display7SEG(time_buffer[led_idx]);
	switch(led_idx) {
	case 0:
		HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin, RESET);
		break;

	case 1:
		HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin,RESET);
		break;

	case 2:
		HAL_GPIO_WritePin(EN3_GPIO_Port,EN3_Pin,RESET);
		break;

	case 3:
		HAL_GPIO_WritePin(EN4_GPIO_Port,EN4_Pin,RESET);
		break;

	case 4:
		HAL_GPIO_WritePin(EN5_GPIO_Port,EN5_Pin, RESET);
		break;

	case 5:
		HAL_GPIO_WritePin(EN6_GPIO_Port,EN6_Pin, RESET);
		break;


	default:
		break;
	}
}

void updateCountdown() {
	if(isTimerExpired(&timer3)) {
		setTimer(&timer3,1000);
		if(mainTimeRemain > 0) mainTimeRemain -- ;
		if(subTimeRemain > 0) subTimeRemain --;
		updateCountTime(mainTimeRemain,subTimeRemain);
	}
}

