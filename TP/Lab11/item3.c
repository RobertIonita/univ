#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5

typedef struct
{
    double x, y;
} coords;

coords graph[10];

void cleanUp(int (*a)[], int n) {
    for (size_t i = 0; i < n; i++)
        (*a)[i] = 0;
}

int read(char *path)
{
    FILE *f;
    int i = 0;
    if ((f = fopen(path, "rt")) == NULL)
        printf("error");
    else
        while (!feof(f))
        {
            fscanf(f, "%lf %lf", &graph[i].x, &graph[i].y);
            printf("%2d: %5.2lf %5.2lf\n", i+1, graph[i].x, graph[i].y);
            i++;
        }
    fclose(f);
    return i;
}

void min_dist(int (*arr)[], int points, int *n)
{
    int i = 0;
    double min = sqrt(pow(graph[0].x, 2) + pow(graph[0].y, 2));
    for (i = 1; i < points; i++)
    {
        double x = sqrt(pow(graph[i].x, 2) + pow(graph[i].y, 2));
        if (x < min)
        {
            cleanUp(&(*arr), points);
            min = x;
            (*arr)[(*n)=0] = i;
        }
        else if (x == min)
        {
            (*arr)[++(*n)] = i;
        }
    }
}

int main()
{
    int arr[10];
    int points = 0,
        n = 0;
    points = read("TP/Lab11/assets/input3.txt");
    cleanUp(&arr, points);
    min_dist(&arr, points, &n);
    for (size_t i = 0; i <= n; i++)
        printf("\nmin at line: %d", arr[i]+1);
    return 0;
}