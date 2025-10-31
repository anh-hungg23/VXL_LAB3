/*
 * global.h
 *
 *  Created on: Oct 25, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"


//===================================START SOFTWARE TIMER VARIABLES==================================================================
#define MAX_TIMER 10
typedef struct {
	uint32_t counter;
	uint8_t flag;
} SoftwareTimer;

extern uint32_t duration;
extern SoftwareTimer timer1;
extern SoftwareTimer timer2;
extern SoftwareTimer timer3;
extern SoftwareTimer timer4;
extern SoftwareTimer timerTestLed;
extern SoftwareTimer timeNoReact;
extern SoftwareTimer timerBlinky1;
extern SoftwareTimer timerBlinky2;

//=========================================DEFINE BUTTON VARIABLE====================================================================
typedef struct {
	uint8_t keyReg0;
	uint8_t keyReg1;
	uint8_t keyReg2;
	uint8_t keyReg3;
	uint8_t pressFlag;
	int timerForPress;
	GPIO_TypeDef * PORT;
	uint16_t PIN;
} Button;

extern Button button1;
extern Button button2;
extern Button button3;

//===============================================DEFINE FSM AUTO ====================================================================
#define MAIN_INIT 	1
#define MAIN_RED	2
#define MAIN_YEL	3
#define MAIN_GREEN	4

#define SUB_INIT	11
#define SUB_RED		12
#define SUB_YEL		13
#define	SUB_GREEN	14

#define CONST_RED   5
#define CONST_YEL   2
#define CONST_GREEN 3
extern int main_status;
extern int sub_status;

extern int timeRed;
extern int timeYel;
extern int timeGreen;


//=================================================DEFINE FSM MANUAL ================================================================
#define MAN_RED		22
#define MAN_YEL		23
#define MAN_GREEN	24

#define MODE_AUTO	101
#define MODE_MANUAL	102

extern int mode;
extern int manual_status;


//==================================================DEFINE SET SEVEN LED ============================================================
extern int time_buffer[6];
extern int mainTimeRemain;
extern int subTimeRemain;
extern int led_idx;

//==================================================DEFINE TRAFFIC LED===============================================================

#define RED_MAIN_1 		RED1_GPIO_Port, RED1_Pin
#define RED_MAIN_3		RED3_GPIO_Port, RED3_Pin

#define YEL_MAIN_1		YEL1_GPIO_Port, YEL1_Pin
#define YEL_MAIN_3		YEL3_GPIO_Port, YEL3_Pin

#define GREEN_MAIN_1	GREEN1_GPIO_Port, GREEN1_Pin
#define GREEN_MAIN_3	GREEN3_GPIO_Port, GREEN3_Pin


#define RED_SUB_2 		RED2_GPIO_Port, RED2_Pin
#define RED_SUB_4		RED4_GPIO_Port, RED4_Pin

#define YEL_SUB_2		YEL2_GPIO_Port, YEL2_Pin
#define YEL_SUB_4		YEL4_GPIO_Port, YEL4_Pin

#define GREEN_SUB_2		GREEN2_GPIO_Port, GREEN2_Pin
#define GREEN_SUB_4		GREEN4_GPIO_Port, GREEN4_Pin


//==================================================START MODE CONTROL DEFINE=======================================================
extern int tempRed;
extern int tempYel;
extern int tempGreen;

extern int backupRed;
extern int backupYel;
extern int backupGreen;

extern uint8_t isEditted;

#endif /* INC_GLOBAL_H_ */
