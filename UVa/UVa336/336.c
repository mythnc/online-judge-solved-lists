/* ACM 336 A Node Too Far
 * mythnc
 * 2012/01/13 13:10:30   
 * run time: 0.052
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNODE 30

/* save num in array node, but save pos in linked node */
typedef union name {
    int num, pos;
} u;

typedef struct node {
    u field;
    /* times: the ttl times */
    int times;
    struct node *next;
} Node;

typedef enum {FALSE = 0, TRUE} bool;

void input(int);
int search(int);
int addg(int);
void update(int, int);
int bfs(int, int);
void addq(int);
int deleteq(void);
void freeg(void);

Node graph[MAXNODE];
int numnode, front, end;
int queue[MAXNODE];
bool visited[MAXNODE];

int main(void)
{
    int edge, v, ttl, set, sum;

    set = 0;
    while (scanf("%d", &edge) && edge != 0) {
        input(edge);
        while (scanf("%d %d", &v, &ttl) && !(v == 0 && ttl == 0)) {
            sum = bfs(search(v), ttl);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                   ++set, sum, v, ttl);
        }
        freeg();
    }

    return 0;
}

/* input: receive edge and initialize graph */
void input(int n)
{
    int i, v1, v2, pos1, pos2;

    for (i = numnode = 0; i < n; i++) {
        scanf("%d %d", &v1, &v2);
        pos1 = search(v1);
        if (pos1 == -1)
            pos1 = addg(v1);
        pos2 = search(v2);
        if (pos2 == -1)
            pos2 = addg(v2);
        if (pos1 != pos2) {
            update(pos1, pos2);
            update(pos2, pos1);
        }
    }
}

/* search: find v in graph.
 * if find return its position
 * else return -1 */
int search(int v)
{
    int i;

    for (i = 0; i < numnode; i++)
        if (graph[i].field.num == v)     
            return i;

    return -1;
}

/* addg: add v in graph and
 * return the position of v */
int addg(int v)
{
    graph[numnode].field.num = v;
    graph[numnode].next = NULL;

    return numnode++;
}

/* update: update the edges of pos1 and pos2 */
void update(int pos1, int pos2)
{
    Node *pt, *tmp;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->field.pos = pos2;
    tmp->next = NULL;

    pt = graph[pos1].next;
    if (pt == NULL) {
        graph[pos1].next = tmp;
        return;
    }
    /* find last link node */
    while (pt->next != NULL)
        pt = pt->next;
    pt->next = tmp;
}

/* bfs: do bfs. the times of bfs has to equal to ttl
 * return unvisited node number */
int bfs(int pos, int ttl)
{
    int times, sum;
    Node *pt;
    sum = numnode;
    /* no such node */
    if (pos == -1)
        return sum;
    /* init visited array, queue tag and graph[pos] times */
    memset(visited, FALSE, MAXNODE * sizeof(int));
    front = end = graph[pos].times = 0;

    visited[pos] = TRUE;
    sum--;
    if (graph[pos].times == ttl)
        return sum;

    addq(pos);
    while (front != end) {
        pos = deleteq();
        for (times = graph[pos].times + 1, pt = graph[pos].next; pt; pt = pt->next) {
            pos = pt->field.pos;
            if (!visited[pos]) {
                visited[pos] = TRUE;
                sum--;
                graph[pos].times = times;
                if (times < ttl)
                    addq(pos);
            }
        }
    }

    return sum;
}

/* addq: add the graph[pos] and its adjacency node
 * to queue */
void addq(int pos)
{
    queue[end++] = pos;
    end %= MAXNODE;
}

/* deleteq: delete the 1st element in queue.
 * and return the element */
int deleteq(void)
{
    int pos;

    pos = queue[front++];
    front %= MAXNODE;

    return pos;
}

/* freeg: free graph node */
void freeg(void)
{
    Node *pt, *tmp;
    int i;

    for (i = 0; i < numnode; i++) {
        pt = graph[i].next;
        while (pt != NULL) {
            tmp = pt;
            pt = pt->next;
            free(tmp);
        }
    }
}

