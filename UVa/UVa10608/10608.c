/* ACM 10608 Friends
 * mythnc
 * 2012/01/14 23:12:34   
 * run time: 0.076
 */
#include <stdio.h>

#define MAXNODE 30001

void init(int);
void input(int);
int collapsingfind(int);
void weightedunion(int, int);
int count(int);

int node[MAXNODE];

int main(void)
{
    int n, m, set;

    scanf("%d", &set);
    while(set--) {
        scanf("%d %d", &n, &m);
        init(n);
        input(m);
        printf("%d\n", count(n));
    }

    return 0;
}

/* init: initialize each node to different sets */
void init(int n)
{
    int i;

    for (i = 1; i <= n; i++)
        node[i] = -1;
}

void input(int n)
{
    int i, v1, v2;

    for (i = 0; i < n; i++) {
        scanf("%d %d", &v1, &v2);
        weightedunion(collapsingfind(v1), collapsingfind(v2));
    }
}

/* collapsingfind: find root first,
 * then use collapsing rule to collapse all nodes
 * form v to root. return the set of node v */
int collapsingfind(int v)
{
    int root, trail, tmp;

    for (root = v; node[root] >= 0; root = node[root])
        ;
    for (trail = v; trail != root; trail = node[trail]) {
        tmp = trail;
        node[tmp] = root;
    }

    return root;
}

/* weightedunoin: union s1 and s2 */
void weightedunion(int s1, int s2)
{
    if (s1 == s2)
        return;

    if (s1 <= s2) {
        node[s1] += node[s2];
        node[s2] = s1;
    }
    else {
        node[s2] += node[s1];
        node[s1] = s2;
    }
}

/* count: return the max nodes set */
int count(int n)
{
    int min, i;

    for (i = 1, min = -1; i <= n; i++)
        if (node[i] < min)
            min = node[i];

    return -min;
}

