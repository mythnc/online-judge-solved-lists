#include <stdio.h>
#include <string.h>

#define MAXLEN  210
#define MAXLINE 9

void input(char (*article)[MAXLEN], int n);
void query(char (*article)[MAXLEN], int n);

int main(void)
{
    int m, n;
    char article[MAXLINE][MAXLEN];

    while (scanf("%d %d", &n, &m) == 2) {
        getchar();
        input(article, n);
        while (m--) {
            query(article, n);
        }
        putchar('\n');
    }
    return 0;
}

void input(char (*article)[MAXLEN], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        fgets(article[i], MAXLEN, stdin);
    }
}

void query(char (*article)[MAXLEN], int n)
{
    char q[MAXLEN];
    char *p;
    int i, count;

    /* fgets(q, MAXLEN, stdin);
    q[strlen(q) - 1] = '\0';
    */
    scanf("%s", q);

    for (i = count = 0; i < n; i++) {
        p = strcasestr(article[i], q);
        while (p != NULL) {
            count++;
            p = strcasestr(p + 1, q);
        }
    }

    printf("%s:%d\n", q, count);
}

