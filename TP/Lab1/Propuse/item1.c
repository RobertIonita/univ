/*1.Definiti o functie care primeste ca parametru un numar intreg pozitiv si o cifra si verifica daca numarul contine cifra respectiva in reprezentarea sa zecimala.
Functia va returna 1 daca numarul contine cifra si 0 in caz contrar.
Folositi functia pentru a afisa toate numere mai mici decat un n dat care contin cifra c. N si c se citesc de la tastatura.*/
#include <stdio.h>

int includes(int x, int y) {
    while (x) {
        if (x % 10 == y) {
            return 1;
        }
        x /= 10;
    }
    return 0;
}



int item1(void) {

    int a, b;

    printf("Insert 'a' and 'b': ");
    scanf("%d %d", & a, & b);

    printf("%i", includes(a, b));

    return 0;
}