#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void showOff(int a[MAX], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void shellSort2(int (*a)[MAX], int n)
{
    for (size_t gap = n / 2; gap > 0; gap /= 2)
    {
        for (size_t i = gap; i < n; i++)
        {
            int temp = (*a)[i],
                j;
            for (j = i; j >= gap && (*a)[j - gap] > temp; j -= gap)
            {
                (*a)[j] = (*a)[j - gap];
            }
            (*a)[j] = temp;
            // printf("\n"); showOff(*a, n); //optional, show steps
        }
    }
}

void generateArray(int (*arr)[])
{
    for (size_t i = 0; i < MAX; i++)
        (*arr)[i] = rand() % 1000000 + 1;
}

int main()
{
    int arr[MAX], n;
    generateArray(&arr);
    n = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock();
    for (size_t i = 0; i < 100; i++)
        shellSort2(&arr, MAX);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // showOff(arr, n); //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); //arr[1000000] took 0.10866316s (avg of 100 tests)
    return 0;
}