#include <iostream>
using namespace std;
class Carte
{
    char titlu[64];
    float const cost2 = 100;

protected:
    void afis_cost2()
    {
        cout << "costul2 " << cost2 << endl;
    }

public:
    // cconstructor
    Carte(char *titlu)
    {
        strcpy(Carte::titlu, titlu);
        cout << "constructorul clasei de baza1" << endl;
    }
    void afis_carte()
    {
        cout << "titlul cartii este " << titlu << endl;
    }
    // destructor
    ~Carte()
    {
        cout << "destructorul clasei de baza1" << endl;
    }

protected:
    float cost;
    // funcția pentru afișarea costului
    void afis_cost()
    {
        cout << "cartea costa " << cost << endl;
    }
};
class Pagini
{
protected:
    int linii;

public:
    // constructor
    Pagini(int linii)
    {
        Pagini::linii = linii;
        cout << "constructor clasa de baza2" << endl;
    }
    // functia pentru afisare
    void afis_pagini()
    {
        cout << "cartea are nr de pagini " << linii << endl;
    }
    // destructor
    ~Pagini()
    {
        cout << "destructorul clasei de baza2" << endl;
    }
};
// moștenire multipla
class FisaBiblioteca : Carte, Pagini
{
    char autor[64], editura[64];

public:
    // constructor
    FisaBiblioteca(char *titlu, char *autor, char *editura) : Carte(titlu), Pagini(50)
    {
        strcpy(FisaBiblioteca::autor, autor);
        strcpy(FisaBiblioteca::editura, editura);
        cost = 100;
        cout << "Constructorul clasei derivate" << endl;
    }
    // functia de afisare
    void afis_biblio()
    {
        afis_carte();
        afis_cost();
        afis_cost2();
        cout << "autor: " << autor << " editura " << editura << endl;
        afis_pagini();
    }
    // destructor
    ~FisaBiblioteca()
    {
        cout << "Destructorul clasei derivate" << endl;
    }
};
int main()
{
    // crearea unui obiect de tip FisaBiblioteca
    FisaBiblioteca fisa("Programare Orientata pe Obiecte", "Vasile STOICU-TIVADAR",
                        "Politehnica");
    // apelarea functiei de afișare
    fisa.afis_biblio();

    return 0;
}
// Pentru versiuni de Visual Studio inferioare 2015, la declararea constantelor de la începutul
//                                                       codului sursă se va folosi următoarea variantă : ....class Carte
// {
//     char titlu[64];
//     float const cost2;

// protected:
//     void afis_cost2()
//     {
//         cout << "costul2 " << cost2 << endl;
//     }

// public:
//     Carte(char *titlu) : cost2(100)
//     {
//         strcpy(Carte::titlu, titlu);
//         cout << "constructorul clasei de baza1" << endl;
//     }
//     void afis_carte()
//     {
//         cout << "titlul cartii este " << titlu << endl;
//     }
//     ~Carte()
//     {
//         cout << "destructorul clasei de baza1" << endl;
//     }

// protected:
//     float cost;
//     void afis_cost()
//     {
//         cout << "cartea costa " << cost << endl;
//     }
// };