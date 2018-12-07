#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct {
    char make[20], 
        model[20],
        category[20],
        network[20],
        color[20];
    int price,
        weight,
        count;
} stock;

void addValues(stock*Darwin, int * counter) {
    (*counter)++;
    fflush(stdin);

    printf("Insert product make: ");
    gets( (Darwin + *counter) -> make);

    printf("Insert product model: ");
    gets( (Darwin + *counter) -> model);

    printf("Insert product category: ");
    gets( (Darwin + *counter) -> category);

    printf("Insert product network: ");
    gets( (Darwin + *counter) -> network);

    printf("Insert product color: ");
    gets( (Darwin + *counter) -> color);

    printf("Insert product price: ");
    scanf("%d",  & ((Darwin + *counter) -> price));

    printf("Insert product weight: ");
    scanf("%d",  & ((Darwin + *counter) -> weight));

    printf("Insert number of products in stock: ");
    scanf("%d",  & ((Darwin + *counter) -> count));
}
void showOff(stock * Darwin, int counter) {
    printf("\n%5s \t %5s \t %5s \t %5s \t %5s \t %5d \t %5d \t %5d",
        (Darwin + counter) -> make,
        (Darwin + counter) -> model,
        (Darwin + counter) -> category,
        (Darwin + counter) -> network,
        (Darwin + counter) -> color,
        Darwin[counter].price,
        Darwin[counter].weight,
        Darwin[counter].count
    );
}
void search(stock * Darwin, int * counter, char _make[20]) {
    int i;
    for (i=0; i<= (*counter); i++) {
        if (strcmp((Darwin + i) -> make, _make) == 0) {
            showOff(Darwin, i);
        }
        showOff(Darwin, i);
    }
}
void sortProducts(int value) {
    printf("%d \n", value);
}
void compareAndDisplay(int value) {
    printf("%d \n", value);
}
void quitExecution() {
    printf("quiting .. \n");
}
int main(void) {
    stock Darwin[20];
    int option, n=-1, i, j, _price, _weight, _count;
    char _make, _model, _categ, _network, _color;
    printf("\nChoose an option from the following list \n");
    do {
        printf("\n 1. to add a new product \n");
        printf(" 2. to display all the devices in stock \n");
        printf(" 3. search a product by make and network \n");
        printf(" 4. to sort products based on their color \n");
        printf(" 5. to dysplay all products cheaper than a given number \n");
        printf(" 0. to quit execution \n");
        printf("Your choice is: ");
        scanf("%d", & option);
        switch (option) {
            case 1:
                addValues(& Darwin[0], &n);
                break;
            case 2:
                for (i=0; i<=n; i++) {
                    showOff(Darwin, i);
                }
                break;
            case 3:
                printf("Insert product make: ");
                scanf("%s\n", _make);
                // printf("\nInsert product network: ");
                // gets(_network);
                search(Darwin, & n, _make);
                break;
            case 4:
                sortProducts(4);
                break;
            case 5:
                compareAndDisplay(5);
                break;
            case 0: 
                quitExecution();
                break;
            default:
                printf("Please insert a valid value \n");
        }
    } while (option != 0);

    return 0;
}