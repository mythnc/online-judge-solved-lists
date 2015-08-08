/* ACM 305 Joseph
 * mythnc
 * 2011/12/01 17:04:37   
 * version 2.b
 * start from 1 not zero
 * run time:
 */
#include <stdio.h>

int findm(int);

int main(void)
{
    int k;

    while (scanf("%d", &k) && k != 0)
        printf("%d\n", findm(k));

    return 0;
}

/* findm: return minimum m */
int findm(int k)
{
    int m, re, position;

    for (m = k + 1; ; m++) {
        for (re = 2 * k, position = 0; re > k; re--) {
            if (position == 0)
                position = m % re;
            else
                position = (position + m - 1) % re;
            if (position <= k && position != 0)
                break;
        }
        if (re == k)
            return m;
    }
}

