#include <stdio.h>

#define MAX 10


void quit(){
    printf("\nquiting..");
}
void read(int arr[][MAX], int *n){
    int i, j;
    printf("\nInsert number of rows and columns: ");
    scanf("%d", n);
    for(i=0; i< *n; i++) {
        for(j=0; j< *n; j++) {
            printf("\narr[%d][%d]: ", i,j);
            scanf("%d", &arr[i][j]);
        }
    }
}
void show(int arr[][MAX], int *n){
    int i, j;
    for(i=0; i< *n; i++) {
        for(j=0; j< *n; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

}
void summ(int arr[][MAX], int *n){
    int i, j, summ = 0;
    for(i=0; i< *n; i++) {
        for(j=0; j< *n; j++) {
            if(i == *n-1 - j) {
                summ += arr[i][j];
            }
        }
    }
    printf("Summ is: %d", summ);
}

int main(void) {
    int arr[MAX][MAX],
        option, i, j, n;

    do {
        printf("\n0. Exit");
        printf("\n1. Read");
        printf("\n2. Show");
        printf("\n3. Summ");
        printf("\nUr choice: ");
        scanf("%d", &option);

        switch(option) {
            case 0:
                quit();
                break;
            case 1:
                read(arr, &n);
                break;
            case 2:
                show(arr, &n);
                break;
            case 3:
                summ(arr, &n);
                break;
            default:
                printf("Invalid option");
                break;
        }
    } while (option != 0);
}