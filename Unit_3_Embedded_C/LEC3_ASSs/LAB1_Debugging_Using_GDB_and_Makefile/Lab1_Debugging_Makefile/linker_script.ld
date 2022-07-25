ENTRY(reset)

/* layout of memory sections */
MEMORY
{
	Mem (rwx):ORIGIN = 0x00000000 , LENGTH = 64M
}

SECTIONS
{
	. = 0x10000 ;
	.startup . :
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
		*(.bss) *(COMMAN)
	}> Mem
	. = . + 0x1000 ; /* 4KB of Stack Memory */
	STACK_TOP = . ; /*set stack pointer at top*/
	
}