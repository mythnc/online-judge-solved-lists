/* ACM 10038 Jolly Jumpers
 * mythnc
 * 2012/03/31 21:03:04
 * run time: 0.008
 */
#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE = 0, TRUE} bool;

bool jolly(int);

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 1) {
            scanf("%*d");
            printf("Jolly\n");
            continue;
        }
        if (jolly(--n))
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}

/* jolly: judge the sequence is jolly or not */
bool jolly(int interval)
{
    int i, x, next;
    bool *seq;

    seq = (bool *)malloc(sizeof(bool) * interval);
    for (i = 0; i < interval; i++)         /* initialize seq */
        seq[i] = FALSE;
    scanf("%d", &x);
    for (i = 0; i < interval; i++) {
        scanf("%d", &next);
        x = abs(x - next);
        /* x have to appear only once or not be a jolly jumper*/
        if (x > 0 && x <= interval && seq[x-1] == FALSE) {
            seq[x-1] = TRUE;
            x = next;
        }
        else {  /* eat remain input string */
            while (getchar() != '\n')
                ;
            /* free(seq); can not free or runtime error */
            return FALSE;
        }
    }
    for (i = 0; i < interval; i++)
        if (seq[i] == FALSE) {
            free(seq);
            return FALSE;
        }
    free(seq);
    return TRUE;
}

