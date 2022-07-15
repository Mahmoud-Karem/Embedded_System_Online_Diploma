/***************************************************************************
 Assignment  : EX3_C_Program_to_print_a_string_in_reverse_using_pointer.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 15 - 2022
****************************************************************************/

#include <stdio.h>
#include <string.h>

#define SIZE 50

void main ()
{
	char String[SIZE];
	char *ptr = NULL;
	int len,i ;
	printf ("\n--------------------------------------------");
	printf ("\nInput a string: ");
	gets(String);
	len =strlen(String);
	ptr = (String+len) ;
	
	printf ("--------------------------------------------");
	printf ("\nInput String : %s",String);
	printf ("\nReverse of the string is : ");
	for (i=0 ; i<=len ; i++)
	{
		printf ("%c",*ptr);
		ptr--;
	}
	printf ("\n--------------------------------------------");

}

