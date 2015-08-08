/* ACM 11044 Searching for Nessy
 * mythnc
 * 2012/01/04 16:41:07   
 * run time: 0.012
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    int m, n;

    scanf("%*d");
    while (scanf("%d %d", &m, &n) == 2)
        printf("%d\n", (int)ceil((double)(m - 2) / 3.0)
                       * (int)ceil((double)(n - 2) / 3.0));

    return 0;
}

