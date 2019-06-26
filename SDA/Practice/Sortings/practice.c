#include <stdio.h>

void insertion(int arr[], int n);
void swap(int *a, int *b);
void printIntArray(int arr[], int n);

int main() {
    int arr[] = {0, 2, 5, 6, 4, 9, 0},
        n = sizeof(arr)/sizeof(int);
    insertion(arr, n);
    printIntArray(arr, n);
    return 0;
}

void insertion(int arr[], int n) {
    for (size_t i = 1; i < n; i++)
       for (int j = i; j >= 0 && arr[j] < arr[j-1]; j--)
            swap(&arr[j], &arr[j-1]);
}

void swap(int *a, int *b){
    int token = *a;
    *a = *b;
    *b = token;
}
void printIntArray(int arr[], int n){
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}