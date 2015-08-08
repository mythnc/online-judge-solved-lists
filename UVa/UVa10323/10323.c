/* ACM 10323 Factorial! You Must be Kidding!!! 
 * mythnc
 * 2011/12/17 09:24:42   
 * run time: 0.028
 */
#include <stdio.h>

#define MAX 6227020800LL

int main(void)
{
    int i, n;
    long long ans[20] = { 1 };

    for (i = 1; ans[i - 1] < MAX; i++)
        ans[i] = ans[i - 1] * i;

    while (scanf("%d", &n) == 1)
        if (n < 0) {
            n *= -1;
            if (n % 2 == 1)
                printf("Overflow!\n");
            else
                printf("Underflow!\n");
        }
        else if (n < 8)
            printf("Underflow!\n");
        else if (n >= i)
            printf("Overflow!\n");
        else
            printf("%lld\n", ans[n]);

    return 0;
}

