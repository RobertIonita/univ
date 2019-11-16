#include <stdlib.h>
#include <iostream>
using namespace std;

void generateArray(int **arr, int n);
void showOff(int arr[], int n);
void swap(int arr[], int a, int b);
int populate(char *path, int arr[], int n);

int main()
{
    int *arr,
        n = 10;
    generateArray(&arr, n);
    // showOff(arr, n); //do not uncoment for big values of n !!!
    populate("AA/Comparisons/assets/input.txt", arr, n);
    return 0;
}

void swap(int arr[], int a, int b)
{
    arr[a] = arr[a] + arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] = arr[a] - arr[b];
}

void generateArray(int **arr, int n)
{
    *arr = (int *)malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; i++)
        (*arr)[i] = i;
    for (size_t i = 0; i < n; i++)
        swap((*arr)[i], (*arr)[rand() % n]);
}

void showOff(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int populate(char *path, int arr[], int n)
{
    FILE *f;
    if ((f = fopen(path, "wt")) == NULL)
    {
        cout << "Error writing file";
        return -1;
    }
    while (n)
        fprintf(f, "%d ", arr[--n]);
    fclose(f);
}
