/* ACM 481 What Goes Up
 * mythnc
 * 2012/01/16 09:58:36   
 * run time: 0.044
 */
#include <stdio.h>

#define MAXN 100000

void lis(int);
void binsearch(int, int, int);

int n;
int seq[MAXN], pos[MAXN], v[MAXN];

int main(void)
{

    n = 0;
    while (scanf("%d", &seq[n]) == 1)
        n++;

    lis(n);

    return 0;
}

/* lis: return the last max len position */
void lis(int n)
{
    int len, i, j;
    int out[MAXN];

    len = 0;
    v[len++] = seq[0];
    pos[0] = 0;

    for (i = 1; i < n; i++) {
        if (seq[i] > v[len - 1]) {
            v[len] = seq[i];
            pos[i] = len++;
        }
        else
            binsearch(0, len, i);
    }
    /* output */
    printf("%d\n-\n", len);
    for (i = n - 1, j = len - 1; i > -1 && j > -1; i--)
        if (pos[i] == j) {
            out[j] = seq[i];
            j--;
        }
    for (i = 0; i < len; i++)
        printf("%d\n", out[i]);
}

void binsearch(int begin, int end, int index)
{
    int mid;

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (v[mid] == seq[index]) {
            pos[index] = mid;
            return;
        }
        else if (v[mid] > seq[index])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    
    mid = (begin + end) / 2;
    if (mid == 0 && index == 1) {
        v[0] = seq[index];
        pos[index] = 0;
    }
    else {
        v[mid + 1] = seq[index];
        pos[index] = mid + 1;
    }
}

