/* ACM 507 Jill Rides Again
 * mythnc
 * 2012/01/18 11:15:29   
 * run time: 0.136
 */
#include <stdio.h>

#define MAXS 20001

void input(void);
void kadane(void);
void output(int);

int list[MAXS];
int n, maxstart, maxend;

int main(void)
{
    int set, i;

    scanf("%d", &set);
    for (i = 1; i <= set; i++) {
        input();
        kadane();
        output(i);
    }

    return 0;
}

/* input: receive input data */
void input(void)
{
    int i;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
        scanf("%d", &list[i]);
}

/* kadane: use kadane algorithm to find the maximum sum */
void kadane(void)
{
    int max, start, end;
    int sum;

    max = 0;
    maxstart = maxend = sum = 0;
    start = 1;
    for (end = 1; end < n; end++) {
        sum += list[end];
        if (sum > max) {
            max = sum;
            maxstart = start;
            maxend = end;
        }
        else if (sum == max && end - start > maxend - maxstart) {
            maxstart = start;
            maxend = end;
        }
        if (sum < 0) {
            sum = 0;
            start = end + 1;
        }
    }
}

/* output: out put result */
void output(int set)
{
    if (maxstart == 0)
        printf("Route %d has no nice parts\n", set);
    else
        printf("The nicest part of route %d is between stops %d and %d\n",
               set, maxstart, maxend + 1);
}

