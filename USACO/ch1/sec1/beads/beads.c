/*
ID: mythnc2
LANG: C
TASK: Beads
Broken Necklace
2011/10/27 11:41:05   
*/
#include <stdio.h>
#include <string.h>

#define MAXARY 360

typedef struct record{
    int count;
    char *head, *tail;
} Record;

int firstlen(char *);
void movefirst(char *, int);
char *len(char *, Record *, int *);
int backward(char *);
int maxvalue(Record *, int);
int pairs(Record *, Record);
int reverse(char *, char *);

int main(void)
{
    FILE *fin, *fout;
    char bead[MAXARY];
    char *move;
    Record rec[MAXARY];
    int n, i, step;

    fin = fopen("beads.in", "r");
    fout = fopen("beads.out", "w");
    
    fscanf(fin, "%d", &n);
    fscanf(fin, "%s", bead);

    if ((i = firstlen(bead)) == n) {  /* one color */
        fprintf(fout, "%d\n", i);
        return 0;
    }
    else
        movefirst(bead, i);

    for (move = bead, i = 0; *move; i++) {
        move = len(move, &rec[i], &step);
        if (step)
            i++;
    }

    if (i < 3)
        fprintf(fout, "%d\n", rec[0].count + rec[1].count);
    else
        fprintf(fout, "%d\n", maxvalue(rec, i));

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
char *len(char *move, Record *rec, int *step)
{
    int wcount;
    char *w;

    wcount = rec->count = *step = 0;
    rec->head = move;
    if (*move == 'b')
        while (*move == 'b' || *move == 'w') {
            if (*move == 'w' && wcount == 0) {
                wcount = firstlen(move);
                w = move;
            }
            rec->count++;
            move++;
        }
    else  /* color r */
        while (*move == 'r' || *move == 'w') {
            if (*move == 'w' && wcount == 0) {
                wcount = firstlen(move);
                w = move;
            }
            rec->count++;
            move++;
        }

    if (wcount > rec->count) {
        *step = 1;
        rec->count -= backward(move); /* corrected count */
        move = w + wcount;            /* corrected position */
        rec->tail = w;
        (++rec)->count = wcount;      /* the next count value */
        rec->head = w;
    }
    rec->tail = move;
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

/* maxvalue: find the max element
 * if max is not only one, judge them sequentially
 * return the biggest count of this element 
 * and its adjacence */
int maxvalue(Record *rec, int n)
{
    int i, max, count, tmp;
    int index[MAXARY];

    for (max = i = 0; i < n; i++)
        if (rec[max].count < rec[i].count)
            max = i;
    /* find the number of max */
    for (count = i = 0; i < n; i++)
        if (rec[max].count == rec[i].count)
            index[count++] = i;

    for (max = i = 0; i < count; i++) {
        if (index[i] == 1)
            tmp = pairs(&rec[n - 1], rec[2]) + rec[0].count;
        else if (index[i] == 0)
            tmp = pairs(&rec[n - 2], rec[1]) + rec[0].count;
        else if (index[i] == n - 1)
            tmp = pairs(&rec[n - 3], rec[0]) + rec[n - 1].count;
        else
            tmp = pairs(&rec[index[i] - 2], rec[index[i] + 1])
                   + rec[index[i]].count;
        if (tmp > max)
            max = tmp;
    }
    return max;
}

/* pairs: recalculate pre and next len
 * return the largest */
int pairs(Record *pre, Record next)
{
    int pv, nv;

    nv = firstlen(next.head);
    pv = reverse(pre->head, pre[1].tail);

    return nv > pv ? nv : pv;
}

/* reverse: reverse the beads before max,
 * recalulate it's len and return it */
int reverse(char *head, char *tail)
{
    char seq[MAXARY];
    char *move;
    int i;

    for (i = 0, move = tail - 1; move > head - 1; move--)
        seq[i++] = *move;
    seq[i] = '\0';

    return firstlen(seq);
}

