/* ACM 10004 Bicoloring
 * mythnc
 * 2011/12/26 19:44:34   
 * run time: 0.012
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXNODE 199
#define TRUE    1
#define FALSE   0

enum color {none, white, black};

typedef struct node {
    int n;
    enum color c;
    struct node *next;
} Node;

void init(Node **);
void input(Node **, int, int);
int check(Node **, int);
void freeg(Node **, int);

int visited[MAXNODE];

int main(void)
{
    int n, e, u, v, i;
    Node *graph[MAXNODE];

    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &e);
        init(graph);
        for (i = 0; i < e; i++) {
            scanf("%d %d", &v, &u);
            input(graph, u, v);
            input(graph, v, u);
        }
        if (check(graph, 0))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        freeg(graph, n);
    }

    return 0;
}

/* init: initialize graph node to NULL and visited to zero */
void init(Node **graph)
{
    int i;

    for (i = 0; i < MAXNODE; i++) {
        graph[i] = NULL;
        visited[i] = FALSE;
    }
}

/* input: receive input data */
void input(Node **graph, int u, int v)
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
 * its adjacency are different colors.
 * if have same color stop dfs and return FALSE
 * else do dfs to the end and return TRUE */
int check(Node **graph, int n)
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
        else
            return FALSE;
    for (pt = graph[n]->next; pt; pt = pt->next)
        if (!visited[pt->n])
            if (!check(graph, pt->n))
                return FALSE;

    return TRUE;
}

/* freeg: free link node */
void freeg(Node **graph, int n)
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

