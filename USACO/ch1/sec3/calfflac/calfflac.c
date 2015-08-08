/*
ID: mythnc2
LANG: C
TASK: calfflac
2012/01/10 16:44:34   
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20010
#define MIN(X, Y) (X <= Y ? X : Y)

int find(int);
int init(int);
int match(int, int, int);
void print(FILE *, int);

char t[MAX];
char s[MAX * 2];
int z[MAX * 2];

int main (void)
{
    FILE *fin, *fout;
    int c, i, n;

    fin = fopen("calfflac.in", "r");
    fout = fopen("calfflac.out", "w");

    i = 0;
    while ((c = fgetc(fin)) != EOF)
        t[i++] = c;
    t[i] = '\0';

    n = find(i);
    print(fout, n);

    fclose(fin);
    fclose(fout);

    return 0;
}

/* find: find maximum palindrome substring */
int find(int n)
{
    int i, mirror, border, center, right;

    n = init(n);

    /* modified z Algorithm */
    center = right = 0;
    for (i = z[0] = 1; i < n; i++)
        if (i > right) {
            z[i] = match(i, i, n);
            center = i;
            right = i + z[i] - 1;
        }
        else {
            mirror = center - (i - center);
            border = right - i + 1;
            if (z[mirror] == border) {
                z[i] = border + match(i - border, i + border, n);
                center = i;
                right = i + z[i] - 1;
            }
            else
                z[i] = MIN(z[mirror], border);
        }

    return n;
}

/* init: initialize s */
int init(int n)
{
    int i, j;

    memset(s, '.', sizeof(s));
    for (i = j = 0; i < n; i++)
        if (isalpha(t[i])) {
            s[2 * j + 1] = tolower(t[i]);
            j++;
        }

    return 2 * j + 1;
}

/* match: from s[a] to left and from s[b] to right
 * do char compare symmetrically */
int match(int a, int b, int n)
{
    int i;

    i = 0;
    while (a - i >= 0 && b + i < n && s[a - i] == s[b + i])
        i++;

    return i;
}

/* print: print out result */
void print(FILE *fout, int n)
{
    int i, j, pos, from, to, k;

    /* find max len */
    for (i = 1, pos = 0; i < n; ++i)
        if (z[i] > z[pos])
            pos = i;

    /* remove '.' */
    i = pos - (z[pos] - 1);
    if (!(i & 1))
        i++;
    for (n = 0; i <= pos + z[pos] - 1; i += 2, n++)
        s[n] = s[i];

    /* print out len */
    fprintf(fout, "%d\n", n);
    /* print out substring */
    for (i = j = from = to = 0; i < strlen(t); i++)
        if (isalpha(t[i]) && tolower(t[i]) == s[j]) {
            from = k = i;
            while (tolower(t[k]) == s[j] && j < n && k < strlen(t)) {
                j++, k++;
                to = k;
                while (!isalpha(t[k]) && k < strlen(t))
                    k++;
            }
            if (j == n)
                break;
            else
                j = from = to = 0;
        }
    for (i = from; i < to; i++)
        fprintf(fout, "%c", t[i]);
    putc('\n', fout);
}

