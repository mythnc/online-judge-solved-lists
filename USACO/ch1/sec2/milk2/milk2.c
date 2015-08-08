/*
ID: mythnc2
LANG: C
TASK: milk2
Milking Cows
2011/10/28 14:44:22   
*/
#include <stdio.h>

#define MAXN 5000
#define BEGIN   0
#define END     1
#define SWAP(x, y, t)  (t = x, x = y, y = t)

void addframer(int (*)[], int *, int *);
void maxf(int (*)[], int, int *, int *);
void sort(int (*)[], int *);

int main (void)
{
    FILE *fin, *fout;
    int farmer[MAXN][2];
    int tmp[2];
    int n, number, maxmilk, maxidle;

    fin = fopen("milk2.in", "r");
    fout = fopen("milk2.out", "w");

    fscanf(fin, "%d", &n);
    for (number = 0; n; n--) {
        fscanf(fin, "%d %d", tmp, tmp + 1);
        addframer(farmer, tmp, &number);
    }

    sort(farmer, &number);
    maxf(farmer, number, &maxmilk, &maxidle);

    fprintf(fout, "%d %d\n", maxmilk, maxidle);

    return 0;
}

/* adframer: if tmp in farmer, update it,
 * if not in farmer, add tmp */
void addframer(int (*farmer)[2], int *tmp, int *n)
{
    int i;

    for (i = 0; i < *n; i++) {
        /* 0 0 condition */
        if (farmer[i][BEGIN] == 0 && farmer[i][END] == 0)
            continue;

        /* tmp contain farmer[i] */
        if (tmp[BEGIN] < farmer[i][BEGIN]
            && tmp[END] > farmer[i][END]) {
            farmer[i][BEGIN] = farmer[i][END] = 0;
            continue;
        }
        /* farmer[i] contains tmp */
        else if (farmer[i][BEGIN] <= tmp[BEGIN]
                 && farmer[i][END] >= tmp[END])
            return;

        /* update: farmer[i] contains tmp[BEGIN] */
        if (farmer[i][BEGIN] < tmp[BEGIN]
            && tmp[BEGIN] <= farmer[i][END]) {
            tmp[BEGIN] = farmer[i][BEGIN];
            farmer[i][BEGIN] = farmer[i][END] = 0;
            /* start from head again */
            i = -1;
        }
        /* update: farmer[i] contains tmp[END] */
        else if (farmer[i][BEGIN] <= tmp[END]
            && tmp[END] < farmer[i][END]) {
            tmp[END] = farmer[i][END];
            farmer[i][BEGIN] = farmer[i][END] = 0;
            /* start from head again */
            i = -1;
        }
    }

    (*n)++;
    farmer[i][BEGIN] = tmp[BEGIN];
    farmer[i][END] = tmp[END];
}

/* maxf: find the maxmilk and maxidle times */
void maxf(int (*farmer)[2], int n, int *milk, int *idle)
{
    int i;

    if (n == 1) {
        *milk = farmer[0][END] - farmer[0][BEGIN];
        *idle = 0;
        return;
    }

    for (*idle = *milk = i = 0; i < n; i++) {
        if (*milk < farmer[i][END] - farmer[i][BEGIN])
            *milk = farmer[i][END] - farmer[i][BEGIN];
        if (i < n - 1 && *idle < farmer[i][BEGIN] - farmer[i + 1][END])
            *idle = farmer[i][BEGIN] - farmer[i + 1][END];
    }
}

/* sort: selection sort from high to low does not contain 0 */
void sort(int (*f)[2], int *n)
{
    int i, j, max, tmp;

    for (i = 0; i < *n - 1; i++) {
        for (max = j = i; j < *n; j++)
            if (f[max][BEGIN] < f[j][BEGIN])
                max = j;
        if (max != i) {
            SWAP(f[max][BEGIN], f[i][BEGIN], tmp);
            SWAP(f[max][END], f[i][END], tmp);
        }
    }

    /* delete 0 0 */
    while (f[*n - 1][BEGIN] == 0 && f[*n - 1][END] == 0)
        (*n)--;
}

