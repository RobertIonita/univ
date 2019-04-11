#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a, *aux;
    a = (int *) malloc(100 *sizeof(int));
    if(!a){
        printf("Nu pot aloca memorie. \n");
        exit(EXIT_FAILURE);
    }
    aux = (int *) realloc(a, 200 * sizeof(int));
    if(!aux){
        printf("Nu pot redimensiona blocul. \n");
        free(a);
        exit(EXIT_FAILURE);
    }
    else{
        a = aux;
    }
    free(a);
    return 0; 
}