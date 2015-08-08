/* ACM 11498 Division of Nlogonia
 * mythnc
 * 2012/01/04 19:37:29   
 * run time: 0.012
 */
#include <stdio.h>

typedef struct coor {
    int x, y;
} Coordinates;

void output(Coordinates, int);

int main(void)
{
    int n;

    while (scanf("%d", &n) && n != 0)
        output(d, n);

    return 0;
}

/* output: find the x in which quadrant
 * and output answer */
void output(Coordinates d, int n)
{
    Coordinates d, i, sub;

    scanf("%d %d", &d.x, &d.y);
    while (n--) {
        scanf("%d %d", &i.x, &i.y);
        sub.x = i.x - d.x;
        sub.y = i.y - d.y;
        if (sub.x == 0 || sub.y == 0)
            printf("divisa\n");
        else if (sub.x > 0 && sub.y > 0)
            printf("NE\n");
        else if (sub.x < 0 && sub.y > 0)
            printf("NO\n");
        else if (sub.x < 0 && sub.y < 0)
            printf("SO\n");
        else if (sub.x > 0 && sub.y < 0)
            printf("SE\n");
    }
}

