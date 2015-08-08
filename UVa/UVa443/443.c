/* ACM 443 Humble Numbers
 * mythnc
 * 2011/12/11 21:49:31   
 * run time: 0.012
 */
#include <stdio.h>
#include <string.h>

#define MAXN 5842

void precal(int *);
void output(int, int *);

int main(void)
{
    int ans[MAXN];
    int n;

    precal(ans);

    while (scanf("%d", &n) && n != 0)
        output(n, ans);

    return 0;
}

/* precal: previous calculation the answer */
void precal(int *ans)
{
    int t2, t3, t5, t7;
    int p2, p3, p5, p7, count;

    p2 = p3 = p5 = p7 = 0;
    ans[0] = count = 1;
    while (count < MAXN) {
        t2 = ans[p2] * 2;
        t3 = ans[p3] * 3;
        t5 = ans[p5] * 5;
        t7 = ans[p7] * 7;
        /* find the minimal */
        if (t2 <= t3 && t2 <= t5 && t2 <= t7)
            ans[count] = t2;
        else if (t3 < t2 && t3 <= t5 && t3 <= t7)
            ans[count] = t3;
        else if (t5 < t2 && t5 < t3 && t5 <= t7)
            ans[count] = t5;
        else if (t7 < t2 && t7 < t3 && t7 < t5)
            ans[count] = t7;
        /* if same, prime number have to move to next */
        if (t2 == ans[count])
            p2++;
        if (t3 == ans[count])
            p3++;
        if (t5 == ans[count])
            p5++;
        if (t7 == ans[count])
            p7++;

        count++;
    }
}

/* output: print out the answer in the format */
void output(int n, int *ans)
{
    char number[3];

    if (n % 100 < 10 || n % 100 > 20)
        switch (n % 10) {
            case 1:
                strcpy(number, "st");
                break;
            case 2:
                strcpy(number, "nd");
                break;
            case 3:
                strcpy(number, "rd");
                break;
            default:
                strcpy(number, "th");
        }
    else
        strcpy(number, "th");

    printf("The %d%s humble number is %d.\n", n, number, ans[n - 1]);
}

