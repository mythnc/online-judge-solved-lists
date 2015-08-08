/* ACM 10258 Contest Scoreboard
 * mythnc
 * 2012/01/11 23:07:41   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

#define LINEMAX 25
#define MAXP 13
#define MAXC 100

typedef struct contestant {
    int num, solved, penalty;
    int tried[MAXP], ac[MAXP];
} Contestant;

typedef enum {FALSE = 0, TRUE} bool;

int input(Contestant *);
int find(Contestant *, int, int);
int cmp(const void *, const void *);
void output(Contestant *, int);

int main(void)
{
    Contestant con[MAXC];
    int set, i, n;

    scanf("%d", &set);
    getchar();
    getchar();
    for (i = 0; i < set; i++) {
        if (i > 0)
            putchar('\n');
        n = input(con);
        qsort(con, n, sizeof(Contestant), cmp);
        output(con, n);
    }

    return 0;
}

/* input: receive input datas */
int input(Contestant *con)
{
    int num, prob, time, n, pos;
    char sub;
    char line[LINEMAX];

    n = 0;
    while (fgets(line, LINEMAX, stdin)) {
        if (strlen(line) <= 1) /* blank line */
            break;
        sscanf(line, "%d %d %d %c", &num, &prob, &time, &sub);
        pos = find(con, num, n);
        if (pos == -1) {
            /* add and init */
            con[n].num = num;
            con[n].solved = con[n].penalty = 0;
            memset(con[n].tried, 0, MAXP);
            memset(con[n].ac, FALSE, MAXP);
            pos = n++;
        }
        if (sub == 'C' && !con[pos].ac[prob - 1]) {
            con[pos].solved++;
            con[pos].penalty += time + con[pos].tried[prob - 1];
            con[pos].ac[prob - 1] = TRUE;
        }
        else if (sub == 'I' && !con[pos].ac[prob - 1])
            con[pos].tried[prob - 1] += 20;
    }

    return n;
}

/* find: if num in con return it's position
 * else retrn -1 */
int find(Contestant *con, int num, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (con[i].num == num)
            return i;

    return -1;
}

/* cmp: for qsort() */
int cmp(const void *a, const void *b)
{
    if (((Contestant *)a)->solved != ((Contestant *)b)->solved)
        return ((Contestant *)b)->solved - ((Contestant *)a)->solved;
    else if (((Contestant *)a)->penalty != ((Contestant *)b)->penalty)
        return ((Contestant *)a)->penalty - ((Contestant *)b)->penalty;
    else
        return ((Contestant *)a)->num - ((Contestant *)b)->num;
}

/* output: output results */
void output(Contestant *con, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d %d %d\n", con[i].num, con[i].solved, con[i].penalty);
}

