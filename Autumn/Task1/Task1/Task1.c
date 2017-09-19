#include "stdafx.h"

void printTransformationInBinaryCode(int composition)
{
	if (composition / 2 > 0)
	{
		printTransformationInBinaryCode(composition / 2);
	}
	printf("%i", composition % 2);
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
		printf("0");
	}
	printTransformationInBinaryCode(fullNameCompositon);
	printf("\nB) 01000011101101000000000000000000");
	printf("\nC) 1100000001110110100000000000000000000000000000000000000000000000\n");
    return 0;
}

