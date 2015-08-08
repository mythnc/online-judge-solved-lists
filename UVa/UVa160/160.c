/* ACM 160 Factors and Factorials
 * mythnc
 * 2011/11/01 20:15:27   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXP 25

void init(int *);
void factor(int, int *, int *);
void printout(int, int *, int);

int main(void)
{
    int n;
    int prime[] = { 2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
                   31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                   73, 79, 83, 89, 97};
    int map[MAXP];

    while (scanf("%d", &n) && n != 0) {
        init(map);
        factor(n, prime, map);
        printout(n, map, size(map));
    }
    return 0;
}

/* init: initialize array m to zero */
void init(int *m)
{
    int i;

    for (i = 0; i < MAXP; i++)
        m[i] = 0;
}

/* factor: find prime factors */
void factor(int n, int *p, int *map)
{
    int i, j, tmp;

    for (i = 2; i < n + 1; i++) {
        tmp = i;
        for (j = 0; p[j] <= tmp; j++)
            while (tmp % p[j] == 0) {
                map[j]++;
                tmp /= p[j];
            }
    }
}

/* size: return the prime factors array m have */
int size(int *m)
{
    int i;

    for (i = MAXP - 1; m[i] == 0; i--)
        ;

    return i + 1;
}

/* printout: print out results */
void printout(int n, int *m, int count)
{
    int i;

    printf("%3d! =", n);
    for (i = 0; i < count; i++) {
        if (i == 15)
            printf("\n%6c", ' ');
        printf("%3d", m[i]);
    }
    printf("\n");
}

