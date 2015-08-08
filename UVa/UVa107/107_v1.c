/* ACM 107 The Cat in the Hat
 * mythnc
 * 2011/10/17 15:12:21   
 * run time: 1.472
 */
#include <stdio.h>
#include <math.h>

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
    int n, k;

    k = n = 1;
    while (1)
        if (pow(n + 1, k) < h)
            k++;
        else if (pow(n + 1, k) > h) {
            n++;
            k = 1;
        }
        else if (pow(n, k) < w){
            n++;
            k = 1;
        }
        else
            return n;
}

