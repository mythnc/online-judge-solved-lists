#include <stdio.h>

int main(int argc, char *argv[])
{
    double n;
    int ary[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
    int i, j;
    long long money[6001] = {0};
    money[0] = 1;

    for (i = 0; i < 11; i++) {
        for (j = ary[i]; j < 6001; j++) {
            money[j] += money[j - ary[i]];
        }
    }
    while (1) {
        scanf("%lf", &n);
        if (n == 0.00) {
            break;
        }
        printf("%6.2lf%17lld\n", n, money[(int)(20 * n + 0.05)]);
    }
    return 0;
}

