/* ACM 350 Pseudo-Random Numbers
 * mythnc
 * 2011/11/17 21:48:38   
 * run time: 1.1
 */
#include <stdio.h>

#define MAXR  10000

int len(int, int, int, int);
int in(int, int *, int);

int main(void)
{
    int z, inc, mod, last, set;

    set = 0;
    while (scanf("%d %d %d %d", &z, &inc, &mod, &last) && mod != 0)
        printf("Case %d: %d\n", ++set, len(z % mod, inc % mod, mod, last));

    return 0;
}

/* len: return the len */
int len(int z, int inc, int mod, int last)
{
    int i, tmp, seed;
    int r[MAXR];

    r[0] = last;
    for (i = 1; ; i++) {
        tmp = (r[i - 1] * z + inc) % mod;
        if ((seed = in(tmp, r, i)) != -1)
            return i - seed;
        r[i] = tmp;
    }
}

/* in: if n in r,
 * i = 0 mean start from seed return TRUE,
 * i > 0 mean start not from seed return i,
 * else return -1 */
int in(int n, int *r, int count)
{
    int i;

    for (i = 0; i < count; i++)
        if (r[i] == n)
            return i;

    return -1;
}

