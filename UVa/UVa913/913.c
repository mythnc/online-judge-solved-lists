/* ACM 913 Joana and the Odd Numbers
 * mythnc
 * 2011/10/24 21:38:34   
 * run time: 0.008
 */
#include <stdio.h>

int main(void)
{
    long long n;

    while (scanf("%lld", &n) != EOF) {
        n++;
        printf("%lld\n", 3 * n * n / 2 - 9);
    }
    return 0;
}

