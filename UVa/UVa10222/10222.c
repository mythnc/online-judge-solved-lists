/* ACM 10222 Decode the Mad man
 * mythnc
 * 2011/11/13 14:52:11   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char key[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int map[256];
    int i, c;
    /* mapping */
    for (i = 0; i < strlen(key); i++)
        map[key[i]] = key[i - 2];

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            putchar(c);
            continue;
        }
        if (c >= 'A' && c <= 'Z')  /* upper case */
            c = c - 'A' + 'a';
        putchar(map[c]);
    }
    return 0;
}

