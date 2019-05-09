#include <stdio.h>
#include <stdlib.h>

int main(){
    char *a , *aux;
    int c, n;

    a = (char *) malloc(1);
    if (!a) {
        exit(EXIT_FAILURE);
    }
    a[0] = 0;
    n = 0;
    while((c = getchar()) != '.'){
        aux = (char *)realloc(a, n +2);
        if(!aux){
            free(a);
            printf("Nu pot redimensiona blocul.\n");
            exit(EXIT_FAILURE);
        } else{
            a =aux;
        }
        a[n]=c;
        a[n+1]=c;
        n++; 
    }
    printf("%s",a);
    free(a);
    return 0;
}