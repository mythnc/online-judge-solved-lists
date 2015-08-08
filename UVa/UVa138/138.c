/* ACM 138 Street Numbers
 * mythnc
 * 2011/11/14 07:54:27   
 * run time: 0.3
 */
#include <stdio.h>

int main(void)
{
    long long i, j, pre, next;
    int count;

    printf("%10d%10d\n", 6, 8);
    pre = next = 15;
    j = 9;
    for (i = 7, count = 1; count < 10; i++) {
            pre += i - 1;
            next -= i;
        for (; next < pre; j++)
            next += j;
        if (next == pre) {
            printf("%10lld%10lld\n", i, j - 1);
            count++;
        }
    }
    return 0;
}

