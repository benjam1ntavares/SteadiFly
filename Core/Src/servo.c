/*
 * servo.c
 *
 *  Created on: May 20, 2025
 *      Author: benji
 */
#include "led.h"

#define PERIOD 80000   // 20ms period (50Hz)
#define DUTY   4000 // 10% duty cycle (2ms high)

void setup_TIM2(void) {
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;
    TIM2->ARR = PERIOD - 1;                   // 80,000 ticks = 20ms
    TIM2->CCR1 = DUTY;                        // 10% duty = 8000 ticks = 2ms
    TIM2->DIER |= TIM_DIER_CC1IE | TIM_DIER_UIE;
    TIM2->SR &= ~(TIM_SR_CC1IF | TIM_SR_UIF);
    NVIC->ISER[0] |= (1 << (TIM2_IRQn & 0x1F));
    __enable_irq();
    TIM2->CR1 |= TIM_CR1_CEN;
    TIM2->CNT = 0;
}

void TIM2_IRQHandler(void) {
    if (TIM2->SR & TIM_SR_CC1IF) {           // CCR1 match: time to go LOW
        TIM2->SR &= ~TIM_SR_CC1IF;           // Clear CC1 interrupt flag
        LED_PORT->BRR = 1;           // Set output LOW
    }

    if (TIM2->SR & TIM_SR_UIF) {             // Update event: time to go HIGH
        TIM2->SR &= ~TIM_SR_UIF;             // Clear update interrupt flag
        LED_PORT->ODR |= 1;            // Set output HIGH
    }
}



