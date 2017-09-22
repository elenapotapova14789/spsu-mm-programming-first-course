// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>


int triangle(float x, float y, float z)
{
	return ((x + y > z) && (x + z > y) && (z + y > x));
}

void angles(float firstSide, float secondSide, float thirdSide, float *firstAngle, float *secondAngle, float *thirdAngle)
{
	*firstAngle = acos((pow(secondSide, 2) + pow(thirdSide, 2) - pow(firstSide, 2)) / (2 * secondSide * thirdSide)) * 180.0 / 3.14159;
	*secondAngle = acos((pow(firstSide, 2) + pow(thirdSide, 2) - pow(secondSide, 2)) / (2 * firstSide * thirdSide)) * 180.0 / 3.14159;
	*thirdAngle = acos((pow(secondSide, 2) + pow(firstSide, 2) - pow(thirdSide, 2)) / (2 * secondSide * firstSide)) * 180.0 / 3.14159;
}

void minutesSeconds(float number, int *degrees, int *minutes, int *seconds)
{
	float temp = 0;
	float afterPoint = modff(number, &temp);
	*degrees = number - afterPoint;
	float min = afterPoint * 60;
	afterPoint = modff(min, &temp);
	*minutes = min - afterPoint;
	*seconds = afterPoint * 60;
}

void printResult(int degrees, int minutes, int seconds)
{
	printf("%d", degrees);
	printf("*%d", minutes);
	printf("'%d", seconds);
	printf("\"\n");
}

int main()
{
	printf("enter 3 numbers\n");
	printf("x = ");
	float x = 0;
	scanf_s("%f", &x);
	printf("y = ");
	float y = 0;
	scanf_s("%f", &y);
	printf("z = ");
	float z = 0;
	scanf_s("%f", &z);

	if (triangle(x, y, z))
	{
		printf("Draw a triangle is possible\n");

		float firstAngle = 0;
		float secondAngle = 0;
		float thirdAngle = 0;
		angles(x, y, z, &firstAngle, &secondAngle, &thirdAngle);

		int degrees = 0;
		int minutes = 0;
		int seconds = 0;

		minutesSeconds(firstAngle, &degrees, &minutes, &seconds);
		printf("first angle = ");
		printResult(degrees, minutes, seconds);

		minutesSeconds(secondAngle, &degrees, &minutes, &seconds);
		printf("second angle = ");
		printResult(degrees, minutes, seconds);

		minutesSeconds(thirdAngle, &degrees, &minutes, &seconds);
		printf("third angle = ");
		printResult(degrees, minutes, seconds);
	}
	else
	{
		printf("Draw a triangle is not possible\n");
	}
	return 0;
}
