/* ACM 10057 A mid-summer night’s dream
 * mythnc
 * 2011/11/09 17:44:48
 * run time: 0.428
 */
#include <stdio.h>
#include <stdlib.h>

int compar(const void *, const void *);
int countm(int *, int, int);

int main(void)
{
    int n, i, mid, num;
    int *seq;

    while (scanf("%d", &n) == 1) {
        seq = (int *)malloc(sizeof(int) * n);

        for (i = 0; i < n; i++)
            scanf("%d", seq + i);

        qsort(seq, n, sizeof(int), compar);

        mid = n / 2;
        if (n % 2 == 1) /* odd */
            printf("%d %d 1\n", seq[mid], countm(seq, seq[mid], n));
        else if (seq[mid] == seq[mid - 1]) /* even if same */
            printf("%d %d 1\n", seq[mid - 1], countm(seq, seq[mid - 1], n));
        else { /* if not same */
            num = countm(seq, seq[mid - 1], n) + countm(seq, seq[mid], n);
            printf("%d %d %d\n", seq[mid - 1], num, seq[mid] - seq[mid - 1] + 1);
        }
        free(seq);
    }
    return 0;
}

/* compar: for qsort */
int compar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/* countm: return number of median */
int countm(int *s, int num, int n)
{
    int i, count;

    for (count = i = 0; s[i] <= num && i < n; i++)
        if (s[i] == num)
            count++;

    return count;
}

