/* ACM 793 Network Connections
 * mythnc
 * 2012/01/14 12:41:37   
 * run time: 0.072
 */
#include <stdio.h>

#define MAXNODE 10001
#define LINEMAX 100

typedef enum {FALSE = 0, TRUE} bool;

void init(int *, int);
int find(int, int *);
void weightedunion(int, int, int *);

int main(void)
{
    int node[MAXNODE];
    bool set;
    int n, v1, v2, yes, no;
    char line[LINEMAX];

    scanf("%*d");
    getchar(); /* eat '\n' */
    getchar(); /* eat blank line */
    set = FALSE;
    while (fgets(line, LINEMAX, stdin))
        switch (line[0]) {
            /* compare */
            case 'q':
                sscanf(line, "%*c %d %d", &v1, &v2);
                if (find(v1, node) == find(v2, node))
                    yes++;
                else
                    no++;
                break;
            /* add */
            case 'c':
                sscanf(line, "%*c %d %d", &v1, &v2);
                weightedunion(find(v1, node), find(v2, node), node);
                break;
            /* output */
            case '\n':
                if (set)
                    putchar('\n');
                printf("%d,%d\n", yes, no);
                set = TRUE;
                break;
            default:
                sscanf(line, "%d", &n);
                init(node, n);
                yes = no = 0;
        }
    /* output last data set */
    if (set)
        putchar('\n');
    printf("%d,%d\n", yes, no);

    return 0;
}

/* init: init each node to disjoint set */
void init(int *node, int n)
{
    int i;

    for (i = 1; i <= n; i++)
        node[i] = -1;
}

/* find: find the set of node v */
int find(int v, int *node)
{
    for (; node[v] >= 0; v = node[v])
        ;

    return v;
}

/* weightedunoin: do i and j set union to one set */
void weightedunion(int i, int j, int *node)
{
    if (i == j)
        return;

    if (i <= j) {
        node[i] += node[j];
        node[j] = i;
    }
    else {
        node[j] += node[i];
        node[i] = j;
    }
}

