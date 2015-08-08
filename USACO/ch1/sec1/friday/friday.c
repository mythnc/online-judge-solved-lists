/*
ID: mythnc2
LANG: C
TASK: friday
Friday the Thirteenth
2011/10/26 19:37:31   
*/
#include <stdio.h>

#define MONTHS      12
#define FIRSTYEAR 1900
#define WEEK         7

int leap(int);

int main (void)
{
    FILE *fin, *fout;
    int n, i, j, day;
    int thirteen[WEEK] = { 0 };
    int month[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    enum Months {JAN, FEB};

    fin = fopen("friday.in", "r");
    fout = fopen("friday.out", "w");

    fscanf(fin, "%d", &n);

    /* simplify months */
    for (i = 0; i < MONTHS; i++)
        month[i] %= WEEK;

    for (day = 1 + 12, i = 0; i < n; i++) {
        if (i > 0)       /* DEC/13 + 31 = JAN/13 */
            day += month[j];
        day %= WEEK;
        thirteen[day]++;
        for (j = JAN; j < MONTHS - 1; j++) {
            day += month[j];
            if (j == FEB && leap(i))
                day++;
            day %= WEEK;
            thirteen[day]++;
        }
    }
    /* printout: from sat to fri */
    fprintf(fout, "%d", thirteen[WEEK - 1]);
    for (i = 0; i < WEEK - 1; i++)
        fprintf(fout, " %d", thirteen[i]);
    fprintf(fout, "\n");
    return 0;
}

/* leap: calculate the year is a leap year or not
 * return 1 if is, 0 if is not */
int leap(int i)
{
    int year;

    year = FIRSTYEAR + i;
    return year % 4 == 0 && year % 100 != 0
           || year % 400 == 0;
}

