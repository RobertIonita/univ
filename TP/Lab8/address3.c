#include <stdio.h>

void inca_o_functie(int * parametru) {
    printf("In functie, la inceput: %d. \n", * parametru);
    ( * parametru) ++;
    printf("In functie, la final: %d.\n", * parametru);
}

int main(void) {
    int variabila = 100;
    printf("Inainte de apelul functiei:%d.\n", variabila);
    inca_o_functie( & variabila);
    printf("Dupa apelul functiei: %d.\n", variabila);
    return 0;
}