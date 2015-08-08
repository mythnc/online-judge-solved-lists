/* ACM 231 Testing the CATCHER
 * mythnc
 * 2012/01/15 21:19:58   
 * run time: 0.004
 */
#include <stdio.h>
#define MAXM 10000

void input(void);
int lds(void);
void binsearch(int, int, int);

int n;
int v[MAXM];
int catcher[MAXM];

int main(void)
{
    int set, data;

    set = 0;
    while (scanf("%d", &data) && data != -1) {
        catcher[0] = data;
        if (set > 0)
            putchar('\n');
        printf("Test #%d:\n", ++set);
        input();
        printf("  maximum possible interceptions: %d\n",
               lds());
    }

    return 0;
}

/* input: receive input data
 * and return the number of missile */
void input(void)
{
    n = 1;
    while (scanf("%d", &catcher[n]) && catcher[n] != -1)
        n++;
}

/* lds: return the longest decrement subsequence length */
int lds(void)
{
    int len, i, j;

    len = 0;
    v[len++] = catcher[n - 1];

    for (i = n - 2; i > -1; i--)
        if (catcher[i] > v[len - 1])
            v[len++] = catcher[i];
        else
            binsearch(0, len, i);

    return len;
}

void binsearch(int begin, int end, int index)
{
    int mid;

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (v[mid] == catcher[index])
            return;
        else if (v[mid] > catcher[index])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    
    mid = (begin + end) / 2;
    if (mid == 0 && index == n - 2)
        v[0] = catcher[index];
    else
        v[mid + 1] = catcher[index];
}

