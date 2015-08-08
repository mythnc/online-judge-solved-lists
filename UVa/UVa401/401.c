/* ACM 401 Palindromes
 * mythnc
 * 2011/11/07 16:22:59   
 * run time: 0.016
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR 21
#define TRUE    1
#define FALSE   0

int reverse(char *, char *);
int mirror(char *, char *);
int valid(char, char *, int);

int main(void)
{
    char str[MAXCHAR], t[MAXCHAR];

    while (scanf("%s", str) != EOF)
        if (reverse(str, t))
            if (mirror(str, t))
                printf("%s -- is a mirrored palindrome.\n\n", str);
            else
                printf("%s -- is a regular palindrome.\n\n", str);
        else
            if (mirror(str, t))
                printf("%s -- is a mirrored string.\n\n", str);
            else
                printf("%s -- is not a palindrome.\n\n", str);
    return 0;
}

/* reverse: save the reverse of s in t,
 * if t and s are palindrome to each other,
 * return TRUE, else return FALSE */
int reverse(char *s, char *t)
{
    int i, j;

    for (i = 0, j = strlen(s) - 1; i < strlen(s); i++, j--)
        t[i] = s[j];
    t[i] = '\0';

    if (strcmp(s, t) == 0)
        return TRUE;
    return FALSE;
}

/* mirror: if s is a mirror string
 * return TRUE, else return FALSE */
int mirror(char *s, char *t)
{
    char map[21] = {'A', 'E', 'H', 'I', 'J', 'L', 'M', 'O', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '5',
                    '8'};
    char key[21] = {'A', '3', 'H', 'I', 'L', 'J', 'M', 'O', '2', 'T',
                    'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', 'Z',
                    '8'};
    char m[MAXCHAR];
    int index, i;

    for (i = 0; i < strlen(t); i++)
        if ((index = valid(t[i], map, 21)) >= 0)
            m[i] = key[index];
        else
            return FALSE;
    m[i] = '\0';

    if (strcmp(s, m) == 0)
        return TRUE;
    return FALSE;
} 

/* valid: return the index of char c in map,
 * if c is a valid char, else return -1 */
int valid(char c, char *map, int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (c == map[i])
            return i;

    return -1;
}

