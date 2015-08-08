/* ACM 10327 Flip Sort
 * mythnc
 * 2011/10/16 20:43:45   
 * run time: 0.06
 * use cocktail sort
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
int bubble1(int *, int, int);
int bubble2(int *, int, int);

int main(void)
{
    int n, i, c;
    int *ary;

    while (scanf("%d", &n) != EOF) {
        ary = (int *)malloc(sizeof(int) * n);
        for (i = 0; i < n; i++)
            scanf("%d", ary + i);
        for (c = i = 0; i < n - 1; i++) {
            if (i % 2 == 0)
                c += bubble1(ary, i / 2, n - (i / 2 + 1));
            else
                c += bubble2(ary, (n - 2) - i / 2, i / 2);
            }
        printf("Minimum exchange operations : %d\n", c);
        free(ary);
    }
    return 0;
}

/* swap: exchange *p and *q */
void swap(int *p, int *q)
{
    int tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

/* bubble1: sort ary from 0 to n */
int bubble1(int *ary, int i, int n)
{
    int c;

    for (c = 0; i < n; i++)
        if (ary[i] > ary[i + 1]) {
            swap(ary + i, ary + i + 1);
            c++;
        }
    return c;
}


/* bubble2: sort ary from 0 to n */
int bubble2(int *ary, int i, int n)
{
    int c;

    for (c = 0; i > n; i--)
        if (ary[i] < ary[i - 1]) {
            swap(ary + i, ary + i - 1);
            c++;
        }
    return c;
}

