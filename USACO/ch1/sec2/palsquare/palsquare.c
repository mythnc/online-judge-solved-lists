/*
ID: mythnc2
LANG: C
TASK: palsquare
Palindromic Squares
2011/11/08 11:09:53   
*/
#include <stdio.h>
#include <string.h>

#define MAXN    300
#define MAXCHAR 20
#define TRUE    1
#define FALSE   0

void conversion(int, int, char *);
void reverse(char *);
int pal(char *);

int main (void)
{
    FILE *fin, *fout;
    int base, i;
    char trans[MAXCHAR];
    char number[MAXCHAR];

    fin = fopen("palsquare.in", "r");
    fout = fopen("palsquare.out", "w");

    fscanf(fin, "%d", &base);

    for (i = 0; i < MAXN; i++) {
        conversion(base, (i + 1) * (i + 1), trans);
        /* output */
        if (pal(trans)) {
            conversion(base, i + 1, number);
            reverse(number);
            fprintf(fout, "%s %s\n", number, trans);
        }
    }
    return 0;
}

/* conversion: conver n in base of b save in t */
void conversion(int b, int n, char *t)
{
    int i, mod;
    char map[] = "0123456789ABCDEFGHIJ";

    /* n conversion */
    for (i = 0; n; i++) {
        t[i] = map[n % b];
        n /= b;
    }
    t[i] = '\0';
}

/* reverse: reverse string s */
void reverse(char *s)
{
    int i, j;
    char tmp;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* pal: return TRUE if array t is palindrome,
 * else return FALSE */
int pal(char *t)
{
    int i, j;

    for (i = 0, j = strlen(t) - 1; i < j; i++, j--)
        if (t[i] != t[j])
            return FALSE;

    return TRUE;
}

