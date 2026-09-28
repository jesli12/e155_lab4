// STM32L432KC_TIM15.c
// Code for TIM15 functions (used to set duration)

#include "STM32L432KC_TIM15.h"
#include "STM32L432KC_RCC.h"

void configureTIM15(){

    // Turn on timer 15 (RM p224, 245) APB2ENR bit 16
    RCC -> APB2ENR


    // set TIM15 Prescaler (RM p939)
    // CLK_INT = 80 Mhz, I want my CLK_CNT to be 1 Khz
    TIM15->PSC 

}