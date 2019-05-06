#include <stdio.h>

void stea(void) {
    printf("*");
}

void plus(void) {
    printf("+");
}

void minus(void) {
    printf("-");
}
void dolar(void) {
    printf("$");
}

int main(void) {
    int i;
    void( * p[4])(void);
    p[0] = & stea;
    p[1] = & plus;
    p[2] = & minus;
    p[3] = & dolar;
    for (i = 0; i < 4; i++)
        ( * p[i])();
    for (i = 3; i >= 0; i--)
        ( * p[i])();
    return 0;
}