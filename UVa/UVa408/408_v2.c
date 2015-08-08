/* ACM 408 Uniform Generator
 * mythnc
 * 2012/01/01 10:07:53   
 * run time: 0.008
 */
#include <stdio.h>

int gcd(int, int);

int main(void)
{
    int step, mod;

    while (scanf("%d %d", &step, &mod) == 2)
        if (gcd(step, mod) == 1)
            printf("%10d%10d    Good Choice\n\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n", step, mod);

    return 0;
}

/* gcd: return gcd(a, b) */
int gcd(int a, int b)
{
    while ((a %= b) && (b %= a))
        ;

    return a + b;
}

