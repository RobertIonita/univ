#include <stdio.h>
#include <stdlib.h>

int main(){
    int *N, n,
        i;
    
    printf("Cate numere citim? ");
    scanf("%d", &n);
    N = (int *) malloc(n *sizeof(int));
    if(!N){
        printf("Nu pot aloca memorie. \n");
        exit(EXIT_FAILURE);
    }
    printf(" Citire\n");
    for(i = 0; i < n; i++){
        printf("\n N[%d]: ", i);
        scanf("%d", &N[i]);
    }
    printf("\n Afisare\n");
    for(i = 0; i < n; i++){
        printf("\nN[%d]: %d",i, N[i]);
    }
     printf("\n Afisare in ordine inversa: \n");
    for(i=n-1; i>=0; i--){  
        printf("\nN[%d]: %d",i, N[i]);
    }

    free(N);
    return 0;
}