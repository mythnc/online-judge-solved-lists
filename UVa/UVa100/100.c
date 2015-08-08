/* ACM 100 The 3n + 1 problem
 * mythnc
 * 2011/11/30 09:10:17
 * version 1.2
 * run time: 0.592
 */
#include <stdio.h>

int count(int);
int cal(int, int);

int main(void)
{
    int i, j;

    while (scanf("%d %d", &i, &j) == 2)
        printf("%d %d %d\n", i, j, j > i ? cal(i, j) : cal(j, i));

    return 0;
}

/* cal: find the big cycle len, and return it */
int cal(int small, int big)
{
    int i, max, tmp;

    for (max = 0, i = small; i <= big; i++) {
        tmp = count(i);
        if (max < tmp)
            max = tmp;
    }

    return max;
}

/* count: count the numbers of value n to 1 */
int count(int n)
{
    int c;

    for (c = 1; n != 1; c++)
        if(n % 2 == 0)
            n >>= 1;    /* n /= 2 */
        else 
            n = n * 3 + 1;

    return c;
}

