/* ACM 10363 Tic Tac Toe
 * mythnc
 * 2012/01/04 14:26:07   
 * run time: 0.012
 */
#include <stdio.h>

#define SQUARE 3
#define TRUE   1
#define FALSE  0 

void input(char (*)[]);
int legal(char (*)[]);

int main(void)
{
    char tic[SQUARE][SQUARE + 1];
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        input(tic);
        if (legal(tic))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

/* input: receive input data */
void input(char (*t)[SQUARE + 1])
{
    int i;

    for (i = 0; i < 3; i++)
        scanf("%s", t[i]);
}

/* legal: if square is legal return TRUE
 * else return FALSE */
int legal(char (*t)[SQUARE + 1])
{
    int counto, countx, linex, lineo;
    int i, j;

    for (counto = countx = i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (t[i][j] == 'O')
                counto++;
            else if (t[i][j] == 'X')
                countx++;
    /* if X - O is not 1 or 0 is illegal */
    if (!(countx - counto == 0 || countx - counto == 1))
        return FALSE;
    /* vertical and horizontal line */
    for (i = lineo = linex = 0; i < 3; i++) {
        if (t[i][0] == t[i][1] && t[i][1] == t[i][2])
            if (t[i][0] == 'O')
                lineo++;
            else if (t[i][0] == 'X')
                linex++;
        if (t[0][i] == t[1][i] && t[1][i] == t[2][i])
            if (t[0][i] == 'O')
                lineo++;
            else if (t[0][i] == 'X')
                linex++;
    }
    /* diagonal line */
    if (t[0][0] == t[1][1] && t[1][1] == t[2][2])
        if (t[1][1] == 'O')
            lineo++;
        else if (t[1][1] == 'X')
            linex++;
    if (t[2][0] == t[1][1] && t[1][1] == t[0][2])
        if (t[1][1] == 'O')
            lineo++;
        else if (t[1][1] == 'X')
            linex++;

    if (lineo > 1 || linex > 2)
        return FALSE;
    if (lineo == 1 && !(linex == 0 && counto == countx))
        return FALSE;
    if (linex == 1 && !(lineo == 0 && countx - counto == 1))
        return FALSE;
    if (linex == 2 && !(lineo == 0 && countx + counto == 9))
        return FALSE;

    return TRUE;
}

