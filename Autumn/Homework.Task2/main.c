#include <stdio.h>
#include "functions.h"

/**
 * Checks if provided numbers are Pythagorean triple
 * @return 1 if numbers are Pythagorean triple, else 0
 */
int isPythagorean(unsigned x, unsigned y, unsigned z)
{
    if (x * x == y * y + z * z
        || y * y == x * x + z * z
        || z * z == x * x + y * y)
    {
        return 1;
    }
    return 0;
}

/**
 * Calculate GCD using Euclid's algorithm
 */
unsigned GCD(unsigned x, unsigned y)
{
    if (x == 0 || y == 0)
    {
        return 0;
    }
    while (x > 0 && y > 0)
    {
        if (x > y)
        {
            x %= y;
        }
        else
        {
            y %= x;
        }
    }
    return x + y;
}

int main()
{
    printf("Checks if entered numbers are Pythagorean triple.\n");
    unsigned x = read_positive();
    unsigned y = read_positive();
    unsigned z = read_positive();
    if (isPythagorean(x, y, z))
    {
        printf("This is a Pythagorean triple.\n");
        if (GCD(GCD(x, y), GCD(y, z)) == 1)
        {
            printf("Numbers are coprime.\n");
        }
        else
        {
            printf("Numbers are not coprime.\n");
        }
    }
    else
    {
        printf("This is not a Pythagorean triple.\n");
    }
    return 0;
}
