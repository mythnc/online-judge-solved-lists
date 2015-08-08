/*
ID: mythnc2
LANG: C
TASK: beads 
2011/10/27 11:41:05   
*/
#include <stdio.h>
#include <string.h>

#define MAX 360

int firstlen(char *);
void movefirst(char *, int);
char *len(char *, int *, int *);
int backward(char *);
int pairs(int *, int);
int maxvalue(int *, int);

int main(void)
{
    FILE *fin, *fout;
    char bead[MAX];
    char *move;
    int count[MAX];
    int n, i, step;

    /*
    fin = fopen("beads.in", "r");
    fout = fopen("beads.out", "w");
    */
    
    /* test loop */
    while (1) {
    int a = scanf("%d", &n);
        if (a == EOF)
        return 0;
    scanf("%s", bead);

    if ((i = firstlen(bead)) == n) {  /* one color */
        printf("%d\n", i);
        return 0;
    }
    else
        movefirst(bead, i);

    for (move = bead, i = 0; *move; i++) {
        move = len(move, &count[i], &step);
        if (step)
            i++;
    }

    printf("%s\n", bead);   /* test */
    printf("%d\n", pairs(count, i));
    }

    return 0;
}

/* firstlen: count the first length
 * also use this function to count w length */
int firstlen(char *bead)
{
    int i;

    i = 0;
    /* if first char is w, skip over it */
    while (bead[i] == 'w')
        i++;
    if (bead[i] == '\0')   /* all beads is w color */
        return i;

    if (bead[i] == 'b')
        while (bead[i] == 'b' || bead[i] == 'w')
            i++;
    else
        while (bead[i] == 'r' || bead[i] == 'w')
            i++;
    return i;
}

/* movefirst: rearrange string bead,
 * move the first len to last */
void movefirst(char *bead, int n)
{
    int i;
    char tmp[n];

    strncpy(tmp, bead, n);
    for (i = 0; bead[i + n] != '\0'; i++)
        bead[i] = bead[i + n];
    bead[i] = '\0';
    strncat(bead, tmp, n);
}

/* len: count the len of each color bead
 * and return the position after count */
char *len(char *move, int *count, int *step)
{
    int wcount;
    char *head;

    wcount = *count = *step = 0;
    if (*move == 'b')
        while (*move == 'b' || *move == 'w') {
            if (*move == 'w' && wcount == 0) {
                wcount = firstlen(move);
                head = move;
            }
            (*count)++;
            move++;
        }
    else  /* color r */
        while (*move == 'r' || *move == 'w') {
            if (*move == 'w' && wcount == 0) {
                wcount = firstlen(move);
                head = move;
            }
            (*count)++;
            move++;
        }
    /* test */
    printf("w:%d c:%d\n", wcount, *count);
    if (wcount > *count) {
        *step = 1;
        *count -= backward(move);     /* corrected count */
        move = head + wcount;         /* corrected position */
        *++count = wcount;            /* the next count value */
    }
    return move;
}

/* backward: backward pointer to find previous color,
 * which is not w color return the backward steps */
int backward(char *back)
{
    int count;

    count = 0;
    while (*--back == 'w')
        count++;
    return count;
}

/* pairs: sum pairs:
 * last + first, first + second, second + third ...
 * to find the max value
 * return maxvalue() */
int pairs(int *count, int n)
{
    int i, pre, tmp;

    /* test */
    printf("before sum pairs:\n%d", count[0]);
    for (i = 1; i < n; i++)
        printf(" %d", count[i]);
    printf("\n");

    pre = count[0];
    count[0] += count[n - 1];
    for (i = 1; i < n; i++) {
        tmp = count[i];
        count[i] += pre;
        pre = tmp;
    }

    /* test */
    printf("after sum pairs:\n%d", count[0]);
    for (i = 1; i < n; i++)
        printf(" %d", count[i]);
    printf("\n");

    return maxvalue(count, n);
}

/* max: return the max value of count */
int maxvalue(int *count, int n)
{
    int i, max;

    for (i = max = 0; i < n; i++)
        if (max < count[i])
            max = count[i];
    return max;
}

