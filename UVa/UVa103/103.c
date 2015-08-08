/* ACM 103 Stacking Boxes
 * mythnc
 * 2012/01/15 14:42:45   
 * run time: 0.008
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXBOX 30
#define MAXD   10

typedef struct box {
    int num;
    int dimen[MAXD];
} Box;

void init(int, int);
int cmpd(const void *, const void *);
int cmpb(const void *, const void *);
int lis(int, int);
void output(int);

Box b[MAXBOX];
int len[MAXBOX], pre[MAXBOX];

int main(void)
{
    int n, d;

    while (scanf("%d %d", &n, &d) == 2) {
        init(n, d);
        output(lis(n, d));
    }

    return 0;
}

/* init: receive input data, initialize b content,
 * and sort data */
void init(int n, int d)
{
    int i, j;

    for (i = 0; i < n; i++) {
        b[i].num = i + 1;
        len[i] = 1;
        pre[i] = -1;
        for (j = 0; j < d; j++)
            scanf("%d", &b[i].dimen[j]);
        qsort(b[i].dimen, d, sizeof(int), cmpd);
    }
    qsort(b, n, sizeof(Box), cmpb);
}

/* cmpd: sort dimension for qsort() */
int cmpd(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/* cmpb: sort dimen[0] for qsort() */
int cmpb(const void *a, const void *b)
{
    return ((Box *)a)->dimen[0] - ((Box *)b)->dimen[0];
}

/* lis: find longest increasing subsequence.
 * the unit is "box"
 * return its pos */
int lis(int n, int d)
{
    int i, j, k, maxi;

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++) {
            for (k = 0; k < d && b[j].dimen[k] > b[i].dimen[k]; k++)
                ;
            if (k == d && len[i] + 1 > len[j]) {
                len[j] = len[i] + 1;
                pre[j] = i;
            }
        }

    for (i = 1, maxi = 0; i < n; i++)
        if (len[i] > len[maxi])
            maxi = i;

    return maxi;
}

/* output: output lis len and seq */
void output(int i)
{
    int num;
    int inc[MAXBOX];
    /* output max lis len */
    printf("%d\n", len[i]);

    num = 0;
    while (1) {
        inc[num++] = b[i].num;
        if (pre[i] == -1)
            break;
        i = pre[i];
    }
    /* out lis seq */
    printf("%d", inc[--num]);
    for (i = num - 1; i > -1; i--)
        printf(" %d", inc[i]);
    putchar('\n');
}

