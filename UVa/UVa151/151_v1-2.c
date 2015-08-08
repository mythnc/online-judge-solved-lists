/* ACM 151 Power Crisis
 * mythnc
 * 2011/12/06 21:42:04   
 * version 1.2
 * use one link instead of two link
 * less space more time
 * run time: 0.008
 */
#include <stdio.h>

#define MAXN 99

typedef struct list {
    int i;
    struct list *next;
} List;

void init(List *array, int n);
int findm(List *p, int n);
void link(List *p, int n);

int main(void)
{
    List array[MAXN];
    int n;

    while (scanf("%d", &n) && n != 0) {
        init(array, n);
        printf("%d\n", findm(array, n));
    }
    return 0;
}

/* init: initialize array */
void init(List *array, int n)
{
    int i;

    for (i = 0; i < n; i++)
        array[i].i = i + 1;
}

/* findm: find and return the number m */
int findm(List *ary, int n)
{
    int count, i, m;
    List *p, *pre;

    for (m = 1; ; m++) {  /* find m */
        link(ary, n);     /* link all again */
        pre = ary + n - 1;
        p = ary;
        count = 1;
        while (count < n) {
            pre->next = p->next;      /* link arrange */
            for (i = 0; i < m; i++) { /* move */
                pre = p;
                p = p->next;
            }
            count++;
            if (p->i == 13) {
                if (count == n)
                    return m;
                break;
            }
        }
    }
}

/* link: link array elements one by one
 * in a circle */
void link(List *p, int n)
{
    int i;

    for (i = 0; i < n; i++)
        p[i].next = &p[(i + 1) % n];
}

