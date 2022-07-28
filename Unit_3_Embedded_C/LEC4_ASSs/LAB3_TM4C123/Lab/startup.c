/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    startup_Cortex_M3.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */  

/********************************************************************************************/
#include "Platform_Types.h"

//extern uint32 _STACK_TOP ;
/*
booking 1024 B located by .bss through uninitalized array of int 256 Element (256*4 = 1024)
reserve static size
*/
static uint32_t Stack_Top[256];
/* Stack_Top is included in .bss section as shown below the size of 
   is 0x400 = 1024 B and then specify the stack_top + <size> to SP register
   ((all of this explained in arm-none-eabi-nm.exe file.elf))*/
   

extern int main(void);

/********************************************************************************************/

void Reset_Handler(void);

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));;
void H_Fault_Handler(void)			__attribute__ ((weak, alias("Default_Handler")));;
void MM_Fault_Handler(void)			__attribute__ ((weak, alias("Default_Handler")));;
void Bus_Fault(void)				__attribute__ ((weak, alias("Default_Handler")));;
void Usage_Fault_Handler(void)		__attribute__ ((weak, alias("Default_Handler")));;

/********************************************************************************************/

/*
uint32 vectors[] __attribute__ ((section(".vectors"))) = 
{
	(uint32)	&_STACK_TOP,
	(uint32)	&Reset_Handler,
	(uint32)	&NMI_Handler,
	(uint32)	&H_Fault_Handler,
	(uint32)	&MM_Fault_Handler,
	(uint32)	&Bus_Fault,
	(uint32)	&Usage_Fault_Handler
};
*/

void (*const g_p_fn_vectors[])() __attribute__ ((section(".vectors"))) =
{
	(void(*)())	((uint32_t)Stack_Top + sizeof(Stack_Top)),
	&Reset_Handler, // Vectors section is an array of pointer to function
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler

};

/********************************************************************************************/

extern uint32 _E_TEXT ;
extern uint32 _S_DATA ;
extern uint32 _E_DATA ;
extern uint32 _S_BSS ;
extern uint32 _E_BSS ;

/********************************************************************************************/

void Reset_Handler (void)
{
	/* copy data from ROM to RAM */
	uint32 DATA_Size = (uint8*)&_E_DATA - (uint8*)&_S_DATA ;
	uint8* P_src = (uint8*)&_E_TEXT ;
	uint8* P_dst = (uint8*)&_S_DATA ;
	
	for (int i = 0; i < DATA_Size; ++i)
		{
			*((uint8*)P_dst++) = *((uint8*)P_src++) ; 
		}

	/*  init the .bss with zero  */
	uint32 BSS_Size = (uint8*)&_E_BSS - (uint8*)&_S_BSS ;
	P_dst = (uint8*)&_S_BSS ;

	for (int i = 0; i < BSS_Size; ++i)
		{
			*((uint8*)P_dst++) = (uint8)0 ; 
		}

	main();   	/* Branch --> main */ 

}

/********************************************************************************************/