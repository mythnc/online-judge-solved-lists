/* ACM 10209 Is This Integration ?
 * mythnc
 * 2011/10/15 00:01:27   
 * run time: 0.040
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    /* x: striped region, y: dotted region, z: the rest */
    /* y and z have 4 pieces */
    /* output x directly: a^2 - 4y - 4z */
    double a, y, z;
    double const pi = 3.1415926535897931159980;

    while (scanf("%lf", &a) != EOF) {
        a *= a; /* a mean a^2 now */
        z = 4*a - 2*pi*a / 3 - a*sqrt(3); /* z mean 4z now */
        y = 4*a - pi*a - 2*z; /* y mean 4y now */
        printf("%.3f %.3f %.3f\n", a - y - z, y, z);
    }
    return 0;
}

