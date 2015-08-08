/* ACM 10004 Bicoloring
 * mythnc
 * 2011/12/26 19:44:34   
 * run time: 0.004
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNODE 199
#define TRUE    1
#define FALSE   0

enum color {none, white, black};

typedef struct node {
    int n;
    enum color c;
    struct node *next;
} Node;

void init(void);
void input(int, int);
void check(int);
void freeg(int);

int visited[MAXNODE];
Node *graph[MAXNODE];
int tag;

int main(void)
{
    int n, e, u, v, i;

    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &e);
        init();
        for (i = 0; i < e; i++) {
            scanf("%d %d", &v, &u);
            input(u, v);
            input(v, u);
        }
        tag = 1;
        check(0);
        if (tag)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        freeg(n);
    }

    return 0;
}

/* init: init graph node to NULL */
void init(void)
{
    int i;

    for (i = 0; i < MAXNODE; i++) {
        graph[i] = NULL;
        visited[i] = FALSE;
    }
}

/* input: receive input data */
void input(int u, int v)
{
    Node *tmp, *pt;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->n = u;
    tmp->c = none;
    tmp->next = NULL;
    if (!graph[v]) {
        graph[v] = (Node *)malloc(sizeof(Node));
        graph[v]->n = v;
        graph[v]->c = none;
        graph[v]->next = tmp;
    }
    else {
        pt = graph[v];
        while (pt->next)
            pt = pt->next;
        pt->next = tmp;
    }
}

/* check(dfs): check each node and
 * its adjanency are different colors.
 * if have same color stop dfs and return FALSE
 * else do dfs to the end and return TRUE */
void check(int n)
{
    enum color c;
    Node *pt;

    pt = graph[n];
    visited[n] = TRUE;
    if (pt->c == none) {
        pt->c = white;
        c = black;
    }
    else if (pt->c == white)
        c = black;
    else
        c = white;
    for (pt = pt->next; pt; pt = pt->next)
        if (graph[pt->n]->c == none)
            graph[pt->n]->c = c;
        else if (graph[pt->n]->c == c)
            ;
        else {
            tag = 0;
            return;
        }
    for (pt = graph[n]->next; pt; pt = pt->next)
        if (tag && !visited[pt->n])
            check(pt->n);
}

/* freeg: free link node */
void freeg(int n)
{
    int i;
    Node *pt, *tmp;

    for (i = 0; i < n; i++) {
        pt = graph[i];
        while (pt) {
            tmp = pt;
            pt = pt->next;
            free(tmp);
        }
    }
}

