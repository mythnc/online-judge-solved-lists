#include <stdio.h>
#include <string.h>

#define MAXCHAR 13

int main(void)
{
    char s[MAXCHAR];
    int count[MAXCHAR - 1] = { 0 };
    int i, sum;

    while (scanf("%s", s) != EOF) {
        count[strlen(s) - 1]++;
    }

    for (sum = i = 0; i < MAXCHAR - 1; i++) {
        printf("%d %d\n", i + 1, count[i]);
        sum += count[i];
    }
    printf("sum %d\n", sum);
    return 0;
}

