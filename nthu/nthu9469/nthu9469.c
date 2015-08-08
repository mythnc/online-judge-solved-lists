#include <stdio.h>
#include <stdlib.h>

void max_sum(int **matrix, int m, int n);

int main(void)
{
    int m, n;
    int i, j;
    int **matrix;

    while (scanf("%d %d", &m, &n) == 2) {
        matrix = (int **)malloc(sizeof(int *) * m);
        for (i = 0; i < m; i++) {
            matrix[i] = (int *)malloc(sizeof(int) * n);
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        max_sum(matrix, m, n);
    }
    return 0;
}

void max_sum(int **matrix, int m, int n)
{
    int i, j;
    long long min, temp;

    // column  sum
    for (i = min = 0; i < m; i++) {
        min += matrix[i][0];
    }

    for (j = 1; j < n; j++) {
        for (i = temp = 0; i < m; i++) {
            temp += matrix[i][j];
        }
        if (temp < min) {
            min = temp;
        }
    }
    printf("%lld", min);

    // row sum
    for (j = min = 0; j < n; j++) {
        min += matrix[0][j];
    }

    for (i = 1; i < m; i++) {
        for (j = temp = 0; j < n; j++) {
            temp += matrix[i][j];
        }
        if (temp < min) {
            min = temp;
        }
    }
    printf(" %lld\n", min);
}

