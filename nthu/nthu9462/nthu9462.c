#include <stdio.h>
#include <string.h>

#define STRLEN 1100

int valid(char *s);

int main(void)
{
    int n, i;
    char s[STRLEN];
    
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        fgets(s, STRLEN, stdin);
        if (strlen(s) == 1 || valid(s)) {
            printf("Case %d: Yes\n", i + 1);
        }
        else {
            printf("Case %d: No\n", i + 1);
        }
    }
    return 0;
}

int valid(char *s)
{
    char t[STRLEN];
    int i ,top;

    for (i = top = 0; i < strlen(s)-1; i++) {
        switch (s[i]) {
            case '{':
            case '[':
            case '<':
            case '(':
                t[top++] = s[i];
                break;
            case '}':
                if (top == 0 || t[top-1] != '{') {
                    return 0;
                }
                --top;
                break;
            case ')':
                if (top == 0 || t[top-1] != '(') {
                    return 0;
                }
                --top;
                break;
            case '>':
                if (top == 0 || t[top-1] != '<') {
                    return 0;
                }
                --top;
                break;
            case ']':
                if (top == 0 || t[top-1] != '[') {
                    return 0;
                }
                --top;
                break;
        }
    }
    if (top != 0) {
        return 0;
    }
    return 1;
}

