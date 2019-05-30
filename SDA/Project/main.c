#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STR_LEN 50 //definesc lungimea maxima pentru un sir de caratere

/* definirea structurilor */

typedef struct
{
    unsigned short int day,
        month,
        year;
} time; // se utilizeaza pentru a stoca in mod comod data

typedef struct
{
    char strada[MAX_STR_LEN],
        oras[MAX_STR_LEN],
        district[MAX_STR_LEN];
    int nr,
        ap;
} location; // se utilizeaza pentru a stoca in mod comod adresa

typedef struct disease
{
    int nr_af,
        nr_pac;
    char naming[MAX_STR_LEN];
    time date;
    struct disease *next;
} condition; // sublista in care se inregistreaza afectiunile

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
} person; // lista in care se inregistreaza pacientii

condition *diseases = NULL; //declararea listei afectiunilor
person *patients = NULL; //declararea listei pacientilor

// functii utile
void shift(char *str, int times)
{
    int i = 0;
    for (i = 0; str[i + times] != '\0'; i++)
        str[i] = str[i + times];
    str[i] = '\0';
} // permuta caracterle din sir la stanga de "times" ori

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
} // sterge caracterele 'ch' nedorite din capetele sirului

void printLine(int count)
{
    printf("\n");
    for (size_t i = 0; i < count; i++)
        printf("-");
} // afiseaza "count" caractere '-'

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
} // sparge sirul in "length" subsiruri formand un vector de siruri (o matrice de caractere)

int compareDates(time *date1, time *date2)
{
    return (date1->year * 365 + date1->month * 30 + date1->day - date2->year * 365 - date2->month * 30 - date2->day);
} // returneaza diferenta dintre doua date calendaristice

time getDate(char *str, char separator, time *date)
{
    char token[3][4];
    split(4, token, str, separator);
    date->day = atoi(token[0]);
    date->month = atoi(token[1]);
    date->year = atoi(token[2]);
    return (*date);
} // converteste sir de caractere in date structurate (data calendaristica)

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
} // converteste sir de caractere in date structurate (adresa)

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
} // incarca nodul cu informatie

void recordDisease(condition *s, int nr, int patient, char *naming, time *date)
{
    s->nr_af = nr;
    s->nr_pac = patient;
    strcpy(s->naming, naming);
    s->date.day = (*date).day;
    s->date.year = (*date).year;
    s->date.month = (*date).month;
    s->next = NULL;
} // incarca nodul cu informatie

/* cautari */
person *searchPatient(person *head, char *name, char *surname)
{
    person *q;

    for (q = head; (q != NULL && strcmp(q->name, name)) || (q != NULL && (strcmp(q->name, name) == 0) && strcmp(q->surname, surname)); q = q->next)
        ;
    return q;
} // cauta in lista o persoana dupa nume si prenume

condition *searchDisease(condition *head, char *naming)
{
    condition *q;
    for (q = head; q != NULL && strcmp(q->naming, naming); q = q->next)
        ;
    return q;
} // cauta in lista o afectiune dupa denumire

/* adaugari */
condition *addDisease(condition *head, int nr, int patient_id, char *naming, time *date)
{
    condition *q1, *q2,
        *token;
    token = (condition *)malloc(sizeof(condition));
    recordDisease(token, nr, patient_id, naming, date);
    for (q1 = q2 = head; q1 != NULL && (compareDates(date, &(token->date)) < 0); q2 = q1, q1 = q1->next)
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
} // adauga o afectiune in sublista cu afectiuni

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
} // adauga o persoana in lista cu pacienti

/* readings */
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
} // citeste din fisier datele despre afectiuni

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
}  // citeste din fisier datele despre pacienti si inlantuie nodurile pacientilor cu cele ale afectiunilor

