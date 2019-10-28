#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class Lista; //prototipul clasei Lista

class Produse_magazin //clasa de baza Produse_magazin
{
private:
    int tip_derivat;      //Ex. 1 Scanere, 2 Imprimante
    string producator;    //Ex. Samsung, Hp, Lexmark, etc.
    int cod_produs;       //Ex. 232345, 12423, 23563, etc.
    Produse_magazin *urm; //adresa um element din lista
public:
    Produse_magazin(int t, string prod, int cod) //constructor clasa de baza
    {
        tip_derivat = t;
        producator = prod;
        cod_produs = cod;
        urm = NULL; //adresa noului nod este initial NULL
    }
    virtual void afisare() //functia de afisare elemente clasa de baza
    {
        cout << "------------------------------------------";
        cout << "Producator:" << producator << endl;
        cout << "Cod produs:" << cod_produs << endl;
    }
    friend class Lista;
};
class Scanere : public Produse_magazin
{
private:
    string soft_inclus;

public:
    Scanere(int t, string prod, int cod, string soft) : Produse_magazin(t, prod, cod) //constructor clasa derivata
    {
        soft_inclus = soft;
    }

    void afisare() //afisare elemente din clasa Scanere
    {
    Produse_magazin::afisare(); //apelare afisare elemente din clasa de baza
        cout << "Soft inclus:" << soft_inclus << endl;
    }
    friend class Lista;
};
class Imprimante : public Produse_magazin // a doua clasa derivata
{
private:
    string format; //Ex. A3, A3/A4/A5, A4, etc.
public:
    Imprimante(int t, string prod, int cod, string form) : Produse_magazin(t, prod, cod) //constructor
    {
        format = form;
    }

    void afisare()
    {
        Produse_magazin::afisare();
        cout << "Format:" << format << endl;
    }

    friend class Lista;
};
class Lista
{
public:
    Produse_magazin *head;
    void adaugare(Produse_magazin *prod);
    void afisare_lista();
};

class Lista::adaugare(Produse_magazin *a)
{
    Produse_magazin *p;
    p = head;
    if (p)
    {
        if (a->producator == p->producator)
        {
            a->urm = head;
            head = a;
        }
        else
        {
            while (p->urm && (p->urm)->producator == a->producator)
                a = a->urm;
            a->urm = p->urm;
            p->urm = a;
        }
    }
    else
    {
        head = a;
        s
    }
};
void Lista::afisare_lista()
{
    Produse_magazin *a;
    a = head; //se initializeaza cu capul listei

    if (!a) //daca lista este vida
        cout << "Lista este vida! ";
    else
        while (a) //cat timp sunt noduri in lista
        {
            a->afisare(); //se apeleaza afisarea corespunzatoare nodulul curent
            a = a->urm;
            getchar();
        }
};
void introducere(Lista &l, int x) // Introducere info in noduri
{
    int Tip_derivat;    //Ex. 1 Scanere, 2 Imprimante
    string Producator;  //Ex. Samsung, Hp, Lexmark, etc.
    int Cod_produs;     //Ex. 232345, 12423, 23563, etc.
    string Soft_inclus; //Ex. Canon imageFormula, HP Scanjet Enterprise
    string Format;      //Ex. A3, A3/A4/A5, A4, etc.
    Produse_magazin *prodMag;

    cout << "Introduceti producatorul:";
    cin >> Producator;
    cout << "Introduceti codul de produs:";
    cin >> Cod_produs;
    if (x == 0) // daca s - a ales adaugarea unui nou Scanner
    {
        Scanere *Sc;
        cout << "Introduceti softul inclus:";
        cin >> Soft_inclus;
        cout << "Introduceti viteza de scanare:";
        Sc = new Scanere(1, Producator, Cod_produs, Soft_inclus); //apelare construct
        prodMag = Sc;                                             // cast pentru clasa de baza
        l.adaugare(prodMag);                                      // se adauga nodul else if (x - 1) //daca s-a ales adaugarea unei pensiuni
    }
    else if (x == 1)
    {
        Imprimante *Imprim;
        cout << "Introduceti formatul imprimantei";
        cin >> Format;
        Imprim = new Imprimante(2, Producator, Cod_produs, Format); //apelare constructor
        prodMag = Imprim;                                           //cast pentru clasa de baza
        l.adaugare(prodMag);                                        //se adauga nodul
    }
}

int main()
{
    int opt;
    Lista l;
    l.head = NULL;
    do
    {
        system("CLS");
        //meniu
        cout << "1. Adaugare scanere in lista, ordonat dupa producator.\n";
        cout << "2. Adaugare imprimante in lista, ordonat dupa producator.\n";
        cout << "3.Afisare articole din magazin.\n";
        cout << "0.Iesire.\n";
        cout << "Dati optiunea dvs: ";
        cin >> opt;
        // apelare functii in functie de optiunea aleasa switch (opt)
        switch (opt)
        {
        case 1:
            introducere(l, 0);
            break;
        case 2:
            introducere(l, 1);
            break;
        case 3:
            l.afisare_lista();
            break;
        case 0:
            break;
        default:
            cout << "Comanda gresita!";
        }
    } while (opt != 0);
    return 0;
}