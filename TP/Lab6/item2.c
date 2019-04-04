#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

typedef struct {
    char name[7];
} types;
typedef struct {
    char name[MAX],
        value[MAX];
    types type;
} string;

typedef struct {
    char name[MAX],
        value;
    types type;
} ch;

typedef struct {
    char name[MAX];
    float value;
    types type;
} real;

typedef struct {
    char name[MAX];
    int value;
    types type;
} integer;

typedef union {
    string strings;
    ch chars;
    real reals;
    integer ints;
} vars;

int matches(char *str, char ch) {

    int i, k = 0;
    for (i = 0;  str[i] != '\0'; i++) {
        if ( str[i] == ch) k++;
    }
    return k;
}

void shift(char *str, int times) {
    int i = 0;
    for(i = 0; str[i+times] != '\0'; i++) {
        str[i] = str[i+times];
    }
    str[i] = '\0';
}

void trim(char *str, char ch) {
    int i;
    for(i = 0; str[i] != '\0'; i++);
    
    while(str[--i] == ch){
        str[i] = '\0';
    }
    i = -1;
    while(str[++i] == ch)
    ;
    shift(str, i);
}

void typeOf(char *str, char *type) {
    int i,
        string = 0, real = 0;
    strcpy(type, "integer");
    for(i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            real++;
        }
        if (real != 1 && (str[i] == ' ' || str[i] > '9' || str[i] < '0') ) {
            string++;
        }
    }
    if(string) {
        if (strlen(str) == 1 || (str[0] == 39 && str[2] == 39) ) {
            strcpy(type, "char");
        } else
            strcpy(type, "string");
    } else if(real)
        strcpy(type, "float");
}
void extractValue(char *str, char *type) {
    int i = strlen(str);
    typeOf(str, type);
    if( (str[0] == 34 && str[i-1] == 34) || (str[0] == 39 && str[i-1] == 39) ) {
        str[i-1] = '\0';
        shift(str, 1);
    }
}

int validateName(char *str) {
    int i;
    if ( !(
            (str[0] <= 'z' && str[0] >= 'a') ||
            (str[0] <= 'Z' && str[0] >= 'A') 
        )){
        return 0;
    }
    for(i = 0; str[i] != '\0'; i++) {
        if (!( 
                (str[i] <= 'z' && str[i] >= 'a') ||
                (str[i] <= 'Z' && str[i] >= 'A') || 
                (str[i] <= '9' && str[i] >= '0') 
            )) {
            return 0;
        }
    }
    
    return 1;
}

int split(char *str, char *name, char *value) {
    int i, k = 1;
    for(i = 0; str[i] != '='; i++, k++){
        name[i] = str[i];
    }
    name[i] = '\0';
    trim(name, ' ');
    if(!validateName(name)) {
        printf("\nInvalid name!");
        return 0;
    } else {
        for(i = 0; str[i] != '\0'; i++){
            value[i] = str[i+k];
        }
        trim(value, ' ');
        extractValue(value, str);
    }
    return 1;
}

void read(vars *record, int *count) {
    char input[MAX],
        name[MAX],
        value[MAX];
    printf("\nEnter input:");
    while(getchar() != '\n')
    ;
    scanf("%[^\n]s", input);
    
    if (!matches(input, '=')) {
        printf("\nInvalid input, assignemt operator is missing!");
    } else if (split(input, name, value)) {
        (*count)++;
        switch (input[0]) {
            case 's':
                strcpy(record[*count].strings.name, name);
                strcpy(record[*count].strings.value, value);
                strcpy(record[*count].strings.type.name, input);
                printf("\nRecord %d:\nname: %s\nvalue: %s\ntype: %s",
                    (*count)+1,
                    record[*count].strings.name,
                    record[*count].strings.value,
                    record[*count].strings.type.name
                );
                break;
            case 'c':
                strcpy(record[*count].chars.name, name);
                record[*count].chars.value = value[0];
                strcpy(record[*count].chars.type.name, input);
                printf("\nRecord %d:\nname: %s\nvalue: %c\ntype: %s",
                    (*count)+1,
                    record[*count].chars.name,
                    record[*count].chars.value,
                    record[*count].chars.type.name
                );
                break;
            case 'i':
                strcpy(record[*count].ints.name, name);
                record[*count].ints.value = atoi(value);
                strcpy(record[*count].ints.type.name, input);
                printf("\nRecord %d:\nname: %s\nvalue: %d\ntype: %s",
                    (*count)+1,
                    record[*count].ints.name,
                    record[*count].ints.value,
                    record[*count].ints.type.name
                );
                break;
            case 'f':
                strcpy(record[*count].reals.name, name);
                record[*count].reals.value = atof(value);
                strcpy(record[*count].reals.type.name, input);
                printf("\nRecord %d:\nname: %s\nvalue: %f\ntype: %s",
                    (*count)+1,
                    record[*count].reals.name,
                    record[*count].reals.value,
                    record[*count].reals.type.name
                );
                break;
        }
    }

}
int main() {
    vars records[10];
    int option,
        count = -1,
        i;
    while(1) {
        printf("\n\n0. Exit");
        printf("\n1. Read input");
        printf("\nYour choice: ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                return 0;
            case 1:
                read(records, &count);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    }
    
    return 0;
}