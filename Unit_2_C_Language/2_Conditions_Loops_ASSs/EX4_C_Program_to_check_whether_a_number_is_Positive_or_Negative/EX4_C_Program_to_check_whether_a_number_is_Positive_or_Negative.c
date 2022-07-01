/********************************************************************************
 Assignment  : EX4_C_Program_to_check_whether_a_number_is_Positive_or_Negative.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 1 - 2022
*********************************************************************************/

#include <stdio.h>
void main ()
{
	float num;
	printf ("Enter a number: ");
	scanf ("%f",&num);
	
	if(num == 0)
		printf ("You entered zero.\n");
	
	else if(num > 0)
		printf ("%f is positive.\n",num);
	
	else if(num < 0)
		printf ("%f is negative.\n",num);
	
	else 
		printf ("The input is not a number.\n");

	
}