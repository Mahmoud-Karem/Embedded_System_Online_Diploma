/***************************************************************************
 Assignment  : EX3_C_Program_to_Reverse_a_Sentence_Using_Recursion.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
****************************************************************************/

#include <stdio.h>

void Reverse_Sentence ();


void main ()
{
	int x ,y;

	printf ("Enter a Sentence: ");
	Reverse_Sentence();
}

void Reverse_Sentence ()
{
	char ch ;
	scanf ("%c" , &ch);
	
	if (ch != '\n')
	{
		Reverse_Sentence();
		printf ("%c",ch);
	}

}
