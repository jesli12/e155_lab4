// STM32L432KC_TIM15.c
// Source code for TIM15 functions
// 

#include "STM32L432KC_TIM15.h"
#include "STM32L432KC_RCC.h"

void initDuration(void) {
    // Turn on timer 15 (RM p224, 245) APB2ENR bit 16
    RCC->APB2ENR |= (1 << 16);

    // set prescaler (PSC) (division factor between 1 and 65536)
    TIM15->PSC = 7999; //8000 division factor
        // turning down PLL 80Mhz to 10khz (period of 0.1 ms)

    TIM15->CR1 |= (1<<7); // auto preload enable (use buffer, shadow register)

    // Set Update Generation bit (RM p953) EGR register, bit 0
        // 0: no action, 1:  Reinitialize the counter and generates an update of the registers. Note that the prescaler counter is cleared too (anyway the prescaler ratio is not affected). 
    TIM15->EGR |= (1<<0); // (UG generates update event)
    TIM15->SR &= ~(1 << 0);

    // Counter Clock Enable
    TIM15->CR1 |= (1<<0);
        // Note that counter starts counting 1 clock cycle after setting the CEN bit in the TIMx_CR1 register.
}

void runDuration(int duration){
        // Set ARR for new note duration
        TIM15->ARR = (duration*10) - 1; // Recall Lab 1-3's maxcount - 1, same thing here

        // UG (update generation) bit to reinitialize counter, take in new ARR
        TIM15->EGR |= (1 << 0);

        // Clear UIF caused by update generation (line before this)
            // see RM p 953, this gets turned on by both overflow and CNT reinitialization from UG
        TIM15->SR &= ~(1 << 0);

        // Restart TIM15
        TIM15->CR1 |= (1 << 0);
}