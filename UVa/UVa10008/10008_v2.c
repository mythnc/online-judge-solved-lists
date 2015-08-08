/* ACM 10008 What's Cryptanalysis?
 * mythnc
 * 2012/03/31 22:19:37   
 * run time:
 */
#include <stdio.h>
#include <ctype.h>

typedef struct pair {
    char name;
    int times;
} Pair;

int count;

void add(Pair *, char);
int cmp(const void *, const void *);
void output(Pair *);

int main(void)
{
    int c;
    Pair letters[26];

    scanf("%*d");
    while ((c = getchar()) != EOF)
        if (isupper(c))
            add(letters, c);
        else if (islower(c))
            add(letters, c - 'a' + 'A');
    qsort(letters, count, sizeof(Pair), cmp);
    output(letters);

    return 0;
}

/* add: add char c to Pair */
void add(Pair *pt, char c)
{
    int i;

    /* find the location of char c */
    for (i = 0; i < count; i++)
        if (pt[i].name == c) {
            pt[i].times++;
            return;
        }

    pt[count].name = c;
    pt[count].times = 1;
    count++;
}

/* cmp: for qsort() */
int cmp(const void *a, const void *b)
{
    if (((Pair *)a)->times != ((Pair *)b)->times)
        return ((Pair *)b)->times - ((Pair *)a)->times;
    return ((Pair *)a)->name - ((Pair *)b)->name;
}

/* output: output results */
void output(Pair *pt)
{
    int i;

    for (i = 0; i < count; i++)
        printf("%c %d\n", pt[i].name, pt[i].times);
}

