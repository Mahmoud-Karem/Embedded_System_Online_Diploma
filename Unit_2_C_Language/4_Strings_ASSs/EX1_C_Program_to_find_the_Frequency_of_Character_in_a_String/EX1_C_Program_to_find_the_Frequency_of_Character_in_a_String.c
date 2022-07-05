/******************************************************************************
 Assignment  : EX1_C_Program_to_find_the_Frequency_of_Character_in_a_Srring.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 5 - 2022
*******************************************************************************/

#include <stdio.h>
#include <string.h>

#define SIZE 50

void main ()
{
	char ch ;
	int i=0 , counter=0 ;
	char String[SIZE];
	
	printf ("\nEnter a String: ");
	gets(String);
	
	printf ("\nEnter a character to find frequency: ");
	scanf  ("%c" ,&ch);
	
	while (String[i] != '\0')
	{
		if (String[i]== ch)
		{
			counter++;
		}
		i++;		
	}
	
	if (counter!=0)
	{
		printf ("\nFrequency of %c = %i\n",ch,counter);
	}
	else
	{
		printf ("\nThe Element is Not Exist");

	}

}