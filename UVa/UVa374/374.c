/* ACM 374 Big Mod
 * mythnc
 * 2011/10/31 11:57:08   
 * run time: 0.02
 */
#include <stdio.h>

#define MAXARY 47000
#define IN     1
#define OUT    0

int add(int *, int, int *);

int main(void)
{
    int b, p, m, tmp, tag, count;
    int rec[MAXARY];

    while (scanf("%d %d %d", &b, &p, &m) == 3) {
        count = 0;
        tag = OUT;
        for (rec[count++] = tmp = b %= m; --p;) {
            b *= tmp;
            if (b > m)
                b %= m;
            if (add(rec, b, &count) == IN) {
                tag = IN;
                break;
            }
        }

        if (tag == IN) {
            tmp = p % count - 1;
            /* can be divide */
            if (tmp < 0)
                tmp = count - 1;
            printf("%d\n", rec[tmp]);
            continue;
        }

        printf("%d\n", b);
    }
    return 0;
}

/* add: save mod number in rec,
 * if number is already in rec,
 * return IN,
 * else save it return OUT */
int add(int *rec, int b, int *n)
{
    int i;

    for (i = 0; i < *n; i++)
        if (rec[i] == b)
            return IN;

    rec[(*n)++] = b;
    return OUT;
}

