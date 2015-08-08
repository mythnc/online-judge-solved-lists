/* ACM 299 Train Swapping
 * mythnc
 * 2011/10/26 09:20:42
 * run time: 0.004
 */
#include <stdio.h>

#define MAXARY 50
#define SWAP(x, y, t)  (t = x, x = y, y = t)

int bubble1(int *, int, int);
int bubble2(int *, int, int);

int main(void)
{
    int n, i, count;
    int ary[MAXARY];

    scanf("%*d");
    while (scanf("%d", &n) == 1) {
        if (n == 0) {
            printf("Optimal train swapping takes 0 swaps.\n");
            continue;
        }
        for (i = 0; i < n; i++)
            scanf("%d", &ary[i]);
        for (count = i = 0; i < n - 1; i++)
            if (i % 2 == 0)
                count += bubble1(ary, i / 2, n - (i / 2 + 1));
            else
                count += bubble2(ary, (n - 2) - i / 2, i / 2);
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}

/* bubble1: sort ary from 0 to n */
int bubble1(int *ary, int i, int n)
{
    int c, tmp;

    for (c = 0; i < n; i++)
        if (ary[i] > ary[i + 1]) {
            SWAP(ary[i], ary[i + 1], tmp);
            c++;
        }
    return c;
}


/* bubble2: sort ary from 0 to n */
int bubble2(int *ary, int i, int n)
{
    int c, tmp;

    for (c = 0; i > n; i--)
        if (ary[i] < ary[i - 1]) {
            SWAP(ary[i], ary[i - 1], tmp);
            c++;
        }
    return c;
}

