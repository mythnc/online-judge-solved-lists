/* ACM 10107 What is the Median? 
 * mythnc
 * 2011/11/04 19:16:36   
 * run time: 0.040
 */
#include <stdio.h>

#define MAXN 10000

void sort(int *, int);
int median(int *, int);

int main(void)
{
    int n, count;
    int seq[MAXN];

    count = 0;
    while (scanf("%d", &n) == 1) {
        seq[count++] = n;
        if (count > 1)
            sort(seq, count);
        printf("%d\n", median(seq, count));
    }

    return 0;
}

/* sort: insertion sort array s */
void sort(int *s, int n)
{
    int i, tmp;

    tmp = s[n - 1];
    for (i = n - 2; i > -1; i--)
        if (s[i] > tmp) {
            s[i + 1] = s[i];
            if (i == 0)
                s[0] = tmp;
        }
        else {
            s[i + 1] = tmp;
            break;
        }
}

/* median: return the median number */
int median(int *s, int n)
{
    int k;

    k = n / 2;
    if (n % 2 == 1)
        return s[k];
    else
        return (s[k] + s[k - 1]) / 2;
}

