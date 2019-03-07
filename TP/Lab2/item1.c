#include <stdio.h>

#define N 21

void showOff(int (*arr)[N], int n){
    int i;
    for(i=0; i< n; i++) {
        printf("%d ", (*arr)[i]);
    }

}

void sort (int (*vect)[N], int n) {

    int clone,
        i, j,
        sorted;

    do {
        sorted = 1,
        clone = 0;
        for(i = 0; i < n-1; i++) {
            if ((*vect)[i] % 2 != 0) {
                for(j = i+1; j <  n-1; j++) {
                    if ((*vect)[j] %2 != 0 && (*vect)[i] > (*vect)[j]) {
                        sorted = 0;
                        clone = (*vect)[j];
                        (*vect)[j] = (*vect)[i];
                        (*vect)[i] = clone;
                        break;
                    }
                }
            }
        }
        
    } while (!sorted);

    showOff(vect, n);
};


int main() {

    int v[N],
        i;
    for (i=N-1; i>=0; i--) {
        v[i] = N-i-1;
    }
    printf("\nInitial vector is:"); showOff(&v, N);
    
    printf("\nSorted  vector is:"); sort(&v, N);

}