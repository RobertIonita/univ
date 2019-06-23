#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pos = 0;
FILE *binary_file;

struct
{

	char titlu[30];
	char autor[20];
	int nr_pag : 6;
	int cr : 1;	//Carte sau revista
	char ISBN[13]; //ISBN pentru carte
	int anul;	  //Anul aparitiei revistei
} t[10];

void Adaugare()
{

	int aux;

	while (getchar() != '\n')
		;
	printf("Titlul cartii: ");
	gets(t[pos].titlu);
	printf("Autorul cartii: ");
	gets(t[pos].autor);
	printf("Numarul de pagini: ");
	scanf("%d", &aux);
	t[pos].nr_pag = aux;
	printf("Carte sau revista? ");
	scanf("%d", &aux);
	t[pos].cr = aux;
	if (aux == 0)
	{
		printf("ISBN-ul cartii: ");
		scanf("%s", t[pos].ISBN);
	}
	else
	{
		printf("Anul aparitiei revistei: ");
		scanf("%d", &t[pos].anul);
	}
	pos++;
	printf("\n");
}

void Afisare()
{

	int aux;

	for (int index = 0; index < pos; index++)
	{
		printf("Titlul cartii: ");
		puts(t[index].titlu);
		fwrite(t[index].titlu, strlen(t[index].titlu), 1, binary_file);
		printf("Autorul cartii: ");
		puts(t[index].autor);
		fwrite(t[index].autor, strlen(t[index].autor), 1, binary_file);
		printf("Numarul de pagini: %d\n", t[index].nr_pag);
		aux = t[index].nr_pag;
		fwrite(&aux, 1, 1, binary_file);
		if (t[index].cr == 0)
		{
			printf("ISBN-ul cartii: %s\n", t[index].ISBN);
			fwrite(t[index].ISBN, 4, 1, binary_file);
		}
		else
		{
			printf("Anul aparitiei revistei: %d\n", t[index].anul);
			aux = t[index].anul;
			fwrite(&aux, 4, 1, binary_file);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{

	Adaugare();
	//Adaugare();
	binary_file = fopen(argv[1], "wb");
	Afisare();
	fclose(binary_file);
}