/* ACM 291 The House Of Santa Claus
 * mythnc
 * 2012/01/13 18:53:08   
 * run time: 0.020
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 8
#define MAXNODE 6 /* Node 0~5 */

typedef enum {FALSE = 0, TRUE} bool;

typedef struct node {
    int node;
    bool visited;
    struct node *next;
} Node;

void init(int, int);
void backtrack(int, int);
Node *find(int, int);

Node *g[MAXNODE] = {NULL};
/* record edge is visited or not */
char output[MAXEDGE + 1];

int main(void)
{
    int i;

    init(1, 2);
    init(2, 1);
    init(1, 3);
    init(3, 1);
    init(1, 5);
    init(5, 1);
    init(2, 3);
    init(3, 2);
    init(2, 5);
    init(5, 2);
    init(3, 4);
    init(4, 3);
    init(3, 5);
    init(5, 3);
    init(4, 5);
    init(5, 4);

    output[0] = 1 + '0';
    backtrack(1, 1);

    return 0;
}

/* init: initialize graph */
void init(int v1, int v2)
{
    Node *pt, *tmp;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->node = v2;
    tmp->visited = FALSE;

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
    Node *v1, *v2;

    if (index == MAXEDGE + 1) {
        output[index] = '\0';
        printf("%s\n", output);
        return;
    }

    for (v1 = g[node]; v1; v1 = v1->next) {
        if (!v1->visited) {
            v2 = find(node, v1->node);
            v1->visited = v2->visited = TRUE;
            output[index] = v1->node + '0';
            backtrack(index + 1, v1->node);
            v1->visited = v2->visited = FALSE;
        }
    }
}

/* find: find and return the correspond v2 position in v1 */
Node *find(int v1, int v2)
{
    Node *pt;

    for (pt = g[v2]; pt; pt = pt->next)
        if (pt->node == v1)
            return pt;
}

