#include <stdio.h>

#define MAX 10010

int main(void)
{
    char a[MAX], b[MAX], c[MAX];
    int n, len, i, carry;

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &len);getchar();
        scanf("%s", a);
        scanf("%s", b);

        for (i = 0; i < len; i++) {
            c[i] = '0';
        }
        c[i] = '\0';

        carry = 0;
        for (i = len - 1; i >= 0; i--) {
            c[i] = (a[i] - '0') + (b[i] - '0') + carry;
            if (c[i] > 1) {
                carry = 1;
                c[i] = (c[i] % 2) + '0';
            }
            else {
                carry = 0;
                c[i] += '0';
            }
        }
        printf("%s\n", c);
    }
    return 0;
}
