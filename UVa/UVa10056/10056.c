/* ACM 10056 What is the Probability ?
 * mythnc
 * 2011/10/13 11:47:52   
 * run time: 0.008
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    int set, n, k;  /* n players, the kth player */
    double p;

    scanf("%d", &set);
    while (set-- > 0) {
        scanf("%d %lf %d", &n, &p, &k);
        if (p == 0.0) {
            printf("0.0000\n");
            continue;
        }
        if (k == 1)
            printf("%.4f\n", p / (1 - pow(1-p, n)));
        else
            printf("%.4f\n", p * pow(1-p, k-1) / (1 - pow(1-p, n)));
    }
    return 0;
}

