/* ACM 299 Train Swapping
 * mythnc
 * 2011/10/26 09:20:42
 * run time: 0.008
 */
#include <stdio.h>

#define MAXARY 50

int merge(int *, int *, int, int);

int main(void)
{
    int n, i;
    int ary[MAXARY], tmp[MAXARY];

    scanf("%*d");
    while (scanf("%d", &n) == 1) {
        if (n == 0) {
            printf("Optimal train swapping takes 0 swaps.\n");
            continue;
        }
        for (i = 0; i < n; i++)
            scanf("%d", &ary[i]);
        printf("Optimal train swapping takes %d swaps.\n",
               merge(ary, tmp, 0, n));
    }
    return 0;
}

/* merge: merge sort ary, return swap times */
int merge(int *ary, int *tmp, int head, int tail)
{
    int half, i, j, k, c;

    /* already sorted */
    if (tail - head == 1)
        return 0;
    /* unsorted list -> merge into 2 sub lists */
    half = (head + tail) / 2;  /* (x / 2) == (x >> 1) */
    c = 0;
    c += merge(ary, tmp, head, half);
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
    for (i = head; i < tail; i++)  /* copy the sorted list to ary*/
        ary[i] = tmp[i];
    return c;
}

