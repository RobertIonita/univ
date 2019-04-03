#include <stdio.h>
#include <string.h>
#define MAX 30

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

void trim(char *str) {
    int i,
        length;
    for(i = 0; str[i] != '\0'; i++);
    
    while(str[--i] == ' '){
        str[i] = '\0';
    }
    i = -1;
    while(str[++i] == ' ')
    ;
    shift(str, i);
}

void split(char *str) {
    char name[MAX],
        value[MAX];
    int i, k = 1;
    for(i = 0; str[i] != '='; i++, k++){
        name[i] = str[i];
    }
    name[i] = '\0';
    trim(name);
    if(matches(name, ' ')) {
        printf("\nInvalid name, contains spaces!");
    } else {
        printf("\nname is: %s", name);
        for(i = 0; str[i] != '\0'; i++){
            value[i] = str[i+k];
        }
        trim(value);
        printf("\nvalue is: %s", value);
    }
}

int main() {

    char input[MAX];
    printf("\nEnter input:");
    scanf("%[^\n]s", input);
    
    if (matches(input, '=')) {
        split(input);
    } else {
        printf("\nInvalid input, assignemt operator is missing!");
    }
    
    return 0;
}