// task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>


int primeNumber(int number)
{
	int i = 2;
	while (i < number / 2)
	{
		if (number % i == 0)
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int main()
{
	printf("Mersenne prime numbers: ");
	for (int n = 2; n <= 30; n++)
	{
		if (primeNumber((int)(pow(2, n) - 1)))
		{
			printf("%d", (int)(pow(2, n) - 1));
			printf(", ");
		}
	}

	if (primeNumber((int)(pow(2, 30) - 1 + pow(2, 30))))
	{
		printf("%d", (int)(pow(2, 30) - 1 + pow(2, 30)));
		printf(", ");
	}

	putchar('\b');
	putchar('\b');
	printf(" ");
	putchar('\n');

	return 0;
}