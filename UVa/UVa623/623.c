/* ACM 623 500!
 * mythnc
 * 2011/11/22 21:08:08   
 * run time: 0.084
 */
#include <stdio.h>

#define MAXD 2600
#define MAXN 1001

int mul(int *, int);
void copy(int *, char *, int);

int main(void)
{
    int n, i, digit;
    int big[MAXD] = { 1 };
    char fac[MAXN][MAXD];
    /* precalculate */
    for (i = 0; i < MAXN; i++) {
        digit = mul(big, i);
        copy(big, fac[i], digit);
    }

    while (scanf("%d", &n) == 1)
        printf("%d!\n%s", n, fac[n]);

    return 0;
}

/* mul: do b * n return its digit */
int mul(int *b, int n)
{
    int i;

    if (n == 0)
        return 0;

    for (i = 0; i < MAXD; i++)
        b[i] *= n;
    /* carry */
    for (i = 0; i < MAXD - 1; i++)
        if (b[i] > 9) {
            b[i + 1] += b[i] / 10;
            b[i] %= 10;
        }
    /* find digit */
    for (i = MAXD - 1; b[i] == 0 && i > -1; i--)
        ;

    return i;
}

/* copy: copy b to f */
void copy(int *b, char *f, int d)
{
    int i;

    for (i = 0; d > -1; i++, d--)
        f[i] = b[d] + '0';
    f[i++] = '\n';
    f[i] = '\0';
}

