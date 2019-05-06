#include <stdio.h>
#include <stdlib.h>

void o_functie(int parametru) {
    printf("In functie, la inceput %d\n", parametru);
    parametru++;
    printf("In functie, la final %d\n", parametru);
}
int main(void) {
    int variabila = 100;
    printf("Inainte de apelul functiei %d\n", variabila);
    o_functie(variabila);
    printf("Dupa apelul functiei%d", variabila);
    return 0;
}