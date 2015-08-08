/* ACM 11727 Cost Cutting
 * mythnc
 * 2012/01/09 10:24:42   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXP 3

int cmp(const void *, const void *);

int main(void)
{
    int i, n;
    int list[MAXP];

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", list, list + 1, list + 2);
        qsort(list, MAXP, sizeof(int), cmp);
        printf("Case %d: %d\n", i, list[1]);
    }

    return 0;
}

/* cmp: for qsort() */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

