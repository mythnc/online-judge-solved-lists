/* ACM 444 Encoder and Decoder
 * mythnc
 * 2011/12/19 17:20:43   
 * version 1.1
 * run time: 0.004
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN    123
#define MAXCHAR 4
#define LINEMAX 1000
#define OTHERSC 7

void map(char (*)[]);
void itoa(char *, int);
void reverse(char *);
void decode(char *, char *);
void encode(char *, char (*)[], char *);

int main(void)
{
    char key[MAXN][MAXCHAR];
    char input[LINEMAX];
    char output[LINEMAX * 3];

    map(key);

    while (fgets(input, LINEMAX, stdin)) {
        /* eat newline */
        input[strlen(input) - 1] = '\0';
        /* number: decode it */
        if (input[0] >= '0' && input[0] <= '9') {
            reverse(input);
            decode(input, output);
        }
        /* encode it */
        else {
            encode(input, key, output);
            reverse(output);
        }
        /* output */
        printf("%s\n", output);
    }

    return 0;
}

/* map: map char to int */
void map(char (*key)[MAXCHAR])
{
    char tmp[MAXCHAR];
    int trans[] = {32, 33, 44, 46, 58, 59, 63};
    int i;

    /* uppercase letter */
    for (i = 65; i <= 90; i++) {
        itoa(tmp, i);
        strcpy(key[i], tmp);
    }
    /* lowercase letter */
    for (i = 97; i <= 122; i++) {
        itoa(tmp, i);
        strcpy(key[i], tmp);
    }
    /* others chars */
    for (i = 0; i < OTHERSC; i++) {
        itoa(tmp, trans[i]);
        strcpy(key[trans[i]], tmp);
    }
}

/* itoa: int to ascii */
void itoa(char *tmp, int n)
{
    int i;

    i = 0;
    while (n != 0) {
        tmp[i++] = n % 10 + '0';
        n /= 10;
    }
    tmp[i] = '\0';
    reverse(tmp);
}

/* reverse: reverse s */
void reverse(char *s)
{
    int i, j;
    char tmp;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* decode: decode number to ascii code */
void decode(char *s, char *output)
{
    int i, count;
    char tmp[MAXCHAR];

    for (i = count = 0; i < strlen(s); ) {
        if (s[i] == '1') {
            strncpy(tmp, s + i, 3);
            tmp[3] = '\0';
            i += 3;
        }
        else {
            strncpy(tmp, s + i, 2);
            tmp[2] = '\0';
            i += 2;
        }
        output[count++] = atoi(tmp);
    }
    output[count] = '\0';
}

/* encode: encode char to number */
void encode(char *s, char (*key)[MAXCHAR], char *output)
{
    char *pt;
    int i;

    output[0] = '\0';
    pt = output;
    for (i = 0; i < strlen(s); i++)
        pt = strcat(pt, key[(int)s[i]]);
}

