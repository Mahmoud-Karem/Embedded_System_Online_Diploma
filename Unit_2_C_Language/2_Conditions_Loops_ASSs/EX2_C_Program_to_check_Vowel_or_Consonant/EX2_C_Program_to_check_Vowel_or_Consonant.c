/***************************************************************************
 Assignment  : EX2_C_Program_to_check_Vowel_or_Consonant.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 1 - 2022
****************************************************************************/

#include <stdio.h>
void main ()
{
	char ch ;
	printf ("Enter an alphabet: ");
	scanf ("%c",&ch);
	switch (ch)
	{
		case 'a'...'z' :
			printf ("%c is a vowel.\n",ch);
			break;
		case 'A'...'Z' :
			printf ("%c is a vowel.\n",ch);
			break;
		default :
			printf ("The input is not an alphabet.\n");
	}
}