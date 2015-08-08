/* ACM 497 Strategic Defense Initiative
 * mythnc
 * 2012/01/16 20:42:20   
 * run time: 0.016
 */
#include <stdio.h>

#define MAXN    100000
#define LINEMAX 50

void input(void);
void lis(void);
void binsearch(int, int, int);

int n;
int seq[MAXN], len[MAXN], pre[MAXN];

int main(void)
{
    int set, i;

    scanf("%d", &set);
    getchar();
    getchar();
    for (i = 0; i < set; i++) {
        input();
        if (i > 0)
            putchar('\n');
        lis();
    }

    return 0;
}

/* input: receive input data */
void input(void)
{
    char line[LINEMAX];

    n = 0;
    while (fgets(line, LINEMAX, stdin) && line[0] != '\n')
        sscanf(line, "%d", &seq[n++]);
}

/* lis: find lis and output */
void lis(void)
{
    int i, j, maxi;
    int out[MAXN];
    /* init */
    for (i = 0; i < n; i++) {
        len[i] = 1;
        pre[i] = -1;
    }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (seq[j] > seq[i] && len[j] < len[i] + 1) {
                len[j] = len[i] + 1;
                pre[j] = i;
            }

    for (i = 1, maxi = 0; i < n; i++)
        if (len[i] > len[maxi])
            maxi = i;

    /* output */
    printf("Max hits: %d\n", len[maxi]);
    i = 0;
    while (1) {
        out[i++] = seq[maxi];
        if (pre[maxi] == -1)
            break;
        maxi = pre[maxi];
    }
    for (j = i - 1; j > -1; j--)
        printf("%d\n", out[j]);
}

