/*********************************************************************************
 Quiz        : EX3_Check_Num_is_Power_of_3.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/

#include <stdio.h>

int Check_Power_of_3 (unsigned int NUM);

void main ()
{
	int NUM ,Check ;
	printf("Input Number = ");
	scanf ("%i",&NUM);
	Check = Check_Power_of_3(NUM);
	printf("%i ==> %i",NUM,Check);
	
}


int Check_Power_of_3 (unsigned int NUM)
{
	if ((NUM%3)==0)
	{
		return 0 ;
	}
	else
	{
		return 1 ;
	}
}