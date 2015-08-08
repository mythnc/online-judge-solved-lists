/* ACM 147 Dollars
 * mythnc
 * 2011/12/13 14:56:54   
 * run time: 0.012
 */
#include <stdio.h>

#define MAXN 6001
#define COIN 11

void cal(long long *);

int main(void)
{
    long long ans[MAXN] = { 0 };
    double n;

    cal(ans);

    while (scanf("%lf", &n) && n != 0.0)
        printf("%6.2f%17lld\n", n, ans[(int)(n * 20)]);

    return 0;
}

/* cal: pre calulate answer */
void cal(long long *ans)
{
    int money[] = {1, 2, 4, 10, 20, 40,
                   100, 200, 400, 1000, 2000};
    int i, j;

    ans[0] = 1;
    for (i = 0; i < COIN; i++)
        for (j = money[i]; j < MAXN; j++)
            ans[j] += ans[j - money[i]];
}

