/* ACM 10050 Hartals
 * mythnc
 * 2011/11/06 22:57:42   
 * run time: 0.020
 */
#include <stdio.h>

#define MAXDAY 3650
#define MAXPTY 100
#define TRUE   1
#define FALSE  0

int hartal(int *, int);
void sort(int *, int, int);
int loseday(int *, int, int *, int);
int countday(int *, int);

int main(void)
{
    int day[MAXDAY] = { FALSE };
    int party[MAXPTY];
    int set, nd, np;

    scanf("%d", &set);
    while (set--) {
        scanf("%d", &nd);
        scanf("%d", &np);
        np = hartal(party, np);
        printf("%d\n", loseday(day, nd, party, np));
    }
    return 0;
}

/* hartal: check hartal number can be mod by
 * other number or not only receive hartal
 * number when it can't be mod by other numbers */
int hartal(int *p, int n)
{
    int count, i, j, tmp, rec;

    for (count = i = 0; i < n; i++) {
        scanf("%d", &tmp);
        for (rec = TRUE, j = 0; j < count; j++)
            if (tmp % p[j] == 0) {
                rec = FALSE;
                break;
            }
        if (rec) {
            sort(p, tmp, ++count);
        }
    }

    return count;
}

/* sort: insertion sort hartal number */
void sort(int *p, int number, int n)
{
    int i;

    if (n == 1) {
        p[0] = number;
        return;
    }

    for (i = n - 2; i > -1; i--)
        if (p[i] > number) {
            p[i + 1] = p[i];
            if (i == 0)
                p[0] = number;
        }
        else {
            p[i + 1] = number;
            break;
        }
}

/* loseday: find the lose day */
int loseday(int *d, int nd, int *p, int np)
{
    int i, j;

    for (i = 0; i < np; i++)
        for (j = p[i]; j < nd + 1; j += p[i])
            if (j % 7 != 0 && j % 7 != 6 && !d[j])
                d[j] = TRUE;

    return countday(d, nd);
}

/* countday: initalize value to zero and 
 * return sum of hartal days */
int countday(int *d, int nd)
{
    int i, sum;

    for (sum = 0, i = 1; i < nd + 1; i++)
        if (d[i]) {
            d[i] = FALSE;  /* initialize value to 0 */
            sum++;
        }

    return sum;
}

