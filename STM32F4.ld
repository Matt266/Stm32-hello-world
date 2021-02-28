/* In this linker script the memory management for the target board is done.*/
OUTPUT_ARCH(arm)
OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
ENTRY(Reset_Handler)

/* Defining two memory regions; address and length were taken from the product datasheet */
MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

/* Here some space for a stack is reserved - as long a stack pointer is provided for the c code this part can be omitted */
	_stack_top = ORIGIN(SRAM)+LENGTH(SRAM);
	_min_stack_size = 0x400;
	
/* In this part the different memory sections are defined. It handles where they are placed in memory and 
   which sections of the code correspond to which section in the output file. */
SECTIONS
{

	
	
	
	


	.text : 
	{
		. = ALIGN(4);	
		*(.isr_vector)	/* this section is self defined in order to place the interrupt vector table to the correct (default) memory address */
		*(.text*)
		*(.glue_7)
		*(.glue_7t)
		*(.eh_frame)
		KEEP(*(.init))
		KEEP(*(.fini))
		. = ALIGN(4);
		_etext = .;
	} > FLASH

	.rodata :
	{
		. = ALIGN(4);	
		*(.rodata*)
		. = ALIGN(4);
	} > FLASH

	.ARM.extab :
    	{
        	*(.ARM.extab* .gnu.linkonce.armextab.*)
   	} >FLASH

	.ARM :
   	 {
       		__exidx_start = .;
        	*(.ARM.exidx*)
        	__exidx_end = .;
   	 } >FLASH



	.preinit_array :
	{
	PROVIDE_HIDDEN (__preinit_array_start = .);
	KEEP (*(.preinit_array*))
	PROVIDE_HIDDEN (__preinit_array_end = .);
	} >FLASH

	.init_array :
	{
	PROVIDE_HIDDEN (__init_array_start = .);
	KEEP (*(SORT(.init_array.*)))
	KEEP (*(.init_array*))
	PROVIDE_HIDDEN (__init_array_end = .);
	} >FLASH

	.fini_array :
	{	
	PROVIDE_HIDDEN (__fini_array_start = .);
	KEEP (*(.fini_array*))
	KEEP (*(SORT(.fini_array.*)))
	PROVIDE_HIDDEN (__fini_array_end = .);
	} >FLASH


	/* the data section needs to be stored in non volatile memory but will be copied to SRAM in the startup code */
	. = ALIGN(4);
	_sidata = .;

	.data : AT(_sidata)
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	} > SRAM

	.bss :
	{
		. = ALIGN(4);
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
		__bss_end__ = _ebss;
	} > SRAM

	/* This part is for stack placement and can be omitted as long a stack pointer can be provided to the vector table.
	   Also there must be enough space left in memory for the stack to work properly. */
	._stack :
  	{
    	. = ALIGN(4);
    	. = . + _min_stack_size;
    	. = ALIGN(4);
  	} > SRAM


	/DISCARD/ :
  	{
   		 libc.a ( * )
   		 libm.a ( * )
   		 libgcc.a ( * )
 	 }

 	 .ARM.attributes 0 : { *(.ARM.attributes) }
		
	
	
}
