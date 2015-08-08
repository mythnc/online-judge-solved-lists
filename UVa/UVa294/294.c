/* ACM 294 Divisors
 * mythnc
 * 2011/11/17 12:13:07   
 * run time: 0.032
 */
#include <stdio.h>

#define MAXP  3402
#define TRUE  1
#define FALSE 0

typedef struct divisor {
    int number, count;
} Divisor;

typedef struct big {
    int number, sum;
} Big;

void findp(Divisor *);
Big maxn(Divisor *, int, int);
int dnumber(Divisor *, int);

int main(void)
{
    int head, tail;
    Big max;
    Divisor prime[MAXP];

    findp(prime);
    scanf("%*d");
    while (scanf("%d %d", &head, &tail) == 2) {
        max = maxn(prime, head, tail);
        printf("Between %d and %d, %d has a maximum of %d divisors.\n"
                , head, tail, max.number, max.sum);
    }
    return 0;
}

/* findp: find n primes */
void findp(Divisor *p)
{
    int count, i, j, flag;

    p[0].number = 2;
    count = 1;
    for (i = 3; count < MAXP; i += 2) {
        for (flag = TRUE, j = 3; j * j <= i; j++)
            if (i % j == 0) {
                flag = FALSE;
                break;
            }
        if (flag)
            p[count++].number = i;
    }
}

/* maxn: return the number which has the max divisors */
Big maxn(Divisor *p, int head, int tail)
{
    int i, number;
    Big max;

    max.number = head;
    max.sum = dnumber(p, head);
    for (i = head + 1; i < tail + 1; i++) {
        number = dnumber(p, i);
        if (max.sum < number) {
            max.sum = number;
            max.number = i;
        }
    }

    return max;
}

/* dnumber: return number of divisors of n */
int dnumber(Divisor *p, int n)
{
    int i, j, d;

    if (n == 1)
        return 1;

    for (i = 0; i < MAXP && n != 1; i++) {
        p[i].count = 0;
        while (n % p[i].number == 0) {
            n /= p[i].number;
            p[i].count++;
        }
    }

    for (d = 1, j = 0; j < i; j++)
        if (p[j].count != 0)
            d *= p[j].count + 1;

    if (n != 1)
        return d * 2;
    return d;
}

