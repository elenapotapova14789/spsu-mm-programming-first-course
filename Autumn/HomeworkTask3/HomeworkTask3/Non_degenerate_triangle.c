#include <stdio.h>
#include <math.h>

void print_degrees(float, float, float);

int main()
{
	float a, b, c;

	printf("Non-degenerate triangle check. Enter 3 numbers: ");
	scanf_s("%f%f%f", &a, &b, &c);

	if (a + b != c && b + c != a && a + c != b)
	{
		printf("This is non-degenerate triangle. Angles:\n");
		print_degrees(a, b, c);
		print_degrees(b, c, a);
		print_degrees(a, c, b);
	}
	else
		printf("This is degenerate triangle.");

	return 0;
}

void print_degrees(float a, float b, float c)
{
	float angle = acosf((b*b + c*c - a*a) / (2 * b*c)); // radians
	angle = angle * 180 / 3.141592f; // decimal degrees

	int degrees = (int)angle;
	int minutes = (int)((angle - degrees) * 60);
	int seconds = (int)((angle - degrees - minutes / 60) * 36); // * 36 because we want only 2 digits

	printf("%d %d' %d\"\n", degrees, minutes, seconds);
}