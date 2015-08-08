#include <stdio.h>

#define MAXF 39

void cal_fib(int dec, char *fib);
void output(int dec, char *fib);

int main(void)
{
    int n, dec;
    char fib[MAXF];

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &dec);
        cal_fib(dec, fib);
        output(dec, fib);
    }
    return 0;
}

void cal_fib(int dec, char *fib)
{
    int i, j;
    static int f[MAXF] = {1, 1, 2, 3,
                          5, 8, 13, 21, 34,
                          55, 89, 144, 233, 377,
                          610, 987, 1597, 2584, 4181,
                          6765, 10946, 17711, 28657, 46368,
                          75025, 121393, 196418, 317811, 514229,
                          832040, 1346269, 2178309, 3524578, 5702887,
                          9227465, 14930352, 24157817, 39088169, 63245986};

    for (i = MAXF - 1, j = 0; dec > 0 || i >= 0; i--, j++) {
        if (f[i] > dec) {
            fib[j] = '0';
            continue;
        }
        dec -= f[i--];
        fib[j++] = '1';
        fib[j] = '0';
    }
    fib[j-1] = '\0';
}

void output(int dec, char *fib)
{
    int i = 0;

    while (fib[i] == '0')
        i++;
    printf("%d = %s (fib)\n", dec, fib + i);
}

