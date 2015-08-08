/* ACM 105 The Skyline Problem
 * mythnc
 * 2012/01/07 09:19:19   
 * run time: 0.02
 */
#include <stdio.h>

#define MAXH 10000

typedef struct build {
    int s, e, h;
} Build;

void update(Build);
void print(void);

int sky[MAXH];

int main(void)
{
    Build x;

    while (scanf("%d %d %d", &x.s, &x.h, &x.e) == 3)
        update(x);
    print();

    return 0;
}

/* update: update sky line */
void update(Build x)
{
    int i;

    for (i = x.s; i < x.e; i++)
        if (x.h > sky[i])
            sky[i] = x.h;
}

/* print: print out result */
void print(void)
{
    int i, h;

    /* find the first building */
    for (i = h = 0; i < MAXH; i++)
        if (sky[i] != h) {
            printf("%d %d", i, sky[i]);
            h = sky[i];
            break;
        }
    for (i++; i < MAXH; i++)
        if (sky[i] != h) {
            printf(" %d %d", i, sky[i]);
            h = sky[i];
        }
    putchar('\n');
}

