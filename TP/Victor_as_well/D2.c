#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pos = 0;
FILE *binary_file;

struct
{
	int anul;	  //Anul aparitiei revistei
} t[10];

void Adaugare()
{

	int aux;
	printf("Anul aparitiei revistei: ");
	scanf("%d", &t[pos].anul);
	pos++;
}

void Afisare()
{
	int aux;
	for (int i = 0; i < pos; i++)
	{
		printf("Anul: %d\n", t[i].anul);
		aux = t[i].anul;
		fwrite(&aux, 4, 1, binary_file);
		printf("\n");
	}
}
void showOff(char *path);

int main(int argc, char *argv[])
{

	Adaugare();
	//Adaugare();
	binary_file = fopen(argv[1], "wb");
	Afisare();
	showOff(argv[1]);
	fclose(binary_file);
}

void showOff(char *path) {
    FILE *f;
	char str[10];
	unsigned int k;
	f = fopen(path, "rb");
    while (pos--)
    {
		fread(&k, 4, 1, f);
		printf("\nvalue: %u", k);
    }
    printf("\n");
	fclose(f);
}