/* ACM 119 Greedy Gift Givers
 * mythnc
 * 2011/10/25 18:37:46   
 * run time: 0.004
 * same as USACO Greedy Gift Givers (gift1.c)
 */
#include <stdio.h>
#include <string.h>

#define LEN   20
#define N     10

typedef struct group {
    char name[LEN + 1];
    int money;
} People;

int findname(People *, char *);
void eatname(int);
void printout(People *, int);

int main(void)
{
    int n, i, j, k, money, ntake, line;
    char tmp[LEN + 1];
    People person[N];

    line = 0;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%s", person[i].name);
            person[i].money = 0;    /* init */
        }

        for (i = 0; i < n; i++) {
            scanf("%s %d %d", tmp, &money, &ntake);
            if (money == 0 || ntake == 0) {        /* haven't to give money */
                if (ntake > 0)
                    eatname(ntake);
                continue;
            }

            j = findname(person, tmp);             /* the giver name */
            /* giver: the money giver have to pay */
            person[j].money += money % ntake - money;
            for (j = 0; j < ntake; j++) {
                scanf("%s", tmp);
                k = findname(person, tmp);         /* the taker name */
                /* taker: the money taker get */
                person[k].money += money / ntake;
            }
        }
        /* output */
        if (line == 1)
            printf("\n");
        printout(person, n);
        line = 1;
    }
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
void eatname(int n)
{
    while (n--)
        scanf("%*s");
}

/* printout: print out the results */
void printout(People *person, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%s %d\n", person[i].name, person[i].money);
}

