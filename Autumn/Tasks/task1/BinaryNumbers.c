#include <stdio.h>
#include <string.h>

void printBin(unsigned long long x, int n)
{// n - sizeof x in bytes
    int k = n * 8;
    int bin[k];

    for (int i = k - 1; i >= 0; --i)
    {
        bin[i] = x % 2;
        x /= 2;
    }

    for (int i = 0; i < k; ++i)
    {
        if (i > 0 && i % 8 == 0) printf("_");
        printf("%d", bin[i]);
    }
    printf("\n");
}

int main()
{
    char *s1 = "Azim";
    char *s2 = "Muradov";
    char *s3 = "Mehmanovich";

    int len = (int) (strlen(s1) * strlen(s2) * strlen(s3));
    printf("%d\n", len);

    unsigned long x1 = (unsigned long) -len;
    printBin(x1, 4);

    float lenF = len;
    unsigned long x2;
    memcpy(&x2, &lenF, 4);
    printBin(x2, 4);

    double lenD = -len;
    unsigned long long x3;
    memcpy(&x3, &lenD, 8);
    printBin(x3, 8);


    return 0;
}
