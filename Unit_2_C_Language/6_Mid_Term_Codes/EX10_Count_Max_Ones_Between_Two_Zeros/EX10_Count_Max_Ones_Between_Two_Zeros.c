/*********************************************************************************
 Exam        : EX10_Count_Max_Ones_Between_Two_Zeros.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
**********************************************************************************/

# include <stdio.h>
int Count_Max_Ones (int NUM);

void main ()
{
	int NUM;
	printf("Enter a Number: ");
	scanf("%d", &NUM);

	printf("\nNumber Of Ones = %d\n",Count_Max_Ones(NUM));
}

int Count_Max_Ones (int NUM)
{
	int  C=0, Frame = 31, Ones=0 , Temp ;
	while (Frame >= 0)
	{
		Temp = NUM >> Frame;

		if (Temp & 1)
		{
			C++;
		}
		else
		{
			if(C>Ones)
			{
				Ones = C ;
				C = 0;
			}
			else
			{
				C=0;
			}
		}
		Frame--;
	}
	return Ones;
}