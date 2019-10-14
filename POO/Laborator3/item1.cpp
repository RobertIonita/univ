#include <iostream>
using namespace std;
// clasa de bază
class Carte
{
    string titlu;

public:
    // constructorul clasei de bază
    Carte(string titlu)
    {
        Carte::titlu = titlu;
    }
    void afis_carte()
    {
        cout << "titlul cartii este " << titlu << endl;
    }

protected:
    float cost;
    void afis_cost()
    {
        cout << "cartea costa " << cost << endl;
    }
};
// clasa derivata
class FisaBiblioteca : public Carte
{
    string autor, editura;

public:
    // constructorul clasei derivate
    FisaBiblioteca(string titlu, string autor, string editura) : Carte(titlu)
    {
        // initializarea variabilelor
        FisaBiblioteca::autor = autor;
        FisaBiblioteca::editura = editura;
        cost = 49.98;
    }
    void afis_biblio()
    {
        afis_carte();
        afis_cost();
        cout << "autor: " << autor << " editura " << editura << endl;
    }
};
int main()
{
    // crearea unui obiect
    FisaBiblioteca fisa("POO", "Vasile Stoicu-Tivadar", "Politehnica");
    // afișarea obiectului
    fisa.afis_biblio();

    return 0;
}