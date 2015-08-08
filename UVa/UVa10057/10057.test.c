/* ACM 10057 A mid-summer night’s dream
 * mythnc
 * 2011/11/09 17:44:48   
 * run time: 0.4
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

int compar(const void *, const void *);
int countm(int, int);

int seq[MAXN];

int main(void)
{
    int n, i, mid, num;

    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++)
            scanf("%d", seq + i);

        qsort(seq, n, sizeof(int), compar);

        mid = n / 2;
        if (n % 2 == 1)
            printf("%d %d 1\n", seq[mid], countm(seq[mid], n));
        else if (seq[mid] == seq[mid - 1])
            printf("%d %d 1\n", seq[mid - 1], countm(seq[mid - 1], n));
        else {
            num = countm(seq[mid - 1], n) + countm(seq[mid], n);
            printf("%d %d %d\n", seq[mid - 1], num, seq[mid] - seq[mid - 1] + 1);
        }
    }
    return 0;
}

/* compar: for qsort */
int compar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/* countm: return number of median */
int countm(int num, int n)
{
    int i, count;

    for (count = i = 0; seq[i] <= num && i < n; i++)
        if (seq[i] == num)
            count++;

    return count;
}

