/* ACM 477 Points in Figures: Rectangles and Circles
 * mythnc
 * 2011/10/22 12:19:02   
 * run time: 0.012
 */
#include <stdio.h>

#define IN  1
#define OUT 0
#define CIR 1
#define REC 0
#define MAX 10
/* DISTANCE: calculate the range of (x, y) and center of cir */
#define DISTANCE(x, y, x1, y1) (x - x1) * (x - x1) + (y - y1) * (y - y1)
/* SQUARE: calculate x^2 */
#define SQUARE(x) x * x

int main(void)
{
    double pic[MAX][4], x, y;
    /* f: number of pic, k: number of (x, y) */
    int f, k, n, i, c;
    int record[MAX] = { REC };

    /* receive r */
    f = 0;
    while ((c = getchar()) != '*')
        if (c == 'r') {
            scanf("%lf %lf %lf %lf", &pic[f][0], &pic[f][1], &pic[f][2], &pic[f][3]);
            f++;
        }
        else if (c == 'c') {
            scanf("%lf %lf %lf", &pic[f][0], &pic[f][1], &pic[f][2]);
            record[f++] = CIR;
        }

    k = 1;
    while (scanf("%lf %lf", &x, &y) == 2) {
        if (x == 9999.9 && y == 9999.9)
            return 0;
        for (n = OUT, i = 0; i < f; i++)
            if (record[i] == REC) {
                if (x > pic[i][0] && x < pic[i][2] && y > pic[i][3] && y < pic[i][1]) {
                    printf("Point %d is contained in figure %d\n", k, i + 1);
                    n = IN;
                }
            }
            else if (record[i] == CIR)
                if (DISTANCE(x, y, pic[i][0], pic[i][1]) < SQUARE(pic[i][2])) {
                    printf("Point %d is contained in figure %d\n", k, i + 1);
                    n = IN;
                }
        if (n == OUT)
            printf("Point %d is not contained in any figure\n", k);
        k++;
    }
    return 0;
}

