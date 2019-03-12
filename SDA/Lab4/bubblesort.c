#include <stdio.h>

void swap(int *xp, int *yp) {
    int clone = *xp;
    *xp = *yp;
    *yp = clone;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap( & arr[j], & arr[j + 1]);
            }
        }
    }
}

void showOff(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main() {
    int arr[] = {3 ,0 ,2 ,1 ,5 ,6},
        n = sizeof(arr) / sizeof(arr[0]);

    printf("\nInitial array: "); showOff(arr, n);
    bubbleSort(arr, n);
    
    printf("\nSorted array: "); showOff(arr, n);

    return 0;
}