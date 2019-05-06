#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void citeste(char ** nume, int * varsta) {
    *nume = (char *) malloc(4 * sizeof(char));
    printf("Introduceti numele: ");
    scanf("%s", *nume);
    printf("Introduceti varsta: ");
    scanf("%d", &(*varsta));
}
void scrie(char * nume, int varsta) {
    printf("%s,%d\n", nume, varsta);
}
int main(void) {
    char * nume;
    int varsta;
    citeste( & nume, & varsta);
    scrie(nume, varsta);
    free(nume);

    return 0;
}