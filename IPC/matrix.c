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
void clean(int arr[][MAX], int *n) {
    int i, j;
    for(i = 0; i<*n; i++) {
        for(j = 0; j<*n; j++) {
            arr[i][j] = 0;
        }
    }
}

void crossing() {
    int matrix[MAX][MAX] = {0,0,0,0,0,0,0,0,0},
        type, i, j,
        n = 3;

    do{
        printf("\n0. Exit");
        printf("\n1. Main diagonal");
        printf("\n2. Main diagonal and lower");
        printf("\n3. Main diagonal and upper");
        printf("\n4. Second diagonal");
        printf("\n5. Second diagonal and lower");
        printf("\n6. Second diagonal and upper");
        printf("\nUr choice:");
        scanf("%d", &type);

        switch (type) {
            case 0:
                printf("\ngot out\n");
                break;
            case 1:
                for(i = 0; i<n; i++) {
                    for(j = 0; j<=i; j++) {
                        if (i==j) matrix[i][j] = 1;
                    }
                }
                break;
            case 2:
                for(i = 0; i<n; i++) {
                    for(j = n-i-1; j<n; j++) {
                        matrix[i][j] = 1;
                    }
                }
                break;
            case 3:
                for(i = 0; i<n; i++) {
                    for(j = 0; j<n; j++) {
                        if (j<n-i) matrix[i][j] = 1;
                    }
                }
                break;
            case 4:
                for(i = 0; i<n; i++) {
                    for(j = n-i-1; j<n-i; j++) {
                        matrix[i][j] = 1;
                    }
                }
                break;
            case 5:
                for(i = 0; i<n; i++) {
                    for(j = n-i-1; j<n; j++) {
                        matrix[i][j] = 1;
                    }
                }
                break;
            case 6:
                for(i = 0; i<n; i++) {
                    for(j = 0; j<n-i; j++) {
                        matrix[i][j] = 1;
                    }
                }
                break;
            default:
                break;
        }
        show(matrix, &n);
        clean(matrix, &n);

    } while(type !=0);
}

int main(void) {
    int arr[MAX][MAX],
        option, i, j, n;

    do {
        printf("\n0. Exit");
        printf("\n1. Crossing");
        printf("\n2. Read");
        printf("\n3. Show");
        printf("\n4. Summ");
        printf("\nUr choice: ");
        scanf("%d", &option);
        
        switch(option) {
            case 0:
                quit();
                break;
            case 1:
                crossing();
                break;
            case 2:
                read(arr, &n);
                break;
            case 3:
                show(arr, &n);
                break;
            case 4:
                summ(arr, &n);
                break;
            default:
                printf("Invalid option");
                break;
        }
    } while (option != 0);
}