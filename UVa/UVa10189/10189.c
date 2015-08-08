/* ACM 10189 Minesweeper
 * mythnc
 * 2011/11/29 15:25:38   
 * version 2
 * run time: 0.016
 */
#include <stdio.h>

#define MAXLEN 100
/* if position (x, y) is not '*' */
#define NOTSTAR(f, x, y) if (f[x][y] != '*') f[x][y]++

void dtoz(char (*)[]);
void findstar(char (*)[]);
void add(char (*)[], int, int);

int row, col;

int main(void)
{
    char field[MAXLEN][MAXLEN + 1];
    int i, set;

    set = 0;
    while (scanf("%d %d", &row, &col) == 2) {
        if (row == 0 && col== 0)
            return 0;

        for (i = 0; i < row; i++)
            scanf("%s", field[i]);

        dtoz(field);
        findstar(field);
        /* output */
        if (set > 0)
            printf("\n");
        printf("Field #%d:\n", ++set);
        for (i = 0; i < row; i++)
            printf("%s\n", field[i]);
    }
}

/* dtoz: change dot to '0' */
void dtoz(char (*field)[MAXLEN + 1])
{
    int i, j;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (field[i][j] == '.')
                field[i][j] = '0';
}

/* findstar: find the position of '*' */
void findstar(char (*f)[MAXLEN + 1])
{
    int i, j;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (f[i][j] == '*')
                add(f, i, j);
}

/* position: add one to the fields surround of '*' */
void add(char (*f)[MAXLEN + 1], int i, int j)
{
    int mover[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int movec[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int k, x, y;

    for (k = 0; k < 8; k++) {
        x = i + mover[k];
        y = j + movec[k];
        if (x >= 0 && x < row && y >= 0 && y < col)
            NOTSTAR(f, x, y);
    }
}

