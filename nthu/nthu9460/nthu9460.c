#include <stdio.h>

#define MAX 500

int main(void)
{
    long long a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int m, n, p;
    int i, j, k;

    scanf("%*d");
    while (scanf("%d %d %d", &m, &n, &p) == 3) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                scanf("%lld", &a[i][j]);
                //printf("%d\n", a[i][j]);
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < p; j++) {
                scanf("%lld", &b[i][j]);
                //printf("%d\n", b[i][j]);
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < p; j++) {
                c[i][j] = 0;
                for (k = 0; k < n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                    //printf("%d\n", a[i][k] * b[k][j]);
                }
            }
        }
        for (i = 0; i < m; i++) {
            printf("%lld", c[i][0]);
            for (j = 1; j < p; j++) {
                printf(" %lld", c[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}

