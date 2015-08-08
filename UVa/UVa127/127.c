/* ACM 127 "Accordian" Patience
 * mythnc
 * 2012/01/12 17:02:02   
 * run time: 0.296
 */
#include <stdio.h>
#include <string.h>

#define MAX     52
#define MAXCHAR 3

typedef struct pile {
    char card[MAX][MAXCHAR];
    int count;
    struct pile *next, *pre;
} Pile;

typedef enum {FALSE = 0, TRUE} bool;

void input(Pile *);
int simulate(Pile *);
bool match(Pile *, Pile *);
void push(Pile *, char *);
void pop(Pile *, char *);
bool empty(Pile *);
void relink(Pile *);
void output(Pile *, int);

int main(void)
{
    Pile p[MAX];
    int n;

    while (scanf("%s", p[0].card[0]) && p[0].card[0][0] != '#') {
        input(p);
        n = simulate(p);
        output(p, n);
    }

    return 0;
}

/* input: receive input data and initialize */
void input(Pile *p)
{
    int i;

    p[0].count = 1;
    p[0].pre = NULL;
    p[0].next = &p[1];
    for (i = 1; i < MAX; i++) {
        scanf("%s", p[i].card[0]);
        p[i].count = 1;
        p[i].pre = &p[i - 1];
        if (i != MAX - 1)
            p[i].next = &p[i + 1];
        else
            p[i].next = NULL;
    }
}

/* simulate: simulate Accordian */
int simulate(Pile *head)
{
    int n, i;
    Pile *pt, *cmp;
    char s[MAXCHAR];

    n = MAX;
    for (pt = head; pt;) {
        /* 3rd pile to the left */
        for (i = 1, cmp = pt->pre; cmp && i < 3; cmp = cmp->pre, i++)
            ;
        if (cmp && match(pt, cmp)) {
            pop(pt, s);
            push(cmp, s);
            if (empty(pt)) {
                relink(pt);
                n--;
            }
            pt = cmp;
            continue;
        }
        /* neighbour on the left */
        cmp = pt->pre;
        if (cmp && match(pt, cmp)) {
            pop(pt, s);
            push(cmp, s);
            if (empty(pt)) {
                relink(pt);
                n--;
            }
            pt = cmp;
            continue;
        }
        pt = pt->next;
    }

    return n;
}

/* match: match condition */
bool match(Pile *p, Pile *q)
{
    return q->card[q->count - 1][0] == p->card[p->count - 1][0]
        || q->card[q->count - 1][1] == p->card[p->count - 1][1];
}

/* push: put s in top of p */
void push(Pile *p, char *s)
{
    strcpy(p->card[p->count++], s);
}

/* pop: pop out the top card */
void pop(Pile *p, char *s)
{
    strcpy(s, p->card[--p->count]);
}

/* empty: return TRUE if stack is empty
 * else return FALSE */
bool empty(Pile *p)
{
    return p->count == 0;
}

/* relink: rearrange linked list */
void relink(Pile *p)
{
    if (p->pre)
        p->pre->next = p->next;
    if (p->next)
        p->next->pre = p->pre;
}

/* output: output result */
void output(Pile *p, int n)
{
    if (n == 1) {
        printf("1 pile remaining: 52\n");
        return;
    }

    printf("%d piles remaining:", n);
    for (; p; p = p->next)
        printf(" %d", p->count);
    putchar('\n');
}

