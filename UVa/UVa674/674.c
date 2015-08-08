/* ACM 674 Coin Change
 * mythnc
 * 2011/12/13 13:48:59   
 * run time: 0.036
 */
#include <stdio.h>

#define MAXC 7490
#define COIN 5

void cal(int *);

int main(void)
{
    int ans[MAXC] = { 0 };
    int n;

    cal(ans);

    while (scanf("%d", &n) == 1)
        printf("%d\n", ans[n]);

    return 0;
}

/* cal: pre calculate answer */
void cal(int *ans)
{
    int i, j;
    int money[] = {1, 5, 10, 25, 50};

    ans[0] = 1;
    for (i = 0; i < COIN; i++)
        for (j = money[i]; j < MAXC; j++)
            ans[j] += ans[j - money[i]];
}

