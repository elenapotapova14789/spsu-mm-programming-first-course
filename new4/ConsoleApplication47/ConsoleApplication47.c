// ConsoleApplication47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>

int check(int);

int main()
{
	int a = 2;

	printf("\n");

	for (int n = 2; n <= 31; n++)
	{
		a *= 2;
		if (check(a - 1))
			printf("%d\n", a - 1);
	}
	system("pause");
	return 0;
}

int check(int a)
{
	if (a % 2 == 0)
	{
		return 0;
	}

	for (int i = 3; i <= sqrtf((float)a); i += 2)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}

	return 1;
}