/* ACM 739 Soundex Indexing
 * mythnc
 * 2012/01/04 11:35:35   
 * run time: 0.024
 */
#include <stdio.h>
#include <string.h>

#define LINEMAX 20

void map(char *, char *);

int main(void)
{
    char name[LINEMAX];
    char encode[5];

    printf("%9c%s%*c%s\n", ' ', "NAME", 25 - strlen("NAME"), ' ', "SOUNDEX CODE");
    while (scanf("%s", name) == 1) {
        map(name, encode);
        printf("%9c%s%*c%s\n", ' ', name, 25 - strlen(name), ' ', encode);
    }
    printf("%19c%s\n", ' ', "END OF OUTPUT");

    return 0;
}

/* map: map name to its correspond code */
void map(char *name, char *encode)
{
    int i, j;
    int table[26] = {0, 1, 2, 3, 0,
                     1, 2, 0, 0, 2,
                     2, 4, 5, 5, 0,
                     1, 2, 6, 2, 3,
                     0, 1, 0, 2, 0,
                     2};

    encode[0] = name[0];
    for (i = 1, j = 1; j < strlen(name) && i < 4; j++) {
        if (table[name[j] - 'A'] == 0
            || table[name[j] - 'A'] == table[name[j - 1] - 'A'])
            continue;
        encode[i++] = table[name[j] - 'A'] + '0';
    }
    while (i < 4)
        encode[i++] = '0';
    encode[i] = '\0';
}

