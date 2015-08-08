/* ACM 10127 Ones
 * mythnc
 * 2011/11/10 10:42:16   
 * run time: 1.34
 */
#include <stdio.h>

#define MAXD  10000

void initbig(int *, int *);
int modbig(int *, int, int);
int divbig(int *, int, int *, int);
void mulbig(int *, int, int, int);
int equalbig(int *, int *, int);
void plusbig(int *, int *);

int main(void)
{
    int n, digit;
    int seq[MAXD];

    while (scanf("%d", &n) == 1) {
        initbig(seq, &digit);
        
        while (modbig(seq, digit, n) != 0)
            plusbig(seq, &digit);

        printf("%d\n", digit);
    }
    return 0;
}

/* initbig: initialzie big to 1 */
void initbig(int *seq, int *digit)
{
    seq[0] = 1;
    *digit = 1;
}

/* modbig: if seq % n == 0 return 0,
 * else return 1 */
int modbig(int *seq, int digit, int n)
{
    int q[MAXD] = { 0 };
    int qd, i;

    qd = divbig(seq, digit, q, n);
    mulbig(q, qd, digit, n);

    return equalbig(seq, q, digit);
}

/* divbig: do n divided by seq
 * return the digit of quotient */
int divbig(int *seq, int digit, int *q, int n)
{
    int i, r;

    for (r = 0, i = digit - 1; i > - 1; i--) {
        r = r * 10 + seq[i];
        q[i] = r / n;
        r %= n;
    }

    for (i = digit - 1; q[i] == 0 && i > -1; i--)
        ;

    return i + 1;
}

/* mulbig: do q * n */
void mulbig(int *q, int qd, int d, int n)
{
    int i;

    for (i = 0; i < qd; i++)
        q[i] *= n;

    /* carry */
    for (i = 0; i < d; i++)
        if (q[i] > 9) {
            q[i + 1] += q[i] / 10;
            q[i] %= 10;
        }
}

/* equalbig: if seq == q return 0
 * else return 1 */
int equalbig(int *seq, int *q, int d)
{
    int i;

    for (i = 0; i < d; i++)
        if (seq[i] != q[i])
            return 1;
    return 0;
}

/* plusbig: let the highest digit of big to be 1 */
void plusbig(int *seq, int *digit)
{
    seq[(*digit)++] = 1;
}

