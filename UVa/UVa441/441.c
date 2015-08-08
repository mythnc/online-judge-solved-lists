/* ACM 441 Lotto
 * mythnc
 * 2012/01/10 21:08:05   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXN 12
#define OUT  6

void input(int n);
void com(int, int, int);

int list[MAXN];
int output[OUT];

int main(void)
{
    int n, set;

    set = 0;
    while (scanf("%d", &n) && n != 0) {
        if (set == 1)
            putchar('\n');
        input(n);
        com(0, n, 0);
        set = 1;
    }

    return 0;
}

/* input: receive input data */
void input(int n)
{
    int i;

    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);
}

/*
void com1(int *list, int n)
{
    int i, j, k, l, m, o;

    for (i = 0; n - i >= OUT; i++)
        for (j = i + 1; n - j >= OUT - 1; j++)
            for (k = j + 1; n - k >= OUT - 2; k++)
                for (l = k + 1; n - l >= OUT - 3; l++)
                    for (m = l + 1; n - m >= OUT - 4; m++)
                        for (o = m + 1; n - o >= OUT - 5; o++)
                            printf("%d %d %d %d %d %d\n",
                            list[i], list[j], list[k], list[l], list[m], list[o]);
}
*/

/* com: recursive combine to all conditions */
void com(int x, int n, int times)
{
    int i;

    if (times == OUT) {
        printf("%d", output[0]);
        for (i = 1; i < OUT; i++)
            printf(" %d", output[i]);
        putchar('\n');
        return;
    }

    for (i = x; n - i >= OUT - times; i++) {
        output[times] = list[i];
        com(i + 1, n, times + 1);
    }
}

