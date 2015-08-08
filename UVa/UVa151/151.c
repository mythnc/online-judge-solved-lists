/* ACM 151 Power Crisis
 * mythnc
 * 2011/11/09 10:55:26   
 * version 1.11
 * run time: 0.008
 */
#include <stdio.h>

#define MAXN 99
#define LAST 13

typedef struct list {
    int i;
    struct list *next;
    struct list *pre;
} List;

void init(List *array);
int findm(List *p, int n);
void link(List *p, int n);

int main(void)
{
    List array[MAXN];
    int n, i;
    int ans[MAXN];

    init(array);

    while (scanf("%d", &n) && n != 0)
        printf("%d\n", findm(array, n));

    return 0;
}

/* init: initialize array */
void init(List *array)
{
    int i;

    for (i = 0; i < MAXN; i++)
        array[i].i = i + 1;
}

/* findm: find and return the number m */
int findm(List *ary, int n)
{
    int count, i, m;
    List *p;

    for (m = 1; ; m++) {  /* find m */
        link(ary, n);     /* link all again */
        p = ary;
        count = 1;
        while (count < n) {
            p->pre->next = p->next;  /* link arrange */
            p->next->pre = p->pre;
            for (i = 0; i < m; i++)  /* move */
                p = p->next;
            count++;
            if (p->i == LAST)
                break;
        }
        if (count == n)
            return m;
    }
}

/* link: link array elements one by one
 * in a circle */
void link(List *p, int n)
{
    int i;

    p[0].next = &p[1];
    p[0].pre = &p[n - 1];
    for (i = 1; i < n; i++) {
        p[i].next = &p[(i + 1) % n];
        p[i].pre = &p[i - 1];
    }
}

