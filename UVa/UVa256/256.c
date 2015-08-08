/* ACM 256 Quirksome Squares
 * mythnc
 * 2011/11/10 16:26:49   
 * run time: 0.008
 */
#include <stdio.h>

typedef struct part {
    int front;
    int end;
} Part;

int range(int);
Part split(int, int);
void output(int, int);
int digitn(int);

int main(void)
{
    int i, digit, n;
    Part s;

    while (scanf("%d", &digit) == 1) {
            n = range(digit / 2);

        for (i = 0; i < n; i++) {
            s = split(i * i, n);
            if (s.front + s.end == i) {
                output(s.front, digit / 2);
                output(s.end, digit / 2);
                putchar('\n');
            }
        }
    }

    return 0;
}

/* range: return the square range */
int range(int max)
{
    int i, n;

    for (n = 1, i = 0; i < max; i++)
        n *= 10;

    return n;
}

/* split: split square in two parts,
 * save in s */
Part split(int square, int n)
{
    Part s;

    s.front = square / n;
    s.end = square % n;

    return s;
}

/* output: output format result */
void output(int number, int digit)
{
    int i;

    for (i = digitn(number); i < digit; i++)
        printf("0");
    printf("%d", number);
}

/* digitn: return the digit of n */
int digitn(int n)
{
    int count;

    if (n == 0)
        return 1;

    for (count = 0; n; count++)
        n /= 10;

    return count;
}

