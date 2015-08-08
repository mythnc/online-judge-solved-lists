#include <stdio.h>

#define MAXN 100000

void input(int *a, int n);
long long query(int *a);

int main(void)
{
    int t, n, q;
    int ary[MAXN];

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        input(ary, n);
        scanf("%d", &q);
        while (q--) {
            printf("%lld\n", query(ary));
        }
    }
    return 0;
}

void input(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
}

long long query(int *a)
{
    int i, start, end;
    long long sum;

    scanf("%d %d", &start, &end);
    for (i = start - 1, sum = 0; i < end; i++) {
        sum += a[i];
    }
    return sum;
}

