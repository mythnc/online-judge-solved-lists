/* ACM 10066 The Twin Towers
 * mythnc
 * 2012/01/09 17:14:48   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXN 101
#define MAX(X, Y) (X >= Y ? X : Y)

void input(int *, int);
void lcs(int *, int *, int, int);
void print(int, int);

int list[MAXN][MAXN];

int main(void)
{
    int set, n1, n2;
    int s1[MAXN], s2[MAXN];

    set = 0;
    while (scanf("%d %d", &n1, &n2) == 2 && n1 != 0) {
        input(s1, n1);
        input(s2, n2);
        lcs(s1, s2, n1, n2);
        print(++set, list[n1][n2]);
    }

    return 0;
}

/* input: receive input data */
void input(int *s, int n)
{
    int i;

    /* start from [1] to save data */
    for (i = 1;i <= n; i++)
        scanf("%d", &s[i]);
}

/* lcs: use dp to find longest length */
void lcs(int *s1, int *s2, int n1, int n2)
{
    int i, j;

    /* set list[x][0] and list[0][x] to zero */
    for (i = 0; i <= n1; i++)
        list[i][0] = 0;
    for (i = 1; i <= n2; i++)
        list[0][i] = 0;

    /* i, j is equal to e1, e2 */
    for (i = 1; i <= n1; i++)
        for (j = 1; j <= n2; j++)
            if (s1[i] == s2[j]) /* e1 = e2: do LCS(sub1, sub2) + e1 */
                list[i][j] = list[i - 1][j - 1] + 1; /* + 1 mean e1 */
            else /* e1 != e2: do max(LCS(sub1, s2), sub2(s1, sub2)) */
                list[i][j] = MAX(list[i - 1][j], list[i][j - 1]);
}

/* print: print out result */
void print(int set, int value)
{
    printf("Twin Towers #%d\n", set);
    printf("Number of Tiles : %d\n\n", value);
}

