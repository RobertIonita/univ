#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float *a, x;
    int n, i;
    printf("Cate numere? ");
    scanf("%d", &n);
    a = (float *) malloc (n * sizeof(float));
    if(!a){
        printf("Nu pot aloca memeorie. \n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < n; i++){
        printf("a[%d]: ", i);
        scanf("%f", &a[i]);
    }
    printf("x: ");
    scanf("%f", &x);
    printf("Numerele din intervalul (%.2f, %.2f) sunt: ", x-1, x+1);
    for(i = 0; i < n; i++){ 
        if(fabs(x - a[i]) <1)
            printf("%.2f", a[i]);
        printf("\n");

    }
    free(a);
    return 0;
}