/* ACM 10370 Above Average
 * mythnc
 * 2011/10/17 10:04:00   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXARY 1000

int main(void)
{
    int n, c, i, count;
    int ary[MAXARY];
    double avg;

    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        for (avg = i = 0; i < n; i++) {
            scanf("%d", ary + i);
            avg += ary[i];
        }
        avg /= n; 
        for (count = i = 0; i < n; i++)
            if (ary[i] > avg)
                count++;
        printf("%.3f%%\n", (double)count / n * 100);
    }
    return 0;
}

