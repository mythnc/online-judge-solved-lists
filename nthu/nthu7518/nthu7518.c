#include <stdio.h>
#include <string.h>

#define MAXC 21
#define MAXW 5000

int is_palindrome(char (*stack)[MAXC], int top);

int main(void)
{
    int c, i, top;
    char word[MAXC];
    char stack[MAXW][MAXC];

    i = top = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\n':
                word[i] = '\0';
                i = 0;
                strcpy(stack[top++], word);
                if (is_palindrome(stack, top))
                    printf("YES\n");
                else
                    printf("NO\n");
                top = 0;
                break;
            case ' ':
                word[i] = '\0';
                i = 0;
                strcpy(stack[top++], word);
                break;
            default:
                word[i++] = c;
        }
    }
    return 0;
}

int is_palindrome(char (*stack)[MAXC], int top)
{
    int i, j;

    for (i = 0, j = top - 1; i < j; i++, j--) {
        if (strcmp(stack[i], stack[j]) != 0)
            return 0;
    }
    return 1;
}

