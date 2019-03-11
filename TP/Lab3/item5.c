#include <stdio.h>

#define MAX 100

char vowels[] = "aeiou";


int isVowel(char ch) {
    int i;
    for (i = 0; i < 5; i++) {
        if ( ch == vowels[i]) {
            return i+1;
        }
    };
    return 0;
}

void incLetters(char (*text)[], int (*arr)[]) {

    int i, j,
        k = 0;

    for (i = 0; (*text)[i] != '\0'; i++) {
        k = isVowel( (*text)[i] );
        (*arr)[k]++;
    }
}


int main() {

    char t1[MAX],
        t2[MAX];
    int vowels1[6] = {0},
        vowels2[6] = {0},
        i;
    printf("Insert first string: ");
    scanf("%s", t1);

    printf("Insert second string: ");
    scanf("%s", t2);

    incLetters( &t1, &vowels1);
    incLetters( &t2, &vowels2);
    
    
    printf("\n\nVowels in first and second text:");
    for(i = 1; i <= 5; i++) {
        printf("\n %c: %d: %d", vowels[i-1], vowels1[i], vowels2[i]);
    }
    

    return 0;
}