/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    startup_Cortex_M3.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */  

/********************************************************************************************/
#include "Platform_Types.h"

extern uint32 _STACK_TOP ;

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