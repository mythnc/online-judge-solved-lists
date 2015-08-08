/* ACM 10696 f91
 * mythnc
 * 2011/10/28 10:17:55   
 * run time: 0.108
 */
#include <stdio.h>

int f91(int);

int main(void)
{
    int n;

    while (scanf("%d", &n)) {
        if (n == 0)
            return 0;
        printf("f91(%d) = %d\n", n, f91(n));
    }
}

/* f91: f91 function */
int f91(int n)
{
    if (n > 100)
        return n - 10;
    else
        return 91;
}

