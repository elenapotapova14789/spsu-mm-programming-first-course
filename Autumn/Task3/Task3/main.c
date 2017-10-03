#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

const double Pi = 3.14159265358979323846;

char inputString(char* s);

void doubleNumb(double* x, char c, char* s, int* n)
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
			*x = atof(s);
			*n += 1;
			break;
		}
		case 'u':
		{
			*x = (double)atoi(s);
			*n += 1;
			break;
		}
	}
}

int testTriangleInequality(double x, double y, double z)
{
	if (x < y + z)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double findCosA (double a, double b, double c)
{
	return (a * a - b * b - c * c) / ((-2) * b * c);
}

int main()
{
	double x, y, z;
	x = 0;
	y = 0;
	z = 0;
	int n = 0;
	printf("Please enter 3 positive numbers :\n");
	while (n == 0)
	{
		printf("X = ");
		char s[20];
		scanf("%19s", &s);
		doubleNumb(&x, inputString(s), s, &n);
	}
	while (n == 1)
	{
		printf("Y = ");
		char s[20];
		scanf("%19s", &s);
		doubleNumb(&y, inputString(s), s, &n);
	}
	while (n == 2)
	{
		printf("Z = ");
		char s[20];
		scanf("%19s", &s);
		doubleNumb(&z, inputString(s), s, &n);
	}
	if ((x > 0) && (y > 0) && (z > 0))
	{
		if (   (testTriangleInequality(x, y, z)) 
			&& (testTriangleInequality(y, x, z))
			&& (testTriangleInequality(z, x, y)))
		{
			printf("You can make a nondegenerate triangle\n");
			int angleX, angleY, angleZ;
			angleX = (int)(acos(findCosA(x, y, z)) * 180 * 60 * 60 / Pi);
			angleY = (int)(acos(findCosA(y, x, z)) * 180 * 60 * 60 / Pi);
			angleZ = (int)(acos(findCosA(z, x, y)) * 180 * 60 * 60 / Pi);
			printf("First angle = %i%c %i\' %i\"\n", angleX / 3600, 248, (angleX / 60) % 60, angleX % 60);
			printf("Second angle = %i%c %i\' %i\"\n", angleY / 3600, 248, (angleY / 60) % 60, angleY % 60);
			printf("Third angle = %i%c %i\' %i\"\n", angleZ / 3600, 248, (angleZ / 60) % 60, angleZ % 60);
		}
		else
		{
			printf("You can not make a nondegenerate triangle\n");
		}
	}
	else
	{
		printf("You can not make a nondegenerate triangle\n");
	}

	return 0;
}