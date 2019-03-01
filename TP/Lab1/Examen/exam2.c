/*2.Sa se scrie o functie recurenta(recursiva) care primeste doua numere: un numar initial N si un numar de adunat la el,q, numere intregi si pozitive. 
O functie este recursiva daca se apeleaza in interiorul ei pe ea insasi.
Functia va returna rezultatul adunarii lui n cu q, folosind doar operatia de incrementare si nicio instructiune de ciclare sau de salt.*/
#include <stdio.h>
#include <string.h>

int summ(int n, int q) {
    return q==0 ? n : summ(++n, --q);
}

int exam2(void) {
    int N, Q;
    printf("Insert 'N': ");
    scanf("%d", &N);

    printf("Insert 'Q': ");
    scanf("%d", &Q);

    printf("%d", summ(N,Q));
    return 0;
}
