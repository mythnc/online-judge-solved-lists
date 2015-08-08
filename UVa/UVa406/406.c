/* ACM 406 Prime Cuts
 * mythnc
 * 2011/10/20 15:50:21   
 * run time: 0.064
 */
#include <stdio.h>

#define MAXARY 200
#define N      1000
#define NOT_P  0
#define PRIME  1

int prime(int *);
int maxnumber(int *, int, int);
void output(int *, int, int);

int main(void)
{
    int n, c, pnumber, ptotal;
    int ary[MAXARY];

    ptotal = prime(ary);
    while (scanf("%d %d", &n, &c) == 2) {
        pnumber = maxnumber(ary, n, ptotal);
        printf("%d %d:", n, c);
        output(ary, pnumber, c);
        printf("\n\n");
    }
    return 0;
}

/* prime: find prime from 1 to 1000, save in s
 * return the numbers */
int prime(int *s)
{
    int i, j, count, rec;

    count = 0;
    s[count++] = 1;
    s[count++] = 2;
    for (i = 3; i < N + 1; i += 2) {
        rec = PRIME;
        for (j = 3; j * j <= i; j += 2)
            if (i % j == 0) {
                rec = NOT_P;
                break;
            }
        if (rec == PRIME)
            s[count++] = i;
    }
    return count;
}

/* maxnumber: return the prime number from 1 to n */
int maxnumber(int *s, int n, int max)
{
    int i;

    for (i = 0; s[i] <= n && i < max; i++)
        ;
    return i;
}


/* output: output result */
void output(int *s, int pnum, int c)
{
    int i, mid;

    mid = pnum / 2;
    /* print all */
    if (mid < c)
        for (i = 0; i < pnum; i++)
            printf(" %d", s[i]);
    /* pnum is odd */
    else if (pnum % 2 == 1)
        for (i = mid - c + 1; i < mid + c; i++)
            printf(" %d", s[i]);
    /* pnum is even */
    else
        for (i = mid - c; i < mid + c; i++)
            printf(" %d", s[i]);
}

