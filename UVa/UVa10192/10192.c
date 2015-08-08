/* ACM 10192 Vacation
 * mythnc
 * 2012/01/09 18:05:11
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR 102 /* 100 + '\n' + '\0' */
#define MAX(X, Y) (X >= Y ? X : Y)

void lcs(char *, char *, int, int);
/* 0~100: totally 100 + 1 */
int list[MAXCHAR - 1][MAXCHAR - 1];

int main(void)
{
    char s1[MAXCHAR], s2[MAXCHAR];
    int set, n1, n2;

    set = 0;
    while (fgets(s1, MAXCHAR, stdin) && s1[0] != '#') {
        fgets(s2, MAXCHAR, stdin);
        n1 = strlen(s1);
        /* eat '\n' */
        s1[n1] = '\0';
        n1--;
        n2 = strlen(s2);
        s2[n2] = '\0';
        n2--;
        lcs(s1, s2, n1, n2);
        /* output */
        printf("Case #%d: you can visit at most %d cities.\n",
        ++set, list[n1][n2]);
    }

    return 0;
}

/* lcs: use DP to find longest len */
void lcs(char *s1, char *s2, int n1, int n2)
{
    int i, j;
    char tmp[MAXCHAR];

    /* start from [1] to save data */
    /* so move data from 0~n to 1~(n + 1) */
    strcpy(tmp, s1);
    strcpy(s1 + 1, tmp);
    strcpy(tmp, s2);
    strcpy(s2 + 1, tmp);

    /* set list[x][0] and list[0][x] to zero */
    for (i = 0; i <= n1; i++)
        list[i][0] = 0;
    for (i = 1; i <= n2; i++)
        list[0][i] = 0;

    for (i = 1; i <= n1; i++)
        for (j = 1; j <= n2; j++)
            if (s1[i] == s2[j])
                list[i][j] = list[i - 1][j - 1] + 1;
            else
                list[i][j] = MAX(list[i - 1][j], list[i][j - 1]);
}

