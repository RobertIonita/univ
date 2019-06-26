#include <stdio.h>

int add(int a, int b) {
    return a+b;
}

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