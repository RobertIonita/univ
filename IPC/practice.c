#include <stdio.h>

#include <conio.h>

#include <string.h>

typedef struct {
    char make[20],
        model[20];
    int price;
}
store;


void quit() {
    printf("\nquiting");
}
void populate(store * Darwin, int * counter) {
    ( * counter) ++;
    printf("\nGive values\n");
    while (getchar() != '\n')
    ;
    printf("Make: ");
    gets(Darwin[ * counter].make);
    printf("Model: ");
    gets(Darwin[ * counter].model);
    printf("Price: ");
    scanf("%d", & Darwin[ * counter].price);
}
void showOff(store * Darwin, int counter) {
    printf("\n%10s \t %10s \t %5d",
        Darwin[counter].make,
        Darwin[counter].model,
        Darwin[counter].price
    );
}
void search(store * Darwin, int counter, char _model[20]) {
    int i;
    for (i = 0; i <= (counter); i++) {
        if (strcmp(Darwin[i].model, _model) == 0) {
            showOff(Darwin, i);
        }
    }
}
void compare(store * Darwin, int counter, int price) {
    int i;
    for (i = 0; i <= (counter); i++) {
        if (Darwin[i].price < price) {
            showOff(Darwin, i);
        }
    }
}
void sort(store * Darwin, int counter) {
    int i, sorted;
    store clone;
    do {
        sorted = 1;
        for (i = 0; i < (counter); i++) {
            if (strcmp(Darwin[i].model, Darwin[i + 1].model) > 0) {
                sorted = 0;
                clone = Darwin[i];
                Darwin[i] = Darwin[i + 1];
                Darwin[i + 1] = clone;
            }
        }
    } while (!sorted);
}

void delete(store * Darwin, int * counter, char _model[20]) {
    int i, j, deleted = 0;
    for (i = 0; i <= ( * counter - deleted); i++) {
        if (strcmp(Darwin[i].model, _model) == 0) {
            deleted++;
            for (j = i; j < ( * counter - deleted); j++) {
                Darwin[j] = Darwin[j + 1];
            }
            i--;
        }
        * counter = * counter - deleted;
    }
}

int main(void) {

    int option = !0,
        n = -1, i, j,
        _price;
    char _make[20],
        _model[20];
    store Darwin[10];


    do {
        printf("\nAvailable options are:");
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show");
        printf("\n3. search");
        printf("\n4. compare");
        printf("\n5. sort");
        printf("\n6. delete");
        printf("\nYor choice: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                quit();
                break;
            case 1:
                populate( & Darwin[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++) {
                    showOff(Darwin, i);
                }
                break;
            case 3:
                printf("\nDesired model: ");
                while (getchar() != '\n')
                ;
                gets(_model);
                search(Darwin, n, _model);
                break;
            case 4:
                printf("\nModels cheaper than: ");
                scanf("%d", & _price);
                compare(Darwin, n, _price);
                break;
            case 5:
                sort(Darwin, n);
                break;
            case 6:
                printf("\nModels to remove: ");
                while (getchar() != '\n')
                ;
                gets(_model);
                delete(Darwin, & n, _model);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (option);
}