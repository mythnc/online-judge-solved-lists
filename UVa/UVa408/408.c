/* ACM 408 Uniform Generator
 * mythnc
 * 2012/01/01 10:07:53   
 * run time: 0.068
 */
#include <stdio.h>
#include <string.h>

#define MAXMOD 10000000
#define TRUE   1
#define FALSE  0

int complete(int, int);

int visited[MAXMOD];

int main(void)
{
    int step, mod;

    while (scanf("%d %d", &step, &mod) == 2)
        if (complete(step, mod))
            printf("%10d%10d    Good Choice\n\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n", step, mod);

    return 0;
}

/* complete: return TRUE if s and m will
 * generate all numbers between 0 to m - 1
 * else return FALSE */
int complete(int s, int m)
{
    int count, x;

    s %= m;
    x = count = 0;
    while (!visited[x]) {
        visited[x] = TRUE;
        count++;
        x = (x + s) % m;
    }
    memset(visited, 0, sizeof(int) * m);

    if (count == m)
        return TRUE;
    return FALSE;
}

