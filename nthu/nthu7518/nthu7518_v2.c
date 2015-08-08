#include <stdio.h>
#include <string.h>

#define MAXC 21
#define MAXW 5000

int is_palindrome(char (*stack)[MAXC], int top);

int main(void)
{
    int top;
    char c;
    char stack[MAXW][MAXC];

    top = 0;
    while (scanf("%s%c", stack[top++], &c) == 2) {
        if (c == '\n') {
            if (is_palindrome(stack, top))
                printf("YES\n");
            else
                printf("NO\n");
            top = 0;
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

