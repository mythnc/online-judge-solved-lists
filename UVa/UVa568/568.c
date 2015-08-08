/* ACM 568 Just the Facts
 * mythnc
 * 2011/11/16 10:06:34   
 * run time: 0.016
 */
#include <stdio.h>

#define MAXN 10001
#define MAXD 100

void init(int *, char *);

int main(void)
{
    int n;
    int digit[MAXD] = { 0 };
    char save[MAXN];

    init(digit, save);
    while (scanf("%d", &n) == 1)
        printf("%5d -> %c\n", n, save[n]);

    return 0;
}

/* init: precalculate answer,
 * save last non-zero in array save */
void init(int *d, char *s)
{
    int i, j, k;

    s[0] = '0';
    d[0] = 1;
    for (i = 1; i < MAXN; i++) {
        for (j = 0; j < MAXD; j++)
            d[j] *= i;
        /* carry */
        for (j = 0; j < MAXD - 1; j++)
            if (d[j] > 9) {
                d[j + 1] += d[j] / 10;
                d[j] %= 10;
            }
        /* remove zero */
        if (i > 4) {
            for (j = 0; d[j] == 0; j++)
                ;
            for (k = 0; j < MAXD; j++, k++)
                d[k] = d[j];
            for (; k < MAXD; k++)
                d[k] = 0;
        }
        /* copy last digit to s */
        s[i] = d[0] + '0';
    }
}

