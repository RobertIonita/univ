#include <stdio.h>

int trans (int vect[20][30]) {

    int i, j;
        for(i = 0; i < 20; i++) {
            for (j = 0; j < 30; j++) {
                printf("%d", vect[i][j]);
            }
        }

    return 0;
};


int main() {

    int v[20][30], 
        i, j, r;

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 30; j++) {
            v[i][j] = j;
        }
        
    }

    trans(v);

    return 0;
}