/* afisari */
void displayDiseases(person *patient)
{
    condition *q;
    printf("\n\nPac|   Nr af   | \t denumire | Zi Luna  An");
    for (q = patient->sublist; q != NULL; q = q->next)
    {
        printf("\n %d |    %3d    |%17s | %2d %3d  %4d",
               q->nr_pac,
               q->nr_af,
               q->naming,
               q->date.day,
               q->date.month,
               q->date.year);
    }
} // afiseaza toate afectiunile unui pacient
void displayPatients(person *patient, unsigned short int required)
{
    person *p;
    printLine(121);
    printf("\n Nr|  \t  Nume | \t  Prenume | Zi Luna  An  | \t  id \t  | \t \t Strada Nr Ap \t  \t  Oras      Judet");
    for (p = patient; p != NULL; p = p->next)
    {
        printLine(121);
        printf("\n%2d |%10s |%17s | %2d %3d  %4d | %13llu | %20s %2d %2d %16s %10s",
               p->nr,
               p->name,
               p->surname,
               p->date.day,
               p->date.month,
               p->date.year,
               p->id,
               p->address.strada,
               p->address.nr,
               p->address.ap,
               p->address.oras,
               p->address.district);
        if (p->sublist != NULL && required)
        {
            displayDiseases(p);
        }
    }
} // afiseaza toati pacientii si afectiunile lor

void searchByDisease(person *head)
{
    person *p;
    condition *c;
    char disease[20];
    printf("\nInserati afectiunea dupa care cautati: ");
    scanf("%s", disease);
    for (p = head; p != NULL; p = p->next)
        for (c = p->sublist; c != NULL; c = c->next)
            if (strcmp(c->naming, disease) == 0)
            {
                printf("\n%s %s", p->name, p->surname);
                continue;
            }
} // afiseza toate persoanele ce au avut afectiunea citita de la tastiera

person *delete (person *head)
{
    char name[20],
        surname[20];
    person *q1, *q2;
    printf("\nIntroduceti numele pacientului: ");
    scanf("%s", name);
    printf("\nIntroduceti prenumele pacientului: ");
    scanf("%s", surname);
    for (q1 = q2 = head; (q1 != NULL && strcmp(q1->name, name)) || (q1 != NULL && (strcmp(q1->name, name) == 0) && strcmp(q1->surname, surname)); q2 = q1, q1 = q1->next)
        ;
    if (q1 != NULL && (strcmp(q1->name, name) == 0) && (strcmp(q1->surname, surname) == 0))
    {
        if (q1 == q2)
        {
            head = head->next;
        }
        else
        {
            q2->next = q1->next;
            free(q1);
        }
    }
    return head;
} // stergerea unui nod din lista pacientilor dupa numele introdus de la tastiera

person *treatPatient(person *head)
{
    char name[20],
        surname[20],
        address[MAX_STR_LEN],
        date[10];
    int nr = 1;
    unsigned long long int cnp;
    time time;
    location location;
    person *p;

    printf("\nIntroduceti numele pacientului: ");
    scanf("%s", name);
    printf("\nIntroduceti prenumele pacientului: ");
    scanf("%s", surname);

    if (searchPatient(head, name, surname) != NULL) {
        printf("\nPacientul deja ia tratament\n");
    } else {
        printf("\nIntroduceti cnp: ");
        scanf("%llu", &cnp);
        printf("\nIntroduceti data nasterii (zz/ll/aaaa): ");
        scanf("%s", date);
        time = getDate(date, '/', &time);
        printf("\n%d/%d/%d", time.day, time.month, time.year);
        printf("\nIntroduceti adresa (strada, nr, ap, oras, judet): ");
        while(getchar() != '\n')
        ;
        scanf("%[^\n]s", address);
        printf("\nad: %s", address);
        location = getAddress(address, ',', &location);
        for (p = head; p != NULL; p = p->next)
        {
            nr++;
        }
        
        head = addPatient(head, nr, name, surname, cnp, &time, &location);

    }
    return head;
} // adaugarea unui nod in lista cu pacienti
void searchPeriod(person *head)
{
    person *p;
    unsigned short int
        day,
        month,
        year;
    char start[10],
        end[10];
    time start_date;
    time end_date;
    printf("\nInserati data de inceput (zz/ll/aaaa): ");
    scanf("%s", start);
    start_date = getDate(start, '/', &start_date);
    printf("\nInserati data de sfarit (zz/ll/aaaa): ");
    scanf("%s", end);
    end_date = getDate(end, '/', &end_date);

    for (p = head; p != NULL; p = p->next)
    {
        if ( (compareDates(&(p->date), &start_date) > 0 ) && (compareDates(&(p->date), &end_date) < 0) ) {
            printf("\n%s %s %d/%d/%d",
                p->name,
                p->surname,
                p->date.day,
                p->date.month,
                p->date.year);
        }
    }
} // afisarea pacientilor ce se incareaza in perioada inserata de la tastiera

