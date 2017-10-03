#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"

int nodNumbers(int x, int y);

char inputString(char* s);

void naturalNumb(int* x, char c, char* s, int* naturalNumber)
{
	switch (c)
	{
		case 'e':
		{
			printf("You entered incorrect number!\nPlease enter number again.\n");
			break;
		}
		case 's':
		{
			printf("You entered negative number!\nPlease enter number again.\n");
			break;
		}
		case 'f':
		{
			printf("You entered fractional number!\nPlease enter number again.\n");
			break;
		}
		case 'u':
		{
			*x = atoi(s);
			*naturalNumber += 1;
			break;
		}
	}
}

int pythagoreanTripple(int x, int y, int z)
{
	if ((x * x + y * y == z * z) || (x * x + z * z == y * y) || (y * y + z * z == x * x))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int simplePythagoreanTripple(int x, int y, int z)
{
	int nod_xy = nodNumbers(x, y);
	int nod_xyz = nodNumbers(nod_xy, z);
	if (nod_xyz == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int x, y, z;
	int naturalNumber = 0;
	printf("Please write 3 natural numbers.\n");
	while (naturalNumber == 0)
	{
		printf("X = ");
		char s[16];
		scanf("%15s", &s);
		naturalNumb(&x, inputString(s), s, &naturalNumber);
	}
	while (naturalNumber == 1)
	{
		printf("Y = ");
		char s[16];
		scanf("%15s", &s);
		naturalNumb(&y, inputString(s), s, &naturalNumber);
	}
	while (naturalNumber == 2)
	{
		printf("Z = ");
		char s[16];
		scanf("%15s", &s);
		naturalNumb(&z, inputString(s), s, &naturalNumber);
	}
		
	if (pythagoreanTripple(x, y, z) == 1)
	{
		printf("These numbers are Pythagorean Tripple\n");
		if (simplePythagoreanTripple(x, y, z) == 1)
		{
			printf("These numbers are simple Pythagorean Tripple\n");
		}
		else
		{
			printf("These numbers are not simple Pythagorean Tripple\n");
		}
	}
	else
	{
		printf("These numbers are not Pythagorean Tripple\n");
	}
	return 0;
}