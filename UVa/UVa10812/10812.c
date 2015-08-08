/* ACM 10812 Beat the Spread!
 * mythnc
 * 2011/11/08 09:29:40   
 * run time: 0.004
 */
#include <stdio.h>

void output(int, int);

int main(void)
{
    int f1, f2;

    scanf("%*d");
    while (scanf("%d %d", &f1, &f2) == 2)
        output(f1, f2);
    return 0;
}

/* output: output result */
void output(int f1, int f2)
{
    int x, y;

    if ((f1 + f2) % 2 != 0) {
        printf("impossible\n");
        return;
    }

    x = (f1 + f2) / 2;
    if (x < 0) {
        printf("impossible\n");
        return;
    }
    y = f1 - x;
    if (y < 0)
        printf("impossible\n");
    else if (x > y)
        printf("%d %d\n", x, y);
    else
        printf("%d %d\n", y, x);
}

