/* ACM 583 Prime Factors
 * mythnc
 * 2011/11/17 22:56:12   
 * run time: 0.340
 */
#include <stdio.h>
#include <math.h>

void factor(int);
int print(int, int);

int main(void)
{
    int n;

    while (scanf("%d", &n) && n != 0) {
        printf("%d = ", n);
        if (n < 0) {
            printf("-1 x ");
            n *= -1;
        }
        factor(n);
    }
    return 0;
}

/* factor: find prime factor and print it */
void factor(int n)
{
    int i;
    /* even */
    while (n % 2 == 0 && n != 1)
        n = print(n, 2);
    if (n == 1)
        return;
    /* odd */
    for (i = 3; i <= sqrt(n) && n != 1; i += 2)
        while (n % i == 0 && n != 1)
            n = print(n, i);
    if (n == 1)
        return;
    /* prime */
    if (n != 1)
        printf("%d\n", n);
}

/* print: print prime and return n */
int print(int n, int i)
{
    n /= i;
    if (n == 1) {
        printf("%d\n", i);
        return 1;
    }
    else
        printf("%d x ", i);

    return n;
}

