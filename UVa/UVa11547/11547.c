/* ACM 11547 AUTOMATIC ANSWER
 * mythnc
 * 2012/01/05 21:01:17   
 * run time: 0.008
 */
#include <stdio.h>

int ans(int);

int main(void)
{
    int n;

    scanf("%*d");
    while (scanf("%d", &n) == 1)
        printf("%d\n", ans(n));

    return 0;
}

/* ans: find the answer and return tens column */
int ans(int n)
{
    n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
    if (n < 0)
        n = -n;

    return n % 100 / 10;
}

