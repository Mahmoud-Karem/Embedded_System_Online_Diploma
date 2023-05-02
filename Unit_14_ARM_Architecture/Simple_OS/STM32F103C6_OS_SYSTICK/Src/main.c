/*

 * main.c
 *
 *  Created on: Sep 26, 2022
 *      Author: Mahmoud Karem Zamel
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

u8 TaskA_Flag=0 , TaskB_Flag=0 ,Schedule_Flag=0 ;

/**************************************************************************/
/****************************  OS Macros  *********************************/
/**************************************************************************/
#define OS_SET_PSP(add)        __asm volatile ("mov r0,%0 \n\t msr PSP,r0 \n\r" : : "r" (add))
#define OS_SWITCH_SP_TO_MSP    __asm volatile ("mrs r0,CONTROL \n\t mov r1,#0x5 \n\t and r0,r0,r1 \n\t msr CONTROL,r3 \n\t")
#define OS_SWITCH_SP_TO_PSP    __asm volatile ("mrs r0,CONTROL \n\t orr r0,r0,#0x2 \n\t msr CONTROL,r0 \n\t")
#define OS_GEN_SWI             __asm volatile ("SVC #0x3 ")

/**************************************************************************/
#define TASKA_STACK_SIZE 100
#define TASKB_STACK_SIZE 100

extern int _estack;

//Main Stack
unsigned int _S_MSP = (unsigned int) &_estack ;
unsigned int _E_MSP ;

//Process Stack for Task A
unsigned int _S_PSP_TA ;
unsigned int _E_PSP_TA ;

//Process Stack for Task B
unsigned int _S_PSP_TB ;
unsigned int _E_PSP_TB ;


/**************************************************************************/
/**********************  Switch Access Level   ****************************/
/**************************************************************************/
enum CPUAccessLevel { privileged , unprivileged };

#define Switch_CPUAccessLevel_TO_PAL   __asm(  "mrs r3,CONTROL \n\t lsr r3,r3,#0x1 \n\t lsl r3,r3,#0x1 \n\t msr CONTROL,r3 \n\t")

#define Switch_CPUAccessLevel_TO_NPAL  __asm(  "mrs r3,CONTROL \n\t orr r3,r3,#0x1 \n\t msr CONTROL,r3 \n\t")

void Switch_CPUAccessLevel (enum CPUAccessLevel level)
{
	switch (level)
	{
	case privileged:
		__asm(  "mrs r3,CONTROL \n\t"
				"lsr r3,r3,#0x1 \n\t"
				"lsl r3,r3,#0x1 \n\t"
				"msr CONTROL,r3 \n\t");
		break;

	case unprivileged:
		__asm(  "mrs r3,CONTROL \n\t"
				"orr r3,r3,#0x1 \n\t"
				"msr CONTROL,r3 \n\t");
		break;
	}
}

void SVC_Handler()
{
	Switch_CPUAccessLevel(privileged);
}

/**************************************************************************/
/************************     TASKs    ************************************/
/**************************************************************************/


int TaskA (int a , int b , int c )
{
	return a+b+c;
}

int TaskB (int a , int b , int c ,int d)
{
	return a+b+c+d;
}
/**************************************************************************/
/**********************     Main OS    ************************************/
/**************************************************************************/
void MainOS()
{
	//Main Stack
	_E_MSP = (_S_MSP - 512) ;

	//Task A
	_S_PSP_TA = (_E_MSP - 8) ;
	_E_PSP_TA = (_S_PSP_TA - TASKA_STACK_SIZE ) ;

	//Task B
	_S_PSP_TB = (_E_PSP_TA - 8) ;
	_E_PSP_TB = (_S_PSP_TB - TASKB_STACK_SIZE ) ;

	while(1)
	{
		__asm("nop"); // Idle Task of This Simple Scheduler

		if (TaskA_Flag == 1)
		{
			// Set PSP Register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TA);
			// SP -> PSP
			OS_SWITCH_SP_TO_PSP;
			// Switch from Privileged to UnPrivileged
			Switch_CPUAccessLevel_TO_NPAL;
			//Or --> Switch_CPUAccessLevel(unprivileged);

			TaskA_Flag=TaskA(1,2,3);

			// Switch from UnPrivileged to Privileged
			OS_GEN_SWI;
			// SP -> MSP
			OS_SWITCH_SP_TO_MSP;
		}
		else if (TaskB_Flag == 1)
		{
			// Set PSP Register = _S_PSP_TB
			OS_SET_PSP(_S_PSP_TA);
			// SP -> PSP
			OS_SWITCH_SP_TO_PSP;
			// Switch from Privileged to UnPrivileged
			Switch_CPUAccessLevel_TO_NPAL;
			//Or --> Switch_CPUAccessLevel(unprivileged);

			TaskB_Flag=TaskB(1,2,3,4);

			// Switch from UnPrivileged to Privileged
			OS_GEN_SWI;
			// SP -> MSP
			OS_SWITCH_SP_TO_MSP;
		}
	}

}


/**************************************************************************/

void Schedule_Func ()
{
	if (Schedule_Flag == 0)
	{
		TaskA_Flag=1;
		Schedule_Flag=1;
	}
	else if (Schedule_Flag == 1)
	{
		TaskB_Flag=1;
		Schedule_Flag=0;
	}
}

/**************************************************************************/

int main ()
{
	/* RCC Init */
	RCC_voidInitSysClock();
	RCC_voidEnablePeripheralClock(APB2_BUS,AFIO_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS,DIOA_RCC);
	RCC_voidEnablePeripheralClock(APB2_BUS,DIOB_RCC);

	MEXTI_voidInit();
	MNVIC_voidInit();

	MDIO_voidSetPinDirection(DIOB,PIN9,INPUT_FLOATING); /* EXTI Pin */

	MAFIO_voidSetEXTIConfiguration(AFIO_EXTI9,DIOB);

	MEXTI_voidSetSignalLatch(EXTI_LINE9,ON_CHANGE);
	MEXTI_voidEnableEXTI(EXTI_LINE9);
	MNVIC_voidEnableInterrupt(23); /* Enable for EXTI[9:5] */


	//MEXTI9_voidSetCallBack(Schedule_Func);
	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */
	MSTK_voidSetIntervalPeriodic( 1000000, Schedule_Func );

	MainOS();

	while(1); // Shall not return from MainOS

	return 0;

}

