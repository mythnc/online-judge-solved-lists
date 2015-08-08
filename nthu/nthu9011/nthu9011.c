#include <stdio.h>

#define MAXN 100
#define ADJ 8

void init(int (*table)[MAXN], int n);
void fill(int (*table)[MAXN], int n);
void add_mine(int (*table)[MAXN], int row, int col, int n);
void output(int (*table)[MAXN], int n);

int main(void)
{
    int n;
    int table[MAXN][MAXN];
    
    while (scanf("%d", &n) != EOF) {
        init(table, n);
        fill(table, n);
        output(table, n);
    }
    return 0;
}

void init(int (*table)[MAXN], int n)
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            table[i][j] = 0;
        }
    }
}

void fill(int (*table)[MAXN], int n)
{
    int i, j, val;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &val);
            if (val == 1) {
                add_mine(table, i, j, n);
            }
        }
    }
}

void add_mine(int (*table)[MAXN], int row, int col, int n)
{
    int i, r, c;
    enum {UP_LEFT, UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT} adj;
    const int x[ADJ] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int y[ADJ] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (i = 0; i < ADJ; i++) {
        r = row + x[i];
        c = col + y[i];
        if (r >= 0 && r < n && c >= 0 && c < n)
            table[r][c]++;
    }
}

void output(int (*table)[MAXN], int n)
{
    int i, j;

    for (i = 0; i < n; i++) {
        printf("%d", table[i][0]);
        for (j = 1; j < n; j++) {
            printf(" %d", table[i][j]);
        }
        putchar('\n');
    }
}

