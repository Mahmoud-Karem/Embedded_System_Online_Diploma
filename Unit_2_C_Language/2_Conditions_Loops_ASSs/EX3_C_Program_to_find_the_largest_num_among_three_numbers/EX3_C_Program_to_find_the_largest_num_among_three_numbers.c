/***************************************************************************
 Assignment  : EX3_C_Program_to_find_the_largest_num_among_three_numbers.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 1 - 2022
****************************************************************************/

#include <stdio.h>
void main ()
{
	float num1 , num2 , num3 ;
	printf ("Enter three numbers: ");
	scanf ("%f\n%f\n%f",&num1,&num2,&num3);
	
	if((num1>num2) && (num1>num3))
		printf ("Largest number = %f\n",num1);
	
	else if((num2>num1) && (num2>num3))
		printf ("Largest number = %f\n",num2);
	
	else if((num3>num1) && (num3>num2))
		printf ("Largest number = %f\n",num3);
	
	else 
		printf ("The Three Numbers are equal.\n");

	
}