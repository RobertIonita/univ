#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a;
    a = (int *) malloc(100 *sizeof(int));
    if(!a){
        printf("Nu pot aloca memorie. \n");
        exit(EXIT_FAILURE);
    }
    a = (int *) realloc(a, 200 * sizeof(int));
    if(!a){
        printf("Nu pot redimensiona blocul. \n");
        exit(EXIT_FAILURE);
    }
    free(a);
    return 0; 
}