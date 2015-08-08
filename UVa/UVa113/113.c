/* ACM 113 Power of Cryptography
 * mythnc
 * 2011/10/18 09:17:44   
 * run time: 0.008
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double p, n;

    while (scanf("%lf %lf", &n, &p) != EOF)
        printf("%.0lf\n", pow(p, 1 / n));
    return 0;
}

