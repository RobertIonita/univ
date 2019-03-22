#include <stdio.h>
#include <string.h>

typedef struct {
	char name[50];
	float price;
} product;

int alreadyExists(char str[50], product *stock, int n) {
    int i;
    for(i = 0; i < n; i++) {
       if( strcmp(stock[i].name, str) == 0) {
           return i;
       }
    }
    return -1;
}

int main()
{
	product stock[100];
	int i,
        option, n=0,
        index;
    char name[50];
	
	while(1) {
        printf("\n1.Add");
        printf("\n2.Display");
        printf("\n0.Exit");
		printf("\nInsert option: "); 
        scanf("%d", &option);
		switch (option){
            case 1:
                getchar();
                printf("name: "); 
                scanf("%s", name);
                index = alreadyExists(name, stock, n);
                if(index >= 0) {
                    printf("new price: "); scanf("%g", &stock[index].price);
                    n--;
                } else {
                    strcpy(stock[n].name, name);
                    printf("price: "); scanf("%g", &stock[n].price);
                }
                n++;
                break;
            case 2:
                for(i = 0; i < n; i++) {
                    printf("%s %g\n", stock[i].name, stock[i].price);
                }
                break;
            case 0: return 0;
            default: 
                printf("\nInvalid option");
            break;
		}
	}
}