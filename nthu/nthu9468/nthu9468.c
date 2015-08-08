#include <stdio.h>
#include <math.h>

void pfactor(int n);

int main(void)
{
    int n;

    while (scanf("%d", &n) == 1) {
        pfactor(n);
    }
    return 0;
}

void pfactor(int n)
{
    int i;
    int output = 0;

    if (n % 2 == 0) {
        n /= 2;
        printf("%d", 2);
        output = 1;
    }
    while (n % 2 == 0) {
        n /= 2;
    }

    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            n /= i;
            if (output) {
                printf(" %d", i);
            }
            else {
                printf("%d", i);
                output = 1;
            }
        }
        while (n % i == 0) {
            n /= i;
        }
    }

    // n is prime
    if (n != 1) {
        if (output)
            printf(" %d\n", n);
        else
            printf("%d\n", n);
    }
    else {
        putchar('\n');
    }
}

