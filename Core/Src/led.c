/* USER CODE BEGIN Header */
/*******************************************************************************
 * EE 329 GENERAL LED CONTROL SOURCE
 *******************************************************************************
 * @file           : led.c
 * @brief          : Implements LED_Config function to configure selected GPIO
 *                   pins for output use. Provides basic LED initialization.
 * project         : EE 329 S'25 General Library
 * authors         : Benjamin Tavares
 * version         : 1.0
 * date            : 4/26/25
 * compiler        : STM32CubeIDE v.1.12.0
 * target          : NUCLEO-L4A6ZG
 * clocks          : 4 MHz MSI to AHB2 (or user configured)
 * @attention      : (c) 2025 STMicroelectronics.  All rights reserved.
 *******************************************************************************
 * led.c PLAN :
 *  - Enable clock to selected GPIO port
 *  - Configure specified pins as general-purpose outputs
 *  - Leave pin behavior (toggle, set, reset) to user code
 *******************************************************************************
 * GPIO PINOUT (example mappings for use):
 *  - PC0 CN9-1
 *  - PC1 CN9-3
 *  - PC2 CN10-4
 *  - PC3 CN9-2
 *  - (Other pins can be configured by modifying LED_Config)
 *******************************************************************************
 * REVISION HISTORY
 * 1.0 250426 Initial general-purpose LED library version
 *******************************************************************************/
/* USER CODE END Header */


#include "led.h"

/*Configures GPIOC Pins 0-3 As Outputs To Be Used For LEDs*/

void LED_Config(void){
	  LED_PORT_CLK_EN;
	  /*Clear Then Mode Pins, Then Set all Mode Pins To Outputs*/
	  LED_PORT->MODER &= ~(GPIO_MODER_MODE0 |
			  	  	  	        GPIO_MODER_MODE1 |
						        GPIO_MODER_MODE2 |
						        GPIO_MODER_MODE3 );
	  LED_PORT->MODER |= (GPIO_MODER_MODE0_0 |
			  	             GPIO_MODER_MODE1_0 |
					          GPIO_MODER_MODE2_0 |
					          GPIO_MODER_MODE3_0 );
	  // Set output type for all pins to Push Pull by making output type pins equal to zero*/
	  LED_PORT->OTYPER &= ~ (GPIO_OTYPER_OT0 |
			  	  	  	          GPIO_OTYPER_OT1 |
						          GPIO_OTYPER_OT2 |
						          GPIO_OTYPER_OT3 );
	  LED_PORT->OSPEEDR |= ((2<<GPIO_OSPEEDR_OSPEED0_Pos) |
			  	  	  	         (2<<GPIO_OSPEEDR_OSPEED1_Pos) |
						         (2<<GPIO_OSPEEDR_OSPEED2_Pos) |
						         (2<<GPIO_OSPEEDR_OSPEED3_Pos));
	  /*Preset Port C Pins to Zero*/
	  LED_PORT->BRR = (GPIO_PIN_0 |
			  	          GPIO_PIN_1 |
					       GPIO_PIN_2 |
					       GPIO_PIN_3);

}
