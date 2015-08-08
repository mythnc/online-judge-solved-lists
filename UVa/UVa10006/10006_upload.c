/* ACM 10006 Carmichael Numbers
 * mythnc
 * 2011/11/14 13:05:56   
 * run time: 0.032
 */
#include <stdio.h>

#define FALSE 0
#define TRUE  1

int prime(int);

int main(void)
{
    int n;

    while (scanf("%d", &n) && n != 0)
        if (in(n))
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    return 0;
}

/* if n is in ary, return TRUE,
 * else return FALSE */
int in(int n)
{
    int ary[15] = {561, 1105, 1729, 2465, 2821,
                   6601, 8911, 10585, 15841, 29341,
                   41041, 46657, 52633, 62745, 63973};
    int i;

    for (i = 0; i < 15; i++)
        if (n == ary[i])
            return TRUE;

    return FALSE;
}

