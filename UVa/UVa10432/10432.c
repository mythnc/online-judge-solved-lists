/* ACM 10432 Polygon Inside A Circle
 * mythnc
 * 2011/12/23 14:04:53   
 * run time: 0.008
 */
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main(void)
{
    int n;
    double r;

    while (scanf("%lf %d", &r, &n) == 2)
        printf("%.3f\n", n * r * sin(PI / n) * r * cos(PI / n));

    return 0;
}

