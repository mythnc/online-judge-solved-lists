/* ACM 392 Polynomial Showdown
 * mythnc
 * 2011/12/21 09:15:20   
 * run time: 0.108
 */
#include <stdio.h>
#include <string.h>

#define MAXD  9
#define TRUE  1
#define FALSE 0

void output(int *);

int main(void)
{
    int i;
    int poly[MAXD] = { 0 };

    while (scanf("%d", &poly[8]) == 1) {
        for (i = 7; i > -1; i--)
            scanf("%d", &poly[i]);
        output(poly);
        /* init */
        memset(poly, 0, sizeof(int) * MAXD);
    }

    return 0;
}

void output(int *p)
{
    int i, first;

    for (i = 8, first = TRUE; i > -1; i--) {
        if (p[i] == 0)
            continue;
        /* first element */
        if (first) {
            first = FALSE;
            if (p[i] < 0)
                putchar('-');
        }
        else if (p[i] > 0)
            printf(" + ");
        else
            printf(" - ");
        /* coefficient */
        if (p[i] > 1 && i != 0)
            printf("%d", p[i]);
        else if (p[i] < -1 && i != 0)
            printf("%d", -p[i]);
        /* degree */
        if (i > 1)
            printf("x^%d", i);
        else if (i == 1)
            putchar('x');
        else
            printf("%d", p[i] >= 0 ? p[i] : -p[i]);
    }
    if (first)
        putchar('0');
    putchar('\n');
}

