/* ACM 530 Binomial Showdown
 * mythnc
 * 2011/11/12 09:39:41   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXARY 50

int com(int, int);
int gcd(int, int);

int main(void)
{
    int m, n;

    while (scanf("%d %d", &n, &m) && n != 0)
        printf("%d\n", com(n, m));
    return 0;
}

/* com: return the combined times */
int com(int n, int m)
{
    int i, j, factor, tmp;
    int num[MAXARY];

    if (m == n || m == 0)
        return 1;

    if (m > n - m)
        m = n - m;
    /* init */
    for (i = 0; i < m; i++)
        num[i] = n - m + 1 + i;
    /* simplify */
    for (i = m; i > 1; i--) {
        tmp = i;
        for (j = 0; j < m; j++) {
            if (num[j] % tmp == 0) {
                num[j] /= tmp;
                break;
            }

            factor = gcd(tmp, num[j]);
            if (factor > 1) {
                tmp /= factor;
                num[j] /= factor;
            }
        }
    }
    /* product */
    for (i = 1; i < m; i++)
        num[0] *= num[i];

    return num[0];
}

/* gcd: return the gcd of a and b */
int gcd(int a, int b)
{
    while ((a %= b) && (b %= a))
        ;

    return a + b;
}

