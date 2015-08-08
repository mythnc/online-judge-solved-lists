#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    int t;
    int a, b;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}

int gcd(int a, int b)
{
    int temp;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

