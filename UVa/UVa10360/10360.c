/* ACM 10360 Rat Attack 
 * mythnc
 * 2012/01/03 21:38:34   
 * run time:
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1025
#define MAX2(X, Y) ((X >= Y) ? X : Y)

typedef struct animal {
    int x, y, n;
} Coordinates;

Coordinates maxkill(Coordinates *, int, int);

int main(void)
{
    int n, d, nrat, i;
    Coordinates *rat;
    Coordinates max;

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &d);
        scanf("%d", &nrat);
        rat = (Coordinates *)malloc(sizeof(Coordinates) * nrat);
        for (i = 0; i < nrat; i++)
            scanf("%d %d %d", &rat[i].x, &rat[i].y, &rat[i].n);
        max = maxkill(rat, nrat, d);
        printf("%d %d %d\n", max.x, max.y, max.n);
        free(rat);
    }

    return 0;
}

/* maxkill: return the max kill coordinates(x, y) and number */
Coordinates maxkill(Coordinates *rat, int n, int d)
{
    Coordinates max;
    int x, y, i, tmp;

    max.n = 0;
    for (x = 0; x < MAXSIZE; x++)
        for (y = 0; y < MAXSIZE; y++) {
            for (i = tmp = 0; i < n; i++)
                if (MAX2(abs(rat[i].x - x), abs(rat[i].y - y)) <= d)
                    tmp += rat[i].n;
            if (tmp > max.n) {
                max.x = x;
                max.y = y;
                max.n = tmp;
            }
        }

    return max;
}

