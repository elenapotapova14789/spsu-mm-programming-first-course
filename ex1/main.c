#include <stdio.h>

const int fio = 528;

void binary(unsigned long long int num, int k, int max) //recursively prints the remainders of the division by two; num is the number, k is the counter, max is the size (4 or 8 bytes)
{
    if (k == (max - 1))
    {
        printf("%llu", num % 2);
    }
    else
    {
        k++;
        binary(num/2, k, max);
        if ((max - k) % 8 == 0)
        {
            printf(" ");
        }
        printf("%llu", num % 2);
    }
}


int main() {

    float a = fio;
    unsigned int *b = (unsigned int*) &a;
    double c = -fio;
    unsigned long long int *d = (unsigned long long int*) &c;
    int e = -fio;
    unsigned int *f = (unsigned int*) &e;

    printf("%s\n%s\n", "Name: Oleg Nickolaevich Chernyavsky", "Composition of the lengths: 12*4*11 = 528");

    printf("%s", "Answer for the first task:  ");
    binary(*f, 0, 32);
    printf("\n%s", "Answer for the second task: ");
    binary(*b, 0, 32);
    printf("\n%s", "Answer for the third task:  ");
    binary(*d, 0, 64);

    return 0;
}
