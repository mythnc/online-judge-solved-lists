/* ACM 10189 Minesweeper
 * mythnc
 * 2011/10/26 14:49:30   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXLEN 100
/* if position (x, y) is not '*' */
#define NOTSTAR(f, x, y) if (f[x][y] != '*') f[x][y]++

void dtoz(char (*)[], int, int);
void findstar(char (*)[], int, int);
void add(char (*)[], int *);

int main(void)
{
    char field[MAXLEN][MAXLEN + 1];
    int i, row, column, set;

    set = 0;
    while (scanf("%d %d", &row, &column) == 2) {
        if (row == 0 && column == 0)
            return 0;

        for (i = 0; i < row; i++)
            scanf("%s", field[i]);

        dtoz(field, row, column);
        findstar(field, row, column);
        /* output */
        if (set > 0)
            printf("\n");
        printf("Field #%d:\n", ++set);
        for (i = 0; i < row; i++)
            printf("%s\n", field[i]);
    }
}

/* dtoz: change dot to '0' */
void dtoz(char (*field)[MAXLEN + 1], int row, int column)
{
    int i, j;

    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            if (field[i][j] == '.')
                field[i][j] = '0';
}

/* findstar: find the position of '*' */
void findstar(char (*f)[MAXLEN + 1], int row, int column)
{
    /* [0] is row, [1] is column */
    /* [2] is maxrow, [3] is maxcolumn */
    int rc[4];

    rc[2] = row;
    rc[3] = column;
    for (rc[0] = 0; rc[0] < row; rc[0]++)
        for (rc[1] = 0; rc[1] < column; rc[1]++)
            if (f[ rc[0] ][ rc[1] ] == '*')
                add(f, rc);
}

/* position: add one to the fields surround of '*' */
void add(char (*f)[MAXLEN + 1], int *rc)
{
    enum direction { NORTH, WEST, EAST, SOUTH };
    enum boolean { NO, YES };
    int record[4] = { NO };
    int row = rc[0];
    int column = rc[1];
    int maxrow = rc[2];
    int maxcolumn = rc[3];
    int w, e, s, n;

    w = column - 1, e = column + 1;
    n = row - 1, s = row + 1;
    /* judge NEWS directions */
    if (column > 0) {
        record[WEST] = YES;
        NOTSTAR(f, row, w);
    }
    if (row > 0) {
        record[NORTH] = YES;
        NOTSTAR(f, n, column);
    }
    if (column < maxcolumn - 1) {
        record[EAST] = YES;
        NOTSTAR(f, row, e);
    }
    if (row < maxrow - 1) {
        record[SOUTH] = YES;
        NOTSTAR(f, s, column);
    }
    /* judge another 4 directions */
    if (record[WEST] == YES) {
        if (record[NORTH] == YES)
            NOTSTAR(f, n, w);
        if (record[SOUTH] == YES)
            NOTSTAR(f, s, w);
    }
    if (record[EAST] == YES) {
        if (record[NORTH] == YES)
            NOTSTAR(f, n, e);
        if (record[SOUTH] == YES)
            NOTSTAR(f, s, e);
    }
}

