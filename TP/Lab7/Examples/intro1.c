#include <stdio.h>

int main(){

    int n, v[5];
    printf("variabila n are dimensiunea %ld \n", sizeof(n));
    printf("variabila n este plasata la adresa %p \n", &n);
    printf("variabila v are dimensiunea %ld\n", sizeof(v));
    printf("variabila v este plasata la adresa %p\n", v);
    return 0;
}