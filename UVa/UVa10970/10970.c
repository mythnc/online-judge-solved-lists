/* ACM 10970 Big Chocolate
 * mythnc
 * 2011/12/05 13:32:12   
 * run time: 0.040
 */
#include <stdio.h>

int main(void)
{
    int m, n;

    while (scanf("%d %d", &m, &n) == 2)
        printf("%d\n", m * n - 1);

    return 0;
}

