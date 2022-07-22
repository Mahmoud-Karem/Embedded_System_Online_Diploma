ENTRY(reset)
MEMORY
{
	Mem (rwx):ORIGIN = 0x00000000 , LENGTH = 64M
}

SECTIONS
{
	. = 0x10000 ;
	.reset . :
	{
		startup.o(.text)
	}> Mem
	.text :
	{
		*(.text) *(.rodata)
	}> Mem
	.data :
	{
		*(.data)
	}> Mem
	.bss :
	{
		*(.bss) *(COMMON)
	}> Mem
	. = . + 0x1000 ;
	STACK_TOP = . ;
	
}