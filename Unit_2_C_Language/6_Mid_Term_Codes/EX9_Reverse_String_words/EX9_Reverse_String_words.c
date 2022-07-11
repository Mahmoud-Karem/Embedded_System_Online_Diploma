/*********************************************************************************
 Exam        : EX9_Reverse_String_words.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/
#include <stdio.h>
#include <string.h>

#define SIZE 50

void main ()
{
	char String[SIZE];
	char String_Rev[SIZE];
	int i=0,j=0;
	
	
	printf ("\nEnter a String: ");
	gets(String);
	
	while (String[i] != '\0')
	{
		i++;
	}
	while (i>0)
	{
		String_Rev[j]=String[--i];
		++j;
	}
	
	String_Rev[j]='\0';
	
	printf ("\nReverse of String: ");
	for (i=0 ;String_Rev[i]!= '\0' ;i++)
	{
		if (String_Rev[i+1]==' ' || String_Rev[i+1]=='\0')
		{
			for (j=i ; ((j>=0)&&(String_Rev[j]!=' ')) ; j--)
			{
				printf ("%c",String_Rev[j]);
			}
			printf (" ");

		}
	}
}
