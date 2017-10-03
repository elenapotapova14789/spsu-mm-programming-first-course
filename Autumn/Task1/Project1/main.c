#include "stdio.h"


void printTransformationInBinaryCodeWithoutOne(int number)
{
	if (number / 2 > 0)
	{
		printTransformationInBinaryCodeWithoutOne(number / 2);
		printf("%i", number % 2);
	}
}

void printTransformationInBinaryCode(int number)
{
	if (number / 2 > 0)
	{
		printTransformationInBinaryCode(number / 2);
	}
	printf("%i", number % 2);
}

void printTransformationInInvertBinaryCode(int composition, int n)
{
	if (composition % 2 == 1)
	{
		if (composition / 2 > 0)
		{
			printTransformationInInvertBinaryCode(composition / 2, n + 1);
		}
	}
	else
	{ 
		if (composition / 2 > 0)
		{
			printTransformationInInvertBinaryCode(composition / 2, n);
		}
	}
	if (n == 0)
	{ 
			if (composition % 2 == 1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
	}
	else
	{
		if (composition % 2 == 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}

}

int lengthBinaryCode(int composition)
{
	int i = 0;
	while (composition > 0)
	{
		i++;
		composition /= 2;

	}
	return i;
}

int main()
{
	printf("My full name is: Usik Vladislav Sergeevich.\nLength: first name - 9, second name - 4, patronymic - 10.\n");
	int firstNameLength = 9;
	int secondNameLength = 4;
	int patronymicLength = 10;
	int fullNameCompositon;
	fullNameCompositon = firstNameLength * secondNameLength * patronymicLength;
	int lengthCode = lengthBinaryCode(fullNameCompositon);
	printf("A) 1");
	for (int i = 0; i < 31 - lengthCode; i++)
	{
		printf("1");
	}
	int n = 0;
	printTransformationInInvertBinaryCode(fullNameCompositon, n);
	printf("\nB) 0");
	printTransformationInBinaryCode(127 + lengthBinaryCode(fullNameCompositon) - 1);
	printTransformationInBinaryCodeWithoutOne(fullNameCompositon);
	for (int i = 0; i < 23 - lengthBinaryCode(fullNameCompositon) + 1; i++)
	{
		printf("0");
	}
	printf("\nC) 1");
	printTransformationInBinaryCode(1023 + lengthBinaryCode(fullNameCompositon) - 1);
	printTransformationInBinaryCodeWithoutOne(fullNameCompositon);
	for (int i = 0; i < 52 - lengthBinaryCode(fullNameCompositon) + 1; i++)
	{
		printf("0");
	}
	return 0;
}