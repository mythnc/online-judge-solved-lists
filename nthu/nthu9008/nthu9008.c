#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXN 33
#define MAXS 1110

void encrypt(char *s, char *t);
void init(char (*sq)[MAXN], int n);
void fill(char (*table)[MAXN], int n, char *s, int len);
void copy(char *t, char (*table)[MAXN], int n);

int main(void)
{
    char s[MAXS], t[MAXS];

    while (fgets(s, MAXS, stdin) != NULL) {
        encrypt(s, t);
        printf("%s\n", t);
    }
    return 0;
}

void encrypt(char *s, char *t)
{
    int len, n, row, col, i;
    char table[MAXN][MAXN];

    len = strlen(s) - 1;
    n = (int)ceil(sqrt((double)len));
    init(table, n);
    fill(table, n, s, len);
    copy(t, table, n);
}

void fill(char (*table)[MAXN], int n, char *s, int len)
{
    int row, col, i;
    int filled[MAXN][MAXN] = {0};
    /* DOWN, RIGHT, UP, LEFT */
    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};
    enum direction {DOWN, RIGHT, UP, LEFT} go;

    go = DOWN;
    for (i = row = col = 0; i < len; ) {
        table[row][col] = s[i];
        filled[row][col] = 1;
        i++;
        /* next direction */
        switch (go) {
            case DOWN:
                if (filled[row + 1][col] || row + 1 == n)
                    go = RIGHT;
                break;
            case RIGHT:
                if (filled[row][col + 1] || col + 1 == n)
                    go = UP;
                break;
            case UP:
                if (filled[row - 1][col] || row - 1 == -1)
                    go = LEFT;
                break;
            case LEFT:
                if (filled[row][col - 1] || col - 1 == -1)
                    go = DOWN;
        }
        row += x[go];
        col += y[go];
    }
}

void init(char (*sq)[MAXN], int n)
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sq[i][j] = ' ';
        }
    }
}

void copy(char *t, char (*table)[MAXN], int n)
{
    int i, j, k;

    for (i = k = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            t[k++] = table[i][j];
        }
    }
    t[k] = '\0';
    /* remove trailing spaces */
    i = strlen(t) - 1;
    while (t[i] == ' ')
        i--;
    t[i + 1] = '\0';
}

