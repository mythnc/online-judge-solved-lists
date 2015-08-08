/* ACM 382 Perfection
 * mythnc
 * 2012/03/31 21:38:57   
 * run time: 0.004
 */
#include <stdio.h>

typedef enum {PERFECT, ABUNDANT, DEFICIENT} number;

number sumfactor(int);

int main(void)
{
    int n;
    char *num[3] = {"PERFECT", "ABUNDANT", "DEFICIENT"};

    printf("PERFECTION OUTPUT\n");
    while (scanf("%d", &n) && n != 0)
        printf("%5d  %s\n", n, num[sumfactor(n)]);

    printf("END OF OUTPUT\n");

    return 0;
}

/* sumfactor: sum the factor of n,
 * and return correspond symbol
 * of n - sum */
number sumfactor(int n)
{
    int i, sum, sub;

    if (n == 1)
        return DEFICIENT;

    for (sum = 1, i = 2; i * i <= n; i++)
        if (n % i == 0) {
            sum += i;
            if (n / i != i)
                sum += n / i;
        }

    sub = n - sum;
    if (sub > 0)
        return DEFICIENT;
    else if (sub == 0)
        return PERFECT;
    else
        return ABUNDANT;
}

