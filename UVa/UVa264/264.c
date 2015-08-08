/* ACM 264 Count on Cantor
 * mythnc
 * 2011/10/18 14:18:56   
 * run time: 0.008
 */
#include <stdio.h>

void findterm(int);

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF)
        if (n == 1)
            printf("TERM %d IS 1/1\n", n);
        else
            findterm(n);
    return 0;
}

/* findterm: find term and print it */
void findterm(int n)
{
    int sum, i, p;

    for (i = 2, sum = 1; sum < n; i++)
        sum += i;
    p = sum - n;
    if (--i % 2 == 0)   /* judge i is even line or odd line */
        printf("TERM %d IS %d/%d\n", n, i - p, 1 + p);
    else
        printf("TERM %d IS %d/%d\n", n, p + 1, i - p);
}

