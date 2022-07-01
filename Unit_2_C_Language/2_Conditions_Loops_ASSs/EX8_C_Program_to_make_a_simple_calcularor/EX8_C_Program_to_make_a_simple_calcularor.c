/***************************************************************************
 Assignment  : EX8_C_Program_to_make_a_simple_calcularor.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 1 - 2022
****************************************************************************/

#include <stdio.h>
void main ()
{
	char ch ;
	float a,b;
	printf ("Enter operator either + or - or * or / : ");
	scanf ("%c",&ch);
	printf ("Enter two operands: ");
	scanf ("%f",&a);
	scanf ("%f",&b);


	
	switch (ch)
	{
		case '+':
			printf ("%f %c %f = %f \n",a,ch,b,a+b);
			break;
		case '-':
			printf ("%f %c %f = %f \n",a,ch,b,a-b);
			break;
		case '*':
			printf ("%f %c %f = %f \n",a,ch,b,a*b);
			break;
		case '/':
			printf ("%f %c %f = %f \n",a,ch,b,a/b);
			break;
		default :
			printf ("Invalide Operator.\n");
	}
}