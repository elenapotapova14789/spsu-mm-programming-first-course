#include <stdio.h>
#include <ctype.h>

int read_positive()
{
    printf("Please, enter a number: ");
    while (1)
    {
        int input;
        char after; // Used to ensure that input is integer.
        int result = scanf("%d%c", &input, &after);
        if (result == 2 && input > 0 && isspace(after))
        {
            if(after != '\n')
            {
                while (getchar() != '\n');
            }
            return input;
        }
        else if (result != 2 || !isspace(after))
        {
            while (getchar() != '\n');
        }
        printf("Error! Please, enter a valid number: ");
    }
}

/**
 * Checks if provided numbers are Pythagorean triple
 * @return 1 if numbers are Pythagorean triple, else 0
 * params are long long to avoid integer overflow.
 */
int isPythagorean(long long x, long long y, long long z)
{
    if (x * x == y * y + z * z
        || y * y == x * x + z * z
        || z * z == x * x + y * y)
    {
        return 1;
    }
    return 0;
}

/// Calculate gcd using Euclid's algorithm.
int GCD(int x, int y)
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
    int x = read_positive();
    int y = read_positive();
    int z = read_positive();
    if (isPythagorean(x, y, z))
    {
        printf("This is a Pythagorean triple.\n");
        if (GCD(GCD(x, y), z) == 1)
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
