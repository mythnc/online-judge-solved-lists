#include <stdio.h>

#define MAXN 500000

typedef enum {FALSE, TRUE} bool;

bool equal(int *ary, int n, int x);

int main(void)
{
    int t, n, x, i;
    int ary[MAXN];

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%d", &x);
        for (i = 0; i < n; i++) {
            scanf("%d", &ary[i]);
        }
        if (equal(ary, n, x))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

bool equal(int *ary, int n, int x)
{
    int i, j, sum;

    for (i = 0; i < n; i++) {
        sum = ary[i];
        if (sum == x)
            return TRUE;
        for (j = i + 1; j < n && sum < x; j++) {
            sum += ary[j];
            if (sum == x)
                return TRUE;
        }
    }
    return FALSE;
}

