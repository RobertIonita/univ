#include <stdio.h>
#define MAX 100
typedef struct
{
    int divizor, putere;
}numar;

void divide(int intreg, numar * date, int *ct)
{
    int d=2, p;
    while (intreg > 1)
    {
        (*ct)++;
        p=0;
        while(intreg % d==0)
        {
            p++;
            intreg /= d;
        }
    
        if(p!=0)
        {
            printf("\ndiv: %d",d);
            (date+ *ct) -> divizor = d;
            printf("\nputere: %d",p);
            (date+ *ct) -> putere = p;
            d++;
        }
        if(intreg > 1 && d*d > intreg)
            d=intreg;
    }
}

void afisare(numar * date, int ct) {
    printf("\n%d %d",
        (date + ct) -> divizor,
        date[ct].putere
    );
}

int main()
{
    numar valori[MAX];
    int n, contor = -1, i;
    printf("Numarul este: ");
    scanf("%d",&n);

    divide(n, valori, &contor);
    for(i = 0; i <= contor; i++)
    {
        afisare(valori, i);
    }
    

}