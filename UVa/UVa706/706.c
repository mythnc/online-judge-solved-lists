/* ACM 706 LC-Display
 * mythnc
 * 2011/11/12 21:54:59   
 * run time: 0.032
 */
#include <stdio.h>

#define MAXCHAR 10

void printn(char, int, int);
void space(int);
void right(int);
void middle(int);
void left(int);
void landr(int);

int main(void)
{
    char str[MAXCHAR];
    int n, i, j;

    while (scanf("%d %s", &n, str) && n != 0) {
        for (i = 0; i < 2 * n + 3; i++) {       /* line */
            for (j = 0; str[j] != '\0'; j++) {  /* number */
                if (j > 0)
                    putchar(' ');
                printn(str[j], i, n);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}

/* printn: depend on row value and char c to do output */
void printn(char c, int row, int n)
{
    int col, head, mid, tail;

    col = n + 2;
    head = 0;
    mid = (2 * n + 3) / 2;
    tail = 2 * n + 2;   /* (2 * n + 3) - 1 */
    switch (c) {
        case '1':
            if (row == head || row == mid || row == tail)
                space(col);
            else
                right(col);
            break;
        case '2':
            if (row == head || row == mid || row == tail)
                middle(col);
            else if (row < mid)
                right(col);
            else
                left(col);
            break;
        case '3':
            if (row == head || row == mid || row == tail)
                middle(col);
            else
                right(col);
            break;
        case '4':
            if (row == head || row == tail)
                space(col);
            else if (row < mid)
                landr(col);
            else if (row == mid)
                middle(col);
            else
            right(col);
            break;
        case '5':
            if (row == head || row == mid || row == tail)
                middle(col);
            else if (row < mid)
                left(col);
            else
                right(col);
            break;
        case '6':
            if (row == head || row == mid || row == tail)
                middle(col);
            else if (row < mid)
                left(col);
            else
                landr(col);
            break;
        case '7':
            if (row == head)
                middle(col);
            else if (row == mid || row == tail)
                space(col);
            else
                right(col);
            break;
        case '8':
            if (row == head || row == mid || row == tail)
                middle(col);
            else
                landr(col);
            break;
        case '9':
            if (row == head || row == mid || row == tail)
                middle(col);
            else if (row < mid)
                landr(col);
            else
                right(col);
            break;
        case '0':
            if (row == head || row == tail)
                middle(col);
            else if (row == mid)
                space(col);
            else
                landr(col);
    }
}

/* space: print ' ' */
void space(int n)
{
    while (n--)
        putchar(' ');
}

/* right: print '|' in the rightmost */
void right(int n)
{
    int i;

    for (i = 0; i < n - 1; i++)
        putchar(' ');
    putchar('|');
}

/* middle: print '-' in middle */
void middle(int n)
{
    int i;

    putchar(' ');
    for (i = 1; i < n - 1; i++)
        putchar('-');
    putchar(' ');
}

/* left: print '|' in leftmost */
void left(int n)
{
    int i;

    putchar('|');
    for (i = 1; i < n; i++)
        putchar(' ');
}

/* landr: print '|' in leftmost and rightmost */
void landr(int n)
{
    int i;

    putchar('|');
    for (i = 1; i < n - 1; i++)
        putchar(' ');
    putchar('|');
}

