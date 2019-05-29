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
typedef struct disease
{
    int nr_af,
        nr_pac;
    char naming[MAX_STR_LEN];
    time date;
    struct disease *next;
} condition;

typedef struct patient
{
    int nr;
    unsigned long long int id;
    char name[MAX_STR_LEN],
        surname[MAX_STR_LEN];
    time date;
    location address;
    struct patient *next;
    struct disease *sublist;

} person;

condition *diseases = NULL;
person *patients = NULL;

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

void recordPerson(person *p, int nr, char *name, char *surname, unsigned long long int id, time *date, location *address)
{
    p->nr = nr;
    strcpy(p->name, name);
    strcpy(p->surname, surname);
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

void recordDisease(condition *s, int nr, int patient, char *naming, time *date)
{
    s->nr_af = nr;
    s->nr_pac = patient;
    strcpy(s->naming, naming);
    s->date.day = (*date).day;
    s->date.year = (*date).year;
    s->date.month = (*date).month;
    s->next = NULL;
}

// searching
person *searchPatient(person *head, char *name, char *surname)
{
    person *q;

    for (q = head; (q != NULL && strcmp(q->name, name)) || (q != NULL && (strcmp(q->name, name) == 0) && strcmp(q->surname, surname)); q = q->next)
        ;

    return q;
}

condition *searchDisease(condition *head, char *naming)
{
    condition *q;
    for (q = head; q != NULL && strcmp(q->naming, naming); q = q->next)
        ;
    return q;
}

// populating
condition *addDisease(condition *head, int nr, int patient_id, char *naming, time *date)
{
    condition *q1, *q2,
        *token;
    token = (condition *)malloc(sizeof(condition));
    recordDisease(token, nr, patient_id, naming, date);
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

person *addPatient(person *head, int nr, char *name, char *surname, unsigned long long int id, time *date, location *address)
{
    person *q1, *q2,
        *token;
    token = (person *)malloc(sizeof(person));
    recordPerson(token, nr, name, surname, id, date, address);
    for (q1 = q2 = head; q1 != NULL && strcmp(q1->name, token->name) < 0; q2 = q1, q1 = q1->next)
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
condition *readDisease(condition *head, int id, char *path)
{
    int nr,
        patient;
    char naming[MAX_STR_LEN],
        date[MAX_STR_LEN];
    time time;
    FILE *f = NULL;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nEroare la cititrea fișierului %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %d %s %s", &nr, &patient, naming, date);
            time = getDate(date, '/', &time);
        if (id == patient)
            if (searchDisease(head, naming) == NULL)
                head = addDisease(head, nr, patient, naming, &time);
        }
        fclose(f);
    }
    return head;
}

person *readPatient(person *head, char *path)
{
    int nr;
    unsigned long long int id;
    char name[MAX_STR_LEN],
        surname[MAX_STR_LEN],
        date[MAX_STR_LEN],
        address[MAX_STR_LEN];
    time time;
    location location;
    person *p;
    condition *c;
    FILE *f;
    if ((f = fopen(path, "rt")) == NULL)
        printf("\nEroare la cititrea fișierului %s", path);
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d %s %s %llu %s %[^\n]s", &nr, name, surname, &id, date, address);
            trim(address, '\"');
            time = getDate(date, '/', &time);
            location = getAddress(address, ',', &location);
            if (searchPatient(head, name, surname) == NULL)
            {
                head = addPatient(head, nr, name, surname, id, &time, &location);
            }
            p = searchPatient(head, name, surname);
            c = p->sublist;
            c = readDisease(c, nr, "SDA/Project/assets/afectiuni.txt");
            p->sublist = c;
        }
        fclose(f);
    }

    return head;
}

// printings
void displayDiseases(person *patient)
{
    condition *q;
    printf("\n\n\tNr af | Nr pac |  denumire | Zi Luna  An");
    for (q = patient->sublist; q != NULL; q = q->next)
    {
        printf("\n\t %3d  | %4d   |%10s | %2d %3d  %4d",
               q->nr_af,
               q->nr_pac,
               q->naming,
               q->date.day,
               q->date.month,
               q->date.year);
    }
}
void displayPatients(person *patient, unsigned short int required)
{
    person *p;
    printLine(107);
    printf("\n\nNr |  \t  Nume |\tPrenume | \tid\t| Zi Luna  An  | \t Strada Nr Ap\t    Oras      Judet");
    for (p = patient; p != NULL; p = p->next)
    {
        printLine(107);
        printf("\n%2d |%10s |%15s | %13llu | %2d %3d  %4d | %14s %2d %2d %10s %10s",
               p->nr,
               p->name,
               p->surname,
               p->id,
               p->date.day,
               p->date.month,
               p->date.year,
               p->address.strada,
               p->address.nr,
               p->address.ap,
               p->address.oras,
               p->address.district);
        if (p->sublist != NULL && required) {
            displayDiseases(p);
        }
    }
}
int main()
{
    patients = readPatient(patients, "SDA/Project/assets/pacienti.txt");
    displayPatients(patients, 1);
    // displayDiseases(diseases);

    return 0;
}