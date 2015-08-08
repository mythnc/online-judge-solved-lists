/* ACM 541 Error Correction
 * mythnc
 * 2011/10/22 20:33:45   
 * run time: 0.008
 */
#include <stdio.h>

#define MAX 99
#define ONE  1
#define MORE 0

void property(int (*)[MAX], int);
int oddnumber(int *, int *, int);

int main(void)
{
    int n, i, j;
    int ary[MAX][MAX];
    
    while (scanf("%d", &n) == 1) {
        if (n == 0)
            return 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &ary[i][j]);

        property(ary, n);
    }
}

/* property: find the matrix has partity property or not */
void property(int (*pt)[MAX], int n)
{
    /* sum[0]: sum of each row, sum[1]: sum of each column */
    /* record[0]: bit row, sum[1]: bit column */
    int i, j, sum[2], record[2];

    for (record[0] = record[1] = i = 0 ; i < n; i++) {
        for (sum[0] = sum[1] = j = 0; j < n; j++) {
            sum[0] += pt[i][j]; /* sum of each row */
            sum[1] += pt[j][i]; /* sum of each column */
        }
        /* judge row and column*/
        for (j = 0; j < 2; j++)
            if (oddnumber(&sum[j], &record[j], i) == MORE) {
                printf("Corrupt\n");
                return;
            }
    }
    if (record[0] == 0 && record[1] == 0)
        printf("OK\n");
    else
        printf("Change bit (%d,%d)\n", record[0], record[1]);
}

/* oddnumber: calculate the odd number,
 * record it's row and column
 * if no odd or only 1 odd return ONE
 * if more then 1 odd return MORE
 */
int oddnumber(int *sum, int *record, int i)
{
    if (*sum % 2 == 1 && *record == 0)
        *record = i + 1;
    else if (*sum % 2 == 1 && *record > 0)
        return MORE;
    return ONE;
}

