/* ACM 438 The Circumference of the Circle
 * mythnc
 * 2011/11/15 12:26:59   
 * run time: 0.012
 */
#include <stdio.h>
#include <math.h>

#define MAXP 3

typedef struct coordinates {
    double x;
    double y;
} Coordinates;

double diameter(Coordinates *);
double distance(Coordinates, Coordinates);

int main(void)
{
    Coordinates point[MAXP];
    int i;
    double const pi = 3.141592653589793;

    while (scanf("%lf %lf", &point[0].x, &point[0].y) == 2) {
        for (i = 1; i < MAXP; i++)
            scanf("%lf %lf", &point[i].x, &point[i].y);
        printf("%.2lf\n", pi * diameter(point));
    }
    return 0;
}

/* circum: return the diameter value */
double diameter(Coordinates *point)
{
    double a, b, c;

    a = distance(point[0], point[1]);
    b = distance(point[1], point[2]);
    c = distance(point[2], point[0]);

    return 2 * a * b * c
           / sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c));
}

/* distance: return the distance between p1 and p2 */
double distance(Coordinates p1, Coordinates p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

