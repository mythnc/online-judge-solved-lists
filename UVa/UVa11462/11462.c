/* ACM 11462 Age Sort
 * mythnc
 * 2012/01/12 11:17:32   
 * run time: 0.856
 */
#include <stdio.h>
#include <stdlib.h>

void input(int *, int);
int cmp(const void *, const void *);
void output(int *, int);

int main(void)
{
    int n;
    int *list;

    while (scanf("%d", &n) && n != 0) {
        list = (int *)malloc(sizeof(int) * n);
        input(list, n);
        qsort(list, n, sizeof(int), cmp);
        output(list, n);
        free(list);
    }
    return 0;
}

/* input: receive input data */
void input(int *list, int n)
{
    int i;

    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);
}

/* cmp: for qsort() */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/* output: output result */
void output(int *list, int n)
{
    int i;

    printf("%d", list[0]);
    for (i = 1; i < n; i++)
        printf(" %d", list[i]);
    putchar('\n');
}

