/**
 * @file stm32_exception_handler_prototype.h
 * 
 * @author Tran Huu Hoang (thhoang08091999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * this is made by Hoang use for custom stm32f103C8T6 cortex-m3 model
 * this header files include of interrupt function use in stm32 kit
 */

#include <stdint.h>
#include "system_components.h"

// internal beginning SRAM memory address
#define SRAM_BEGIN 0x20000000U

//internal SRAM memory size
#define SRAM_SIZE (20 * 1024) // 20KB

//internal end SRAM memory address
#define SRAM_END ((SRAM_BEGIN) + (SRAM_SIZE))

//internal main stack pointer
#define MAIN_STACK_POINTER SRAM_END


/**
 * this STACK segment is allocated in SRAM 
 * that's mean the stack_pointer allocated by default at the end of SRAM
 * the stack_pointer contain the vector table so that we relocate this address to 0x0800000U
 * by default of stm32f103C8T6 model
 * this address is the beginning of Flash
 */



// access the custom symbols created in linker

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

// global stack pointer defined here
uint32_t stack_pointer = MAIN_STACK_POINTER;


// prototype void
int main(void);

void Reset_handler(void);

void NMI_hanlder            (void)  __WEAK_DEFAULT_HANLDER__;
void Hardfault_handler      (void)  __WEAK_DEFAULT_HANLDER__;
void MMfault_handler        (void)  __WEAK_DEFAULT_HANLDER__;
void Busfault_handler       (void)  __WEAK_DEFAULT_HANLDER__;
void Usagefault_handler     (void)  __WEAK_DEFAULT_HANLDER__;

/*
  next four pages use for Reserved
*/

void CVcall_handler         (void)  __WEAK_DEFAULT_HANLDER__;
void RD_handler             (void)  __WEAK_DEFAULT_HANLDER__;

/*
  next one page use for Reserved
*/

void PendSV_handler         (void)  __WEAK_DEFAULT_HANLDER__;
void Systick_handler        (void)  __WEAK_DEFAULT_HANLDER__;

/*
 *  stm32 include of 67 IRQ function if you want more interrupt function you could define more below
 *   @param IRQ
*/

