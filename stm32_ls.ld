/*
  ENTRY point call the vector table first
*/
ENTRY(Reset_handler)

/*
  DEFINE MEMORY BLOCK
*/
MEMORY
{
  FLASH(rx):ORIGIN = 0x08000000, LENGTH = 64K
  SRAM(rwx):ORIGIN = 0x20000000, LENGTH = 12K
}

SECTIONS
{
  .text :
  {

    *(.vector_table)

    /*
      .text of main.o stm32_startUp.o  // use this or below one are all fine
    */

    *(.text)
    *(.rodata)
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
    . = ALIGN(4);
    _ebss = .;
  } > SRAM

}