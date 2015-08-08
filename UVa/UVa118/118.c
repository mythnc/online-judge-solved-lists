/* ACM 118 Mutant Flatworld Explorers
 * mythnc
 * 2011/12/05 14:23:59   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXCO   51  /* 0 to 50 */
#define MAXCHAR 101
#define TRUE    1
#define FALSE   0
#define RANGE(X, Y) X >= 0 && X <= Y

typedef struct robot {
    int row, col, dir;
} Robot;

int ctoi(char);
int takeorder(Robot *, char *, int (*)[]);
int changedir(int);
void output(Robot);

int row, col;

int main(void)
{
    int fall;
    int mark[MAXCO][MAXCO] = { FALSE };
    char dir;
    char order[MAXCHAR];
    Robot ro;

    scanf("%d %d", &col, &row);
    while (scanf("%d %d %c", &ro.col, &ro.row, &dir) == 3) {
        getchar(); /* eat newline */
        scanf("%s", order);
        getchar(); /* eat newline */
        ro.dir = ctoi(dir);
        fall = takeorder(&ro, order, mark);
        output(ro);
        if (fall)
            printf(" LOST");
        putchar('\n');
    }

    return 0;
}

/* coti: convert c to correspond int
 * and return it */
int ctoi(char c)
{
    switch (c) { /* NESW <=> 0123 */
        case 'N':
            return 0;
        case 'E':
            return 1;
        case 'S':
            return 2;
        case 'W':
            return 3;
    }
}

/* takeorder: take the order,
 * do the correspond action,
 * and return fall or not */
int takeorder(Robot *ro, char *order, int (*mark)[MAXCO])
{
    int i, fall, nextr, nextc;
    int movec[] = {0, 1, 0, -1};
    int mover[] = {1, 0, -1, 0};

    for (fall = FALSE, i = 0; order[i] != '\0'; i++) {
        switch (order[i]) {
            case 'R':
                ro->dir = changedir(ro->dir + 1);
                break;
            case 'L':
                ro->dir = changedir(ro->dir - 1);
                break;
            case 'F':
                nextr = ro->row + mover[ro->dir];
                nextc = ro->col + movec[ro->dir];
                if (RANGE(nextc, col) && RANGE(nextr, row)) {
                    ro->col = nextc;
                    ro->row = nextr;
                }
                else if (!mark[ro->row][ro->col]){
                    mark[ro->row][ro->col] = TRUE;
                    fall = TRUE;
                }
        }
        if (fall)
            return fall;
    }

    return fall;
}

/* changedir: change the direction of ro */
int changedir(int dir)
{
    if (dir > 3)
        return dir % 4;
    else if (dir < 0)
        return dir + 4;
    return dir;
}

/* output: the information of robot */
void output(Robot ro)
{
    char s[] = "NESW";

    printf("%d %d %c", ro.col, ro.row, s[ro.dir]);
}

