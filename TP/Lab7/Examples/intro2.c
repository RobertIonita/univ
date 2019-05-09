#include <stdio.h>
#include <stdlib.h>

int main(){
int n, *v;
    printf("variabila n are dimensiunea %ld \n", sizeof(n));
    printf("variabila n este plasata la adresa %p \n", &n);
    printf("variabila v are dimensiunea %ld\n", sizeof(v));
    printf("variabila v este plasata la adresa %p\n", &v);
    
    v=(int *) malloc(5 * sizeof(int));
    printf("blocul de memorie este plasat la adresa %p\n", v);
    if(v == NULL){
        printf("Nu pot aloca memorie. \n");
        exit(EXIT_FAILURE);
    }
    for(n = 0; n < 5; n++)
        v[n] = n;

    free(v);
    return 0;
}