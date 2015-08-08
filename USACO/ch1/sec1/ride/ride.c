/*
ID: mythnc2
LANG: C
TASK: ride
Your Ride Is Here
*/
#include <stdio.h>

#define MAXARY 10

int product(char *);

int main(void)
{
    FILE *fin, *fout;
    char comet[MAXARY], group[MAXARY];

    fin = fopen("ride.in", "r");
    fout = fopen("ride.out", "w");

    fscanf(fin, "%s\n", comet);
    fscanf(fin, "%s\n", group);

    if (product(comet) == product(group))
        fprintf(fout, "GO\n");
    else
        fprintf(fout, "STAY\n");
    return 0;
}

/* product: return the product mod 47 of letters */
int product(char *ary)
{
    int p;

    p = 1;
    while (*ary) {
        p *= (*ary - 'A' + 1);
        p %= 47;
        ary++;
    }
    return p;
}

