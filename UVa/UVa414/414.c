/* ACM 414 Machined Surfaces
 * mythnc
 * 2011/11/25 09:06:42   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXCHAR 27 /* 25 + newline + '\0' */
#define MAXLINE 12

void input(char (*)[], int);
int count(char (*)[], int);

int main(void)
{
    char str[MAXLINE][MAXCHAR];
    int n, i;

    while (scanf("%d", &n) && n != 0) {
        getchar();   /* eat newline */
        input(str, n);
        printf("%d\n", count(str, n));
    }
    return 0;
}

/* input: receive input data */
void input(char (*s)[MAXCHAR], int n)
{
    int i;

    for (i = 0; i < n; i++)
        fgets(s[i], MAXCHAR, stdin);
}

/* count: return the count of remain space numbers */
int count(char (*s)[MAXCHAR], int n)
{
    int i, j, min, sum;
    int countb[MAXLINE];

    for (i = 0, min = 25; i < n; i++) {
        /* calculate space number in each row */
        for (j = countb[i] = 0; j < MAXCHAR; j++)
            if (s[i][j] == ' ')
                countb[i]++;
        /* find the minimum space number */
        if (min > countb[i])
            min = countb[i];
    }

    for (i = sum = 0; i < n; i++)
        sum += countb[i] - min;

    return sum;
}

