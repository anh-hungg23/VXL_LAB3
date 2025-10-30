/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED_LED_TEST_Pin GPIO_PIN_1
#define RED_LED_TEST_GPIO_Port GPIOA
#define YEL_LED_TEST_Pin GPIO_PIN_2
#define YEL_LED_TEST_GPIO_Port GPIOA
#define GREEN_LED_TEST_Pin GPIO_PIN_3
#define GREEN_LED_TEST_GPIO_Port GPIOA
#define RED1_Pin GPIO_PIN_4
#define RED1_GPIO_Port GPIOA
#define YEL1_Pin GPIO_PIN_5
#define YEL1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_6
#define GREEN1_GPIO_Port GPIOA
#define RED3_Pin GPIO_PIN_7
#define RED3_GPIO_Port GPIOA
#define LED_a_Pin GPIO_PIN_0
#define LED_a_GPIO_Port GPIOB
#define LED_b_Pin GPIO_PIN_1
#define LED_b_GPIO_Port GPIOB
#define LED_c_Pin GPIO_PIN_2
#define LED_c_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_10
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_11
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_12
#define EN3_GPIO_Port GPIOB
#define EN4_Pin GPIO_PIN_13
#define EN4_GPIO_Port GPIOB
#define EN5_Pin GPIO_PIN_14
#define EN5_GPIO_Port GPIOB
#define EN6_Pin GPIO_PIN_15
#define EN6_GPIO_Port GPIOB
#define YEL3_Pin GPIO_PIN_8
#define YEL3_GPIO_Port GPIOA
#define GREEN3_Pin GPIO_PIN_9
#define GREEN3_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_10
#define RED2_GPIO_Port GPIOA
#define YEL2_Pin GPIO_PIN_11
#define YEL2_GPIO_Port GPIOA
#define GREEN2_Pin GPIO_PIN_12
#define GREEN2_GPIO_Port GPIOA
#define RED4_Pin GPIO_PIN_13
#define RED4_GPIO_Port GPIOA
#define YEL4_Pin GPIO_PIN_14
#define YEL4_GPIO_Port GPIOA
#define GREEN4_Pin GPIO_PIN_15
#define GREEN4_GPIO_Port GPIOA
#define LED_d_Pin GPIO_PIN_3
#define LED_d_GPIO_Port GPIOB
#define LED_e_Pin GPIO_PIN_4
#define LED_e_GPIO_Port GPIOB
#define LED_f_Pin GPIO_PIN_5
#define LED_f_GPIO_Port GPIOB
#define LED_g_Pin GPIO_PIN_6
#define LED_g_GPIO_Port GPIOB
#define but_1_Pin GPIO_PIN_7
#define but_1_GPIO_Port GPIOB
#define but_2_Pin GPIO_PIN_8
#define but_2_GPIO_Port GPIOB
#define but_3_Pin GPIO_PIN_9
#define but_3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
