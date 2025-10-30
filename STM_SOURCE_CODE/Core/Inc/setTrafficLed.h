/*
 * setTrafficLed.h
 *
 *  Created on: Oct 26, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_SETTRAFFICLED_H_
#define INC_SETTRAFFICLED_H_

#include "main.h"
#include "global.h"



//turn off function
void turnOffMainLeds();
void turnOffSubLeds();

//control main led
void redOnMain(void);
void yellowOnMain(void);
void greenOnMain(void);

//control sub led
void redOnSub(void);
void yellowOnSub(void);
void greenOnSub(void);

void blinkyLedMain(	GPIO_TypeDef * port1, uint16_t pin1,
					GPIO_TypeDef * port2, uint16_t pin2 );

void blinkyLedSub(	GPIO_TypeDef * port1, uint16_t pin1,
					GPIO_TypeDef * port2, uint16_t pin2 );
#endif /* INC_SETTRAFFICLED_H_ */
