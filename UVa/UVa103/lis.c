/* Longest Increasing Subsequence
 * mythnc
 * http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html
 * 2012/01/15 13:04:16   
 */
#include <stdio.h>

#define MAXN 8
#define MAX(X, Y) (X >= Y ? X : Y)

int lis(void);
void printlis(int);

int seq[8] = {1, 2, 3, 4, 3, 6, 7, 8};
int dp[8]; /* for lis len */
int find[8]; /* find a lis seq */

int main(void)
{
    printf("%d\n", lis());
    printlis(lis());

    return 0;
}

int lis(void)
{
    int i, j, sum;
    /* init: each subsequence is 1 */
    for (i = 0; i < MAXN; i++) {
        dp[i] = 1;
        /* -1 means [i] is not append to others */
        find[i] = -1;
    }

    for (i = 0; i < MAXN; i++)
        for (j = i + 1; j < MAXN; j++)
            if (seq[j] > seq[i] && dp[i] + 1 > dp[j]) {
                dp[j] = dp[i] + 1;
                find[j] = i; /* s[j] append to s[i] */
            }

                /* compare j itself to [i]
                dp[j] = MAX(dp[j], dp[i] + 1);
                */

    for (i = sum = 0; i < MAXN; i++)
        sum = MAX(sum, dp[i]);

    return sum;
}

void printlis(int len)
{
    int i;

    for (i = 0; i < MAXN; i++)
        if (dp[i] == len)
            break;

    while (1) {
        printf("%d ", seq[i]);
        if (find[i] == -1)
            break;
        i = find[i];
    }
}

