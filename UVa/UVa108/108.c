/* ACM 108 Maximum Sum
 * mythnc
 * 2012/04/03 16:17:17
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>

#define MAXN 100

void subsum(int, int);

int s[MAXN][MAXN];
int colsum[MAXN];
int max;

int main(void)
{
    int n, i, j;

    scanf("%d", &n);
    /* init */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &s[i][j]);

    max = -12701;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++)
            subsum(j, n);
        /* clear colsum's content */
        memset(colsum, 0, sizeof(int) * n);
    }

    printf("%d\n", max);

    return 0;
}

/* subsum: calculate the sub-rectangle value */
void subsum(int row, int n)
{
    int i, sum;

    for (i = 0; i < n; i++)
        colsum[i] += s[row][i];
    /* Kadane's algorithm (modified) */
    for (i = sum = 0; i < n; i++) {
        sum += colsum[i];
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
}

