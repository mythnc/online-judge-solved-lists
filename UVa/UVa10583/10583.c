/* ACM 10583 Ubiquitous Religions
 * mythnc
 * 2012/01/14 22:48:07   
 * run time: 0.2
 */
#include <stdio.h>

#define MAXNODE 50001

void init(int);
void input(int);
int find(int);
void weightedunion(int, int);
void output(int *, int);
int count(int);

int node[MAXNODE];

int main(void)
{
    int n, m, set;

    set = 0;
    while (scanf("%d %d", &n, &m) && n != 0) {
        init(n);
        input(m);
        output(&set, n);
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
        weightedunion(find(v1), find(v2));
    }
}

/* find: return the set of node v */
int find(int v)
{
    for (; node[v] >= 0; v = node[v])
        ;

    return v;
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

/* output: output result */
void output(int *set, int n)
{
    printf("Case %d: %d\n", ++*set, count(n));
}

/* count: return the number of different sets */
int count(int n)
{
    int sum, i;

    for (i = 1, sum = 0; i <= n; i++)
        if (node[i] < 0)
            sum++;

    return sum;
}

