/* 1. Scrieti functie str_anagram(char *s1,char *s2) care primeste ca parametri doua siruri de caractere si decide daca al doile sir de caractere este o anagrama a primului sir de caractere (un sir este o anagrama a altui sir daca el contine exact aceleasi litere ca si primul sir, dar in alta ordine).
Cititi de la tastatura doua cuvinte si verificati folosind functia scrisa daca al doile cuvant este anagrama primului cuvant.*/
#include <stdio.h>
#include <string.h>

void sort(char *st) {
    int i, sorted,
        len = len = strlen(st);
    char clone;
    do {
        sorted = 1;
        for (i = 0; i < len-1; i++) {
            if (st[i] > st[i+1]) {
                sorted = 0;
                clone = st[i];
                st[i] = st[i+1];
                st[i+1] = clone;
            }
        }
    } while (!sorted);
}

int checkIfAnagram(char *s1, char *s2) {
    int i = 0,
        match_len = strlen(s1) == strlen(s2);

    sort(s1); 
    sort(s2); 
    while(match_len && s1[i] !='\0') {
        if(s1[i] != s2[i])
            return 0;
        i++;
    }
    return match_len ? 1 : 0;
}

int exam1(void) {

    char str1[20],
        str2[20];

    printf("Insert 'str1': ");
    scanf("%s", str1);

    printf("Insert 'str2': ");
    scanf("%s", str2);

    printf("Is anagram?: %d", checkIfAnagram(str1, str2));
    return 0;
}
