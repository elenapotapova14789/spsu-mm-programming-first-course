#include <stdio.h>
#include"stdafx.h"
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

char *s1 = "Elena";
char *s2 = "Potapova";
char *s3 = "Sergeevna";

int a = (int)(strlen(s1) * strlen(s2) * strlen(s3));

void bin(int a)
{
	for (int i = 0; i < 32; i++)
	{
		//Проверяем старший бит)
		if (a & 0x80000000)
			cout << "1";
		else
			cout << "0";
		//Сдвигаем влево на 1 бит
		a = a << 1;
	}
}

int main() {

	float f1 = a;
	unsigned int *f = (unsigned int*)&f1;

	double d1 = -a;
	unsigned long long int *d = (unsigned long long int*) &d1;

	int i1 = -a;
	unsigned int *i = (unsigned int*)&i1;

	printf("%s\n");
	bin(*i);

	printf("%s\n");
	bin(*f);

	printf("%s\n");
	bin(*d);

	system("pause");
	return 0;
}