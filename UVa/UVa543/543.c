/* ACM 543 Goldbach's Conjecture
 * mythnc
 * 2011/11/04 15:28:29   
 * run time: 0.164
 */
#include <stdio.h>

#define TRUE  1
#define FALSE 0

int prime(int);

int main(void)
{
    int n, i;

    while (scanf("%d", &n) && n != 0)
        for (i = 3; i < n; i += 2)
            if (prime(i) == TRUE && prime(n - i) == TRUE) {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }

    return 0;
}

/* prime: if n is prime, return TRUE,
 * else return FALSE */
int prime(int n)
{
    int i;

    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return FALSE;

    return TRUE;
}

