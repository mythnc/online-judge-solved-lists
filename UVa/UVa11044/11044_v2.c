/* ACM 11044 Searching for Nessy
 * mythnc
 * 2012/01/04 16:59:37   
 * version2: optimization v1
 * run time: 0.008
 */
#include <stdio.h>

int main(void)
{
    int m, n;

    scanf("%*d");
    while (scanf("%d %d", &m, &n) == 2)
        printf("%d\n", (m / 3) * (n / 3));

    return 0;
}

