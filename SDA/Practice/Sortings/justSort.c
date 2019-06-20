#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void showOff(int arr[], int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void cleanUp(int (*arr)[], int n)
{
    for (size_t i = 0; i < n; i++)
        (*arr)[i] = 0;
}

void justSort(int (*arr)[], int n, int min, int max)
{
    int gap = abs(min) + max,
        token[gap],
        k = 0;
    cleanUp(&token, gap+1);
    for (size_t i = 0; i < n; i++) {
        token[(*arr)[i] - min]++;
    }
    for (size_t i = 0; i < gap+1; i++)
        if (token[i] > 0)
            while (token[i]--)
                (*arr)[k++] = i + min;
}

void generateArray(int (*arr)[])
{
    for (size_t i = 0; i < MAX; i++)
        (*arr)[i] = rand() % 1000000 + 1;
}

void getMax(int arr[], int n, int *min, int *max)
{
    *min = 0;
    *max = arr[0];
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

int main()
{
    int arr[MAX], n,
        min, max;
    generateArray(&arr);
    n = sizeof(arr) / sizeof(arr[0]);

    getMax(arr, n, &min, &max);
    clock_t start = clock();
    justSort(&arr, n, min, max);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // showOff(arr, n); //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); //arr[1000000] took 0.02236018s (avg of 100 tests)
    return 0;
}