/* ACM 10194 Football (aka Soccer)
 * mythnc
 * 2012/01/11 16:12:21   
 * run time: 0.008
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXRACEN 110
#define MAXTEAMN 40
#define MAXTEAM  30

typedef struct team {
    char name[MAXTEAMN];
    int pt, win, tie, lose;
    /* game played, goal diff, goal score, goal against */
    int gp, gd, gs, ga;
} Team;

int input(Team *, char *);
int findteam(char *, Team *, int);
void updateteam(Team *, int, int);
void output(Team *, int, char *);
int cmp(const void *, const void *);

int main(void)
{
    char racename[MAXRACEN];
    int nrace, i;
    int nteam;
    Team t[MAXTEAM];

    scanf("%d", &nrace);
    getchar(); /* eat '\n' */
    for (i = 0; i < nrace; i++) {
        if (i > 0)
            putchar('\n');
        nteam = input(t, racename);
        qsort(t, nteam, sizeof(Team), cmp);
        output(t, nteam, racename);
    }

    return 0;
}

/* input: receive input datas */
int input(Team *t, char *racename)
{
    int nteam, ngame, g1, g2, t1, t2;
    int i;
    char team1[MAXTEAMN], team2[MAXTEAMN];
    /* eat racename */
    fgets(racename, MAXRACEN, stdin);
    scanf("%d", &nteam);
    getchar(); /* eat '\n' */
    /* eat teamname */
    for (i = 0; i < nteam; i++) {
        scanf("%[^\n]\n", t[i].name);
        /* init */
        t[i].pt = t[i].win = t[i].tie = t[i].lose
        = t[i].gp = t[i].gd = t[i].gs = t[i].ga = 0;
    }
    scanf("%d", &ngame);
    getchar(); /* eat '\n' */
    /* eat game played */
    while (ngame--) {
        scanf("%[^#]#%d@%d#%[^\n]\n", team1, &g1, &g2, team2);
        t1 = findteam(team1, t, nteam);
        t2 = findteam(team2, t, nteam);
        updateteam(&t[t1], g1, g2);
        updateteam(&t[t2], g2, g1);
    }

    return nteam;
}

/* findteam: return corresponded team number with s */
int findteam(char *s, Team *t, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (strcmp(s, t[i].name) == 0)
            return i;
}

/* updateteam: update team data */
void updateteam(Team *t, int g1, int g2)
{
    t->gp++;
    if (g1 > g2) {
        t->win++;
        t->pt += 3;
    }
    else if (g1 == g2) {
        t->tie++;
        t->pt += 1;
    }
    else
        t->lose++;
    t->gs += g1;
    t->ga += g2;
    t->gd = t->gs - t->ga;
}

/* cmp: for qsort() */
int cmp(const void *a, const void *b)
{
    if (((Team *)a)->pt != ((Team *)b)->pt)
        return ((Team *)b)->pt - ((Team *)a)->pt;
    else if (((Team *)a)->win != ((Team *)b)->win)
        return ((Team *)b)->win - ((Team *)a)->win;
    else if (((Team *)a)->gd != ((Team *)b)->gd)
        return ((Team *)b)->gd - ((Team *)a)->gd;
    else if (((Team *)a)->gs != ((Team *)b)->gs)
        return ((Team *)b)->gs - ((Team *)a)->gs;
    else if (((Team *)a)->gp != ((Team *)b)->gp)
        return ((Team *)a)->gp - ((Team *)b)->gp;
    else
        return strcasecmp(((Team *)a)->name, ((Team *)b)->name);
}

/* output: output results */
void output(Team *t, int n, char *racename)
{
    int i;

    printf("%s", racename);
    for (i = 0; i < n; i++)
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
               i + 1, t[i].name, t[i].pt, t[i].gp, t[i].win,
               t[i].tie, t[i].lose, t[i].gd, t[i].gs, t[i].ga);
}

