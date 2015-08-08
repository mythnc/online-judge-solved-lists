#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void divide(int *, int *, int, int);

int main(void)
{
    int n, i;
    int *ary, *tmp;

    scanf("%d", &n);
    ary = (int *)malloc(sizeof(int) * n);
    tmp = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", ary + i);
    divide(ary, tmp, 0, n);
    for (i = 0; i < n; i++)
        printf("%d ", ary[i]);
    printf("\n");
    free(tmp);
    free(ary);
    return 0;
}

void divide(int *ary, int *tmp, int head, int tail)
{
    int half, i, j, k;

    /* already sorted */
    if (tail - head == 1)
        return;
    /* unsorted list -> divide into 2 sub lists */
    half = (head + tail - 1) / 2;  /* (x / 2) == (x >> 1) */
    divide(ary, tmp, head, half + 1);
    divide(ary, tmp, half + 1, tail);
    /* sort 2 sublists and merge */
    k = i = head;
    j = half+1;
    while (i < half + 1 && j < tail)
        if (ary[j] < ary[i])
            tmp[k++] = ary[j++];
        else
            tmp[k++] = ary[i++];
    while (i < half + 1)
        tmp[k++] = ary[i++];
    while (j < tail)
        tmp[k++] = ary[j++];
    for (i = head; i < tail; i++)  /* copy the sorted list to ary*/
        ary[i] = tmp[i];
}

