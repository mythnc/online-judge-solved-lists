/* ACM 623 500!
 * mythnc
 * 2011/11/22 21:08:08   
 * run time:
 */
#include <stdio.h>

#define MAXD 2600

void init(int *);
void mul(int *, int);
void printbig(int *);

int main(void)
{
    int n;
    int big[MAXD];

    while (scanf("%d", &n) == 1) {
        init(big);
        mul(big, n);
        printf("%d!\n", n);
        printbig(big);
    }

    return 0;
}

/* init: initialize b to zero */
void init(int *b)
{
    int i;

    for (i = 0; i < MAXD; i++)
        b[i] = 0;
}

/* mul: do b * n */
void mul(int *b, int n)
{
    int i, j;

    b[0] = 1;
    for (i = 2; i < n + 1; i++) {
        for (j = 0; j < MAXD; j++)
            b[j] *= i;
        /* carry */
        for (j = 0; j < MAXD - 1; j++)
            if (b[j] > 9) {
                b[j + 1] += b[j] / 10;
                b[j] %= 10;
            }
    }
}

/* printbig: print b */
void printbig(int *b)
{
    int digit;

    /* find digit */
    for (digit = MAXD - 1; b[digit] == 0 && digit > -1; digit--)
        ;
    for (; digit > -1; digit--)
        printf("%d", b[digit]);
    putchar('\n');
}

