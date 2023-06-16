#ifndef STM32_CLOCK_H
#define STM32_CLOCK_H

#include <stdint.h>

#define RCC_BASE                                        0x40021000U

struct RCC {
    uint32_t RCC_CR_clock;                              /* clock control register */
    uint32_t RCC_CFGR_clock;                            /* clock configuration register */
    uint32_t RCC_CIR_clock;                             /* clock interrupt register */
    uint32_t RCC_APB2RSTR_clock;                        /* clock APB2 peripheral reset register */
    uint32_t RCC_APB2RSTR_clock;                        /* clock APB2 peripheral reset register */
    uint32_t RCC_AHBENR_clock;                          /* clock AHB peripheral clock enable register */
    uint32_t RCC_APB2ENR_clock;                         /* clock APB2 peripheral clock enable register */
    uint32_t RCC_APB1ENR_clock;                         /* clock APB1 peripheral clock enable register */
    uint32_t RCC_BDCR_clock;                            /* clock back up domain control register */
    uint32_t RCC_CSR_clock;                             /* clock control/status register */
    uint32_t RCC_AHBRSTR_clock;                         /* clock AHB peripheral clock reset register */
    uint32_t RCC_CFGR2_clock;                           /* clock clock configuration register 2 */ 
};

struct RCC* rcc_clock = (struct RCC*)RCC_BASE;


#endif // STM32_CLOCK_H