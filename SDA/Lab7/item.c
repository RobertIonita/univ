#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct item{
    char brand[20],
        name[20],
        type[20];
    int year;
    struct item *next;
} record;


void print(record *);
record * insert_top(char *, char *, char *, int, record *);

record * insert_top(char * brand, char * name, char * type, int year, record * head) {
    record * new_record;
    new_record = (record *) malloc( sizeof(record) );
    strcpy(new_record -> brand, brand);
    new_record -> next = head;
    return head;
}

void print(record * head) {
    record * current_record = head;

    while(current_record != NULL){
        printf("\n%10s %10s %6d %10s",
            current_record -> brand,
            current_record -> name,
            current_record -> year,
            current_record -> type
        );
        current_record = current_record -> next;
    }
}
void read (record * cars, int * count) {
    (*count)++;
    FILE * f;
    if ((f = fopen("SDA/Lab7/file.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s %s %d %s",
                cars[*count].brand,
                cars[*count].name,
                &cars[*count].year,
                cars[(*count)++].type
            );
        }
        fclose(f);
    }
}


void showOff(record * cars, int n) {
    printf("\n%10s %10s %6d %10s",
        cars[n].brand,
        cars[n].name,
        cars[n].year,
        cars[n].type
    );
}

int main () {
    record cars;
    int count = -1,
        i;

    read(&cars, &count);
    printf("\n     Brand \tModel   Year  Body type\n");
    for(i = 0; i <= count; i++) {
        showOff(&cars, i);
    }
    
    
    return 0;
}