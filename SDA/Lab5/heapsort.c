#include<stdio.h>


void down_adjust(int heap[], int i) {
    int j, temp, n, flag = 1;
    n = heap[0];

    while (2 * i <= n && flag == 1) {
        j = 2 * i;
        if (j + 1 <= n && heap[j + 1] > heap[j])
            j = j + 1;
        if (heap[i] > heap[j])
            flag = 0;
        else {
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }
    }
}

void create(int heap[]) {
    int i, n;
    n = heap[0];
    for (i = n / 2; i >= 1; i--) {
        down_adjust(heap, i);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
        heapify(&arr, n, largest); 
    } 
} 

void heapSort2(int (*a)[], int n) {
    for (size_t i = n/2-1; i >= 0; i--)
    {
        heapify(*a, n, i);
        for (size_t i = n/2-1; i >= 0; i--)
        {
            swap(&(*a)[0], &(*a)[i]);
            heapify(*a, n, 0);
        }
    }
    
}

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        printf("%d", arr[i]);
    printf("\n");
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort2(arr, n); 
    printArray(arr, n); 
    return 0;
} 