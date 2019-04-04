#include <stdio.h>
#include <string.h>
#define MAX 30


typedef struct {
    char name[MAX],
        value[MAX];
} string;

typedef struct {
    char name[MAX],
        value;
} ch;

typedef struct {
    char name[MAX];
    float value;
} real;

typedef struct {
    char name[MAX];
    int value;
} integer;

typedef union {
    string strings;
    ch chars;
    real reals;
    integer ints;
} type;


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

void typeOf(char *str) {
    int i,
        string = 0, real = 0;
    
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
            printf("char");
        } else
            printf("string");
    } else if(real) {
        printf("float");
    } else
        printf("integer");
}
void extractValue(char *str) {
    int i = strlen(str);
    printf("\ntype is:"); 
    typeOf(str);

    if( (str[0] == 34 && str[i-1] == 34) || (str[0] == 39 && str[i-1] == 39) ) {
        str[i-1] = '\0';
        shift(str, 1);
    }
    printf("\nvalue is:%s", str);
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

void split(char *str) {
    char name[MAX],
        value[MAX];
    int i, k = 1;
    for(i = 0; str[i] != '='; i++, k++){
        name[i] = str[i];
    }
    name[i] = '\0';
    trim(name, ' ');
    if(!validateName(name)) {
        printf("\nInvalid name!");
    } else {
        printf("\nname is:%s", name);
        for(i = 0; str[i] != '\0'; i++){
            value[i] = str[i+k];
        }
        trim(value, ' ');
        extractValue(value);
    }
}

void populate() {
    char input[MAX],
        name[MAX],
        value[MAX];
    printf("\nEnter input:");
    scanf("%[^\n]s", input);
    
    if (matches(input, '=')) {
        split(input);
    } else {
        printf("\nInvalid input, assignemt operator is missing!");
    }
}

int main() {
    type records[10];
    char input[MAX];
    int option,
        count = -1;

    while(1) {
        printf("\n\n0. Exit");
        printf("\n0. Read input");
        printf("\n2. Display records");
        printf("\nYour choice: ");
        scanf("%d", &option);
        switch (option)
        {
            case 0:
                return 0;
            case 1:
                populate(records, &count, option);
            default:
                printf("\nInvalid option");
                break;
        }
    }
    
    return 0;
}