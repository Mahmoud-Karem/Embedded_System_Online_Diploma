/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    startup_Cortex_M3.s    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mahmoud Karem Zamel
 *
 */  

/*************************************************************/

.section .vectors

.word 0x20001000                /* Stack top Address --> Stack Pointer */
.word _reset                    /* 1  reset handler */
.word _VECTOR_handler 	    	/* 2  NMI */
.word _VECTOR_handler 	    	/* 3  Hard Fault */
.word _VECTOR_handler 	    	/* 4  MM Fault */
.word _VECTOR_handler 	    	/* 5  Bus Fault */
.word _VECTOR_handler 	    	/* 6  Usage Fault */
.word _VECTOR_handler 	    	/* 7  RESERVED */
.word _VECTOR_handler 	    	/* 8  RESERVED */
.word _VECTOR_handler 	    	/* 9  RESERVED */
.word _VECTOR_handler 	    	/* 10 RESERVED */
.word _VECTOR_handler 	    	/* 11 SV Call */
.word _VECTOR_handler 	    	/* 12 Debug Reserved */
.word _VECTOR_handler 	    	/* 13 RESERVED */
.word _VECTOR_handler 	    	/* 14 PendSV */
.word _VECTOR_handler 	    	/* 15 SysTick */
.word _VECTOR_handler 	    	/* 16 IRQ0 */
.word _VECTOR_handler 	    	/* 17 IRQ1 */
.word _VECTOR_handler 	    	/* 18 IRQ2 */
.word _VECTOR_handler 	    	/* 19 ... */  
								/*  on to IRQ67 */

/*************************************************************/

.thumb_func             /* Enable thumb instructions */

/*************************************************************/

.section .text

_reset :
	b main
	b .
	
_VECTOR_handler :
	b _reset

/*************************************************************/
