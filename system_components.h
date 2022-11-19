/*
    given for function with weak define and alias to Default_handler function of all exceptions and interrupt
*/

#define __WEAK_DEFAULT_HANLDER__ __attribute__((weak, alias("Default_handler")))

/*
    given for interrupt vector table a section inside FLASH memory
*/

#define __VRB__ __attribute__((section(".vector_table")))