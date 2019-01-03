#include <stdio.h>
#include <curses.h>
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

void addValues(stock *Darwin, int *counter) {
    ( *counter)++;
    printf("Insert product make: ");
	fflush(stdin);
	while (getchar() != '\n')
    ;

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
    }
}
void sortProducts(stock * Darwin, int * counter) {
	int i, k;
	stock temp;
	do {
		k = 1;
		for (i = 0; i <= (*counter - 1); i++) {
			if (strcmp((Darwin + i) -> color, (Darwin + i+1) -> color) > 0 ) {
				temp = *(Darwin + i);
				*(Darwin + i) = * (Darwin + i+1);
				*(Darwin + i+1) = temp;
				k = 0;
			}
		}
	} while (!k);
}
void compareAndDisplay(int value) {
    printf("%d \n", value);
}
void deleteProduct(stock * Darwin, int *counter, char _make[20]) {
    int k = 0, i, j;
	for (i = 0; i <= (*counter - k); i++) {
		if(strcmp((Darwin + i) -> make, _make) == 0) {
			k++;
			for (j = i; j <= (*counter - k); j++) {
				Darwin[j] = Darwin[j+1];
			}
			i--;
		}
		*counter = *counter - k;
	}
}
void quitExecution() {
    printf("quiting .. \n");
}
int main() {
    stock Darwin[20];
    int option, n=-1, i, j, _price, _weight, _count;
    char _make[30], _model[30], _categ[30], _network[30], _color[30];
    printf("\nChoose an option from the following list \n");
    do {
        printf("\n\n 1. Add a new product \n");
        printf(" 2. Display all the devices in stock \n");
        printf(" 3. Search a product by make and network \n");
        printf(" 4. Sort products based on their color \n");
        printf(" 5. Display all products cheaper than a given number \n");
        printf(" 6. Delete product by make \n");
        printf(" 0. Quit execution \n");
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
                scanf("%s", _make);
                // printf("\nInsert product network: ");
                // gets(_network);
                search(Darwin, & n, _make);
                break;
            case 4:
                sortProducts(&Darwin[0], &n);
				for (i=0; i <= n; i++) {
					showOff(&Darwin[0], i);
				}
                break;
            case 5:
                compareAndDisplay(5);
                break;
            case 6:
				printf("Insert product make that you want to delete: ");
				scanf("%s", _make);
                deleteProduct(& Darwin[0], & n, _make);
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