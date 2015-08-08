/* ACM 111 History Grading
 * mythnc
 * 2012/01/09 16:13:15   
 * run time: 0.016
 */
#include <stdio.h>

#define MAXN  21
#define TRUE  1
#define FALSE 0
#define MAX(X, Y) (X >= Y ? X : Y)

int input(int *, int);
void lcs(int *, int *, int);

int list[MAXN][MAXN];

int main(void)
{
    int n;
    int correct[MAXN], test[MAXN];

    scanf("%d", &n);
    input(correct, n);
    while (input(test, n)) {
        lcs(correct, test, n);
        printf("%d\n", list[n][n]);
    }

    return 0;
}

/* input: receive input data */
int input(int *seq, int n)
{
    int i, pos;

    /* start from [1] to save data */
    for (i = 1; i <= n; i++) {
        if (scanf("%d", &pos) != 1)
            return FALSE;
        seq[pos] = i;
    }

    return TRUE;
}

/* lcs: use dp to find longest length */
void lcs(int *s1, int *s2, int n)
{
    int i, j;

    /* set list[x][0] and list[0][x] to zero */
    for (i = 0; i <= n; i++)
        list[i][0] = list[0][i] = 0;

    /* i, j is equal to e1, e2 */
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (s1[i] == s2[j]) /* e1 = e2: do LCS(sub1, sub2) + e1 */
                list[i][j] = list[i - 1][j - 1] + 1; /* + 1 mean e1 */
            else /* e1 != e2: do max(LCS(sub1, s2), sub2(s1, sub2)) */
                list[i][j] = MAX(list[i - 1][j], list[i][j - 1]);
}

