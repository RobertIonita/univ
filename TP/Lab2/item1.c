#include <stdio.h>

#define MAX 20

int sort (int vect[MAX]) {

    int clone, i, sorted;

    do {
        sorted = 1;

        for(i = 0; i < 3; i++) {
            printf("%d", vect[i]);
        }
    // sorted = 0;
        
    } while (!sorted);

    return 0;
};


int main() {

    int v[111];
    printf("\nSorted vector is: %i", sort(v));

}