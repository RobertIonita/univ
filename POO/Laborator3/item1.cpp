#include <iostream>
using namespace std;
// clasa de bază
class Carte
{
    char titlu[64];

public:
    // constructorul clasei de bază
    Carte(char *titlu)
    {
        strcpy(Carte::titlu, titlu);
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
    char autor[64], editura[64];

public:
    // constructorul clasei derivate
    FisaBiblioteca(char *titlu, char *autor, char *editura) : Carte(titlu)
    {
        // initializarea variabilelor
        strcpy(FisaBiblioteca::autor, autor);
        strcpy(FisaBiblioteca::editura, editura);
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