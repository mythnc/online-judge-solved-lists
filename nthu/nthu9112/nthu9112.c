#include <stdio.h>
#include <stdlib.h>

/*#define DEBUG*/
#define MAXV 1000000

typedef struct graph {
    int node;
    int visited;
    struct graph *next;
} Graph;

enum {CYCLE = 1, FOREST = 1, NOT_FOREST = 0, NOT_CYCLE = 0};

void init(int n);
void add_edge(int u, int v);
int is_forest(int n);
int dfs(int v);
void edge_visited(int u, int v);

Graph nodes[MAXV];

int main(void)
{
    int m, n, u, v;

    while (scanf("%d %d", &n, &m) && n != 0) {
        init(n);
        while (m--) {
            scanf("%d %d", &u, &v);
            add_edge(u - 1, v - 1);
            add_edge(v - 1, u - 1);
        }
#ifdef DEBUG
        int i;
        Graph *gp;
        for (i = 0; i < n; i++) {
            printf("%d:", i + 1);
            gp = nodes[i].next;
            while (gp != NULL) {
                printf(" %d", gp->node + 1);
                gp = gp->next;
            }
            putchar('\n');
        }
#endif
        if (is_forest(n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

void init(int n)
{
    int i;

    for (i = 0; i < n; i++) {
        nodes[i].next = NULL;
        nodes[i].visited = 0;
    }
}

void add_edge(int u, int v)
{
    Graph *new, *current;

    current = &nodes[u];
    while (current->next != NULL) {
        current = current->next;
        if (current->node == v)
            return;
    }
    new = (Graph *)malloc(sizeof(Graph));
    new->node = v;
    new->visited = 0;
    new->next = NULL;
    current->next = new;
}

/* do DFS */
int is_forest(int n)
{
    int i;

    for (i = 0; i < n; i++) {
#ifdef DEBUG
        printf("out: start from node %d\n", i + 1);
#endif
        if (dfs(i) == CYCLE)
            return NOT_FOREST;
#ifdef DEBUG
        printf("out: end from node %d\n", i + 1);
#endif
    }
    return FOREST;
}

int dfs(int v)
{
#ifdef DEBUG
        printf("in: start from node %d\n", v + 1);
#endif
    Graph *gp;

    nodes[v].visited = 1;  /* node */
    gp = nodes[v].next;
    while (gp != NULL) {
#ifdef DEBUG
        printf("node %d\n", gp->node + 1);
#endif
        if (gp->visited) {
            gp = gp->next;
            continue;
        }
        if (nodes[gp->node].visited)
            return CYCLE;
        gp->visited = 1;  /* edge */
        edge_visited(gp->node, v);
        if (dfs(gp->node) == CYCLE) {
            return CYCLE;
        }
#ifdef DEBUG
        printf("node %d\n", gp->node + 1);
#endif
        gp = gp->next;
    }
#ifdef DEBUG
        printf("in: end from node %d\n", v + 1);
#endif
    return NOT_CYCLE;
}

void edge_visited(int u, int v)
{
    Graph *gp;

    gp = nodes[u].next;
    while (gp != NULL) {
        if (gp->node == v) {
#ifdef DEBUG
            printf("find edge: %d %d\n", gp->node + 1, v + 1);
#endif
            gp->visited = 1;
            return;
        }
        gp = gp->next;
    }
}

