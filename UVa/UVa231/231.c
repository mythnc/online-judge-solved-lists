/* ACM 231 Testing the CATCHER
 * mythnc
 * 2012/01/15 21:19:58   
 * run time: 0.004
 */
#include <stdio.h>

int input(int *);
int lds(int *, int);

#define MAXM 10000

int main(void)
{
    int set, data;
    int catcher[MAXM];

    set = 0;
    while (scanf("%d", &data) && data != -1) {
        catcher[0] = data;
        if (set > 0)
            putchar('\n');
        printf("Test #%d:\n", ++set);
        printf("  maximum possible interceptions: %d\n",
               lds(catcher, input(catcher)));
    }

    return 0;
}

/* input: receive input data
 * and return the number of missile */
int input(int *catcher)
{
    int i;

    i = 1;
    while (scanf("%d", &catcher[i]) && catcher[i] != -1)
        i++;

    return i;
}

/* lds: return the longest decrement subsequence length */
int lds(int *catcher, int n)
{
    int len[MAXM];
    int i, j, maxlen;

    for (i = 0; i < n; i++)
        len[i] = 1;

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (catcher[j] < catcher[i] && len[j] < len[i] + 1)
                len[j] = len[i] + 1;
                
    for (i = maxlen = 0; i < n; i++)
        if (len[i] > maxlen)
            maxlen = len[i];

    return maxlen;
}

