/* ACM 445 Marvelous Mazes
 * mythcn
 * 2011/10/20 16:47:21
 * run time: 0.024
 */
#include <stdio.h>

int main(void)
{
    int c, num;

    num = 0;
    while ((c = getchar()) != EOF)
        if (c > '0' && c <= '9')
            num += (c - '0');
        else if (c >= 'A' && c <= 'Z' || c == '*')
            while (num > 0) {
                putchar(c);
                num--;
            }
        else if (c == 'b')
            while (num > 0) {
                putchar(' ');
                num--;
            }
        else if (c == '!' || c == '\n')
            putchar('\n');
    return 0;
}

