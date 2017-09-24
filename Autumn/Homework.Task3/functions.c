#include <stdio.h>

int read()
{
    printf("Please, enter a number: ");
    while (1)
    {
        int x;
        int result = scanf("%d", &x);
        if (result != 0)
        {
            return x;
        }
        while (getchar() != '\n') {} // We need to free the input stream
        printf("Error! Please, enter a valid number: ");
    }
}

unsigned read_positive()
{
    printf("Please, enter a number: ");
    while (1)
    {
        // needs to be long long to manage negative values properly
        long long x;
        int result = scanf("%lli", &x);
        // Check that x is a number, positive and fits into unsigned data type
        if (result != 0 && x > 0 && x == (unsigned) x)
        {
            return (unsigned) x;
        }
        else
        {
            while (getchar() != '\n') {} // We need to free the input stream
        }
        printf("Error! Please, enter a valid number: ");
    }
}

double read_double_positive()
{
    printf("Please, enter a number: ");
    while (1)
    {
        double x;
        int result = scanf("%lf", &x);
        if (result != 0 && x > 0) {
            return x;
        }
        else
        {
            while (getchar() != '\n') {} // We need to free the input stream
        }
        printf("Error! Please, enter a valid number: ");
    }
}
