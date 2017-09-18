#include <stdio.h>

int check_pyth_triple(int, int, int);
int check_prime(int, int, int);
int get_min(int, int, int);

int main()
{
	int a, b, c;

	printf("Enter 3 numbers: ");
	scanf_s("%d%d%d", &a, &b, &c);

	printf("(%d, %d, %d) is", a, b, c);

	if (check_pyth_triple(a, b, c))
	{
		if (check_prime(a, b, c))
			printf(" a primitive pythagorean triple\n");
		else
			printf(" a pythagorean triple\n");
	}
	else
		printf("n't a pythagorean triple\n");

	return 0;
}

int check_pyth_triple(int a, int b, int c)
{
	if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
		return 1;
	return 0;
}

int check_prime(int a, int b, int c)
{
	for (int i = 2; i < get_min(a, b, c); i++)
		if (a % i && b % i && c % i)
			return 0;
	return 1;
}

int get_min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return a;
		else
			return c;
	}
	else
	{
		if (b < c)
			return b;
		else
			return c;
	}
}