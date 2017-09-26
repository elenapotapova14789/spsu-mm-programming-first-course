#include "stdio.h"
#include "math.h"

int main()
{
	int denominator = 0;
	int testPrimitive = 0;
	int numberMerssen = 0;
	printf("Primitive numbers of Merssen:\n");
	for (int n = 2; n <= 31; n++)
	{
		denominator = 2;
		testPrimitive = 1;
		numberMerssen = (int)pow(2, n) - 1;
		while (denominator <= sqrt(numberMerssen))
		{
			if (numberMerssen % denominator == 0)
			{
				testPrimitive = 0;
				break;
			}
			else
			{
				testPrimitive = 1;
			}
			denominator++;
		}
		if (testPrimitive == 1)
		{
			printf("%i\n", numberMerssen);
		}
	}

	return 0;
}