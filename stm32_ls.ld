/*
  ENTRY point call the vector table first
*/
ENTRY(Reset_handler)

/*
  DEFINE MEMORY BLOCK
*/
MEMORY
{
  FLASH(rx):ORIGIN = 0x08000000, LENGTH = 64K /* internal flash memory of stm32f103C8T6 is 64KB */
  SRAM(rwx):ORIGIN = 0x20000000, LENGTH = 20K /* inter sram memory of stm32f103C8T6 is 20KB */
}

SECTIONS
{
  .text :
  {

    *(.vector_table)

    /*
      .text of main.o stm32_startUp.o  // use this or below one are all fine
    */

    *(.text) /* grab all the code of program into this section */
    *(.rodata) /* this sector contains the constant data of program */
    . = ALIGN(4); /* if you dont use ALIGN the boundary of etext (the end of text section) range is plus one byte */
    _etext = .;
  } > FLASH

  .data :
  {
    _sdata = .;
    *(.data)
    . = ALIGN(4);
    _edata = .;
  } > SRAM AT> FLASH

  .bss :
  {
    _sbss = .;
    *(.bss)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > SRAM

}