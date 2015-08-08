/* ACM 713 Adding Reversed Numbers
 * mythnc
 * 2011/12/02 12:34:53   
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>

#define MAXD 201

void ignorezero(char *, int);
int bigsum(char (*)[], int *);
void print(int *, int);

int main(void)
{
    char v[2][MAXD];
    int sum[MAXD];
    int i, digit;

    scanf("%*d");
    while (scanf("%s %s", v[0], v[1]) == 2) {
        for (i = 0; i < 2; i++)
            ignorezero(v[i], strlen(v[i]) - 1);
        memset(sum, 0, sizeof(sum));
        digit = bigsum(v, sum);
        print(sum, digit);
    }

    return 0;
}

/* ignorezero: cutting of trailing zero */
void ignorezero(char *s, int i)
{
    while (s[i] == '0')
        i--;

    s[i + 1] = '\0';
}

/* bigsum: do v[0] + v[1] = sum,
 * return sum's digit */
int bigsum(char (*v)[MAXD], int *sum)
{
    int i, j;

    for (i = 0; i < strlen(v[0]) && i < strlen(v[1]); i++)
        sum[i] += v[0][i] - '0' + v[1][i] - '0';
    for (; i < strlen(v[0]); i++)
        sum[i] += v[0][i] - '0';
    for (; i < strlen(v[1]); i++)
        sum[i] += v[1][i] - '0';
    /* carry */
    for (j = 0; j < i; j++)
        if (sum[j] > 9) {
            sum[j + 1] += sum[j] / 10;
            sum[j] %= 10;
        }

    if (sum[j] != 0)
        return j + 1;
    return j;
}

/* print: print out result */
void print(int *sum, int n)
{
    int i;
    /* do not print out leading zeros */
    for (i = 0; sum[i] == 0; i++)
        ;
    for (; i < n; i++)
        printf("%d", sum[i]);
    putchar('\n');
}

