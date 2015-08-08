/* ACM 10038 Jolly Jumpers
 * mythnc
 * 2011/10/12 21:51:09   
 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int jolly(int);
int wrong(int *);

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 1) {
            scanf("%*d");
            printf("Jolly\n");
            continue;
        }
        if (jolly(--n) == TRUE)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}

/* jolly: judge the sequence is jolly or not */
int jolly(int interval)
{
    int i, x, next;
    int *seq;
    
    seq = (int *)malloc(sizeof(int) * interval);
    for (i = 0; i < interval; i++)         /* initialize seq */
        seq[i] = FALSE;
    scanf("%d", &x);
    for (i = 0; i < interval; i++) {
        scanf("%d", &next);
        x = abs(x - next);
        if (x <= interval && seq[x-1] == FALSE) {
            seq[x-1] = TRUE;
            x = next;
        }
        else                               /* the same value appear twice */
            return wrong(seq);             /* is not a jolly jumper */
    }
    for (i = 0; i < interval; i++)
        if (seq[i] == FALSE) {
            free(seq);
            return FALSE;
        }
    free(seq);
    return TRUE;
}

/* wrong: if not jolly eat string and return FALSE */
int wrong(int *pt)
{
    free(pt);
    while (getchar() != '\n')
        ;
    return FALSE;
}
