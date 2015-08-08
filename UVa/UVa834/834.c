/* ACM 834 Continued Fractions
 * mythnc
 * 2011/12/06 12:05:34   
 * run time: 0.012
 */
#include <stdio.h>

#define MAXK 1000

int cal(int, int, int *, int);
void print(int *, int);

int main(void)
{
    int a, b, count;
    int answer[MAXK];

    while (scanf("%d %d", &a, &b) == 2) {
        count = 0;
        if (a < b)
            answer[count++] = 0;
        count = cal(a, b, answer, count);
        print(answer, count);
    }

    return 0;
}

/* cal: find n and save it in ans
 * return the numbers */
int cal(int a, int b, int *ans, int count)
{
    while (a != 0 && b != 0)
        if (a > b) {
            ans[count++] = a / b;
            a %= b;
        }
        else {
            ans[count++] = b / a;
            b %= a;
        }

    return count;
}

/* print: print out result */
void print(int *ans, int n)
{
    int i;

    if (n == 1) {
        printf("[%d]\n", ans[0]);
        return;
    }
    printf("[%d;%d", ans[0], ans[1]);
    for (i = 2; i < n; i++) {
        printf(",%d", ans[i]);
    }
    printf("]\n");
}

