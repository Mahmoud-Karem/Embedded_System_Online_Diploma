/***************************************************************************
 Assignment  : EX1_Multidimentional_Array_in_C.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 5 - 2022
****************************************************************************/

#include <stdio.h>
void main ()
{

	float Arr1[2][2] , Arr2[2][2] ;
	int i,j;

	printf ("Enter The Elements of 1st matrix \n");
	for(i=0 ; i<2 ; i++)
	{
		for(j=0 ; j<2 ;j++)
		{
			printf ("Enter a%i%i: ",i+1,j+1);
			scanf  ("%f" ,&Arr1[i][j] );
		}
	}
	
	printf ("Enter The Elements of 2nd matrix \n");
	for(i=0 ; i<2 ; i++)
	{
		for(j=0 ; j<2 ;j++)
		{
			printf ("Enter b%i%i: ",i+1,j+1);
			scanf  ("%f" ,&Arr2[i][j] );
		}
	}
			
			
	printf ("Sum Of Matrix:\n");
	for(i=0 ; i<2 ; i++)
	{
		for(j=0 ; j<2 ;j++)
		{
			printf ("%f\t",Arr1[i][j]+Arr2[i][j]);
		}
		printf ("\n");
	}
}