/* P3.Citire, afisare valori tablou unidimensional; suma valorilor pe componente. */

#include<stdio.h>
#define N_MAX 200
/* Functie pentru citirea unui tablou.
La tablourile unidimensionale nu e nevoie sa specificam in parametrii dimensiunea tabloului.
Al doilea parametru, n, ne spune cate elemente vrem sa citim. */
void citire (int a[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("elementul %d:",i);
scanf("%d",&a[i]);
}

}
/* Functie pentru afisarea unui tablou.
Din nou nu trebuie sa specificam dimensiunea tabloului.
Al doilea parametru, n, ne spune cate elemente vrem sa afisam. */
void afisare(int a[],int n)

{
int i;
for(i=0;i<n;i++)
	printf(" %d ",a[i]);
printf("\n");

}
int main (void)
{
	int a[N_MAX],b[N_MAX],s[N_MAX];
	int n,i;
	printf("Cate elemente sunt in tablouri?:");
	scanf("%d",&n);
	printf("Primul tablou:\n");
	citire(a,n);
	printf("Al doilea tablou:\n");
	citire(b,n);
/* Construim un tablou care contine suma elementelor din cele doua tablouri. */
	for(i=0;i<n;i++)
		s[i]=a[i]+b[i];
	afisare(a,n);
	afisare(b,n);
	afisare(s,n);
	return 0;



}