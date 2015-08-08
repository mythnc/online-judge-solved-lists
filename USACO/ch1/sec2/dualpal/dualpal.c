/*
ID: mythnc2
LANG: C
TASK: dualpal
Dual Palindromes
2011/11/14 20:30:40   
*/
#include <stdio.h>
#include <string.h>

#define MAXCHAR 15
#define TRUE    1
#define FALSE   0

void conversion(int, int, char *);
int pal(char *);

int main (void)
{
    FILE *fin, *fout;
    int n, s, i, j, count;
    char t[MAXCHAR];

    fin = fopen("dualpal.in", "r");
    fout = fopen("dualpal.out", "w");

    fscanf(fin, "%d %d", &n, &s);

    for (i = s + 1; n; i++)
        for (count = 0, j = 2; j < 11; j++) {
            conversion(j, i, t);
            if (pal(t))
                count++;
            if (count > 1) {
                fprintf(fout, "%d\n", i);
                n--;
                break;
            }
        }

    return 0;
}

/* conversion: conver n in base of b,
 * save in t */
void conversion(int b, int n, char *t)
{
    int i, mod;
    char map[] = "0123456789";

    for (i = 0; n; i++) {
        t[i] = map[n % b];
        n /= b;
    }
    t[i] = '\0';
}

/* pal: if t is palindrome return TRUE,
 * else return FALSE */
int pal(char *t)
{
    int i, j;

    for (i = 0, j = strlen(t) - 1; i < j; i++, j--)
        if (t[i] != t[j])
            return FALSE;

    return TRUE;
}

