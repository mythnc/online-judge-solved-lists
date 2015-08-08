#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINEMAX 1010
#define MIN(x, y) ((x) <= (y) ? (x) : (y))

int find(int);
int init(int);
int match(int, int, int);
void print(int);

char t[LINEMAX];
char s[LINEMAX * 2];
int z[LINEMAX * 2];

int main(void)
{
    int n;

    while (fgets(t, LINEMAX, stdin) != NULL) {
        print(find(strlen(t)));
    }
    return 0;
}

/* find: find maximum palindrome substring */
int find(int n)
{
    int i, mirror, border, center, right;

    n = init(n);

    /* modified z Algorithm */
    center = right = 0;
    for (i = z[0] = 1; i < n; i++)
        if (i > right) {
            z[i] = match(i, i, n);
            center = i;
            right = i + z[i] - 1;
        }
        else {
            mirror = center - (i - center);
            border = right - i + 1;
            if (z[mirror] == border) {
                z[i] = border + match(i - border, i + border, n);
                center = i;
                right = i + z[i] - 1;
            }
            else
                z[i] = MIN(z[mirror], border);
        }

    return n;
}

/* init: initialize s */
int init(int n)
{
    int i, j;

    memset(s, '.', sizeof(s));
    for (i = j = 0; i < n; i++) {
        s[2 * j + 1] = t[i];
        j++;
    }

    return 2 * j + 1;
}

/* match: from s[a] to left and from s[b] to right
 * do char compare symmetrically */
int match(int a, int b, int n)
{
    int i;

    i = 0;
    while (a - i >= 0 && b + i < n && s[a - i] == s[b + i])
        i++;

    return i;
}

/* print: print out result */
void print(int n)
{
    int i, j, pos, from, to, k;

    /* find max len */
    for (i = 1, pos = 0; i < n; ++i)
        if (z[i] > z[pos])
            pos = i;

    /* remove '.' */
    i = pos - (z[pos] - 1);
    if (!(i & 1))
        i++;
    for (n = 0; i <= pos + z[pos] - 1; i += 2, n++)
        s[n] = s[i];

    /* print out substring */
    for (i = j = from = to = 0; i < strlen(t); i++)
        if (t[i] == s[j]) {
            from = k = i;
            while (t[k] == s[j] && j < n && k < strlen(t)) {
                j++, k++;
                to = k;
            }
            if (j == n)
                break;
            else
                j = from = to = 0;
        }
    for (i = from; i < to; i++)
        printf("%c", t[i]);
    putchar('\n');
}

