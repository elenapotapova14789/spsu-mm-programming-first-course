#include <stdio.h>
#include <math.h>

int check_prime(int);

int main()
{
	int a = 1;

	printf("Mersenne primes:\n");

	for (int n = 1; n <= 31; n++)
	{
		a *= 2;
		if (check_prime(a - 1))
			printf("%d\n", a - 1);
	}

	return 0;
}

int check_prime(int a) // проверка на простоту
{
	for (int i = 2; i <= sqrtf((float)a); i++)
		if (a % i == 0)
			return 0;
	return 1;
}