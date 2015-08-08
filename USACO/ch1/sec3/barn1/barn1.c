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

int cmp(const void *, const void *);

int main (void)
{
    FILE *fin, *fout;
    int n, nc, i, sum;
    int ary[MAXARY], diff[MAXARY];

    fin = fopen("barn1.in", "r");
    fout = fopen("barn1.out", "w");

    fscanf(fin, "%d %*d %d", &n, &nc);
    for (i = 0; i < nc; i++)
        fscanf(fin, "%d", ary + i);

    if (n < nc) {
        qsort(ary, nc, sizeof(int), cmp);
        for (i = 0; i < nc - 1; i++)
            diff[i] = ary[i + 1] - ary[i] - 1;
        qsort(diff, nc - 1, sizeof(int), cmp);
        sum = ary[nc - 1] - ary[0] + 1;
        for (i = nc - 2; n > 1 ; i--, n--)
            sum -= diff[i];
        fprintf(fout, "%d\n", sum);
    }
    else
        fprintf(fout, "%d\n", nc);

    fclose(fin);
    fclose(fout);
    return 0;
}

/* cmp: function of qsort argument */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

