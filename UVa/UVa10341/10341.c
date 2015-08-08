/* ACM 10341 Solve It
 * mythnc
 * 2012/01/10 20:27:26   
 * run time: 0.064
 */
#include <stdio.h>
#include <math.h>

#define EPS 1e-7

double f(double);
double bisection(void);

int p, q, r, s, t, u;

int main(void)
{
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6)
        if (f(0) * f(1) > 0)
            printf("No solution\n");
        else
            printf("%.4f\n", bisection());

    return 0;
}

double f(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisection(void)
{
    double low, high, x;

    low = 0.0;
    high = 1.0;
    while (high - low > EPS) {
        x = (low + high) / 2;
        if (f(low) * f(x) > 0)
            low = x;
        else
            high = x;
    }

    return (low + high) / 2;
}

