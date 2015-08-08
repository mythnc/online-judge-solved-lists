/* ACM 10161 Ant on a Chessboard
 * mythnc
 * 2011/11/26 16:49:42   
 * run time: 0.004
 */
#include <stdio.h>
#include <math.h>

void output(int);

int main(void)
{
    int x;

    while (scanf("%d", &x) && x != 0)
        output(x);

    return 0;
}

/* output: output answer */
void output(int x)
{
    int n, value;

    if (x == 1) {
        printf("1 1\n");
        return;
    }

    n = sqrt(x);
    /* if x is a square number */
    if (n * n == x) {
        if (n % 2 == 1)
            printf("%d %d\n", 1, n);
        else
            printf("%d %d\n", n, 1);
        return;
    }
    /* if x bigger than a square number n */
    value = x - n * n;
    if (value == n + 1)
        printf("%d %d\n", n + 1, n + 1);
    else if (value < n + 1)
        if (n % 2 == 1)
            printf("%d %d\n", value, n + 1);
        else
            printf("%d %d\n", n + 1, value);
    else
        if (n % 2 == 1)
            printf("%d %d\n", n + 1, 2 * n - value + 2);
        else
            printf("%d %d\n", 2 * n - value + 2, n + 1);
}

