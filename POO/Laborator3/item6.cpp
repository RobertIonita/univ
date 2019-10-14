#include <iostream>
using namespace std;
class Persoana
{
    string nume;
    string prenume;
    unsigned int varsta;

public:
    //constructor vid folosit pentru declararea vectorului
    Persoana() {}
    //constructor pentru initializarea variabilelor
    Persoana(string nume, string prenume, unsigned int varsta)
    {
        Persoana::nume = nume;
        Persoana::prenume = prenume;
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
    string returnareNume()
    {
        return Persoana::nume;
    }
    //returnare prenume pentru functia de stergere
    string returnarePrenume()
    {
        return Persoana::prenume;
    }
};
class Angajat : public Persoana
{
    unsigned int salar;
    string departament;

public:
    //constructor vid folosit pentru declararea vectorului
    Angajat() {}
    //constructor pentru initializarea variabilelor
    Angajat(string nume, string prenume, int varsta, string departament, unsigned int salar) : Persoana(nume, prenume, varsta)
    {
        Angajat::departament = departament;
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
    string n, p, d;
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
        {
            //cautare angajat dupa nume
            string num;
            cout << "Dati numele cautat: ";
            cin >> num;
            for (int i = 0; i < nr; i++)
                if (num == angajati[i].returnareNume())
                {
                    cout << "Am gasit angajatul!\n";
                    ok = 1;
                }
            if (ok == 0)
                cout << "Angajatul nu s-a gasit!\n";
            break;
        }
        case 4:
        {
            //stergere angajat dupa prenume
            string pren;
            cout << "Dati prenumele care vreti sa-l stergeti: ";
            cin >> pren;
            for (int i = 0; i < nr; i++)
                if (pren == angajati[i].returnarePrenume())
                {
                    for (int j = i; j < nr; j++)
                        angajati[j] = angajati[j + 1];
                    nr--;
                    ok2 = 1;
                }
            if (ok2 == 0)
                cout << "Prenumele nu exista, nu s-a sters nimic!\n";
            break;
        }
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