/* USER CODE BEGIN Header */
/*******************************************************************************
 * EE 329 GENERAL LED CONTROL HEADER
 *******************************************************************************
 * @file           : led.h
 * @brief          : Provides prototype for LED_Config function and LED port
 *                   clock enable macros for general use.
 * project         : EE 329 S'25 General Library
 * authors         : Benjamin Tavares
 * version         : 1.1
 * date            : 4/26/25
 * compiler        : STM32CubeIDE v.1.12.0
 * target          : NUCLEO-L4A6ZG
 * clocks          : 4 MHz MSI to AHB2 (or user configured)
 * @attention      : (c) 2025 STMicroelectronics.  All rights reserved.
 *******************************************************************************
 * led.h PLAN :
 *  - Define LED_PORT (default GPIOC)
 *  - Define LED_PORT clock enable macro
 *  - Provide prototype for LED_Config()
 *******************************************************************************
 * REVISION HISTORY
 * 1.0 250426 Initial general-purpose LED config
 *******************************************************************************/
/* USER CODE END Header */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32l4xx.h"

/*In case you want to change the port*/
#define LED_PORT_CLK_EN RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOCEN);
#define LED_PORT GPIOC


void LED_Config(void);


#endif /* INC_LED_H_ */
