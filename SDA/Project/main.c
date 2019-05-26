#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STR_LEN 50

// structuri
typedef struct
{
    unsigned short int zi,
        luna,
        an;
} timp;

typedef struct
{
    char strada[MAX_STR_LEN],
        oras[MAX_STR_LEN],
        judet[MAX_STR_LEN];
    int nr,
        ap;
} locuinta;
typedef struct afectiune
{
    int nr_af,
        nr_pac;
    char denumire[MAX_STR_LEN];
    timp data;
    struct afectiune *urm;
} stare;

typedef struct pacient
{
    int nr;
    unsigned long long int cnp;
    char nume[MAX_STR_LEN],
        prenume[MAX_STR_LEN];
    timp data;
    locuinta adresa;
    struct pacient *urm;
} persoana;

stare *afectiuni = NULL;
persoana *pacienti = NULL;

// utilități
void shift(char *str, int times)
{
    int i = 0;
    for (i = 0; str[i + times] != '\0'; i++)
        str[i] = str[i + times];
    str[i] = '\0';
}

char *trim(char *str, char ch)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    while (str[--i] == ch)
        str[i] = '\0';
    i = -1;
    while (str[++i] == ch)
        ;
    shift(str, i);
    return str;
}

void printeazaLinie(int count)
{
    printf("\n");
    for (size_t i = 0; i < count; i++)
        printf("-");
}
void despicaSir(int lungime, char (*aux)[lungime], char *sir, char separator)
{
    int j = 0, k = 0, i = 0;
    for (i = 0; sir[i] != '\0'; i++)
    {
        if (sir[i] != separator)
        {
            aux[k][j + 1] = '\0';
            aux[k][j++] = sir[i];
        }
        else
        {
            aux[k][j] = '\0';
            k++;
            j = 0;
        }
    }
}

timp dataDinSir(char *sir, char separator, timp *data)
{
    char aux[3][4];
    despicaSir(4, aux, sir, separator);
    data->zi = atoi(aux[0]);
    data->luna = atoi(aux[1]);
    data->an = atoi(aux[2]);
    return (*data);
}

locuinta adresaDinSir(char *sir, char separator, locuinta *adresa)
{
    char aux[5][MAX_STR_LEN];
    despicaSir(MAX_STR_LEN, aux, sir, separator);
    strcpy(adresa->strada, trim(aux[0], ' '));
    adresa->nr = atoi(aux[1]);
    adresa->ap = atoi(aux[2]);
    strcpy(adresa->oras, trim(aux[3], ' '));
    strcpy(adresa->judet, trim(aux[4], ' '));
    return (*adresa);
}

void creeazaPersoana(persoana *p, int nr, char *nume, char *prenume, unsigned long long int cnp, timp *data, locuinta *adresa)
{
    p->nr = nr;
    strcpy(p->nume, nume);
    strcpy(p->prenume, prenume);
    p->cnp = cnp;
    p->data.zi = (*data).zi;
    p->data.an = (*data).an;
    p->data.luna = (*data).luna;
    strcpy(p->adresa.strada, (*adresa).strada);
    p->adresa.nr = (*adresa).nr;
    p->adresa.ap = (*adresa).ap;
    strcpy(p->adresa.oras, (*adresa).oras);
    strcpy(p->adresa.judet, (*adresa).judet);
    p->urm = NULL;
}

void creeazaAfectiune(stare *p, int nr, int pacient, char *denumire, timp *data)
{
    p->nr_af = nr;
    p->nr_pac = pacient;
    strcpy(p->denumire, denumire);
    p->data.zi = (*data).zi;
    p->data.an = (*data).an;
    p->data.luna = (*data).luna;
    p->urm = NULL;
}
// adăugări
stare *adaugaAfectiune(stare *prima, int nr, int pacient, char *denumire, timp *data)
{
    stare *q1, *q2,
        *aux;
    aux = (stare *)malloc(sizeof(stare));
    creeazaAfectiune(aux, nr, pacient, denumire, data);
    for (q1 = q2 = prima; q1 != NULL && q1->nr_af < aux->nr_af; q2 = q1, q1 = q1->urm)
        ;
    if (q1 == q2)
    {
        aux->urm = prima;
        prima = aux;
    }
    else
    {
        q2->urm = aux;
        aux->urm = q1;
    }
    return prima;
}

