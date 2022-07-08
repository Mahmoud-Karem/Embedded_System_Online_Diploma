/***************************************************************************
 Assignment  : EX2_C_Program_to_Calculate_Factorial_Using_Recursion.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
****************************************************************************/

#include <stdio.h>

int Fact (int NUM);


void main ()
{
	int x ,y;

	printf ("Enter a Positive integer: ");
	scanf ("%d",&x);
	y=Fact(x);
	
	printf ("Factorial of %i = %i",x,y);


}

int Fact (int NUM)
{
	
	if (NUM <=1)
	{
		return 1;
	}
	else 
	{
		return (NUM * Fact(NUM-1)) ;
	}
	printf ("\n");

}
