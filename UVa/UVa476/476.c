/* ACM 476 Points in Figures: Rectangles
 * mythnc
 * 2011/10/21 16:13:45   
 * run time: 0.02
 */
#include <stdio.h>

#define IN  1
#define OUT 0

int main(void)
{
    double r[10][4], x, y;
    /* kr: number of r, k: number of (x, y) */
    int kr, k;
    int n, i;
    char c;

    kr = 0;
    /* receive r */
    while ((c = getchar()) != '*')
        if (c == 'r') {
            scanf("%lf %lf %lf %lf", &r[kr][0], &r[kr][1], &r[kr][2], &r[kr][3]);
            kr++;
        }

    k = 1;
    while (scanf("%lf %lf", &x, &y) == 2) {
        if (x == 9999.9 && y == 9999.9)
            break;
        for (n = OUT, i = 0; i < kr; i++)
            if (x > r[i][0] && x < r[i][2] && y > r[i][3] && y < r[i][1]) {
                printf("Point %d is contained in figure %d\n", k, i + 1);
                n = IN;
            }
        if (n == OUT)
            printf("Point %d is not contained in any figure\n", k);
        k++;
    }
    return 0;
}

