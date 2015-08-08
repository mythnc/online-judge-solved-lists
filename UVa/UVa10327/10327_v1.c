/* ACM 10327 Flip Sort
 * mythnc
 * 2011/10/16 20:44:23   
 * run time: 0.068
 * use bubble sort
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
int bubble(int *, int);

int main(void)
{
    int n, i, c;
    int *ary;

    while (scanf("%d", &n) != EOF) {
        ary = (int *)malloc(sizeof(int) * n);
        for (i = 0; i < n; i++)
            scanf("%d", ary + i);
        for (c = 0, i = n - 1; i > 0; i--)
            c += bubble(ary, i);
        printf("Minimum exchange operations : %d\n", c);
        free(ary);
    }
    return 0;
}

/* swap: exchange *p and *q */
void swap(int *p, int *q)
{
    int tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

/* bubble: sort ary from 0 to n */
int bubble(int *ary, int n)
{
    int c, i;

    for (c = i = 0; i < n; i++)
        if (ary[i] > ary[i + 1]) {
            swap(ary + i, ary + i + 1);
            c++;
        }
    return c;
}

