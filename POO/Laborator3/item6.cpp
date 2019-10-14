#include <iostream>
using namespace std;
class Persoana
{
    char nume[50];
    char prenume[50];
    unsigned int varsta;

public:
    //constructor vid folosit pentru declararea vectorului
    Persoana() {}
    //constructor pentru initializarea variabilelor
    Persoana(char *nume, char *prenume, unsigned int varsta)
    {
        strcpy(Persoana::nume, nume);
        strcpy(Persoana::prenume, prenume);
        Persoana::varsta = varsta;
    }
    //functie de afisare
    void afisare()
    {
        cout << "-----------------------------\n";
        cout << "Numele: " << Persoana::nume << "\n";
        cout << "Prenume: " << Persoana::prenume << "\n";
        cout << "Varsta: " << Persoana::varsta << "\n";
    }
    //returnare nume pentru functia de cautare
    char *returnareNume()
    {
        return Persoana::nume;
    }
    //returnare prenume pentru functia de stergere
    char *returnarePrenume()
    {
        return Persoana::prenume;
    }
};
class Angajat : public Persoana
{
    unsigned int salar;
    char departament[50];

public:
    //constructor vid folosit pentru declararea vectorului
    Angajat() {}
    //constructor pentru initializarea variabilelor
    Angajat(char *nume, char *prenume, int varsta, char *departament, unsigned int salar) : Persoana(nume, prenume, varsta)
    {
        strcpy(Angajat::departament, departament);
        Angajat::salar = salar;
    }
    //functia de afisare
    void afisare()
    {
        Persoana::afisare();
        cout << "Departament: " << Angajat::departament << "\n";
        cout << "Salar: " << Angajat::salar << "\n";
        cout << endl;
    }
};
int main()
{
    char n[100], p[100], d[100];
    int v, s, ok = 0, ok2 = 0;
    Angajat angajati[20];
    unsigned int nr, opt;
    do
    {
        //meniu
        cout << "1. Introducere angajati" << endl;
        cout << "2. Afisare angajati" << endl;
        cout << "3. Cautare angajati" << endl;
        cout << "4. Stergere angajat" << endl;
        cout << "0. Iesire." << endl;
        cout << " Dati optiunea: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            //citire angajati
            cout << "Dati numarul de angajati: ";
            cin >> nr;
            for (int i = 0; i < nr; i++)
            {
                cout << "Dati numele: ";
                cin >> n;
                cout << "Dati prenume: ";
                cin >> p;
                cout << "Dati varsta:";
                cin >> v;
                cout << "Dati departamentul: ";
                cin >> d;
                cout << "Dati salarul:";
                cin >> s;

                //apelare constructor pentru fiecare angajat si introducerea in vector a angajatilor

                angajati[i] = Angajat(n, p, v, d, s);
            }
            break;
        case 2:
            //afisare angajati
            for (int i = 0; i < nr; i++)
            {
                angajati[i].afisare();
            }
            break;
        case 3:
            //cautare angajat dupa nume
            char num[50];
            cout << "Dati numele cautat: ";
            cin >> num;
            for (int i = 0; i < nr; i++)
                if (strcmp(num, angajati[i].returnareNume()) == 0)
                {
                    cout << "Am gasit angajatul!\n";
                    ok = 1;
                }
            if (ok == 0)
                cout << "Angajatul nu s-a gasit!\n";
            break;
        case 4:
            //stergere angajat dupa prenume
            char pren[20];
            cout << "Dati prenumele care vreti sa-l stergeti: ";
            cin >> pren;
            for (int i = 0; i < nr; i++)
                if (strcmp(pren, angajati[i].returnarePrenume()) == 0)
                {
                    for (int j = i; j < nr; j++)
                        angajati[j] = angajati[j + 1];
                    nr--;
                    ok2 = 1;
                }
            if (ok2 == 0)
                cout << "Prenumele nu exista, nu s-a sters nimic!\n";
            break;
        case 0:
            break;
        default:
            cout << "Optiune gresita!\n"
                 << endl;
            break;
        }
    } while (opt != 0);
    system("pause");
    return 0;
}