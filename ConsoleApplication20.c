// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

struct st
{
	int a[8];
	int*next;
};


int main()
{
	struct st
	{
		int a[8];
		int* next;
	}b;
	int i;
	for (i = 0; i < 8; i++) {
		b.a[8] = i++;
		printf("%d\n", b.a[i]);
	}
	struct st*st1 = malloc(sizeof(struct st));

	addtoend(b.a[8], 1);

	system("pause");
	//???????
    return 0;
}

