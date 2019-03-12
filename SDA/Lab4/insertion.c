#include <stdio.h>
#include <math.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    
    printf("\nSorted array: "); showOff(arr, n);

    return 0;
}