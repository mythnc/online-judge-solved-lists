/* ACM 492 Pig-Latin
 * mythnc
 * 2011/11/16 11:50:51   
 * run time: 0.028
 */
#include <stdio.h>
#include <ctype.h>

#define MAXCHAR 1000

void print(char *);

int main(void)
{
    char word[MAXCHAR];
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF)
        if (isalpha(c))
            word[i++] = c;
        else {
            if (i != 0) {
                word[i] = '\0';
                print(word);
                i = 0;
            }
            putchar(c);
        }
    return 0;
}

/* print: print out word in pig-latin form */
void print(char *w)
{
    switch (w[0]) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            printf("%say", w);
            break;
        default:
            printf("%s%cay", w + 1, w[0]);
    }
}

