/* ACM 900 Brick Wall Patterns
 * mythnc
 * 2011/12/30 10:12:43   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXN 50
#define MIN(X, Y) ((X <= Y) ? X : Y)

long long count(int);
long long com(int, int);
int gcd(int, int);

int main(void)
{
    int n, i;

    while (scanf("%d", &n) && n != 0)
        printf("%lld\n", count(n));

    return 0;
}

/* count: return the combination numbers */
long long count(int n)
{
    int i, ver, hor;
    long long times;

    times = 1;
    ver = n - 2;
    hor = 1;
    while (ver >= 0) {
        times += com(ver, hor);
        ver -= 2;
        hor++;
    }

    return times;
}

/* com: return the combination times:
 * (m + n)! / (n! * m!) */
long long com(int m, int n)
{
    int sum, i, j, times, factor, tmp;
    long long ans[MAXN] = { 0 };

    if (m == 0 || n == 0)
        return 1;
    if (m == 1 || n == 1)
        return m + n;

    times = 0;
    sum = m + n;
    /* init */
    for (i = sum - MIN(m, n) + 1; i <= sum; i++)
        ans[times++] = i;
    /* simplify */
    for (i = 2; i <= MIN(m, n); i++) {
        tmp = i;
        for (j = 0; j < times; j++) {
            if (ans[j] % tmp == 0) {
                ans[j] /= tmp;
                break;
            }
            if ((factor = gcd(tmp, ans[j])) != 1) {
                ans[j] /= factor;
                tmp /= factor;
            }
        }
    }
    /* cal ans */
    for (i = 1; i < times; i++)
        ans[0] *= ans[i];

    return ans[0];
}

/* gcd: return gcd */
int gcd(int a, int b)
{
    while ((a %= b) && (b %= a))
        ;

    return a + b;
}

