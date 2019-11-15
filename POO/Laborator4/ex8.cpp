#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
class carti
{
    char *autor;
    char *titlu;
    int imprumutat;
    carti *head;
    carti *next;

public:
    carti(char *, char *, int);
    void adaugare();
    void afisare();
};
carti::carti(char *a, char *t, int i)
{
    autor = new char[20];
    titlu = new char[20];
    strcpy(autor, a);
    strcpy(titlu, t);
    imprumutat = i;
    head = NULL;
}
void dynamicRead(char **str, FILE *terminal, char finish)
{
    char ch;
    unsigned long long
        size = 1,
        index = 0;
    *str = (char *)malloc(sizeof(char) * size);
    while ((ch = fgetc(terminal)) != EOF && ch != finish)
    {
        (*str)[index++] = ch;
        if (index == size)
        {
            (*str) = static_cast<char *>(realloc((*str), sizeof(char) * (size += 1)));
        }
    }
    (*str)[index++] = '\0';
}
void carti::adaugare()
{
    cout << "Adaugarea unui nod la inceputul listei" << endl;
    cout << "Dati autorul: ";
    dynamicRead(&autor, stdin, '\n');
    cout << "Dati titlul: ";
    dynamicRead(&titlu, stdin, '\n');
    cout << "Dati starea cartii(imprumutata = 1/ neimprumutata = 0): ";
    cin >> imprumutat;
    carti *c = new carti(autor, titlu, imprumutat);
    c->next = head;
    head = c;
}
void carti::afisare()
{
    carti *c = head;
    while (c != NULL)
    {
        cout << "--------------" << endl;
        cout << "Autor: " << c->autor << endl;
        cout << "Titlu: " << c->titlu << endl;
        cout << "Imprumutat" << c->imprumutat << endl;
        cout << "--------------" << endl;
        c = c->next;
    }
}
int main()
{
    int opt;
    carti *c = new carti(" ", " ", 0);
    do
    {
        cout << "1. Adaugare carte" << endl;
        cout << "2. Afisare carte" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiune: " << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            c->adaugare();
            break;
        case 2:
            c->afisare();
            break;
        }
    } while (opt != 0);
}