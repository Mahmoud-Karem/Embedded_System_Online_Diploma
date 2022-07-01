/**********************************************************************************
 Assignment  : EX7_C_Program_to_find_the_Factorial.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 1 - 2022
***********************************************************************************/

#include <stdio.h>
void main ()
{
	int num;
	printf ("Enter an integer: ");
	scanf ("%i",&num);
	
	if((num == 0) || (num == 1))
		printf ("Factorial = 1\n");
	
	else if(num < 0)
		printf ("Error!!! Factorial of negative number doesn't exist.\n");
	
	else
	{
		int i = num-1 ;
		while (i!=0)
		{
			num=num*i;
			i--;
		}
		printf ("Factorial = %i\n",num);
	}
	
}