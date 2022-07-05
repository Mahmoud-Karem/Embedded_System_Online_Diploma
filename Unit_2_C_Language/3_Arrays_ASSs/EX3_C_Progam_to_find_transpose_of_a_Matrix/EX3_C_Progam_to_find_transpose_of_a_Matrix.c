/***************************************************************************
 Assignment  : EX3_C_Progam_to_find_transpose_of_a_Matrix.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 5 - 2022
****************************************************************************/

#include <stdio.h>
void main ()
{
	int i,j,ROW,COL;
	
	printf ("Enter rows and columns of matrix: ");
	scanf  ("%i" ,&ROW);
	scanf  ("%i" ,&COL);

	// Declaration
	float Arr[ROW][COL] ;
	float Arr_Trans[COL][ROW] ;

	// Scanning Matrix
	printf ("\nEnter elements of matrix: \n");
	for(i=0 ; i<ROW ; i++)
	{
		for(j=0 ; j<COL ;j++)
		{
			printf ("Enter a%i%i: ",i+1,j+1);
			scanf  ("%f" ,&Arr[i][j] );
		}
	}
	
	// Printing Matrix
	printf ("\nEntered Matrix:\n");
	for(i=0 ; i<ROW ; i++)
	{
		for(j=0 ; j<COL ;j++)
		{
			printf ("%.1f  ",Arr[i][j]);
		}
		printf ("\n");
	}
	
	// Init The Transpose Of Matrix
	for(i=0 ; i<COL ; i++)
	{
		for(j=0 ; j<ROW ;j++)
		{
			Arr_Trans[i][j] = Arr[j][i] ;
		}
	}
	
	// Printing The Transpose Of Matrix
	printf ("\nTranspose Of Matrix:\n");
	for(i=0 ; i<COL ; i++)
	{
		for(j=0 ; j<ROW ;j++)
		{
			printf ("%.1f  ",Arr_Trans[i][j]);
		}
		printf ("\n");
	}
}