// ConsoleApplication38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

int input()
{
	setlocale(LC_ALL, "Rus");
	int x;
	while (1)
		if ((scanf_s("%d", &x) != 1) || ((int)sqrt(x)*(int)sqrt(x)) == x)
		{
			printf("%s", "Ошибка, введите другое");
			while (getchar() != '\n');
		}
		else
		{
			return x;
		}
}

int cf(int di, double n, int t)
{

	int k, i = 0;
	double num = 1, den = 1, id = di;

	printf("%d ", di);

	while ((num / den != (n + di)))
	{
		num = (n + id);
		den = (t - id*id) / den;

		k = (int)(num / den);
		id = den*k - id;

		printf("%d ", k);
		i++;
	}
	/*while ((num / den != (n + di)));*/
	return i;
}

int main()
{
	double t;
	printf("%s", "Введите ");
	t = input();
	printf("\n%s%d \n", "Период = ", cf((int)sqrt(t), sqrt(t), (int)t));
	system("pause");
    return 0;
}

