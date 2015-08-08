/* ACM 10079 Pizza Cutting
 * mythnc
 * 2011/11/04 14:49:55   
 * run time: 0.016
 */
#include <stdio.h>

int main(void)
{
    long long n;

    while (scanf("%lld", &n) && n >= 0)
        printf("%lld\n", n * (1 + n) / 2 + 1);
    return 0;
}

