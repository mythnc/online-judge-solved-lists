/* ACM 10110 Light, more light
 * mythnc
 * 2012/03/31 22:12:48
 * run time: 0.028
 */
#include <stdio.h>
#include <math.h>

typedef enum {NO = 0, YES} light;

light factor(double n);

int main(void)
{
    double n;

    while (scanf("%lf", &n) && n != 0.0)
        if (n == 1 || factor(n))
            printf("yes\n");
        else
            printf("no\n");

    return 0;
}

/* factor: calculate the square root of n is integer or not
 * if is return 1 else return 0 */
light factor(double n)
{
    long long i;

    i = sqrt(n);
    if (i * i == n)
        return YES;
    else
        return NO;
}

