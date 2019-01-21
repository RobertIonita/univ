#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct {
    char name[20],
        color[20],
        category[20];
    int year,
        classes,
        capacity;
} ship;

void quit() {
    printf("\n quiting..");
}

void populate(ship *lil_boat, int *index) {
    (*index)++;

    char categ[20] = "UNASSIGNED";
    while(getchar() != '\n')
    ;
    printf("Name: ");
    gets(lil_boat[*index].name);
    printf("Color: ");
    gets(lil_boat[*index].color);
    printf("Year: ");
    scanf("%d", &lil_boat[*index].year);
    do {
        if(strcmp(categ, "UNASSIGNED") !=0) {
            printf("\nPlease be careful at the spelling\n");
        }
        printf("Category is: ");
        while(getchar() != '\n')
        ;
        gets(categ);
    } while (strcmp(categ, "cargo") != 0 && strcmp(categ, "cruise") != 0);
    strcpy(lil_boat[*index].category, categ);

    if (strcmp(categ, "cargo") == 0) {
        printf("\nInsert ship's transport capacity: ");
        scanf("%d", &lil_boat[*index].capacity);
    } else {
        printf("\nInsert ship's number of classes: ");
        scanf("%d", &lil_boat[*index].classes);
    }
}

void showOff(ship *lil_boat, int index) {
    printf("\n%s \t %s \t %d \t %s ship",
        lil_boat[index].name,
        lil_boat[index].color,
        lil_boat[index].year,
        lil_boat[index].category
    );
    if (strcmp(lil_boat[index].category, "cargo") == 0 ) {
        printf("\t %d",  lil_boat[index].capacity);
    } else {
        printf("\t %d",  lil_boat[index].classes);
    }
}

void search(ship *lil_boat, int index, int year) {
    int i;
    for (i=0; i<index; i++){
        if(lil_boat[index].year == year) {
            showOff(lil_boat, i);
        }
    }
}

void compare(ship *lil_boat, int index, int value) {
    int i;
    for (i=0; i<index; i++){
        if(strcmp(lil_boat[index].category, "cargo") == 0 && lil_boat[index].capacity == value) {
            showOff(lil_boat, i);
        }
    }
}

int main(void) {
    int executing = !0,
        n = -1, i, j,
        _year, _capacity;
    char _name[20],
        color[20];
    ship AC_INFO_YEAR_I[10]; //hope U won't drown it 😢

    printf("\nU have some options");
    do {
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show");
        printf("\n3. compare");
        printf("\n4. search");
        printf("\nUr choice:");
        while(getchar() != '\n')
        ;
        scanf("%d", &executing);

        switch(executing) {
            case 0:
                quit();
                break;
            case 1:
                populate(&AC_INFO_YEAR_I[0], &n);
                break;
            case 2:
                printf("\nName \t Color \t Year \t Category\tCharacteristics\n");
                for (i=0; i<=n; i++) {
                    showOff(AC_INFO_YEAR_I, i);
                }
                break;
            case 3:
                printf("\nShip's transport capacity: ");
                while(getchar() != '\n')
                ;
                scanf("&d", &_capacity);
                compare(AC_INFO_YEAR_I, n, _capacity);
                break;
            case 4:
                printf("\nShip's year of manufacture: ");
                while(getchar() != '\n')
                ;
                scanf("&d", &_year);
                search(AC_INFO_YEAR_I, n, _year);
                break;
            default:
                printf("\n Invalid option");
                break;
        }
    } while(executing); 
}