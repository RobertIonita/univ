#include <stdio.h>

void swap(int *xp, int *yp) {
    int clone = *xp;
    *xp = *yp;
    *yp = clone;
}

void selectionSort(int arr[], int n) {
    int i, j,
        min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap( & arr[min_idx], & arr[i]);
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
    selectionSort(arr, n);

    printf("\nSorted array: "); showOff(arr, n);
    return 0;
}