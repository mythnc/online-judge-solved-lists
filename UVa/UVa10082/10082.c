/* ACM 10082 WERTYU
 * mythnc
 * 2011/10/26 11:11:29   
 * run time: 0.004
 */
#include <stdio.h>
#include <string.h>

void mapping(int c);

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
        mapping(c);
    return 0;
}

/* mapping: mapping the wrong typing to correct typing */
void mapping(int c)
{
    char key[] = "=-0987654321`\\][POIUYTREWQ';LKJHGFDSA/.,MNBVCXZ";
    char map[256];
    int i;

    for (i = 0; i < strlen(key); i++)
        map[key[i]] = key[i + 1];
    if (c == ' ' || c == '\n')
        putchar(c);
    else
        putchar(map[c]);

}

