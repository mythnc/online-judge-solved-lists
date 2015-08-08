/* ACM 686 Goldbach's Conjecture (II)
 * mythnc
 * 2011/11/07 17:45:42   
 * run time: 0.016
 */
#include <stdio.h>

#define TRUE  1
#define FALSE 0

int countp(int);
int prime(int);

int main(void)
{
    int n;

    while (scanf("%d", &n) && n != 0)
        printf("%d\n", countp(n));
    return 0;
}

/* countp: return the pair numbers match
 * Goldbach's Conjecture */
int countp(int n)
{
    int i, count;

    if (n == 4)
        return 1;

    for (count = 0, i = 3; 2 * i <= n; i += 2)
        if (prime(i) && prime(n - i))
            count++;

    return count;
}

/* prime: return TRUE if n is prime,
 * else return FALSE */
int prime(int n)
{
    int i;

    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return FALSE;

    return TRUE;
}

