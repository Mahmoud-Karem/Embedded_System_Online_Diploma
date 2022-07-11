/***************************************************************************
 Exam        : EX3_Prime_Numbers_in_Interval
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 10 - 2022
****************************************************************************/

#include <stdio.h>

void Prime_Between_Interval (unsigned int Start , unsigned int End);


void main ()
{
	unsigned int x,y;

	printf ("Enter two numbers(intervals): ");
	scanf ("%d %d",&x,&y);
	Prime_Between_Interval (x,y);

}

void Prime_Between_Interval (unsigned int Start , unsigned int End)
{
	
	unsigned int Counter=0 , Flag=0;
	
	printf ("Ptime numbers between %i and %i are: ",Start,End);
	
	while (Start <= End)
	{
		if (Start == 0 || Start == 1)
		{
			Start ++ ;
		}
		else
		{
			for (Counter=2 ; Counter<=(Start/2) ; Counter++)
			{
				if ((Start%Counter) == 0)
				{
					Flag = 1 ;
					Start ++ ;
					break;
				}
			}
			
			if (Flag==0)
			{
				printf ("%d ",Start);
				Start ++ ;
			}
			
			Flag=0;
			
		}
	}
	printf ("\n");
}
