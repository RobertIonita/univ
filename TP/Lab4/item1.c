#include <stdio.h>

typedef struct {
	char nume[50];
	float pret;
}Produs;

int main()
{
	Produs produse[100];
	int i, opt,n=0;
	
	while(1) {
        printf("1.Introducere\n");
        printf("2.Afisare\n");
        printf("0.Iesire\n");
		printf("operatia: "); scanf("%d", &opt);
		switch (opt){
            case 1:
                getchar();
                printf("nume: "); gets(produse[n].nume);
                printf("pret: "); scanf("%g", &produse[n].pret);
                n++;
                break;
            case 2:
                for(i = 0; i < n; i++) {
                    printf("%s %g\n", produse[i].nume, produse[i].pret);
                }
                break;
            case 0: return 0;
            default: printf("operatie necunoscuta\n");
		}
	}
}