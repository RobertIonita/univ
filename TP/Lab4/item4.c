#include <stdio.h>
#include <math.h>

typedef struct {
    int x,
        y;
} point;

#define MAX 10

void populate(point * dot, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nInsert x & y: ");
        scanf("%d %d", &
            dot[i].x, &
            dot[i].y
        );
    }
}

void showOff(point * dot, int n) {
    printf("\n%d %d",
        dot[n].x,
        dot[n].y
    );
}

int square (a, b) {
    return (a-b) * (a-b);
}

int distance(point * dot, int n) {
    int min_dist = square(dot[0].x, dot[1].x) + square(dot[0].y, dot[1].y),
        analised = min_dist,
        i;
    for(i = 1; i < n-1; i++) {
        analised = square(dot[i].x, dot[i+1].x) + square(dot[i].y, dot[i+1].y);
        if ( analised < min_dist) {
            min_dist = analised;
        }
    }
    return min_dist;
}

int main() {

    int n,
    i;

    point dot[MAX];
    printf("Insert nr of points: ");
    scanf("%d", & n);

    populate( & dot[0], n);

    printf("Points' coordinates are: ");
    for (i = 0; i < n; i++) {
        showOff(dot, i);
    }

    printf("\nMin distance is: %2.2f", sqrt(distance(dot, n)) );

    return 0;
}