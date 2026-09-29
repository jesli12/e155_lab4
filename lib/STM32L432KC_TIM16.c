// STM32L432KC_TIM16.c
// Source code for TIM16 functions
// This timer will be used for note frequencies, by counting up to half a period of the desired frequency

#include "STM32L432KC_TIM16.h"
#include "STM32L432KC_RCC.h"

void initPitch() {
    // Turn on timer 16 (RM p224, 245) APB2ENR bit 17
    RCC->APB2ENR |= (1 << 17);

    // set prescaler (PSC) (division factor between 1 and 65536)
    TIM16->PSC = 79; //80 division factor
        // turning down PLL 80Mhz to 1Mhz (period of 1 microsecond)

    TIM16->CR1 |= (1<<7); // auto preload enable (use buffer, shadow register)

    // Set Update Generation bit (RM p953) EGR register, bit 0
        // 0: no action, 1:  Reinitialize the counter and generates an update of the registers. Note that the prescaler counter is cleared too (anyway the prescaler ratio is not affected). 
    TIM16->EGR |= (1<<0); // (UG generates update event)

    // Clear UIF caused by update generation (line before this)
        // see RM p 953, this gets turned on by both overflow and CNT reinitialization from UG
    TIM16->SR &= ~(1 << 0);

    // Counter Clock Enable
    TIM16->CR1 |= (1<<0);
        // Note that counter starts counting 1 clock cycle after setting the CEN bit in the TIMx_CR1 register.
}

void playPitch(int noteFreq){
    uint32_t halfPeriodCount = 0;

    if (noteFreq == 0){
        // stop when rest, de-enable Counter Enable CEN (RM p 950)
        TIM16->CR1 &= ~(1 << 0);
    }
    else{
        // halfPeriodCount = (Frequency of CK_INT/PSC=1Mhz) / (2*noteFreq)
        halfPeriodCount = 1000000 / (2 * noteFreq);

        // Set ARR for new note frequency
        TIM16->ARR = halfPeriodCount - 1; // Recall Lab 1-3's maxcount - 1, same thing here

        // UG (update generation) bit to reinitialize counter, take in new ARR
        TIM16->EGR |= (1 << 0);

        // Clear UIF caused by update generation (line before this)
            // see RM p 953, this gets turned on by both overflow and CNT reinitialization from UG
        TIM16->SR &= ~(1 << 0);

        //Reset Counter (this is done by UG?)
        // TIM16->CNT = 0;
        
        // Restart TIM16 (enable counter again)
        TIM16->CR1 |= (1 << 0);
    }
}