/* actualizae */
void updateFiles(person *head)
{
    FILE *f, *g;
    person *p;
    condition *c;
    f = fopen("pacienti_actualizat.txt", "wt");
    g = fopen("afectiuni_actualizat.txt", "wt");
    if (f == NULL || g == NULL)
        printf("\nEroare la scrierea fisierelor");
    else
    {
        for (p = head; p != NULL; p = p->next)
        {
            fprintf(f, "%d %s %s %d %d %d %llu \"%s, %d, %d ,%s, %s\"\n",
                    p->nr,
                    p->name,
                    p->surname,
                    p->date.day,
                    p->date.month,
                    p->date.year,
                    p->id,
                    p->address.strada,
                    p->address.nr,
                    p->address.ap,
                    p->address.oras,
                    p->address.district);
            for (c = p->sublist; c != NULL; c = c->next)
            {
                fprintf(g, " %d %d %s %d/%d/%d\n",
                        c->nr_af,
                        c->nr_pac,
                        c->naming,
                        c->date.day,
                        c->date.month,
                        c->date.year);
            }
        }
        fclose(f);
        fclose(g);
    }
} // incarcare unor fisiere noi cu datele actualizate despre pacienti si afecriunie lor

void meniu()
{
    int optiune;
    person *patient = NULL;
    condition *diseases = NULL;
    do
    {
        printf("\n1. Incarca datele din fisiere");
        printf("\n2. Tipareste alfabetic pacientii si afectiunile in ordine invers cronologica.");
        printf("\n3. Afiseaza numele pacientilor ce au suferit de o anumita afectiune.");
        printf("\n4. Sterge un anumit pacient, datorita mutarii sale la un alt medic de familie.");
        printf("\n5. Tratare pacient");
        printf("\n6. Listare pacienti tratati intr-o anumita periada citita de la tastatura");
        printf("\n7. Actualizare continut fisiere");
        printf("\n8. Parasire program");
        printf("\nOptiunea dorita: ");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
            if (!patients)
            {
                patients = readPatient(patients, "SDA/Project/assets/pacienti.txt");
                printf("\nDatele din fisiere au fost încărcate\n");
            }
            else
                printf("\nDatele au fost deja încărcate anterior\n");
            break;
        case 2:
            if (patients)
                displayPatients(patients, 1);
            else
                printf("\nDatele nu au fost încărcate\n");
            break;
        case 3:
            if (patients)
                searchByDisease(patients);
            else
                printf("\nDatele nu au fost încărcate\n");
            break;
        case 4:
            if (patients)
                patients = delete (patients);
            else
                printf("\nDatele nu au fost încărcate\n");
            break;
        case 5:
            if (patients)
                patients = treatPatient(patients);
            else
                printf("\nDatele nu au fost încărcate\n");
            break;
        case 6:
            if (patients)
                searchPeriod(patients);
            else
                printf("\nDatele nu au fost încărcate\n");
            break;
        case 7:
            if (patients)
                updateFiles(patients);
            else
                printf("\nDatele nu au fost încărcate\n");
            break;
        case 8:
            printf("\n\nFinisat");
            break;
        default:
            printf("\nOptiune inexistenta\n");
            break;
        }
    } while (optiune != 8);
} // meniul

int main()
{

    meniu();
    return 0;
}