/*
ID: mythnc2
LANG: C
TASK: gift1
Greedy Gift Givers
2011/10/25 18:37:46   
*/
#include <stdio.h>
#include <string.h>

#define LEN   20
#define N     10
/* giver: the money giver have to pay */
#define GIVER(person, money, n)  person.money += money % n - money
/* taker: the money taker get */
#define TAKER(person, money, n)  person.money += money / n

typedef struct group {
    char name[LEN + 1];
    int money;
} People;

int findname(People *, char *);
void eatname(FILE *, int);
void printout(FILE *, People *, int);

int main(void)
{
    FILE *fin, *fout;
    int n, i, j, money, ntake;
    char tmp[LEN + 1];
    People person[N];

    fin = fopen("gift1.in", "r");
    fout = fopen("gift1.out", "w");

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%s", person[i].name);
        person[i].money = 0;    /* init */
    }

    while (1) {
        if (fscanf(fin, "%s", tmp) == EOF) 
            break;
        fscanf(fin, "%d %d", &money, &ntake);
        if (money == 0) {                      /* haven't to give money */
            if (ntake > 0)
                eatname(fin, ntake);
            continue;
        }

        i = findname(person, tmp);             /* the giver name */
        GIVER(person[i], money, ntake);
        for (i = 0; i < ntake; i++) {
            fscanf(fin, "%s", tmp);
            j = findname(person, tmp);         /* the taker name */
            TAKER(person[j], money, ntake);
        }
    }
    /* output */
    printout(fout, person, n);
    return 0;
}

/* findname: find the tmp name in person,
 * return the index of that name */
int findname(People *person, char *tmp)
{
    int i;

    for (i = 0; ; i++)
        if (strcmp(person[i].name, tmp) == 0)
            return i;
}

/* eatname: eat name token */
void eatname(FILE *fin, int n)
{
    while (n--)
        fscanf(fin, "%*s");
}

/* printout: print out the results */
void printout(FILE *fout, People *person, int n)
{
    int i;

    for (i = 0; i < n; i++)
        fprintf(fout, "%s %d\n", person[i].name, person[i].money);
}

