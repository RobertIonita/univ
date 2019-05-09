#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct item {
    char name[MAX],
        location[MAX];
    struct item * next;
} node;

node * map_nam = NULL;
node * map_loc = NULL;
node * add (node * first, char * name, char * location, int normal) {
    node *q1, *q2,
        *clone;
    clone = (node *)malloc(sizeof(node));
    strcpy(clone -> name, name);
    strcpy(clone -> location, location);
    clone -> next = NULL;
    if (normal) {
        for(q1 = q2 = first; q1 != NULL && (strcmp(q1 -> name, clone -> name) < 0); q2 = q1, q1 = q1 -> next);
    } else{
        for(q1 = q2 = first; q1 != NULL && (strcmp(q1 -> location, clone -> location) < 0); q2 = q1, q1 = q1 -> next);
    }
    
    if (q1 == q2) {
        clone -> next = first;
        first = clone;
    } else {
        q2 -> next = clone;
        clone -> next = q1;
    }
    return first;
}

void read(char * path) {
    char name[MAX],
        location[MAX];
    FILE *f;
    if( (f = fopen(path, "rt") ) == NULL) {
        printf("\nerror reading file");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s %s", name, location);
            map_nam = add(map_nam, name, location, 1);
            map_loc = add(map_loc, name, location, 0);
        }
        fclose(f);
    }
}

node * deleteItem (node * item, char * visited) {
    node *q1, *q2;
    for (q1 = q2 = item; q1 != NULL && strcmp (q1 -> name, visited); q2 = q1, q1 = q1 -> next);

    if (q1 != NULL && (strcmp (q1 -> name, visited) == 0) ) {
        if (q1 == q2) {
            item = item -> next;
        } else {
            q2 -> next = q1 -> next;
            free(q1);
        }
    }
    return item;
}

void showOff(node * item) {
    node *q1;
    for (q1 = item; q1 != NULL; q1 = q1 -> next) {
        printf("\n%s %s",
            q1 -> name,
            q1 -> location
        );
    }
}
int main() {
    char visited[MAX];
    read("SDA/TEST/gradini_Anglia.txt");
    printf("\nGardens sorted by name: \n"); showOff(map_nam);
    printf("\nGardens sorted by location: \n"); showOff(map_loc);

    printf("\nInsert garden that you already visited: ");
    scanf("%s", visited);
    map_nam = deleteItem(map_nam, visited);
    printf("\nGardens after visit: \n"); showOff(map_nam);
    return 0;
}
