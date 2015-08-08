/*
ID: mythnc2
LANG: C
TASK: namenum
Name That Number
2011/11/07 21:10:16   
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN    5000
#define MAXCHAR 12
#define TRUE    1
#define FALSE   0

typedef struct name {
    long long number;
    char name[MAXCHAR];
} Name;

int screen(char *);
void copy(Name *, char *);
void sort(Name *, int);
int cton(char);
int find(long long, Name *, int);
void printout(FILE *, int, Name *, int);

int main (void)
{
    FILE *fin, *fout, *fdict;
    char str[MAXCHAR + 1];
    Name cow[MAXN];
    int count, index;
    long long serial;

    fin = fopen("namenum.in", "r");
    fout = fopen("namenum.out", "w");
    fdict = fopen("dict.txt", "r");

    count = 0;
    while (fscanf(fdict, "%s", str) != EOF) {
        if (screen(str))
            continue;
        copy(&cow[count++], str);
        sort(cow, count);
    }

    fscanf(fin, "%lld", &serial);

    if ((index = find(serial, cow, count)) > -1)
        printout(fout, index, cow, count);
    else
        fprintf(fout, "NONE\n");

    return 0;
}

/* screen: if letter has Q or Z,
 * jump over it */
int screen(char *s)
{
    for (; *s != '\0'; s++)
        if (*s == 'Q' || *s == 'Z')
            return TRUE;

    return FALSE;
}

/* copy: copy the letter and number of s
 * to cow */
void copy(Name *cow, char *s)
{
    int i;

    /* copy letters */
    strcpy(cow->name, s);
    /* make letter to number */
    for (cow->number = i = 0; s[i] != '\0'; i++) {
        if (i > 0)
            cow->number *= 10;
        cow->number += cton(s[i]);
    }
}

/* sort: insertion sort array cow */
void sort(Name *cow, int n)
{
    int i;
    Name tmp;

    if (n < 2)
        return;

    tmp = cow[n - 1];
    for (i = n - 2; i > -1; i--)
        if (cow[i].number > tmp.number) {
            cow[i + 1] = cow[i];
            if (i == 0)
                cow[i] = tmp;
        }
        else {
            cow[i + 1] = tmp;
            break;
        }
}

/* cton: cast char to number */
int cton(char c)
{
    char letter[24] = {'A', 'B', 'C',
                       'D', 'E', 'F',
                       'G', 'H', 'I',
                       'J', 'K', 'L',
                       'M', 'N', 'O',
                       'P', 'R', 'S',
                       'T', 'U', 'V',
                       'W', 'X', 'Y'};
    int i;

    for (i = 0; i < 24; i++)
        if (c == letter[i])
            return 2 + i / 3;
}


/* find: find number in array cow
 * if find return index,
 * else return -1 */
int find(long long number, Name *cow, int n)
{
    int head, mid, tail;

    head = 0;
    tail = n - 1;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (cow[mid].number < number)
            head = mid + 1;
        else if (cow[mid].number > number)
            tail = mid - 1;
        else
            return mid;
    }

    return -1;
}

/* printout: print out result */
void printout(FILE *f, int i, Name *cow, int n)
{
    /* find the first same value number */
    while (cow[i - 1].number == cow[i].number && i - 1 >= 0)
        i--;
    /* print out */
    fprintf(f, "%s\n", cow[i].name);
    while (cow[i + 1].number == cow[i].number && i + 1 < n) {
        i++;
        fprintf(f, "%s\n", cow[i].name);
    }
}

