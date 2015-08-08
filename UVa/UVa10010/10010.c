/* ACM 10010 Where's Waldorf? 
 * mythnc
 * 2011/12/16 12:31:16   
 * run time: 0.008
 */
#include <stdio.h>

#define MAXF  50
#define MAXK  20
#define DIRC  8
#define RANGE(X, Y) X >= 0 && X < maxrow && Y >= 0 && Y < maxcol
#define TRUE  1
#define FALSE 0

void findword(void);
int move(int, int, int);
int sameletter(char, char);

char square[MAXF][MAXF + 1];
char word[MAXK][MAXF + 1];
int maxrow, maxcol, kword;

int main(void)
{
    int n, i, j, set;

    scanf("%d", &n);
    for (i = set = 0; i < n; i++) {
        /* input data */
        scanf("%d %d", &maxrow, &maxcol);
        getchar(); /* eat newline */
        for (j = 0; j < maxrow; j++)
            scanf("%s", square[j]);
        scanf("%d", &kword);
        getchar(); /* eat newline */
        for (j = 0; j < kword; j++)
            scanf("%s", word[j]);
        /* blank line in each set */
        if (set == 1)
            putchar('\n');
        findword();
        set = 1;
    }

    return 0;
}

/* findword: find the word position */
void findword(void)
{
    int i, j, k, find;

    for (i = 0; i < kword; i++) {
        for (find = j = 0; j < maxrow && !find; j++)
            for (k = 0; k < maxcol && !find; k++)
                if (sameletter(word[i][0], square[j][k]))
                    find = move(i, j, k);
        if (find)
            printf("%d %d\n", j, k);
    }
}

/* move: move around from (r, c),
 * if find return TRUE, else return FALSE */
int move(int n, int r, int c)
{
    int mover[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int movec[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int i, j, nextr, nextc;

    for (i = 0; i < DIRC; i++) {
        nextr = r + mover[i];
        nextc = c + movec[i];
        j = 1;
        /* find word from direction i */
        while (word[n][j] != '\0' && RANGE(nextr, nextc)
               && sameletter(word[n][j], square[nextr][nextc])) {
            j++;
            nextr += mover[i];
            nextc += movec[i];
        }
        /* find */
        if (word[n][j] == '\0')
            return TRUE;
    }

    return FALSE;
}

/* sameletter: if the letter is same
 * (regardless of case)
 * return TRUE
 * else return FALSE */
int sameletter(char s, char t)
{
    if (s == t)
        return TRUE;
    /* upper to lower */
    if (s >= 'A' && s <= 'Z')
        s = s - 'A' + 'a';
    if (t >= 'A' && t <= 'Z')
        t = t - 'A' + 'a';

    if (s == t)
        return TRUE;
    return FALSE;
}

