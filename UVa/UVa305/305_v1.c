/* ACM 305 Joseph
 * mythnc
 * 2011/12/01 12:19:49   
 * run time: TLE
 */
#include <stdio.h>

#define MAXN  26
#define TRUE  1
#define FALSE 0

typedef struct list {
    int i;
    struct list *next;
    struct list *pre;
} List;

void init(List *, int);
int findm(List *, int);
void link(List *, int);
int remain(List *, int *);
int goodlive(int, int *, int n);
int baddie(int, int *, int);

int main(void)
{
    List array[MAXN];
    int k;

    while (scanf("%d", &k) && k != 0) {
        init(array, 2 * k);
        printf("%d\n", findm(array, k));
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
int findm(List *ary, int k)
{
    int re[MAXN];
    int i, rec;
    long long m;
    List *p;

    link(ary, 2 * k);        /* link all */
    p = &ary[1];
    for (m = 2; ;) {         /* find m */
        p->pre->next = p->next;  /* link arrange */
        p->next->pre = p->pre;
        rec = remain(p->next, re);
        if (!goodlive(k, re, rec)) {
            link(ary, 2 * k);
            p = &ary[m % (2 * k)];
            m++;
            continue;
        }
        if (baddie(k, re, rec))
            return m;
        p = p->next;
        for (i = 0; i < (m - 1) % rec; i++)  /* move */
            p = p->next;
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

/* remain: save remain guys in r,
 * and return remain numbers */
int remain(List *p, int *r)
{
    int i;

    r[0] = p->i;

    i = 1;
    for (p = p->next; p->i != r[0]; p = p->next)
        r[i++] = p->i;

    return i;
}

/* goodlive: if one of the good guys is die return FALSE,
 * else return TRUE */
int goodlive(int k, int *r, int n)
{
    int i, j, found;

    for (i = 1; i < k + 1; i++) {
        found = FALSE;
        for (j = 0; j < n; j++)
            if (i == r[j]) {
                found = TRUE;
                break;
            }
        if (!found)
            return FALSE;
    }

    return TRUE;
}

/* baddie: if bad guys are all die return TRUE,
 * else return FALSE */
int baddie(int k, int *r, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = k + 1; j < 2 * k + 1; j++)
            if (r[i] == j)
                return FALSE;

    return TRUE;
}

