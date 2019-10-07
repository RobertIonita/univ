#include <iostream>
using namespace std;
class Persoana
{
    char *nume;
    char *prenume;
    unsigned int varsta;

public:
    Persoana(char *n, char *p, int v);
    ~Persoana();
    void afisare_date()
    {
        cout << "Nume: " << nume << endl;
        cout << "Prenume: " << prenume << endl;
        cout << "Varsta: " << varsta << endl;
    }
};
//constructor
Persoana::Persoana(char *n, char *p, int v)
{
    nume = new char[strlen(n) + 1];
    prenume = new char[strlen(p) + 1];
    strcpy(nume, n);
    strcpy(prenume, p);
    varsta = v;
}
//destructor
Persoana::~Persoana()
{
    delete[] nume;
    delete[] prenume;
    cout << "Memorie eliberata!";
}
int main()
{
    //crearea a 3 obiecte de tip Persoana
    Persoana p1("Popescu", "Marian", 20);
    Persoana p2("Ionescu", "Daria", 21);
    Persoana p3("Filipescu", "Dana", 25);
    //afișarea celor 3 obiecte
    p1.afisare_date();
    p2.afisare_date();
    p3.afisare_date();
    return 0;
}