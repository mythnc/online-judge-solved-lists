/* ACM 640 Ugly Numbers
 * mythnc
 * 2011/12/11 21:14:58   
 * version v2
 * Dynamic programming 
 * run time:
 */
#include <stdio.h>

#define MAXN 1500

int main(void)
{
    int ans[MAXN];
    int p2, p3, p5, count;
    int tmp2, tmp3, tmp5, value;

    p2 = p3 = p5 = 0;
    ans[0] = count = 1;
    while (count < MAXN) {
        tmp2 = ans[p2] * 2;
        tmp3 = ans[p3] * 3;
        tmp5 = ans[p5] * 5;
        /* find the minimal */
        if (tmp2 <= tmp3 && tmp2 <= tmp5)
            ans[count++] = tmp2;
        else if (tmp3 < tmp2 && tmp3 <= tmp5)
            ans[count++] = tmp3;
        else if (tmp5 < tmp2 && tmp5 < tmp3)
            ans[count++] = tmp5;
        /* if same, prime have to move to next element */
        if (tmp2 == ans[count - 1])
            p2++;
        if (tmp3 == ans[count - 1])
            p3++;
        if (tmp5 == ans[count - 1])
            p5++;
    }

    printf("The 1500'th ugly number is %d.\n", ans[count - 1]);

    return 0;
}

