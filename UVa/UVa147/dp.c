#include <stdio.h>

int main(void)
{
    int ary[] = {1, 5, 10, 25};
    int money[27] = { 0 };
    int i, j;

    money[0] = 1;
    for (i = 0; i < 4; i++)
        for (j = ary[i]; j < 27; j++)
            money[j] = money[j] + money[j - ary[i]];

    for (i = 0; i < 27; i++)
        printf("%d %d\n", i, money[i]);

    return 0;
}

