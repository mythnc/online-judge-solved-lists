/* ACM 10006 Carmichael Numbers
 * mythnc
 * 2011/11/14 16:53:51   
 * run time: 0.144
 */
#include <stdio.h>

#define FALSE 0
#define TRUE  1

int prime(int);
int fermat(int);
unsigned int powermod(int a, int n, int d);

int main(void)
{
    int n;

    while (scanf("%d", &n) && n != 0)
        if (!prime(n) && fermat(n))
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);

    return 0;
}

/* fermat: do Fermat test,
 * if n is prime return TRUE,
 * else return FALSE.
 * WARNING: it means in Fermat test is a prime,
 * maybe it isn't really a prime */
int fermat(int n)
{
    int i;

    for (i = 2; i < n; i++)
        if (powermod(i, n, n) != i)
            return FALSE;

    return TRUE;
}

/* powermod: calculate mod value,
 * in recursive method,
 * return big mod number */
unsigned int powermod(int a, int n, int d)
{
    unsigned int x;

    if (n == 0)
        return 1;
    if (n == 1)
        return a % d;
    
    x = powermod(a, n / 2, d);
    x = x * x % d;
    if (n % 2 == 0)
        return x;
    else
        return x * a % d;
}

/* prime: return TRUE if n is prime,
 * else return FALSE */
int prime(int n)
{
    int i;

    for (i = 3; i * i <= n; i++)
        if (n % i == 0)
            return FALSE;

    return TRUE;
}