persoana *adaugaPacient(persoana *prima, int nr, char *nume, char *prenume, unsigned long long int cnp, timp *data, locuinta *adresa)
{
    persoana *q1, *q2,
        *aux;
    aux = (persoana *)malloc(sizeof(persoana));
    creeazaPersoana(aux, nr, nume, prenume, cnp, data, adresa);
    for (q1 = q2 = prima; q1 != NULL && strcmp(q1->nume, aux->nume) < 0; q2 = q1, q1 = q1->urm)
        ;
    if (q1 == q2)
    {
        aux->urm = prima;
        prima = aux;
    }
    else
    {
        q2->urm = aux;
        aux->urm = q1;
    }
    return prima;
}

// citiri
stare *citireAfectiuni(stare *afectiune, char *cale)
{
    int val_nr,
        val_pacient;
    char val_denumire[MAX_STR_LEN],
        val_data[MAX_STR_LEN];
    timp val_timp;
    FILE *f;
    if ((f = fopen(cale, "rt")) == NULL)
        printf("\nEroare la cititrea fișierului %s", cale);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %d %s %s", &val_nr, &val_pacient, val_denumire, val_data);
            val_timp = dataDinSir(val_data, '/', &val_timp);
            // afectiune = adaugaAfectiune(afectiune, val_nr, val_pacient, val_denumire, &val_timp);
        }
        fclose(f);
    }
    return afectiune;
}

persoana *citirePacienti(persoana *pacienti, char *cale)
{
    int val_nr;
    unsigned long long int val_cnp;
    char val_nume[MAX_STR_LEN],
        val_prenume[MAX_STR_LEN],
        val_data[MAX_STR_LEN],
        val_adresa[MAX_STR_LEN],
        *token;
    timp val_timp;
    locuinta val_locuinta;
    FILE *f;
    if ((f = fopen(cale, "rt")) == NULL)
        printf("\nEroare la cititrea fișierului %s", cale);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %s %s %llu %s %[^\n]s", &val_nr, val_nume, val_prenume, &val_cnp, val_data, val_adresa);
            trim(val_adresa, '\"');
            val_timp = dataDinSir(val_data, '/', &val_timp);
            val_locuinta = adresaDinSir(val_adresa, ',', &val_locuinta);
            // pacienti = adaugaPacient(pacienti, val_nr, val_nume, val_prenume, val_cnp, &val_timp, &val_locuinta);
            continue;
        }
        fclose(f);
    }
    return pacienti;
}

// afișări
void afiseazaAfectiuni(stare *afectiune)
{
    stare *q;
    printf("Nr af | Nr pac |  Denumire | Zi Luna  An");
    for (q = afectiune; q != NULL; q = q->urm)
    {
        printeazaLinie(41);
        printf("\n %3d  | %4d   |%10s | %2d %3d  %4d",
               q->nr_af,
               q->nr_pac,
               q->denumire,
               q->data.zi,
               q->data.luna,
               q->data.an);
    }
}
void afiseazaPacienti(persoana *pacient)
{
    persoana *q;
    printeazaLinie(107);
    printf("\nNr |  \t  Nume |\tPrenume | \tCNP\t| Zi Luna  An  | \t Strada Nr Ap\t    Oras\t  Judet");
    for (q = pacient; q != NULL; q = q->urm)
    {
        printeazaLinie(107);
        printf("\n%2d |%10s |%15s | %13llu | %2d %3d  %4d | %14s %2d %2d %10s %10s",
               q->nr,
               q->nume,
               q->prenume,
               q->cnp,
               q->data.zi,
               q->data.luna,
               q->data.an,
               q->adresa.strada,
               q->adresa.nr,
               q->adresa.ap,
               q->adresa.oras,
               q->adresa.judet);
    }
}
int main()
{
    afectiuni = citireAfectiuni(afectiuni, "SDA/Project/assets/afectiuni.txt");
    afiseazaAfectiuni(afectiuni);
    pacienti = citirePacienti(pacienti, "SDA/Project/assets/pacienti.txt");
    afiseazaPacienti(pacienti);

    return 0;
}