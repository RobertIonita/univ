/*2.Definiti o functie care primeste ca parametri un tablou de numere reale si un numar intreg reprezentand numarul de elemente din tablou.
Functia va returna valoarea maxima din tabloul primit ca parametru.
In main cititi de la tastatura n numere reale, pastrati-le intr-un tablou si apoi apelati functia pentru a gasi valoarea maxima dintre numerele citite.*/
#include <stdio.h>

#define MAX 10

int max(int arr[MAX], int n) {
    int max = arr[0], i;

    for (i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}



int item2(void) {

    int Mat[MAX], n, i;

    printf("Insert 'n': ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Insert Mat[%d]: ", i);
        scanf("%d", &Mat[i]);
    }

    printf("%i", max(Mat, n));

    return 0;
}
