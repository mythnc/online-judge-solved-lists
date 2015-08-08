/* ACM 10235 Simply Emirp
 * mythnc
 * 2011/10/15 13:29:01   
 * run time: 0.012
 */
#include <stdio.h>

#define PRIME 1
#define NOT_P 0

int prime(int);
int reverse(int);

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        if (prime(n))
            if (reverse(n))
                printf("%d is emirp.\n", n);
            else
                printf("%d is prime.\n", n);
        else
                printf("%d is not prime.\n", n);
    }
    return 0;
}

/* prime: judge n is prime or not */
int prime(int n)
{
    int i;

    if (n == 2)           /* 2 is prime */
        return PRIME;
    if (n % 2 == 0)       /* even is not prime */
        return NOT_P;
    for (i = 3; i * i <= n; i++)
        if (n % i == 0)
            return NOT_P;
    return PRIME;
}

/* reverse: return prime(the reverse n) */
int reverse(int n)
{
    int x, tmp;

    tmp = n;
    x = n % 10;
    while ((n /= 10) > 0) {
        x *= 10;
        x += n % 10;
    }
    if (x == tmp)    /* if reverse n is the same n */
        return NOT_P;    /* can't output emirp */
    return prime(x);
}

