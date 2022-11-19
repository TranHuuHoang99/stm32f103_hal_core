#ifndef CORE_M3_NVIC_H
#define CORE_M3_NVIC_H

#include <stdint.h>

#define NVIC_BASE                               0xE000E100U     /*Nester vectored interrupt controller*/
#define NVIC_ISER_OFFSET                        0x000U          /*Interrupt set enable register*/
#define NVIC_ICER_OFFSET                        0x080U          /*Interrupt clear enable regiset*/
#define NVIC_ISPR_OFFSET                        0x100U          /*Interrupt set pending register*/
#define NVIC_ICPR_OFFSET                        0x180U          /*Interrupt clear pending regiser*/
#define NVIC_IABR_OFFSET                        0x200U          /*Interrupt active bit register*/
#define NVIC_IPR0_OFFSET                        0x300U          /*Interrupt priority register*/
#define NVIC_IPR20_OFFSET                       0x320U          /*Interrupt priority regiser*/

#define NVIC_ISER                               ((NVIC_BASE) + (NVIC_ISER_OFFSET))
#define NVIC_ICER                               ((NVIC_BASE) + (NVIC_ICER_OFFSET))
#define NVIC_ISPR                               ((NVIC_BASE) + (NVIC_ISPR_OFFSET))
#define NVIC_ICPR                               ((NVIC_BASE) + (NVIC_ICPR_OFFSET))
#define NVIC_IABR                               ((NVIC_BASE) + (NVIC_IABR_OFFSET))
#define NVIC_IPR0                               ((NVIC_BASE) + (NVIC_IPR0_OFFSET))
#define NVIC_IPR20                              ((NVIC_BASE) + (NVIC_IPR20_OFFSET))


struct ISER {
    uint32_t iser0;
    uint32_t iser1;
    uint32_t iser2;
};

struct ISER* iser_interrupt = (struct ISER*)NVIC_ISER;

struct ICER {
    uint32_t icer0;
    uint32_t icer1;
    uint32_t icer2;
};

struct ICER* icer_interrupt = (struct ICER*)NVIC_ICER;

struct ISPR {
    uint32_t ispr0;
    uint32_t ispr1;
    uint32_t ispr2;
};

struct ISPR* ispr_interrupt = (struct ISPR*)NVIC_ISPR;

struct ICPR {
    uint32_t icpr0;
    uint32_t icpr1;
    uint32_t icpr2;
};

struct ICPR* icpr_interrupt = (struct ICPR*)NVIC_ICPR;

struct IABR {
    uint32_t iabr0;
    uint32_t iabr1;
    uint32_t iabr2;
};

struct IABR* iabr_interrupt = (struct IABR*)NVIC_IABR;

uint32_t* ipr0_interrupt = (uint32_t*)NVIC_IPR0;
uint32_t* ipr20_interrupt = (uint32_t*)NVIC_IPR20;

/*
    --------------------------------------------- ENUMIRATION OF INTERRUPT IN STM32F1XX-----------------------------------
*/

enum INTERRUPT_ORDER{
    WWDG_interrupt = 0,
	PVD_interrupt,
	TAMPER_interrupt,
	RTC_interrupt,
	FLASH_interrupt,
	RCC_interrupt,
	EXTI0_interrupt,
	EXTI1_interrupt,
	EXTI2_interrupt,
	EXTI3_interrupt,
	EXTI4_interrupt,
	DMA1_channel1_interrupt,
	DMA1_channel2_interrupt,
	DMA1_channel3_interrupt,
	DMA1_channel4_interrupt,
	DMA1_channel5_interrupt,
	DMA1_channel6_interrupt,
	DMA1_channel7_interrupt,
	ADC1_2_interrupt,
	CAN1_TX_interrupt,
	CAN1_RX0_interrupt,
	CAN1_RX1_interrupt,
	CAN1_SCE_interrupt,
	EXTI9_5_interrupt,
	TIM1_BRK_interrupt,
	TIM1_UP_interrupt,
	TIM1_TRG_COM,
	TIM1_CC,
	TIM2_interrupt,
	TIM3_interrupt,
	TIM4_interrupt,
	I2C1_EV_interrupt,
	I2C1_ER_interrupt,
	I2C2_EV_interrupt,
	I2C2_ER_interrupt,
	SPI1_interrupt,
	SPI2_interrupt,
	USART1_interrupt,
	USART2_interrupt,
	USART3_interrupt,
	EXTII15_10_interrupt,
	RTCAlarm_interrupt,
	OTP_FS_WKUP_interrupt,
    // reserved to be zero
    reserved1,
    reserved2,
    //end reserved
	TIM5_interrupt,
	SPI3_interrupt,
	UART4_interrupt,
	UART5_interrupt,
	TIM6_interrupt,
	TIM7_interrupt,
	DMA2_channel1,
	DMA2_channel2,
	DMA2_channel3,
    DMA2_channel4,
	DMA2_channel5,
	ETH_interrupt,
	ETH_WKUP_interrupt,
	CAN2_TX_interrupt,
	CAN2_RX0_interrupt,
	CAN2_RX1_interrupt,
	CAN2_SCE_interrupt,
	OTG_FS_interrupt
};


/*
    --------------------------------------------- FUNCTION TRIGGER INTERRUPT ON NVIC--------------------------------------
*/

void NVIC_set_enable_interrupt(uint8_t order);
void NVIC_clear_enable_interrupt(uint8_t order);
void NVIC_set_pending_interrupt(uint8_t order);
void NVIC_clear_pending_interrupt(uint8_t order);
void NVIC_active_bit_interrupt(uint8_t order);
void NVIC_priority0_interrupt(uint8_t order);
void NVIC_priority20_interrupt(uint8_t order);

#endif //CORE_M3_NVIC_H