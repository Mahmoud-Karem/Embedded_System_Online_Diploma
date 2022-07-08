/*********************************************************************************
 Assignment  : EX4_C_Program_to_Calculate_The_Power_of_a_Number_Using_Recursion.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/

#include <stdio.h>

int Power (int Num , int pow);


void main ()
{
	int x,y,z;

	printf ("Enter base number: ");
	scanf ("%i",&x);
	printf ("Enter poer number(positive integer): ");
	scanf ("%i",&y);
	
	z=Power(x,y);
	printf ("%i^%i = %i",x,y,z);

	printf ("\n");

}

int Power (int Num , int pow)
{
	if (pow == 1)
	{
		Num = Num ;
	}	
	else
	{
		Num = (Num*(Power(Num,pow-1)));
	}
	return Num ;

}
