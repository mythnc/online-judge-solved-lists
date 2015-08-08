/*
ID: mythnc2
LANG: C
TASK: transform
2011/11/04 22:41:28   
Transformations
*/
#include <stdio.h>

#define MAXN 10
#define TRUE  1
#define FALSE 0

int menu(char (*)[], char (*)[], int);
int de90(char (*)[], char (*)[], int);
int de180(char (*)[], char (*)[], int);
int de270(char (*)[], char (*)[], int);
void reflect(char (*)[], char (*)[], int);
int equal(char (*)[], char (*)[], int);

int main (void)
{
    FILE *fin, *fout;
    int n, i;
    char sq[MAXN][MAXN + 1], trans[MAXN][MAXN + 1];

    fin = fopen("transform.in", "r");
    fout = fopen("transform.out", "w");

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fin, "%s", sq[i]);
    for (i = 0; i < n; i++)
        fscanf(fin, "%s", trans[i]);
    fprintf(fout, "%d\n", menu(sq, trans, n));
    return 0;
}

/* menu: return one of the possible transformation */
int menu(char (*sq)[MAXN + 1], char (*trans)[MAXN + 1], int n)
{
    char mirror[MAXN][MAXN + 1];

    if (de90(sq, trans, n))
        return 1;

    if (de180(sq, trans, n))
        return 2;

    if (de270(sq, trans, n))
        return 3;

    reflect(sq, mirror, n);
    if (equal(mirror, trans, n))
        return 4;

    if (de90(mirror, trans, n) || de180(mirror, trans, n)
        || de270(mirror, trans, n))
        return 5;

    if (equal(sq, trans, n))
        return 6;

    return 7;
}

/* de90: if sq rotate 90 degree is trans return True */
int de90(char (*sq)[MAXN + 1], char (*trans)[MAXN + 1], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (sq[i][j] != trans[j][n - 1 - i])
                return FALSE;

    return TRUE;
}

/* de180: if sq rotate 180 degree is trans return True */
int de180(char (*sq)[MAXN + 1], char (*trans)[MAXN + 1], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (sq[i][j] != trans[n - 1 - i][n - 1 - j])
                return FALSE;

    return TRUE;
}

/* de270: if sq rotate 270 degree is trans return True */
int de270(char (*sq)[MAXN + 1], char (*trans)[MAXN + 1], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (sq[i][j] != trans[n - 1 - j][i])
                return FALSE;

    return TRUE;
}

/* reflect: copy the reflection of sq to mirror */
void reflect(char (*sq)[MAXN + 1], char (*mirror)[MAXN + 1], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mirror[i][n - 1 - j] = sq[i][j];
}

/* equal: if sq is same as trans return True */
int equal(char (*sq)[MAXN + 1], char (*trans)[MAXN + 1], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (sq[i][j] != trans[i][j])
                return FALSE;

    return TRUE;
}

