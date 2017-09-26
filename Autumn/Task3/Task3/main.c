#include "stdio.h"
#include "math.h"

const double Pi = 3.14159265358979323846;

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
	printf("Please enter 3 numbers :\n");
	printf("x = ");
	scanf_s("%lf", &x);
	printf("y = ");
	scanf_s("%lf", &y);
	printf("z = ");
	scanf_s("%lf", &z);
	if ((x > 0) && (y > 0) && (z > 0))
	{
		if (   (testTriangleInequality(x, y, z)) 
			&& (testTriangleInequality(y, x, z))
			&& (testTriangleInequality(z, x, y))   )
		{
			printf("You can make a neural triangle\n");
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
			printf("You can not make a neural triangle\n");
		}
	}
	else
	{
		printf("You can not make a neural triangle\n");
	}

	return 0;
}