// ConsoleApplication18.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


	int main()
	{
		int x;
		int y;
		int z;


		printf("vvedite x");
		scanf_s("%d", &x);
		printf("vvedite y");
		scanf_s("%d", &y);
		printf("vvedite z");
		scanf_s("%d", &z);
		
		
		if (((x*x) + (y*y)) == (z*z))
			printf("da\n");
		
		else
			printf("net\n");
			
		if (((x*x) + (y*y)) == (z*z))
		{
			while (x != y)
			{
				if (x > y)
					x = x - y;
				else
					y = y - x;
			}
			if (x = 1)
			{
				printf("primitiv\n");
			}
		}



		system("pause");
		return 0;
	}


