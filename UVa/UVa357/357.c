/* ACM 357 Let Me Count The Ways
 * mythnc
 * 2011/12/15 11:15:23   
 * version 1.1
 * run time: 0.016
 */
#include <stdio.h>

#define MAXN 30001
#define COIN 5

void cal(long long *);

int main(void)
{
    int n;
    long long ans[MAXN] = { 1 };

    cal(ans);

    while (scanf("%d", &n) == 1)
        if (n < 5)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", ans[n], n);

    return 0;
}

/* cal: pre calulate the answer */
void cal(long long *ans)
{
    int money[COIN] = {1, 5, 10, 25, 50};
    int i, j;

    for (i = 0; i < COIN; i++)
        for (j = money[i]; j < MAXN; j++)
            ans[j] += ans[j - money[i]];
}

