#include <iostream>
using namespace std;
class Forma
{
public:
    virtual void afisareNumeForma()
    {
        cout << "Forma -> clasa de baza" << endl;
    }
};
class Punct : public Forma
{
public:
    void afisareNumeForma()
    {
        cout << "Punct -> clasa derivata Punct" << endl;
    }
};
int main()
{
    cout << "Functii apelate prin pointer la Forma:" << endl;
    Forma *ptrForma = new Forma();
    ptrForma->afisareNumeForma();
    cout << "\nFunctii apelate prin pointer la Forma initializat prin pointer la Punct:" << endl;
    Punct *ptrPunct = new Punct();
    ptrForma = ptrPunct;
    cout << "Comportament polimorfic: ";
    ptrForma->afisareNumeForma();
    cout << "\nFunctii apelate prin obiect de tip Forma:" << endl;
    Forma forma;
    forma.afisareNumeForma();
    cout << "\nFunctii apelate prin obiect de tip Punct:" << endl;
    Punct punct;
    punct.afisareNumeForma();
    return 0;
}