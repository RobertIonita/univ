#include <stdio.h>

void swap(int *a, int *b){
    int token = *a;
    *a = *b;
    *b = token;
}

void printIntArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void printFloatArray(float arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
}

void printCharArray(char arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);
}

void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && arr[j] < arr[j-1] ; j--)
            swap(&arr[j], &arr[j-1]);
}