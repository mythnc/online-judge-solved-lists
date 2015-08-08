/* ACM 10195 The Knights Of The Round Table
 * mythnc
 * 2012/01/02 09:56:51   
 * run time: 0.008
 */
#include <stdio.h>
#include <math.h>

double radius(double, double, double);

int main(void)
{
    double a, b, c;

    while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
        printf("The radius of the round table is: %.3f\n", radius(a, b, c));

    return 0;
}

double radius(double a, double b, double c)
{
    double p;
    
    if (a == 0.0 || b == 0.0 || c == 0.0)
        return 0.0;

    p = (a + b + c) / 2.0;

    return sqrt((p - a) * (p - b) * (p - c) / p);
}

