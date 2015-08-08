/* ACM 459 Graph Connectivity
 * mythnc
 * 2012/01/13 23:34:04   
 * run time: 0.020
 */
#include <stdio.h>

#define MAXLETTER 26
#define LINEMAX   4  /* 2 + '\n' + '\0' */

void init(int *, int);
int find(int *, int);
void unionsub(int, int, int *);
int count(int *, int);

int main(void)
{
    int i, set, n;
    int node[MAXLETTER];
    char c;
    char token[LINEMAX];

    scanf("%d", &set);
    getchar(); /* eat '\n' */
    scanf("%*c"); /* eat blank line */
    for (i = 0; i < set; i++) {
        scanf("%c", &c);
        getchar();
        n = c - 'A' + 1;
        init(node, n);
        while (fgets(token, LINEMAX, stdin) && token[0] != '\n')
            unionsub(find(node, token[0] - 'A'), find(node, token[1] - 'A'), node);
        /* ouput */
        if (i > 0)
            putchar('\n');
        printf("%d\n", count(node, n));
    }

    return 0;
}

/* init: initialize each node to -1 */
void init(int *node, int n)
{
    int i;

    for (i = 0; i < n; i++)
        node[i] = -1;
}

/* find: find root of node x */
int find(int *node, int x)
{
    for (; node[x] != -1; x = node[x])
        ;
    return x;
}

/* unionsub: union i and j two sets to one set */
void unionsub(int i, int j, int *node)
{
    if (i != j)
        node[i] = j;
}

/* count: return the number of subgraph */
int count(int *node, int n)
{
    int sum, i;

    for (i = sum = 0; i < n; i++)
        if (node[i] < 0)
            sum++;

    return sum;
}

