/* ACM 497 Strategic Defense Initiative
 * mythnc
 * 2012/01/16 20:42:20   
 * run time: WA
 */
#include <stdio.h>

#define MAXN    100000
#define LINEMAX 50

void input(void);
void lis(void);
void binsearch(int, int, int);

int n;
int seq[MAXN], pos[MAXN], v[MAXN];

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
    int len, i, j;
    int out[MAXN];

    len = 0;
    v[len++] = seq[0];
    pos[0] = 0;

    for (i = 1; i < n; i++)
        if (seq[i] > v[len - 1]) {
            v[len] = seq[i];
            pos[i] = len++;
        }
        else
            binsearch(0, len, i);
    /* output */
    printf("Max hits: %d\n", len);
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

