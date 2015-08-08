/* ACM 10137 The Trip
 * mythnc
 * 2011/11/27 20:38:34   
 * run time: 0.012
 */
#include <stdio.h>

#define MAXS 1000

double input(double *, int);
double roundoff(double);
double exchange(double *, double, int);

int main(void)
{
    double student[MAXS];
    double average;
    int n;

    while (scanf("%d", &n) && n != 0) {
        average = roundoff(input(student, n));
        printf("$%.2f\n", exchange(student, average, n));
    }

    return 0;
}

/* input: receive input data, return average cost */
double input(double *s, int n)
{
    int i;
    double sum;

    for (i = sum = 0; i < n; i++) {
        scanf("%lf", s + i);
        sum += s[i];
    }

    return sum / n;
}

/* roundoff: roundoff average to cent */
double roundoff(double money)
{
    return (int)(money * 100 + 0.5) / 100.0;
}

/* exchange: return total amount of exchange money */
double exchange(double *s, double average, int n)
{
    int i;
    double sum1, sum2;

    for (i = sum1 = sum2 = 0; i < n; i++) {
        if (s[i] > average)
            sum1 += s[i] - average;
        if (s[i] < average)
            sum2 += average - s[i];
    }

    return (sum1 < sum2) ? sum1 : sum2;
}

