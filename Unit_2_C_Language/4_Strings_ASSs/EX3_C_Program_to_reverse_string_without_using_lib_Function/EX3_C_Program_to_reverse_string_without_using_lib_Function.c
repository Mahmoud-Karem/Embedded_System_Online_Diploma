/***************************************************************************
 Assignment  : EX3_C_Program_to_reverse_string_without_using_lib_Function.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 5 - 2022
****************************************************************************/

#include <stdio.h>
#include <string.h>

#define SIZE 50

void main ()
{
	int  Counter=0 , Length=0 ;
	char String[SIZE];
	char String_Rev[SIZE];
	
	
	printf ("\nEnter a String: ");
	gets(String);
	
	Length = strlen(String);

	while (String[Counter] != '\0')
	{
		String_Rev[Length-Counter-1] = String[Counter];
		Counter++;
	}
	String_Rev[Length] = '\0';
	
	Counter=0;
	printf ("\nReverse string is : ");
	while (String_Rev[Counter] != '\0')
	{
		printf ("%c",String_Rev[Counter]);
		Counter++;
	}
	printf ("\n");

	
}