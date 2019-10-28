#include <iostream>
using namespace std;
class baza
{
    int pret;

public:
    int static suma;
    int static contor;
    // constructor
    baza(int g)
    {
        pret = g;
    }
    // funcția virtuala afisare care afiseaza contorul si pretul
    virtual void afisare()
    {
        contor++;
        cout << "valoarea setata pentru clasa de baza: " << pret << " iar valoarea contorului este " << contor << endl;
    }
    // functia care calculeaza suma
    void static inc(baza *t)
    {
        suma = suma + t->pret;
    }
};
// initializarea membrilor statici
int baza::suma = 0;
int baza::contor = 0;
int main()
{
    // crearea unor obiecte de tip clasa baza si afisarea valorilor
    baza *pA = new baza(5);
    pA->afisare();
    baza::inc(pA);
    baza *pA2 = new baza(7);
    pA2->afisare();
    baza::inc(pA2);
    baza *pA3 = new baza(7);
    pA3->afisare();
    cout << "Valoare sumei este: " << baza::suma << endl;
    return 0;
}