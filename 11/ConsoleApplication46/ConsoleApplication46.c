// ConsoleApplication46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>

int sum(int i)
{
	int sum = 0;
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}

	return sum;
}

int main()
{
	/*int l = 1000000;*/
	int mdrs[1000000];


	for (int i = 0; i < 10; ++i)
	{
		mdrs[i] = i;
	}


	for (int i = 10; i < 1000000; ++i)
	{
		mdrs[i] = mdrs[sum(i)];

	}


	for (int i = 2; i < 1000; ++i)
	{
		for (int j = i; i * j < 1000000; ++j)
		{
			if (mdrs[i] + mdrs[j] > mdrs[i * j])
			{
				mdrs[i * j] = mdrs[i] + mdrs[j];
			}
		}
	}


	int ans = 0;
	for (int i = 2; i < 100000; ++i)
	{
		ans += mdrs[i];
	}

	printf("%d", ans);
	system("pause");
	return 0;
}
