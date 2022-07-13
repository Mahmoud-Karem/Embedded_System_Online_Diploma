/***************************************************************************
 Assignment  : EX2_C_Program_to_add_two_distances_in_inch_feet.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 13 - 2022
****************************************************************************/

#include <stdio.h>

struct S_Distance
{
	int Feet;
	float Inch;
};

struct S_Distance Get_Distance(struct S_Distance S_Dis );
struct S_Distance Sum_Distance(struct S_Distance S_Dis_1 , struct S_Distance S_Dis_2 );

void main ()
{
	
	struct S_Distance S_Dis_1 ;
	struct S_Distance S_Dis_2 ;
	struct S_Distance S_Sum_Dis ;
	
	S_Dis_1 = Get_Distance(S_Dis_1 );
	fflush(stdin); fflush(stdout);
	
	S_Dis_2 = Get_Distance(S_Dis_2 );
	fflush(stdin); fflush(stdout);
	
	S_Sum_Dis = Sum_Distance (S_Dis_1 , S_Dis_2);
	printf ("\nSum of two Distances = %i Feet , %.4f Inch\n",S_Sum_Dis.Feet,S_Sum_Dis.Inch);

	
}

struct S_Distance Get_Distance(struct S_Distance S_Dis )
{
	printf ("\nEnter Information for the Distance : \n");
	printf ("Enter Feet: ");
	scanf ("%d",&S_Dis.Feet);
	printf ("Enter Inch: ");
	scanf ("%f",&S_Dis.Inch);
	printf ("\n");

	return S_Dis ;
}

struct S_Distance Sum_Distance(struct S_Distance S_Dis_1 , struct S_Distance S_Dis_2 )
{
	struct S_Distance S_Sum_Dis ;
	S_Sum_Dis.Feet = S_Dis_1.Feet + S_Dis_2.Feet ;
	S_Sum_Dis.Inch = S_Dis_1.Inch + S_Dis_2.Inch ;
	
	while(S_Sum_Dis.Inch >= 12.0)
	{
		S_Sum_Dis.Inch -= 12.0 ;
		S_Sum_Dis.Feet++;
	}
	
	return S_Sum_Dis ;

}