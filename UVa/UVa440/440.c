/* ACM 440 Eeny Meeny Moo
 * mythnc
 * 2011/12/07 08:07:57   
 * run time: 0.068
 */
#include <stdio.h>

#define MAXN 149

typedef struct list {
    int i;
    struct list *next;
    struct list *pre;
} List;

void init(List *);
int findm(List *, int);
void link(List *, int);

int main(void)
{
    List array[MAXN];
    int n, i;
    int ans[MAXN];

    init(array);

    for (i = 3; i < MAXN + 1; i++)
        ans[i - 1] = findm(array, i);

    while (scanf("%d", &n) && n != 0)
        printf("%d\n", ans[n - 1]);

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

    for (m = 2; ; m++) {  /* find m */
        link(ary, n);     /* link all again */
        p = ary;
        count = 1;
        while (count < n) {
            p->pre->next = p->next;  /* link arrange */
            p->next->pre = p->pre;
            for (i = 0; i < m; i++)  /* move */
                p = p->next;
            count++;
            if (p->i == 2)
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

