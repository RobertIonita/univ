#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STR_LEN 50

// structs
typedef struct
{
    unsigned short int day,
        month,
        year;
} time;

typedef struct
{
    char strada[MAX_STR_LEN],
        oras[MAX_STR_LEN],
        district[MAX_STR_LEN];
    int nr,
        ap;
} location;
typedef struct afectiune
{
    int nr_af,
        nr_pac;
    char denumire[MAX_STR_LEN];
    time date;
    struct afectiune *next;
} stare;

typedef struct pacient
{
    int nr;
    unsigned long long int id;
    char nume[MAX_STR_LEN],
        prenume[MAX_STR_LEN];
    time date;
    location address;
    struct pacient *next;
} person;

stare *afectiuni = NULL;
person *pacienti = NULL;

// utils
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

void printLine(int count)
{
    printf("\n");
    for (size_t i = 0; i < count; i++)
        printf("-");
}
void split(int length, char (*token)[length], char *str, char separator)
{
    int j = 0, k = 0, i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != separator)
        {
            token[k][j++] = str[i];
        }
        else
        {
            token[k][j] = '\0';
            k++;
            j = 0;
        }
    }
}

time getDate(char *str, char separator, time *date)
{
    char token[3][4];
    split(4, token, str, separator);
    date->day = atoi(token[0]);
    date->month = atoi(token[1]);
    date->year = atoi(token[2]);
    return (*date);
}

location getAddress(char *str, char separator, location *address)
{
    char token[5][MAX_STR_LEN];
    split(MAX_STR_LEN, token, str, separator);
    strcpy(address->strada, trim(token[0], ' '));
    address->nr = atoi(token[1]);
    address->ap = atoi(token[2]);
    strcpy(address->oras, trim(token[3], ' '));
    strcpy(address->district, trim(token[4], ' '));
    return (*address);
}

void recordPerson(person *p, int nr, char *nume, char *prenume, unsigned long long int id, time *date, location *address)
{
    p->nr = nr;
    strcpy(p->nume, nume);
    strcpy(p->prenume, prenume);
    p->id = id;
    p->date.day = (*date).day;
    p->date.year = (*date).year;
    p->date.month = (*date).month;
    strcpy(p->address.strada, (*address).strada);
    p->address.nr = (*address).nr;
    p->address.ap = (*address).ap;
    strcpy(p->address.oras, (*address).oras);
    strcpy(p->address.district, (*address).district);
    p->next = NULL;
}

void recordDisease(stare *s, int nr, int pacient, char *denumire, time *date)
{
    s->nr_af = nr;
    s->nr_pac = pacient;
    strcpy(s->denumire, denumire);
    s->date.day = (*date).day;
    s->date.year = (*date).year;
    s->date.month = (*date).month;
    s->next = NULL;
}
// populating
stare *addDisease(person *pacient, stare *head, int nr, int pacient_id, char *denumire, time *date)
{
    stare *q1, *q2,
        *token;
    token = (stare *)malloc(sizeof(stare));
    recordDisease(token, nr, pacient_id, denumire, date);
    for (q1 = q2 = head; q1 != NULL && q1->nr_af < token->nr_af; q2 = q1, q1 = q1->next)
        ;
    if (q1 == q2)
    {
        token->next = head;
        head = token;
    }
    else
    {
        q2->next = token;
        token->next = q1;
    }
    return head;
}

person *addPatient(person *head, int nr, char *nume, char *prenume, unsigned long long int id, time *date, location *address)
{
    person *q1, *q2,
        *token;
    token = (person *)malloc(sizeof(person));
    recordPerson(token, nr, nume, prenume, id, date, address);
    for (q1 = q2 = head; q1 != NULL && strcmp(q1->nume, token->nume) < 0; q2 = q1, q1 = q1->next)
        ;
    if (q1 == q2)
    {
        token->next = head;
        head = token;
    }
    else
    {
        q2->next = token;
        token->next = q1;
    }
    return head;
}

// readings
stare *readDisease(person *pacient, stare *afectiune, char *path)
{
    int val_nr,
        val_pacient;
    char val_denumire[MAX_STR_LEN],
        val_date[MAX_STR_LEN];
    time val_time;
    FILE *f;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nError reading file: %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %d %s %s", &val_nr, &val_pacient, val_denumire, val_date);
            val_time = getDate(val_date, '/', &val_time);
            afectiune = addDisease(pacient, afectiune, val_nr, val_pacient, val_denumire, &val_time);
        }
        fclose(f);
    }
    return afectiune;
}

person *readPatient(person *pacienti, char *path)
{
    int val_nr;
    unsigned long long int val_id;
    char val_nume[MAX_STR_LEN],
        val_prenume[MAX_STR_LEN],
        val_date[MAX_STR_LEN],
        val_address[MAX_STR_LEN];
    time val_time;
    location val_location;
    FILE *f;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nEroare la cititrea fișierului %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %s %s %llu %s %[^\n]s", &val_nr, val_nume, val_prenume, &val_id, val_date, val_address);
            trim(val_address, '\"');
            val_time = getDate(val_date, '/', &val_time);
            val_location = getAddress(val_address, ',', &val_location);
            pacienti = addPatient(pacienti, val_nr, val_nume, val_prenume, val_id, &val_time, &val_location);
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
    printf("\n\nNr af | Nr pac |  Denumire | day month  An");
    for (q = afectiune; q != NULL; q = q->next)
    {
        printLine(41);
        printf("\n %3d  | %4d   |%10s | %2d %3d  %4d",
               q->nr_af,
               q->nr_pac,
               q->denumire,
               q->date.day,
               q->date.month,
               q->date.year);
    }
}
void afiseazaPacienti(person *pacient)
{
    person *q;
    printLine(107);
    printf("\n\nNr |  \t  Nume |\tPrenume | \tid\t| day month  An  | \t Strada Nr Ap\t    Oras      district");
    for (q = pacient; q != NULL; q = q->next)
    {
        printLine(107);
        printf("\n%2d |%10s |%15s | %13llu | %2d %3d  %4d | %14s %2d %2d %10s %10s",
               q->nr,
               q->nume,
               q->prenume,
               q->id,
               q->date.day,
               q->date.month,
               q->date.year,
               q->address.strada,
               q->address.nr,
               q->address.ap,
               q->address.oras,
               q->address.district);
    }
}
int main()
{
    pacienti = readPatient(pacienti, "SDA/Project/assets/pacienti.txt");
    afiseazaPacienti(pacienti);
    afectiuni = readDisease(pacienti, afectiuni, "SDA/Project/assets/afectiuni.txt");
    afiseazaAfectiuni(afectiuni);

    return 0;
}