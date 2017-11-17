// ConsoleApplication43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include<locale.h>

int read()
{
	setlocale(LC_ALL, "rus");

	printf("введите сумму\n");

	while (1)
	{
		int value = 0;
		char next = '0';
		if ((scanf_s("%d%c", &value, &next) == 2) && (value > 0) && (isspace(next)))
		{
			return value;
		}
		else
		{
			if (next != '\n')
			{
				while (getchar() != '\n');
			}
			printf("ошибка\n");
		}
	}
}

int resh(int Money)
{
	int m[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	return get(Money, m, 7);
}

int get(int Money, int m[], int Coin)
{
	if (Money == 0)
	{
		return 1;
	}
	if (Money < 0)
	{
		return 0;
	}
	if (m[Coin] == 1)
	{
		return 1;
	}

	return get(Money, m, Coin - 1) + get(Money - m[Coin], m, Coin);
}

int main()
{
	int Money = read();
	int ways = resh(Money);
	printf("количество наборов = %d \n", ways);

	system("pause");

	return 0;
}
