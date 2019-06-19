#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (size_t i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int T[n];
    int i, Number[10] = {0};

    for (i = 0; i < n; i++)
        Number[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        Number[i] += Number[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        T[Number[(arr[i] / exp) % 10] - 1] = arr[i];
        Number[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = T[i];
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (size_t exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void showOff(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
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
        radixSort(arr, n);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // showOff(arr, n); //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); // arr[1000000] took 0.24695282s (avg of 100 tests)
    return 0;
}