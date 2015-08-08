/* ACM 468 Key to Success
 * mythnc
 * 2011/10/21 14:43:51   
 * run time: 0.048
 */
#include <stdio.h>
#include <ctype.h>

#define ALPHABET 52
#define LINEMAX  10000

typedef struct letters {
/* c: save letter name,
 * count: counts the letter time */
    char c;
    int count;
} Text;

int line(char *, Text *, int);
int save(Text *, char, int);
void sort(Text *, int);
void swap(Text *, int, int);
void output(char *, Text *, Text *, int);
char findkey(char, Text *, Text *, int);

int main(void)
{
    int n, i, index;
    Text key[ALPHABET], encode[ALPHABET];
    char tmp[LINEMAX];

    scanf("%d", &n);
    getchar();  /* eat '\n' after n */
    for (i = 0; i < n; i++) {
        getchar();  /* eat blank line */
        /* handle line1 */
        fgets(tmp, LINEMAX, stdin);
        index = 0;
        index = line(tmp, key, index);
        sort(key, index);
        /* handle line2 */
        fgets(tmp, LINEMAX, stdin);
        index = 0;
        index = line(tmp , encode, index);
        sort(encode, index);
        /* handle output */
        if (i > 0)
            printf("\n");
        output(tmp, key, encode, index);
    }
    return 0;
}

/* line: find letter in line, return index of target */
int line(char *pt, Text *target, int index)
{
    for (; *pt != '\n'; pt++)
        if (isalpha(*pt))
            index = save(target, *pt, index);
    return index;
}

/* save: find c in t or not, if not, add c in t
 * return count of Text t */
int save(Text *t, char c, int count)
{
    int i;

    for (i = 0; i < count; i++)
        if (t[i].c == c) {   /* if find, return directly */
            t[i].count++;
            return count;
        }
    /* if not find, add it */
    t[count].c = c;
    t[count++].count = 1;
    return count;
}

/* sort: sort pt from high to low */
void sort(Text *pt, int count)
{
    int i, j, max;

    /* selection sort */
    for(i = 0; i < count - 1; i++) {
        max = i;
        for (j = i; j < count; j++)
            if (pt[j].count > pt[max].count)
                max = j;
        if (max != i)
            swap(pt, max, i);
    }
}

/* swap: swap the contents of x and y */
void swap(Text *pt, int x, int y)
{
    Text tmp;

    tmp = pt[x];
    pt[x] = pt[y];
    pt[y] = tmp;
}

/* output: output encode text */
void output(char *pt, Text *key, Text *encode, int count)
{
    for (; *pt != '\0'; pt++)
        if (isalpha(*pt))
            printf("%c", findkey(*pt, key, encode, count));
        else
            printf("%c", *pt);
}

/* findkey: find correspond key and return it */
char findkey(char c, Text *key, Text *encode, int count)
{
    int i;

    for (i = 0; i < count; i++)
        if (encode[i].c == c)
            return key[i].c;
}

