/* ACM 10074 Take the Land
 * mythnc
 * 2012/04/04 17:16:52
 * run time: 0.012
 */
#include <stdio.h>
#include <string.h>

#define MAXN 100

void input(int (*)[]);
int findsubsum(int (*)[]);
int subsum(int *, int *, int);

int maxrow, maxcol;

int main(void)
{
    int matrix[MAXN][MAXN];

    while (scanf("%d %d", &maxrow, &maxcol) && maxrow != 0) {
        input(matrix);
        printf("%d\n", findsubsum(matrix));
    }

    return 0;
}

/* input: receive input data. */
void input(int (*matrix)[MAXN])
{
    int i, j, tmp;

    for (i = 0; i < maxrow; i++)
        for (j = 0; j < maxcol; j++) {
            scanf("%d", &tmp);
            /* exchange 0 and 1 */
            if (tmp == 1)
                matrix[i][j] = 0;
            else
                matrix[i][j] = 1;
        }
}

/* findsubsum: find sub sum and return it */
int findsubsum(int (*matrix)[MAXN])
{
    int max, sum, i, j;
    int line[MAXN];

    /* from row 1 to N, 2 to N, ... , calculate each
     * subsum */
    for (i = max = 0; i < maxrow; i++) {
        /* init line */
        memset(line, 0, sizeof(int) * maxcol);
        for (j = i; j < maxrow; j++) {
            sum = subsum(line, matrix[j], j - i + 1);
            if (max < sum)
                max = sum;
        }
    }

    return max;
}

/* subsum: use Kadane's algorithm to find the subsum */
int subsum(int *line, int *matrix, int rown)
{
    int i, sum, max;
    /* add each column to line */
    for (i = 0; i < maxcol; i++)
        line[i] += matrix[i];

    for (i = sum = max = 0; i < maxcol; i++) {
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

