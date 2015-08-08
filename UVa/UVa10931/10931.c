/* ACM 10931 Parity
 * mythnc
 * 2011/12/28 08:14:34   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

#define MAXCHAR 32

int dectobin(int, char *);
void reverse(char *);

int main(void)
{
    int n, count;
    char bin[MAXCHAR];

    while (scanf("%d", &n) && n != 0) {
        count = dectobin(n, bin);
        reverse(bin);
        printf("The parity of %s is %d (mod 2).\n", bin, count);
    }
        
    return 0;
}

/* dectobin: make decimal number to
 * correspond its binary number,
 * and return the number of 1(bin) */
int dectobin(int n, char *b)
{
    int i, count;

    i = count = 0;
    while (n) {
        if (n % 2)
            count++;
        b[i++] = n % 2 + '0';
        n /= 2;
    }
    b[i] = '\0';

    return count;
}

/* reverse: reverse bin number */
void reverse(char *b)
{
    int i, j;
    char tmp;

    for (i = 0, j = strlen(b) - 1; i < j; i++, j--) {
        tmp = b[i];
        b[i] = b[j];
        b[j] = tmp;
    }
}

