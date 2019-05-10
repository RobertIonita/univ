#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5

typedef struct {
    int x, y;
} coords;

coords graph[10];

int read (char * path) {
    FILE * f;
    int i = 0;
    if ((f = fopen(path, "rt")) == NULL) {
        printf("error");
    } else {
         while (!feof(f)) {
            fscanf(f, "%d %d", &graph[i].x, &graph[i].y);
            printf("%d %d\n", graph[i].x, graph[i].y);
            i++;
        }
        fclose(f);
    }
    return i;
}

void min_dist(int (*arr)[], int points, int *n) {
    int i = 0;
    double min = sqrt(graph[0].x + graph[0].y);
    for (i = 1; i < points; i++)
    {
        double x = sqrt(graph[i].x + graph[i].y);
        if (x < min) {
            min = x;
        } else if (x == min){
            (*arr)[(*n)++] = i;
        }
    }
}

int main() {
    int arr[10];
    int points = 0,
        n = 0;
    points = read("TP/Lab11/input3.txt");
    min_dist(&arr, points, &n);
    for (size_t i = 0; i < n; i++)
    {
        printf("min is at line: %d\n", arr[i]+1);
    }
    
}