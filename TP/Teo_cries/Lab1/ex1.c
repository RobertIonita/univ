#include <stdio.h>

#include<string.h>

#define MAX 100

void sortare(char (*s)) {
    int n = strlen(s), i, ok = 0, aux;
    do {
        ok = 1;
        for (i = 0; i <n-1; i++)
            if (s[i + 1] < s[i]) {
                aux = s[i + 1];
                s[i + 1] = s[i];
                s[i] = aux;
                ok = 0;
            }
    }while(!ok);                             //BAG PULA IN VIATA
}

int comparare(char sir1[MAX], char sir2[MAX]) {
    int n = strlen(sir1), i, j;
    if(n==strlen(sir2))
    {
        sortare(sir1);
        printf("%s", sir1);
        sortare(sir2);
        printf("%s", sir1);
        if(strcmp(sir1, sir2)==0)
         return 1;        
    }
    return 0;

}

int main() {
    char sir1[MAX], sir2[MAX];
    printf("primul sir este:");
    scanf("%s", sir1);
    printf("al doilea sir este:");
    scanf("%s", sir2);
    printf("%d", comparare(sir1, sir2));

}