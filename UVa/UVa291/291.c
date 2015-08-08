/* ACM 291 The House Of Santa Claus
 * mythnc
 * 2012/01/13 18:53:08   
 * run time: 0.004
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 8
#define MAXNODE 6 /* Node 0~5 */

typedef struct node {
    /* pos: edge position */
    int pos, node;
    struct node *next;
} Node;

typedef enum {FALSE = 0, TRUE} bool;

void init(int, int, int);
void backtrack(int, int);
void freeg(void);

Node *g[MAXNODE] = {NULL};
/* record edge is visited or not */
bool visited[MAXEDGE];
char output[MAXEDGE + 1];

int main(void)
{
    int i;

    init(1, 2, 0);
    init(2, 1, 0);
    init(1, 3, 1);
    init(3, 1, 1);
    init(1, 5, 2);
    init(5, 1, 2);
    init(2, 3, 3);
    init(3, 2, 3);
    init(2, 5, 4);
    init(5, 2, 4);
    init(3, 4, 5);
    init(4, 3, 5);
    init(3, 5, 6);
    init(5, 3, 6);
    init(4, 5, 7);
    init(5, 4, 7);

    output[0] = 1 + '0';
    backtrack(1, 1);
    freeg();

    return 0;
}

/* init: initialize graph */
void init(int v1, int v2, int pos)
{
    Node *pt, *tmp;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->node = v2;
    tmp->pos = pos;

    if (g[v1] == NULL) {
        g[v1] = tmp;
        return;
    }
    pt = g[v1];
    while (pt->next != NULL)
        pt = pt->next;
    pt->next = tmp;
}

/* backtrack: use backtracking method to output answer */
void backtrack(int index, int node)
{
    Node *pt;
    int pos;

    if (index == MAXEDGE + 1) {
        output[index] = '\0';
        printf("%s\n", output);
        return;
    }

    for (pt = g[node]; pt; pt = pt->next) {
        pos = pt->pos;
        node = pt->node;
        if (!visited[pos]) {
            visited[pos] = TRUE;
            output[index] = node + '0';
            backtrack(index + 1, node);
            visited[pos] = FALSE;
        }
    }
}

/* freeg: free all graph node */
void freeg(void)
{
    Node *pt, *tmp;
    int i;

    for (i = 0; i < MAXNODE; i++) {
        pt = g[i];
        while (pt != NULL) {
            tmp = pt;
            pt = pt->next;
            free(tmp);
        }
    }
}

