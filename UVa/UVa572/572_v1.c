/* ACM 572 Oil Deposits
 * mythnc
 * 2011/11/15 15:02:43   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXROW 100
#define MAXCOL 101
#define TRUE   1
#define FALSE  0

int row, col;

int sweep(char (*g)[MAXCOL]);
void clear(char (*g)[MAXCOL], int i, int j);

int main(void)
{
    char grid[MAXROW][MAXCOL];
    int i;

    while (scanf("%d %d", &row, &col) && row != 0) {
        for (i = 0; i < row; i++)
            scanf("%s", grid[i]);

        printf("%d\n", sweep(grid));
    }
    return 0;
}

/* sweep: sweep and return distinct oil number */
int sweep(char (*g)[MAXCOL])
{
    int count, i, j;

    for (count = i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (g[i][j] == '@') {
                count++;
                clear(g, i, j);
            }

    return count;
}

/* clear: clear '@' to '*' */
void clear(char (*g)[MAXCOL], int i, int j)
{
    struct direction {
        int n, e, w, s;
    } rec;
    
    g[i][j] = '*';
    rec.n = rec.e = rec.w = rec.s = FALSE;
    /* n, w, e, s directions */
    if (i > 0) {
        rec.n = TRUE;
        if (g[i - 1][j] == '@')
            clear(g, i - 1, j);
    }
    if (j > 0) {
        rec.w = TRUE;
        if (g[i][j - 1] == '@') 
            clear(g, i, j - 1);
    }
    if (j < col - 1) {
        rec.e = TRUE;
        if (g[i][j + 1] == '@')
            clear(g, i, j + 1);
    }
    if (i < row - 1) {
        rec.s = TRUE;
        if (g[i + 1][j] == '@')
            clear(g, i + 1, j);
    }
    /* nw, ne, sw, se directions */
    if (rec.n) {
        if (rec.w && g[i - 1][j - 1] == '@')
            clear(g, i - 1, j - 1);
        if (rec.e && g[i - 1][j + 1] == '@')
            clear(g, i - 1, j + 1);
    }
    if (rec.s) {
        if (rec.w && g[i + 1][j - 1] == '@')
            clear(g, i + 1, j - 1);
        if (rec.e && g[i + 1][j + 1] == '@')
            clear(g, i + 1, j + 1);
    }
}

