/* ACM 439 Knight Moves
 * mythnc
 * 2011/11/29 16:49:26   
 * run time: 0.024
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

Point stoc(char *);
void draw(int (*)[], Point);
void filln(int (*)[], Point, Point);

int count;
Point stack[MAXS * MAXS];

int main(void)
{
    char start[MAXCHAR], end[MAXCHAR];
    int square[MAXS][MAXS];
    Point from, to;

    while (scanf("%s %s", start, end) == 2) {
        /* init */
        memset(square, 0, sizeof(square));

        from = stoc(start);
        to = stoc(end);
        draw(square, from);

        printf("To get from %s to %s takes %d knight moves.\n",
                start, end, square[to.x][to.y]);
    }

    return 0;
}

/* stoc: string change to coordinate */
Point stoc(char *s)
{
    Point pt;
    pt.x = s[1] - '1';
    pt.y = s[0] - 'a';

    return pt;
}

/* draw: fill square with numbers */
void draw(int (*s)[MAXS], Point pt)
{
    int i, j;
    Point origin;

    origin.x = pt.x;
    origin.y = pt.y;
    count = 0;
    filln(s, pt, origin);

    for (i = 0; i < count; i++) {
        pt.x = stack[i].x;
        pt.y = stack[i].y;
        filln(s, pt, origin);
    }
}

/* filln: fill blocks to number n */
void filln(int (*s)[MAXS], Point pt, Point o)
{
    int i, x, y, n;
    int movex[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int movey[] = {1, 2, 2, 1, -1, -2, -2, -1};

    n = s[pt.x][pt.y] + 1;
    for (i = 0; i < 8; i++) {
        x = pt.x + movex[i];
        y = pt.y + movey[i];
        if (RANGE(x) && RANGE(y) && s[x][y] == 0
            && (x != o.x || y != o.y)) {
            s[x][y] = n;
            stack[count].x = x;
            stack[count].y = y;
            count++;
        }
    }
}

