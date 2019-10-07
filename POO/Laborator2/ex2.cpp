#include <iostream>
using namespace std;
class Persoana
{
    char nume[20];
    char prenume[20];
    unsigned int varsta;

public:
    //definirea constructorului clasei
    Persoana(char n[20], char p[20], int v);
    //funcție de afișare
    void afisare_date()
    {
        cout << "Nume: " << nume << endl;
        cout << "Prenume: " << prenume << endl;
        cout << "Varsta: " << varsta << endl;
    }
};
//constructor
Persoana::Persoana(char n[20], char p[20], int v)
{
    strcpy(nume, n);
        strcpy(prenume, p);
    varsta = v;
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