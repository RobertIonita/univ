#include <stdio.h>

typedef struct {
    int x,
    y;
} point;

#define MAX 10

void showOff(point * shape, int n) {
    printf("\n%d %d",
        shape[n].x,
        shape[n].y
    );
}

int main() {

    int n,
    i;

    point shape[MAX];
    printf("Insert nr of points: ");
    scanf("%d", & n);

    for (i = 0; i < n; i++) {
        printf("\nInsert x & y: ");
        scanf("%d %d",
            &shape[i].x,
            &shape[i].y
        );
    }
    printf("Points' coordinates are: ");

    for (i = 0; i < n; i++) {
        showOff(shape, i);
    }

    return 0;
}