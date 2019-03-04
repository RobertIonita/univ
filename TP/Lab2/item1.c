#include <stdio.h>

#define N 8


void showOff(int arr[N], int n){
    int i;
    for(i=0; i< n; i++) {
        printf("%d ", arr[i]);
    }

}

int sort (int vect[N], int n) {

    int clone, i, sorted;

    do {
        sorted = 1,
        clone;
        for(i = 0; i < n-1; i++) {
            if (vect[i] > vect[i+1]) {
                sorted = 0;
                clone = vect[i+1];
                vect[i+1] = vect[i];
                vect[i] = clone;
            }
        }
        
    } while (!sorted);
    showOff(vect, n);
};


int main() {

    int v[N],
        i, k;
    for (i=N-1, k = 0; i>=0; i--, k++) {
        v[i] = ++k;
    }
    printf("\nInitial vector is:"); showOff(v, N);
    
    printf("\nSorted vector is:"); sort(v, N);

}