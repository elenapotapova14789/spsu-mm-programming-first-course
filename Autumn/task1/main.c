#include <stdio.h>
#include <malloc.h>

char* name1 = "Kirill";
char* name2 = "Glazyrin";
char* name3 = "Maximovich";

int is_little_endian()
{
    int value = 1;
    int *x = &value;
    short *y = (short*) x;
    return (int) *y;
}

void print_bits(int length, int *bits)
{
    for (int i = length - 1; i >= 0; i--)
    {
        printf("%d", bits[i]);
        if (i % 8 == 0 && i != 0)
        {
            printf(" ");
        }
    }
}

void int_binary(int x)
{
    int mem[sizeof(x) * 8];
    int bit = 1;
    for (int i = 0; i < sizeof(x) * 8; i++)
    {
        mem[i] = (x & bit) == 0? 0: 1;
        bit = bit << 1;
    }
    print_bits(sizeof(x) * 8, mem);
}

void long_long_binary(long long x)
{
    int mem[sizeof(x) * 8];
    long long bit = 1;
    for (int i = 0; i < sizeof(x) * 8; i++)
    {
        mem[i] = (x & bit) == 0? 0: 1;
        bit = bit << 1;
    }
    print_bits(sizeof(x) * 8, mem);
}

// This case is a terrible one!
// It has to be dealt with separately.
void double_binary_x86(double *x)
{
    long long *ptr = (long long*) x;
    if (is_little_endian())
    {
        long_long_binary(*(ptr + 1));
        printf(" ");
        long_long_binary(*ptr);
    }
    else
    {
        long_long_binary(*ptr);
        printf(" ");
        long_long_binary(*(ptr + 1));
    }

}

// Unused.
void double_binary_x64(double *x)
{
    int *ptr = (int*) x;
    if (is_little_endian())
    {
        int_binary(*(ptr + 1));
        printf(" ");
        int_binary(*ptr);
    }
    else
    {
        int_binary(*ptr);
        printf(" ");
        int_binary(*(ptr + 1));
    }
}

int len(char const *string)
{
    int result = 0;
    for (; string[result] != '\0'; result++);
    return result;
}

int main()
{
    if (sizeof(float) != 4 || sizeof(double) != 8)
    {
        printf("Error: unsupported machine.");
        return 1;
    }
    switch (sizeof(int))
    {
        case 2:
        {
            // x86
            long long x = - len(name1) * len(name2) * len(name3);
            printf("32-bit negative integer:\n%lli = \n", x);
            long_long_binary(x);
            printf("\n");

            float *y = malloc(sizeof(float));
            *y = len(name1) * len(name2) * len(name3);
            printf("Positive single-precision floating-point number:\n%f = \n", *y);
            long long *ptr = (long long*) y;
            long_long_binary(*ptr);
            printf("\n");
            free(y);

            double *z = malloc(sizeof(double));
            *z = - len(name1) * len(name2) * len(name3);
            printf("Negative double-precision floating-point number:\n%lf = \n", *z);
            double_binary_x86(z);
            printf("\n");
            free(z);

            return 0;
        }
        case 4:
        {
            // x32, x64
            int x = - len(name1) * len(name2) * len(name3);
            printf("32-bit negative integer:\n%d = \n", x);
            int_binary(x);
            printf("\n");

            float *y = malloc(sizeof(float));
            *y = len(name1) * len(name2) * len(name3);
            printf("Positive single-precision floating-point number:\n%f = \n", *y);
            int *ptry = (int*) y;
            int_binary(*ptry);
            printf("\n");
            free(y);

            double *z = malloc(sizeof(double));
            *z = - len(name1) * len(name2) * len(name3);
            printf("Negative double-precision floating-point number:\n%lf = \n", *z);
            long long *ptrz = (long long*) z;
            long_long_binary(*ptrz);
            printf("\n");
            free(z);

            return 0;
        }
        default:
        {
            printf("Error: unsupported machine.");
            return 1;
        }
    }
}
