/*********************************************************************************
 Quiz        : EX5_Check_User_Name.c
 Author      : Mahmoud Karem Zamel
 Date  		 : Jul 7 - 2022
**********************************************************************************/

#include <stdio.h>
#include <string.h>

#define SIZE 50

int Check_User(char String[] , char User_Name[]);
void main ()
{
	int  Check;
	char String[SIZE];
	char User_Name[SIZE]="Mahmoud";
	
	
	printf ("\nEnter a String: ");
	gets(String);
	Check = Check_User(String,User_Name);
	

	if (Check==0)
	{
		printf ("User name is correct\n");

	}
	else
	{
		printf ("User name is not correct\n");

	}	
}
int Check_User(char String[] , char User_Name[])
{
	return strcmp(String,User_Name);
}
