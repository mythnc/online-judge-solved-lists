/* ACM 10699 Count the factors
 * mythnc
 * 2011/12/29 09:41:28   
 * run time: 0.024
 */
#include <stdio.h>

int countp(int);

int main(void)
{
    int n;

    while (scanf("%d", &n) && n != 0)
        printf("%d : %d\n", n, countp(n));

    return 0;
}

/* countp: return the number of prime factor */
int countp(int n)
{
    int i, count;

    for (i = 2, count = 0; n != 1; i++) {
        if (n % i == 0) {
            count++;
            while (n % i == 0)
                n /= i;
        }
    }

    return count;
}

