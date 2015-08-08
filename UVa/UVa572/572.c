/* ACM 572 Oil Deposits
 * mythnc
 * 2011/11/29 15:17:44   
 * version 2
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
    int mover[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int movec[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int k, x, y;

    g[i][j] = '*';
    for (k = 0; k < 8; k++) {
        x = i + mover[k];
        y = j + movec[k];
        if (x >= 0 && x < row && y >= 0 && y < col
            && g[x][y] == '@')
            clear(g, x, y);
    }
}

