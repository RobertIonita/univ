#include <stdio.h>
#include <stdlib.h>

int init0 (int *N, int count) {
    N = (int *) malloc(count * sizeof (int));
    if (!N) {
        printf("\nUnable to alloc\n");
        exit(EXIT_FAILURE);
    }
    return *N;
}

void read (int *arr, int count) {
    for (size_t i = 0; i < count; i++)
    {
        printf("\nArr[%zu]: ",i);
        scanf("%d", &arr[i]);
    }
}
int main(){
    int *N, n,
        i;
    
    printf("Cate numere citim? ");
    scanf("%d", &n);
    // n = 3;
    *N = init0(N, n);
    read(N, n);
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