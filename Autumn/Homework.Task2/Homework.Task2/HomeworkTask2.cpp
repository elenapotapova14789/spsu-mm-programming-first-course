// HomeworkTask2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include < math.h > 


int pythagoreanTriple (int x, int y, int z)
{
	return ((pow(x, 2) + pow(y, 2) == pow(z, 2)) || (pow(x, 2) + pow(z, 2) == pow(y, 2)) || (pow(z, 2) + pow(y, 2) == pow(x, 2)));
}

void swap (int *x, int *y)
{
	int k = *x;
	*x = *y;
	*y = k;
}

int relativePrime (int x, int y, int z)
{
	if(x > y)
	{
		swap(&x, &y);
	}

	if(x > z)
	{
		swap(&x, &z);
	}
	 
	if((y % x == 0) && (z % x == 0))
	{
		return 0;
	}
	
	int i = 2;
	while (i <= x / 2)
	{
		if((x % i == 0) && (y % i == 0) && (z % i == 0))
		{
			return 0;
		}
		i++;
	}
	
	return 1;
}

int primitivePythagoreanTriple (int x, int y, int z)
{
	return relativePrime(x, y, z);
}

int main()
{
	printf("enter 3 natural numbers\n");
	printf("x = ");
	int x = 0;
	scanf_s("%u", &x);
	printf("y = ");
	int y = 0;
	scanf_s("%u", &y);
	printf("z = ");
	int z = 0;
	scanf_s("%u", &z);
	
	if(pythagoreanTriple(x, y, z))
	{
		printf("These numbers are Pythagorean triple\n");
		if(primitivePythagoreanTriple(x, y, z))
		{
			printf("These numbers are primitive Pythagorean triple\n");
		}
		else
		{
			printf("These numbers are not primitive Pythagorean triple\n");
		}
	}
	else
	{
		printf("These numbers are not Pythagorean triple\n");
	}
	
	return 0;
}

