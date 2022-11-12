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
extern uint32_t stack_pointer = MAIN_STACK_POINTER;


// prototype void
int main(void);

void Reset_handler(void);

void NMI_hanlder            (void)  __attribute__((weak, alias("Default_handler")));
void Hardfault_handler      (void)  __attribute__((weak, alias("Default_handler")));
void MMfault_handler        (void)  __attribute__((weak, alias("Default_handler")));
void Busfault_handler       (void)  __attribute__((weak, alias("Default_handler")));
void Usagefault_handler     (void)  __attribute__((weak, alias("Default_handler")));

/*
  next four pages use for Reserved
*/

void CVcall_handler         (void)  __attribute__((weak, alias("Default_handler")));
void RD_handler             (void)  __attribute__((weak, alias("Default_handler")));

/*
  next one page use for Reserved
*/

void PendSV_handler         (void)  __attribute__((weak, alias("Default_handler")));
void Systick_handler        (void)  __attribute__((weak, alias("Default_handler")));

/*
 *  stm32 include of 67 IRQ function if you want more interrupt function you could define more below
 *   @param IRQ
*/

void IRQ0                   (void)  __attribute__((weak, alias("Default_handler")));
void IRQ1                   (void)  __attribute__((weak, alias("Default_handler")));



uint32_t vectors[] __attribute__((section(".vector_table"))) = {
    MAIN_STACK_POINTER,
    (uint32_t)Reset_handler,
    (uint32_t)NMI_hanlder,
    (uint32_t)Hardfault_handler,
    (uint32_t)MMfault_handler,
    (uint32_t)Busfault_handler,
    (uint32_t)Usagefault_handler,
    0,
    0,
    0,
    0,
    (uint32_t)CVcall_handler,
    (uint32_t)RD_handler,
    0,
    (uint32_t)PendSV_handler,
    (uint32_t)Systick_handler,
    (uint32_t)IRQ0,
    (uint32_t)IRQ1
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
