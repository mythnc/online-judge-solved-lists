/* ACM 107 The Cat in the Hat
 * mythnc
 * 2011/10/17 19:16:52   
 * run time: 0.064
 */
#include <stdio.h>

int findn(int, int);

int main(void)
{
    int w, h, n;

    while (scanf("%d %d", &h, &w) == 2) {
        if (!h && !w)
            break;
        if (h == 1) {
            printf("0 1\n");
            continue;
        }
        if (w == 1) {
            while ((h >> w) != 1)
                w++;
            printf("%d %d\n", w, 2 * h - 1);
            continue;
        }
        n = findn(h, w);
        printf("%d %d\n", (w - 1) / (n - 1), (n + 1) * h - w * n);
    }
    return 0;
}

/* findn: find and return the constant N */
int findn(int h, int w)
{
    int n, i, j;

    n = 2;
    while (1) {
        i = w;
        j = h;
        /* n have to divide w and j */
        while (i % n == 0 && j % (n + 1) == 0) {
            i /= n;
            j /= n + 1;
            if (i == 1 && j == 1)
                return n;
        }
        n++;
    }
}

