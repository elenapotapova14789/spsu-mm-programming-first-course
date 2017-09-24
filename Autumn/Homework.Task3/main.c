#include <stdio.h>
#include <math.h>
#include "functions.h"

/**
 * Determines angle using cosine theorem.
 * @param a
 * @param b - sides of triangle.
 * @param c
 * @return angle in degrees between sides a and b
 */
double angle(double a, double b, double c)
{
    double _cos = (a * a + b * b - c * c) / (2 * a * b);
    return acos(_cos) * M_1_PI * 180;
}

void stats(double a, double b, double c)
{
    double deg = angle(a, b, c);

    int degrees = (int) deg;
    deg -= degrees;
    deg *= 60;
    int minutes = (int) deg;
    deg -= minutes;
    deg *= 60;
    int seconds = (int) deg;

    printf("%d degrees", degrees);
    if (minutes)
    {
        printf(", %d minutes", minutes);
    }
    if (seconds)
    {
        printf(", %d seconds", seconds);
    }
    printf("\n");
}

int main()
{
    printf("Checks input values can form a triangle.\n");
    double a = read_double_positive();
    double b = read_double_positive();
    double c = read_double_positive();
    if (a + b > c &&
            a + c > b &&
            b + c > a)
    {
        printf("The values can be lengths of triangle sides.\n");
        printf("Angles:\n");
        stats(a, b, c);
        stats(a, c, b);
        stats(b, c, a);
    }
    else
    {
        printf("The values can not be lengths of triangle sides.\n");
    }
    return 0;
}