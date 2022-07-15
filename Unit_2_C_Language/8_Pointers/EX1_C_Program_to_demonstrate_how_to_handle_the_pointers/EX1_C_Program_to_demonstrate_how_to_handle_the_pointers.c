/***************************************************************************
 Assignment  : EX1_C_Program_to_demonstrate_how_to_handle_the_pointers.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 15 - 2022
****************************************************************************/

#include <stdio.h>


void main ()
{
	int m = 29 ;
	int* ab ;
	ab = &m ;

	printf ("\n=========================================================");
	printf ("\nAddress of m : 0x%p",&m);
	printf ("\nValue of m : %i",m);
	printf ("\n=========================================================");
	printf ("\nNow ab is assigned with the address of m");
	printf ("\nAddress of pointer ab : 0x%p",ab);
	printf ("\nContent of pointer ab : %i",*ab);
	printf ("\n=========================================================");
	m=34;
	printf ("\nThe value of m assigned to 34 now.");
	printf ("\nAddress of pointer ab : 0x%p",ab);
	printf ("\nContent of pointer ab : %i",*ab);
	printf ("\n=========================================================");
	*ab=7;
	printf ("\nThe pointer variable ab is assigned with 7 now.");
	printf ("\nAddress of m : 0x%p",&m);
	printf ("\nValue of m : %i",m);
	printf ("\n=========================================================");

}

