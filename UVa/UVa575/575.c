/* ACM 575 Skew Binary
 * mythnc
 * 2011/10/27 09:21:55   
 * run time: 0.004
 */
#include <stdio.h>

#define MAXARY 35

void reverse(char *s);

int main(void)
{
    int sum, i, k; 
    char seq[MAXARY];

    while (scanf("%s", seq)) {
        if (seq[0] == '0' && seq[1] == '\0')
            return 0;
        reverse(seq);
        for (sum = i = 0, k = 1; seq[i] != '\0'; i++) {
            k *= 2;
            sum += (seq[i] - '0') * (k - 1);
        }
        printf("%d\n", sum);
    }
}


/* reverse: reverse seq s */
void reverse(char *s)
{
    int i, j;
    char tmp;

    for (j = 0; s[j] != '\0'; j++)
        ;
    for (j--, i = 0; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

