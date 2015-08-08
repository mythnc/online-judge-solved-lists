/* ACM 102 Ecological Bin Packing
 * mythnc
 * 2011/10/14 19:22:33   
 * run time: 0.028
 */
#include <stdio.h>

#define MAXARY 6  /* six permutations */
#define BIN    3

int findmax(int *);
void output(int *);

int main(void)
{
    int b, c, g, i;
    /* cmp counts bottles which don't have to move */
    /* each element to a permutation */
    int cmp[MAXARY]; 

    i = 0;
    while (scanf("%d %d %d", &b, &g, &c) == 3) {
        switch (i++) {
            case 0:
                cmp[0] = cmp[1] = b;
                cmp[2] = cmp[3] = c;
                cmp[4] = cmp[5] = g;
                break;
            case 1:
                cmp[0] += c;
                cmp[1] += g;
                cmp[2] += b;
                cmp[3] += g;
                cmp[4] += b;
                cmp[5] += c;
                break;
            case 2:
                cmp[0] += g;
                cmp[1] += c;
                cmp[2] += g;
                cmp[3] += b;
                cmp[4] += c;
                cmp[5] += b;
                /* sum of element 0, 3, 4 is the total bottles */
                output(cmp);
                i = 0;
        }
    }
    return 0;
}

/* findmax: find the max element of s */
int findmax(int *s)
{
    int i, max;

    for (max = i = 0; i < MAXARY; i++)
        if (s[i] > s[max])
            max = i;
    return max;
}

/* output: output result */
void output(int *s)
{
    int i = findmax(s);
    char p[MAXARY][BIN + 1] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    int result[MAXARY] = {s[3]+s[4],
                          s[2]+s[5],
                          s[1]+s[5],
                          s[0]+s[4],
                          s[0]+s[3],
                          s[1]+s[2]};

    printf("%s %d\n", p[i], result[i]);
}

