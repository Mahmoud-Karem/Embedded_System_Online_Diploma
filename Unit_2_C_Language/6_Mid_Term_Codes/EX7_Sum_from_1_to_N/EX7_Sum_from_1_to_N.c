/*********************************************************************************
 Assignment  : EX7_Sum_from_1_to_N.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/

#include <stdio.h>
void main ()
{
	int i ;
	printf ("Enter the end of Interval (1:N): ");
	scanf ("%i",&i);
	printf ("Sum = %i",(i*(i+1)/2));

}