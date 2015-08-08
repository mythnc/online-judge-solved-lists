/* ACM 499 What's The Frequency, Kenneth?
 * mythnc
 * 2011/11/06 22:05:39   
 * run time: 0.044
 */
#include <stdio.h>

#define MAXARY 52

void printout(int *);
void init(int *);

int main(void)
{
    int letter[MAXARY] = { 0 };
    int c;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            letter[c - 'A']++;
        else if (c >= 'a' && c <= 'z')
            letter[c - 'a' + 26]++;
        else if (c == '\n') {
            printout(letter);
            init(letter);
        }
    }
    return 0;
}

/* printout: print out the max letters */
void printout(int *p)
{
    int i, max;

    /* find the element which has max value */
    for (i = max = 0; i < MAXARY; i++)
        if (p[max] < p[i])
            max = i;

    /* output */
    for (i = 0; i < MAXARY; i++)
        if (p[i] == p[max] && i < 26)
            printf("%c", 'A' + i);
        else if (p[i] == p[max] && i >= 26)
            printf("%c", 'a' + i - 26);
    printf(" %d\n", p[max]);
}

/* init: initialize array to zero */
void init(int *p)
{
    int i;

    for (i = 0; i < MAXARY; i++)
        p[i] = 0;
}

