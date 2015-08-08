/* ACM 836 Largest Submatrix
 * mythnc
 * 2012/04/03 16:01:37   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

#define MAXN 25

int input(char (*)[]);
int findsubsum(char (*)[], int);
int subsum(int *, char *, int, int);
void ctoi(int *, char *, int);

int main(void)
{
    int n, i, len;
    char matrix[MAXN][MAXN + 1];

    scanf("%d", &n);
    /* eat '\n' */
    getchar();
    for (i = 0; i < n; i++) {
        if (i > 0)
            putchar('\n');
        /* eat blank line */
        getchar();
        len = input(matrix);
        printf("%d\n", findsubsum(matrix, len));
    }

    return 0;
}

/* input: receive input data.
 * return its len */
int input(char (*matrix)[MAXN])
{
    int len, i;

    scanf("%s", matrix[0]);
    len = strlen(matrix[0]);
    for (i = 1; i < len; i++)
        scanf("%s", matrix[i]);

    return len;
}

/* findsubsum: find sub sum and return it */
int findsubsum(char (*matrix)[MAXN], int len)
{
    int max, sum, i, j;
    int line[MAXN];

    /* from row 1 to N, 2 to N, ... , calculate each
     * subsum */
    for (i = max = 0; i < len; i++) {
        /* init line */
        memset(line, 0, sizeof(int) * len);
        for (j = i; j < len; j++) {
            sum = subsum(line, matrix[j], len, j - i + 1);
            if (max < sum)
                max = sum;
        }
    }

    return max;
}

/* subsum: use Kadane's algorithm to find the subsum */
int subsum(int *line, char *row, int len, int rown)
{
    int i, sum, max;

    /* add row to line */
    ctoi(line, row, len);

    for (i = sum = max = 0; i < len; i++) {
        if (line[i] != rown) {
            sum = 0;
            continue;
        }
        sum += line[i];
        if (sum > max)
            max = sum;
    }

    return max;
}

/* ctoi: transform char to int */
void ctoi(int *line, char *row, int len)
{
    int i;

    for (i = 0; i < len; i++)
        line[i] += row[i] - '0';
}

