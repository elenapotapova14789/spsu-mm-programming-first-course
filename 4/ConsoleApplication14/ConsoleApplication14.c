// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int i;
	for (i = 0; i < 31; i++)
	{
		printf("%f\n", (powl (2,i) - 1));
	}
	system("pause");
    return 0;
}

