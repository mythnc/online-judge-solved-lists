/* ACM 10810 Ultra-QuickSort
 * mythnc
 * 2012/01/12 10:43:46   
 * run time: 0.196
 */
#include <stdio.h>
#include <stdlib.h>

void input(int *, int);
long long merge(int *, int *, int, int);

int main(void)
{
    int n;
    int *ary, *tmp;

    while (scanf("%d", &n) && n != 0) {
        ary = (int *)malloc(sizeof(int) * n);
        tmp = (int *)malloc(sizeof(int) * n);
        input(ary, n);
        printf("%lld\n", merge(ary, tmp, 0, n));
        free(ary);
        free(tmp);
    }

    return 0;
}

/* input: receive input data */
void input(int *ary, int n)
{
    int i;

    for (i = 0; i < n; i++)
        scanf("%d", &ary[i]);
}

/* merge: merge sort */
long long merge(int *ary, int *tmp, int head, int tail)
{
    int half, i, j, k;
    long long c;

    /* already sorted */
    if (tail - head == 1)
        return 0;
    /* unsorted list -> merge into 2 sub lists */
    half = (head + tail) / 2;  /* (x / 2) == (x >> 1) */
    c = merge(ary, tmp, head, half);
    c += merge(ary, tmp, half, tail);
    /* sort 2 sublists and merge */
    k = i = head;
    j = half;
    while (i < half && j < tail)
        if (ary[j] < ary[i]) {
            tmp[k++] = ary[j++];
            c += half - i;
        }
        else
            tmp[k++] = ary[i++];
    while (i < half)
        tmp[k++] = ary[i++];
    while (j < tail)
        tmp[k++] = ary[j++];
    for (i = head; i < tail; i++)  /* copy the sorted list to ary */
        ary[i] = tmp[i];

    return c;
}

