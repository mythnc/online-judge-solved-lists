/* ACM 11137 Ingenuous Cubrency
 * mythnc
 * 2012/01/17 21:40:44   
 * run time: 0.032
 */
#include <stdio.h>

#define MAXN 10000
#define MAXC 21

int main(void)
{
    int coin[MAXC] = {1, 8, 27, 64, 125, 216,
                    343, 512, 729, 1000, 1331, 1728,
                    2197, 2744, 3375, 4096, 4913, 5832,
                    6859, 8000, 9261};
    long long dp[MAXN] = { 1 };
    int i, j, money;

    for (i = 0; i < MAXC; i++)
        for (j = coin[i]; j < MAXN; j++)
            dp[j] += dp[j - coin[i]];

    while (scanf("%d", &money) == 1)
        printf("%lld\n", dp[money]);

    return 0;
}

