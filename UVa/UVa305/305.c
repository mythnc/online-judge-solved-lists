/* ACM 305 Joseph
 * mythnc
 * 2011/12/01 14:33:02   
 * version 2
 * run time: 0.076
 */
#include <stdio.h>

#define MAX 13

int findm(int);

int main(void)
{
    int k, i;
    int answer[MAX];

    for (i = 0; i < MAX; i++)
        answer[i] = findm(i + 1);

    while (scanf("%d", &k) && k != 0)
        printf("%d\n", answer[k - 1]);

    return 0;
}

/* findm: return minimum m */
int findm(int k)
{
    int m, re, position;

    for (m = k + 1; ; m++) {
        for (position = 0, re = 2 * k; re > k; re--) {
            position = (position + m - 1) % re;
            if (position < k)
                break;
        }
        if (re == k)
            return m;
    }
}

