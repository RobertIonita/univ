#include "TONU.h"

int main (){
    int arr[] = {2, 0, 5, 9, 1, 0},
        n = sizeof(arr)/sizeof(int);
    insertion(arr, n);
    printIntArray(arr, n);
}