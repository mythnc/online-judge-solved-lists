/* ACM 10302 Summation of Polynomials
 * mythnc
 * 2011/11/14 07:28:09   
 * run time: 0.016
 */
#include <stdio.h>

int main(void)
{
    long long n;

    while (scanf("%lld", &n) == 1)
        printf("%lld\n", n * n * (n + 1) * (n + 1) / 4);

    return 0;
}

