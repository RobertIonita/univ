#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct item{
    char brand[20],
        model[20],
        type[20];
    int year;
    struct item *next;
} record;


record * insert_top(char * brand, char * model, char * type, int year, record * head) {
    record * new_record;
    new_record = (record *) malloc( sizeof(record) );
    strcpy(new_record -> brand, brand);
    strcpy(new_record -> model, model);
    strcpy(new_record -> type, type);
    new_record -> year = year;
    new_record -> next = head;
    head = new_record;
    return head;
}
record * insert_bottom(char * brand, char * model, char * type, int year, record * head) {
    record * current_record = head;
    record * new_record;

    while(current_record != NULL && current_record -> next != NULL){
        current_record = current_record -> next;
    }
    
    new_record = (record *) malloc( sizeof(record) );
    strcpy(new_record -> brand, brand);
    strcpy(new_record -> model, model);
    strcpy(new_record -> type, type);
    new_record -> year = year;
    new_record -> next = NULL;
    if (current_record != NULL) {
        current_record -> next = new_record;
    } else {
        head = new_record;
    }
    return head;
}

void showOff(record *head) {
  record *current_record = head;
  while ( current_record != NULL) {
    printf("\n%10s %10s %6d %10s",
        current_record -> brand,
        current_record -> model,
        current_record -> year,
        current_record -> type
    );
    current_record = current_record->next;
  }
}

record * deleteRecord(record * head, char * c) {
    record * car1, * car2;
    for (car1 = car2 = head; car1 != NULL && (strcmp(car1 -> model, c)); car2 = car1, car1 = car1 -> next);
    if (car1 != NULL && ((strcmp(car1 -> model, c) == 0))) {
        if (car1 == car2)
            head = head -> next;
        else
            car2 -> next = car1 -> next;
        free(car1);
    }
    return head;
}

int main () {
    char brand[MAX],
        model[MAX],
        type[MAX];
    int year,
        option;

    record * cars = NULL;
    FILE * f;
    if ((f = fopen("SDA/Lab7/file.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s %s %d %s",
                brand,
                model,
                &year,
                type
            );
            cars = insert_bottom(brand, model, type, year, cars);
        }
        fclose(f);
    }

    while(1){
        printf("\n0. exit");
        printf("\n1. add to top");
        printf("\n2. add to bottom");
        printf("\n3. delete model");
        printf("\n4. show records");
        printf("\nYour choice: ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                return 0;
            case 1:
                printf("\nInsert brand:");
                scanf("%s", brand);
                printf("\nInsert model:");
                scanf("%s", model);
                printf("\nInsert type:");
                scanf("%s", type);
                printf("\nInsert year:");
                scanf("%d", &year);
                cars = insert_top(brand, model, type, year, cars);
                break;
            case 2:
                printf("\nInsert brand:");
                scanf("%s", brand);
                printf("\nInsert model:");
                scanf("%s", model);
                printf("\nInsert type:");
                scanf("%s", type);
                printf("\nInsert year:");
                scanf("%d", &year);
                cars = insert_bottom(brand, model, type, year, cars);
                break;
            case 3:
                printf("\nDesired model:");
                scanf("%s", model);
                deleteRecord(cars, model);
                break;
            case 4:
                printf("\n     Brand \tModel   Year  Body type\n");
                showOff(cars);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    }
    

    return 0;
}