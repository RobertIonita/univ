#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct medicament
{
	char nume[MAX];
	int cantitate;
	struct medicament *urm;
} medicament;

typedef struct reteta
{
	char nume[MAX];
	struct reteta *urm;
	struct medicament *sublista;
} reteta;

typedef struct stoc
{
	char nume[MAX];
	int cantitate;
	int pret;
	struct stoc *urm;
} stoc;

reteta *cautare_reteta(reteta *prescriptie, char *nume)
{
	reteta *q;
	for (q = prescriptie; q != NULL && strcmp(q->nume, nume); q = q->urm)
		;
	return q;
}

stoc *adaugare_stoc(stoc *depozit, char *nume, int cantitate, int pret)
{
	stoc *q1, *q2, *aux;
	aux = (stoc *)malloc(sizeof(stoc));
	strcpy(aux->nume, nume);
	aux->cantitate = cantitate;
	aux->pret = pret;
	aux->urm = NULL;
	for (q1 = q2 = depozit; q1 != NULL && strcmp(q1->nume, aux->nume) < 0; q2 = q1, q1 = q1->urm)
		;
	if (q1 == q2)
	{
		aux->urm = depozit;
		depozit = aux;
	}
	else
	{
		q2->urm = aux;
		aux->urm = q1;
	}
	return depozit;
}

reteta *adaugare_reteta(reteta *prescriptie, char *nume) //char * med1, int cantitate1, char * med2, int cantitate2, char * med3, int cantitate3
{
	reteta *q1, *q2, *aux;
	aux = (reteta *)malloc(sizeof(reteta));
	strcpy(aux->nume, nume);
	aux->urm = NULL;
	aux->sublista = NULL;
	for (q1 = q2 = prescriptie; q1 != NULL && strcmp(q1->nume, aux->nume) < 0; q2 = q1, q1 = q1->urm)
		;
	if (q1 == q2)
	{
		aux->urm = prescriptie;
		prescriptie = aux;
	}
	else
	{
		q2->urm = aux;
		aux->urm = q1;
	}
	return prescriptie;
}

medicament *adaugare_med(medicament *med, char *nume_med, int cantitate)
{
	medicament *q1, *q2, *aux;
	aux = (medicament *)malloc(sizeof(medicament));
	strcpy(aux->nume, nume_med);
	aux->cantitate = cantitate;
	aux->urm = NULL;

	for (q1 = q2 = med; q1 != NULL && strcmp(q1->nume, aux->nume) < 0; q2 = q1, q1 = q1->urm)
		;
	if (q1 == q2)
	{
		aux->urm = med;
		med = aux;
	}
	else
	{
		q2->urm = aux;
		aux->urm = q1;
	}
	return med;
}

stoc *citire_stoc(stoc *depozit, char *str)
{
	FILE *f = NULL;
	char nume[MAX];
	int cantitate, pret;
	if ((f = fopen(str, "rt")) == NULL)
	{
		printf("\nEroare la citire_stoca fisierului");
	}
	else
	{
		while (!feof(f))
		{
			fscanf(f, "%s %d %d", nume, &cantitate, &pret);
			depozit = adaugare_stoc(depozit, nume, cantitate, pret);
		}
		fclose(f);
	}

	return depozit;
}

reteta *citire_reteta(reteta *prescriptie, char *str)
{
	FILE *f = NULL;
	medicament *med = NULL;
	reteta *r = NULL;
	char nume[MAX],
		med1[MAX],
		med2[MAX],
		med3[MAX];
	int cantitate1, cantitate2, cantitate3;
	if ((f = fopen(str, "rt")) == NULL)
	{
		printf("\nEroare la citirea fisierului");
	}
	else
	{
		while (!feof(f))
		{
			fscanf(f, "%s %s %d %s %d %s %d", nume, med1, &cantitate1, med2, &cantitate2, med3, &cantitate3);
			if (cautare_reteta(prescriptie, nume) == NULL)
				prescriptie = adaugare_reteta(prescriptie, nume);
			r = cautare_reteta(prescriptie, nume);
			med = r->sublista;
			med = adaugare_med(med, med1, cantitate1);
			med = adaugare_med(med, med2, cantitate2);
			med = adaugare_med(med, med3, cantitate3);
			r->sublista = med;
		}
		fclose(f);
	}

	return prescriptie;
}

void afisare_stoc(stoc *depozit)
{
	stoc *q;
	for (q = depozit; q != NULL; q = q->urm)
	{
		printf("\n%s %2d %2d",
			   q->nume,
			   q->cantitate,
			   q->pret);
	}
}

void afisare_reteta(reteta *prescriptie)
{
	reteta *r;
	medicament *m;
	for (r = prescriptie; r != NULL; r = r->urm)
	{
		printf("\n%s", r->nume);
		if (r->sublista != NULL)
			for (m = r->sublista; m != NULL; m = m->urm)
				printf("\n\t%s %2d", m->nume, m->cantitate);
	}
}

void meniu()
{
	int optiune;
	stoc *depozit = NULL;
	reteta *prescriptie = NULL;
	do
	{
		printf("\n1. Incarca datele din fisiere");
		printf("\n2. Afiseaza lista retetelor in ordine alfabetica.");
		printf("\n3. Verifica pentru o reteta citita de la tastatura daca exista toate medicamentele in stoc si care e pretul ei in acest caz.");
		printf("\n4. Afiseaza lista medicamentelor in ordine alfabetica din stoc cu informatiile legate de ele.");
		printf("\n5. Adauga/sterge o reteta in/din lista");
		printf("\n6. Adauga/sterge/modifica un medicament in/din lista");
		printf("\n7. Salvare inapoi in fisierele aferente a retetelor si medicamentelor.");
		printf("\n0. Pentru a finisa executia programului");
		printf("\nOptiunea dorita: ");
		scanf("%d", &optiune);
		switch (optiune)
		{
		case 1:
			if (!prescriptie && !depozit) {
				prescriptie = citire_reteta(prescriptie, "SDA/Teodora❤️/retete.txt");
				depozit = citire_stoc(depozit, "SDA/Teodora❤️/stoc.txt");
				printf("\nDatele din fisiere au fost încărcate\n");
			} else {
				printf("\nDatele au fost deja încărcate anterior\n");
			}
			break;
		case 2:
			afisare_reteta(prescriptie);
			break;
		case 3:
			afisare_reteta(prescriptie);
			break;
		case 4:
			afisare_stoc(depozit);
			break;
		case 0:
			printf("\n\nO zi buna sa aveti😋");
			break;
		default:
			printf("\nOptiune inexistenta\n");
			break;
		}
	} while (optiune != 0);
}

int main()
{
	meniu();
	return 0;
}