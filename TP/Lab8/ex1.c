#include <stdio.h>
#include <stdlib.h>

void f1(int n1, int n2) {
    printf("O functie care are doi parametrii de tip int: %d si %d.\n", n1, n2);
}
void f2(int n3, int n4) {
    printf("A doua functie cu  doi parametrii de tip int: %d si %d.\n", n3, n4);
}
int main(void) {
    void( * un_pointer)(int x, int y);
    un_pointer = & f1;
    f1(100, 200);
    ( * un_pointer)(300, 400);
    un_pointer = & f2;
    f2(500, 600);
    ( * un_pointer)(700, 800);
    return 0;
}