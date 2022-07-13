/***************************************************************************
 Assignment  : EX2_C_Program_to_add_two_distances_in_Imag_Real.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 13 - 2022
****************************************************************************/

#include <stdio.h>

struct S_Complex
{
	float Real;
	float Imag;
};

struct S_Complex Get_Complex(struct S_Complex S_Complex );
struct S_Complex Sum_Complex(struct S_Complex S_Complex_1 , struct S_Complex S_Complex_2 );

void main ()
{
	
	struct S_Complex S_Complex_1 ;
	struct S_Complex S_Complex_2 ;
	struct S_Complex S_Sum_Dis ;
	
	S_Complex_1 = Get_Complex(S_Complex_1 );
	fflush(stdin); fflush(stdout);
	
	S_Complex_2 = Get_Complex(S_Complex_2 );
	fflush(stdin); fflush(stdout);
	
	S_Sum_Dis = Sum_Complex (S_Complex_1 , S_Complex_2);
	printf ("\nSum = %.2f+ %.2f j \n",S_Sum_Dis.Real,S_Sum_Dis.Imag);

	
}

struct S_Complex Get_Complex(struct S_Complex S_Complex )
{
	printf ("\nEnter Complex Number : \n");
	printf ("Enter Real: ");
	scanf ("%f",&S_Complex.Real);
	printf ("Enter Imag: ");
	scanf ("%f",&S_Complex.Imag);
	printf ("\n");

	return S_Complex ;
}

struct S_Complex Sum_Complex(struct S_Complex S_Complex_1 , struct S_Complex S_Complex_2 )
{
	struct S_Complex S_Sum_Dis ;
	S_Sum_Dis.Real = S_Complex_1.Real + S_Complex_2.Real ;
	S_Sum_Dis.Imag = S_Complex_1.Imag + S_Complex_2.Imag ;

	return S_Sum_Dis ;
}