#include <stdio.h>

#define MAXN 100000

void input(long long *a, int n);
long long query(long long *a);

int main(void)
{
    int t, n, q, i;
    long long ary[MAXN];

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

void input(long long *a, int n)
{
    int i, val;

    scanf("%lld", a);
    for (i = 1; i < n; i++) {
        scanf("%d", &val);
        a[i] = a[i - 1] + val;
    }
}

long long query(long long *a)
{
    int start, end;

    scanf("%d %d", &start, &end);
    if (start == 1)
        return a[end-1];
    return a[end-1] - a[start-2];
}

