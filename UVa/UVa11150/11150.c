/* ACM 11150 Cola
 * mythnc
 * 2012/01/04 17:25:04   
 * run time: 0.008
 */
#include <stdio.h>

int change(int);

int main(void)
{
    int n;

    while (scanf("%d", &n) == 1)
        printf("%d\n", change(n));

    return 0;
}

/* change: return the max colas we can get
 * from this change mechanism */
int change(int n)
{
    int sum;

    sum = n;
    while (n >= 3) {
        sum += n / 3;
        n = n / 3 + n % 3;
    }
    if (n == 2)
        sum++;

    return sum;
}

