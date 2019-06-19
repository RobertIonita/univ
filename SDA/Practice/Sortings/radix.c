#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define BASE 10

void radixSort(int arr[], int n);
void countSort(int arr[], int n, int exp);
void showOff(int arr[], int n);
void generateArray(int (*arr)[]);
int getMax(int arr[], int n);

int main()
{
    int arr[MAX], n;
    generateArray(&arr);
    n = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock();
    // for (size_t i = 0; i < 100; i++)
    radixSort(arr, n);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    showOff(arr, n);            //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); // arr[1000000] took 0.24695282s (avg of 100 tests)
    return 0;
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (size_t exp = 1; max / exp; exp *= BASE)
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
        (*arr)[i] = rand() % 100 + 1;
}
void countSort(int arr[], int n, int exp)
{
    int T[n],
        Number[BASE] = {0};

    for (size_t i = 0; i < n; i++)
        Number[(arr[i] / exp) % BASE]++;

    for (size_t i = 1; i < BASE; i++)
        Number[i] += Number[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        T[Number[(arr[i] / exp) % BASE] - 1] = arr[i];
        Number[(arr[i] / exp) % BASE]--;
    }

    for (size_t i = 0; i < n; i++)
        arr[i] = T[i];
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (size_t i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}