/* ACM 439 Knight Moves
 * mythnc
 * 2011/11/29 16:49:26   
 * run time:
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR 3  /* 2 + '\0' */
#define MAXS    8
#define RANGE(X) X >= 0 && X < MAXS

typedef struct point {
    int x; /* row */
    int y; /* col */
} Point;

Point stoi(char *);
void draw(int (*)[], Point);
int move(int (*)[], Point, Point);


int main(void)
{
    char start[MAXCHAR], end[MAXCHAR];
    int square[MAXS][MAXS];
    Point from, to;

    while (scanf("%s %s", start, end) == 2) {
        /* init */
        memset(square, 0, MAXS * MAXS * sizeof(int));
        from = stoi(start);
        to = stoi(end);
        draw(square, from);
        printf("To get from %s to %s takes %d knight moves.\n",
                start, end, move(square, from, to));
    }

    return 0;
}

/* atoi: ascii code to int */
Point stoi(char *s)
{
    Point pt;
    pt.x = s[1] - '1';
    pt.y = s[0] - 'a';

    return pt;
}

/* draw: fill square with numbers, recursively */
void draw(int (*s)[MAXS], Point pt)
{
    int i, j, x, y, count, ox, oy, number;
    int movex[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int movey[] = {1, 2, 2, 1, -1, -2, -2, -1};
    Point stack[MAXS * MAXS];

    ox = pt.x;
    oy = pt.y;
    for (count = i = 0; i < 8; i++) {
        x = pt.x + movex[i];
        y = pt.y + movey[i];
        if (RANGE(x) && RANGE(y) && s[x][y] == 0) {
            s[x][y] = 1;
            stack[count].x = x;
            stack[count].y = y;
            count++;
        }
    }
    /* test
    for (i = 0; i < MAXS; i++) {
        printf("%2d", s[i][0]);
        for (j = 1; j < MAXS; j++)
            printf(" %2d", s[i][j]);
        putchar('\n');
    }
    putchar('\n');
    putchar('\n');
    */

    for (i = 0; i < count; i++) {
        pt.x = stack[i].x;
        pt.y = stack[i].y;
        number = s[pt.x][pt.y] + 1;
        for (j = 0; j < 8; j++) {
            x = pt.x + movex[j];
            y = pt.y + movey[j];
            if (RANGE(x) && RANGE(y) && s[x][y] == 0
                && (x != ox || y != oy)) {
                s[x][y] = number;
                stack[count].x = x;
                stack[count].y = y;
                count++;
            }
        }
    }

    /* test
    for (i = 0; i < MAXS; i++) {
        printf("%2d", s[i][0]);
        for (j = 1; j < MAXS; j++)
            printf(" %2d", s[i][j]);
        putchar('\n');
    }
    */
}

/* move: return moves which from f to t */
int move(int (*s)[MAXS], Point f, Point t)
{
    return s[t.x][t.y] - s[f.x][f.y];
}