void WWDG_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void PVD_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void TAMPER_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void RTC_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void FLASH_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void RCC_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void EXTI0_interrupt					(void)	__WEAK_DEFAULT_HANLDER__;
void EXTI1_interrupt					(void)	__WEAK_DEFAULT_HANLDER__;
void EXTI2_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void EXTI3_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void EXTI4_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA1_channel1_interrupt			(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA1_channel2_interrupt			(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA1_channel3_interrupt			(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA1_channel4_interrupt			(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA1_channel5_interrupt			(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA1_channel6_interrupt			(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA1_channel7_interrupt			(void) 	__WEAK_DEFAULT_HANLDER__;
void ADC1_2_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN1_TX_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN1_RX0_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN1_RX1_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN1_SCE_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void EXTI9_5_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM1_BRK_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM1_UP_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM1_TRG_COM						(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM1_CC							(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM2_interrupt 					(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM3_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM4_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void I2C1_EV_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void I2C1_ER_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void I2C2_EV_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void I2C2_ER_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void SPI1_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void SPI2_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void USART1_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void USART2_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void USART3_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void EXTII15_10_interrupt				(void) 	__WEAK_DEFAULT_HANLDER__;
void RTCAlarm_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void OTP_FS_WKUP_interrupt				(void) 	__WEAK_DEFAULT_HANLDER__;

/*
	next 2 pages for reserved
*/

void TIM5_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void SPI3_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void UART4_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void UART5_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM6_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void TIM7_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA2_channel1						(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA2_channel2						(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA2_channel3						(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA2_channel4						(void) 	__WEAK_DEFAULT_HANLDER__;
void DMA2_channel5						(void) 	__WEAK_DEFAULT_HANLDER__;
void ETH_interrupt						(void) 	__WEAK_DEFAULT_HANLDER__;
void ETH_WKUP_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN2_TX_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN2_RX0_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN2_RX1_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void CAN2_SCE_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;
void OTG_FS_interrupt					(void) 	__WEAK_DEFAULT_HANLDER__;


uint32_t vectors[] __VRB__ = {
    MAIN_STACK_POINTER,
    //exceptions
    (uint32_t)Reset_handler,
    (uint32_t)NMI_hanlder,
    (uint32_t)Hardfault_handler,
    (uint32_t)MMfault_handler,
    (uint32_t)Busfault_handler,
    (uint32_t)Usagefault_handler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)CVcall_handler,
    (uint32_t)RD_handler,
    (uint32_t)0,
    (uint32_t)PendSV_handler,
    (uint32_t)Systick_handler,
    // interrupt 
	(uint32_t)WWDG_interrupt,
	(uint32_t)PVD_interrupt,
	(uint32_t)TAMPER_interrupt,
	(uint32_t)RTC_interrupt,
	(uint32_t)FLASH_interrupt,
	(uint32_t)RCC_interrupt,
	(uint32_t)EXTI0_interrupt,
	(uint32_t)EXTI1_interrupt,
	(uint32_t)EXTI2_interrupt,
	(uint32_t)EXTI3_interrupt,
	(uint32_t)EXTI4_interrupt,
	(uint32_t)DMA1_channel1_interrupt,
	(uint32_t)DMA1_channel2_interrupt,
	(uint32_t)DMA1_channel3_interrupt,
	(uint32_t)DMA1_channel4_interrupt,
	(uint32_t)DMA1_channel5_interrupt,
	(uint32_t)DMA1_channel6_interrupt,
	(uint32_t)DMA1_channel7_interrupt,
	(uint32_t)ADC1_2_interrupt,
	(uint32_t)CAN1_TX_interrupt,
	(uint32_t)CAN1_RX0_interrupt,
	(uint32_t)CAN1_RX1_interrupt,
	(uint32_t)CAN1_SCE_interrupt,
	(uint32_t)EXTI9_5_interrupt,
	(uint32_t)TIM1_BRK_interrupt,
	(uint32_t)TIM1_UP_interrupt,
	(uint32_t)TIM1_TRG_COM,
	(uint32_t)TIM1_CC,
	(uint32_t)TIM2_interrupt,
	(uint32_t)TIM3_interrupt,
	(uint32_t)TIM4_interrupt,
	(uint32_t)I2C1_EV_interrupt,
	(uint32_t)I2C1_ER_interrupt,
	(uint32_t)I2C2_EV_interrupt,
	(uint32_t)I2C2_ER_interrupt,
	(uint32_t)SPI1_interrupt,
	(uint32_t)SPI2_interrupt,
	(uint32_t)USART1_interrupt,
	(uint32_t)USART2_interrupt,
	(uint32_t)USART3_interrupt,
	(uint32_t)EXTII15_10_interrupt,
	(uint32_t)RTCAlarm_interrupt,
	(uint32_t)OTP_FS_WKUP_interrupt,
	(uint32_t)0,
	(uint32_t)0,
	(uint32_t)TIM5_interrupt,
	(uint32_t)SPI3_interrupt,
	(uint32_t)UART4_interrupt,
	(uint32_t)UART5_interrupt,
	(uint32_t)TIM6_interrupt,
	(uint32_t)TIM7_interrupt,
	(uint32_t)DMA2_channel1,
	(uint32_t)DMA2_channel2,
	(uint32_t)DMA2_channel3,
	(uint32_t)DMA2_channel4,
	(uint32_t)DMA2_channel5,
	(uint32_t)ETH_interrupt,
	(uint32_t)ETH_WKUP_interrupt,
	(uint32_t)CAN2_TX_interrupt,
	(uint32_t)CAN2_RX0_interrupt,
	(uint32_t)CAN2_RX1_interrupt,
	(uint32_t)CAN2_SCE_interrupt,
	(uint32_t)OTG_FS_interrupt

};

void Default_handler(void) {
    while(1);
};


void Reset_handler(void) {

	// this is used for copy data from flash to sram from the beginning after power on
	uint32_t* src = (uint32_t*)&_etext;
	uint32_t* des = (uint32_t*)&_sdata;

	while(des < (uint32_t*)&_edata) {
		*des++ = *src++;
	}

	des = (uint32_t*)&_sbss;
	while(des < (uint32_t*)&_ebss) {
		*des++ = 0;
	}

	main();
};
