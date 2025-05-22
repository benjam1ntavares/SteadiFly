/*
 * servo.h
 *
 *  Created on: May 20, 2025
 *      Author: benji
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "stm32l4xx.h"

void setup_TIM2(void);
void TIM2_IRQHandler(void);

#endif /* INC_SERVO_H_ */
