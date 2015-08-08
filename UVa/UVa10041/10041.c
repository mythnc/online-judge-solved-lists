/* ACM 10041 Vito's family
 * mythnc
 * 2011/11/09 15:57:38
 * run time: 0.024
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXR 499

int compare(const void *, const void *);

int main(void)
{
    int r[MAXR];
    int n, sum, i, median, mid;
    
    scanf("%*d");
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++)
            scanf("%d", r + i);

        qsort(r, n, sizeof(int), compare);
        mid = n / 2;
        if (n % 2 == 1)
            median = r[mid];
        else
            median = (r[mid] + r[mid - 1]) / 2;
        for (sum = i = 0; i < n; i++)
            if (median < r[i])
                sum += r[i] - median;
            else
                sum += median - r[i];

        printf("%d\n", sum);
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

