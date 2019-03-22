#include <stdio.h>

#include <stdlib.h>

typedef struct {
    int value,
    power;
}
factors;

int isPrime(int nr) {
    int i;
    for (i = 2; i < nr / 2 + 1; i++) {
        if (nr % i == 0) {
            return 0;
        }
    }

    return 1;
}

int decompose(factors * set, int nr, int * count) {
    int i,
    k = 0;
    float root;
    for (i = 2; i < abs(nr) / 2 + 1; i++) {
        if (nr % i == 0) {
            if (isPrime(i)) set[( * count) ++].value = i;
        }
    }

    return ( * count);
}

void showOff(factors * set, int counter) {
    printf("\n%d",
        set[counter].value
    );
}

int main() {

    int number,
    n = 0,
        i;

    factors set[10];

    printf("Insert number: ");
    scanf("%d", & number);

    if (decompose(set, number, & n)) {
        printf("\nPrime divisors are: \n");
        for (i = 0; i < n; i++) {
            showOff(set, i);
        }
    } else {
        printf("\n%d is a prime number", number);
    }

    return 0;

}