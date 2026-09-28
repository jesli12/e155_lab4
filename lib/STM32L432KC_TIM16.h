// STM32L432KC_TIM16.h
// Header for TIM16 functions

#ifndef STM32L432KC_TIM16_H
#define STM32L432KC_TIM16_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM16_BASE (0x40014400) // base address of TIM16


/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t CR1;         /*Address offset: 0x00 */
  __IO uint32_t CR2;         /* Address offset: 0x04 */
  uint32_t      RESERVED0;   /*Address offset: 0x08 */
  __IO uint32_t DIER;        /*Address offset: 0x0C */
  __IO uint32_t SR;          /*Address offset: 0x10 */
  __IO uint32_t EGR;         /*Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*Address offset: 0x18 */
  uint32_t      RESERVED1;   /*Address offset: 0x1C */
  __IO uint32_t CCER;        /*Address offset: 0x20 */
   __IO uint32_t CNT;        /*Address offset: 0x24 */
  __IO uint32_t PSC;         /*Address offset: 0x28 */
  __IO uint32_t ARR;         /*Address offset: 0x2C */
  __IO uint32_t RCR;         /*Address offset: 0x30 */
  __IO uint32_t CCR1;        /*Address offset: 0x34 */
  uint32_t      RESERVED2;   /*Address offset: 0x38 */
  uint32_t      RESERVED3;   /*Address offset: 0x3C */
  uint32_t      RESERVED4;   /*Address offset: 0x40 */
  __IO uint32_t BDTR;        /*Address offset: 0x44 */
  __IO uint32_t DCR;         /*Address offset: 0x48 */
  __IO uint32_t DMAR;        /*Address offset: 0x4C */
  __IO uint32_t OR1;         /*Address offset: 0x50 */
  uint32_t      RESERVED3;   /*Address offset: 0x54 */
  uint32_t      RESERVED4;   /*Address offset: 0x58 */
  uint32_t      RESERVED5;   /*Address offset: 0x5C */
  __IO uint32_t OR2;         /*Address offset: 0x60 */
} TIM16_TypeDef;

#define TIM16 ((TIM16_TypeDef *) TIM16_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

// void configurePLL(void);
// void configureClock(void);

#endif