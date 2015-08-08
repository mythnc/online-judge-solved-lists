/* ACM 10327 Flip Sort
 * mythnc
 * 2011/10/17 08:52:53   
 * run time: 0.016
 * merge sort
 */
#include <stdio.h>

#define MAXARY 1000

int divide(int *, int *, int, int);

int main(void)
{
    int n, i;
    int ary[MAXARY], tmp[MAXARY];

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++)
            scanf("%d", ary + i);
        printf("Minimum exchange operations : %d\n",
               divide(ary, tmp, 0, n));
    }
    return 0;
}

/* divide: merge sort ary */
int divide(int *ary, int *tmp, int head, int tail)
{
    int half, i, j, k, c;

    /* already sorted */
    if (tail - head == 1)
        return 0;
    /* unsorted list -> divide into 2 sub lists */
    c = 0;
    half = (head + tail - 1) >> 1;
    c += divide(ary, tmp, head, half + 1);
    c += divide(ary, tmp, half + 1, tail);
    /* sort 2 sublists and merge */
    k = i = head;
    j = half+1;
    while (i < half + 1 && j < tail)
        if (ary[j] < ary[i]) {
            tmp[k++] = ary[j++];
            c += half + 1 - i;
        }
        else
            tmp[k++] = ary[i++];
    while (i < half + 1)
        tmp[k++] = ary[i++];
    while (j < tail)
        tmp[k++] = ary[j++];
    for (i = head; i < tail; i++)  /* copy the sorted list to ary*/
        ary[i] = tmp[i];
    return c;
}

