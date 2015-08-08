/* ACM 10499 The Land of Justice
 * mythnc
 * 2011/12/26 10:04:46   
 * run time: 0.024
 */
#include <stdio.h>

int main(void)
{
    long long n;

    while (scanf("%lld", &n) && n > 0)
        if (n == 1)
            printf("0%%\n");
        else
            printf("%lld%%\n", n * 25);

    return 0;
}

