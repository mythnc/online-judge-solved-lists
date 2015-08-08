/*
ID: mythnc2
LANG: C
TASK: barn1
barn repair
2011/11/16 16:21:20   
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXARY 200
#define MAXM   50

typedef struct split {
    int head, tail, i_h, i_t, len;
} Split;

int cmp(const void *, const void *);
void init(Split *, int *, int);
void minstall(Split *, int *, int);
int maxlen(Split *, int);
int minsplitsum(int *, int, int);
int sum(int *, int, int, int);
void rearrange(Split *, Split *, int *, int);
int numbers(Split *, int);

int main (void)
{
    FILE *fin, *fout;
    int n, nc, i;
    int ary[MAXARY];
    Split board[MAXM];

    fin = fopen("barn1.in", "r");
    fout = fopen("barn1.out", "w");

    fscanf(fin, "%d %*d %d", &n, &nc);
    for (i = 0; i < nc; i++)
        fscanf(fin, "%d", ary + i);
        
    if (n < nc) {
        qsort(ary, nc, sizeof(int), cmp);
        init(&board[0], ary, nc);
        minstall(board, ary, n);
        fprintf(fout, "%d\n", numbers(board, n));
    }
    else
        fprintf(fout, "%d\n", nc);


    return 0;
}

/* cmp: function of qsort argument */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/* init: initialize first element */
void init(Split *b, int *ary, int n)
{
    b->head = ary[0];
    b->i_h = 0;
    b->tail = ary[n - 1];
    b->i_t = n - 1;
    b->len = b->tail - b->head + 1;
}

/* minstall: calculate the minimum stall */
void minstall(Split *b, int *ary, int n)
{
    int i, max, min, first, last;

    for (i = 1; i < n; i++) {
        max = maxlen(b, i);
        first = b[max].i_h;
        last = b[max].i_t;
        min = minsplitsum(ary, first, last);
        rearrange(&b[max], &b[i], ary, min);
    }
}

/* maxlen: return longest len */
int maxlen(Split *b, int n)
{
    int i, max;

    for (max = 0, i = 1; i < n; i++)
        if (b[max].len < b[i].len)
            max = i;

    return max;
}

/* minsplitsum: return minimum sum of split point */
int minsplitsum(int *ary, int first, int n)
{
    int i, min;

    for (min = first, i = first + 1; i < n; i++)
        if (sum(ary, min, first, n) > sum(ary, i, first, n))
            min = i;

    return min;
}

/* sum: return sum of split point with head and tail */
int sum(int *ary, int i, int first, int last)
{
    return ary[last] - ary[i + 1] + ary[i] - ary[first];
}

/* rearrange: rearrange board */
void rearrange(Split *maxb, Split *b, int *ary, int min)
{
    b->head = ary[min + 1];
    b->i_h = min + 1;
    b->tail = maxb->tail;
    b->i_t = maxb->i_t;
    b->len = b->tail - b->head + 1;
    maxb->tail = ary[min];
    maxb->i_t = min;
    maxb->len = maxb->tail - maxb->head + 1;
}

/* numbers: return the number of stalls */
int numbers(Split *b, int n)
{
    int sum, i;

    for (sum = i = 0; i < n; i++)
        sum += b[i].len;

    return sum;
}

