// ConsoleApplication31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	float a, b, c;
	scanf_s("%F%F%F", &a, &b, &c);

	if (a + b != c&&b + c != a&&a + c != b)
	{
		printf("можно построить невырожденный треугольник\n");
		angle(a, b, c);
		angle(b, c, a);
		angle(a, c, b);
	}
	else
	{
		printf("нельзя построить невырожденный треугольник\n");
	}

	system("pause");

	return 0;
}
void angle(float a, float b, float c)
{
	float angle = acosf((b * b + c * c - a * a) / (2 * b * c) * 180 / 3.141592f);
	int gr = (int)angle;
	int min = (int)((angle - gr) * 60);
	int s = (int)((angle - gr - min / 60) * 36);
	printf("%d\n%d\n %d\n", gr, min, s);
}


