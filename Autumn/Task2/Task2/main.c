#include "stdio.h"

int NODNumbers(int x, int y);

int PythagoreanTripple(int x, int y, int z)
{
	if ((x*x + y*y == z*z) || (x*x + z*z == y*y) || (y*y + z*z == x*x))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int SimplePythagoreanTripple(int x, int y, int z)
{
	int nod_xy = NODNumbers(x, y);
	int nod_xyz = NODNumbers(nod_xy, z);
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
	printf("Please write 3 natural numbers.\n");
	printf("X: ");
	scanf_s("%i", &x);
	printf("Y: ");
	scanf_s("%i", &y);
	printf("Z: ");
	scanf_s("%i", &z);
	if (PythagoreanTripple(x, y, z) == 1)
	{
		printf("These numbers are Pythagorean Tripple\n");
		if (SimplePythagoreanTripple(x, y, z) == 1)
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