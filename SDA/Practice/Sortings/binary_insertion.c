#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void showOff(int arr[], int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int binarySearch(int a[], int item, int low, int high) 
{ 
	if (high <= low) 
		return (item > a[low])? (low + 1): low; 

	int mid = (low + high)/2; 

	if(item == a[mid]) 
		return mid+1; 

	if(item > a[mid]) 
		return binarySearch(a, item, mid+1, high); 
	return binarySearch(a, item, low, mid-1); 
} 

void insertionSort(int a[], int n) 
{ 
	int i, loc, j, k, selected; 

	for (i = 1; i < n; ++i) 
	{ 
		j = i - 1; 
		selected = a[i]; 

		loc = binarySearch(a, selected, 0, j); 
		while (j >= loc) 
		{ 
			a[j+1] = a[j]; 
			j--; 
		} 
		a[j+1] = selected; 
	} 
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
    insertionSort(arr, n);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // showOff(arr, n); //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); //arr[100000] took 8.126727s (avg of 10 tests)
} 
