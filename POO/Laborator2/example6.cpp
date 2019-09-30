#include <iostream>
using namespace std;
//crearea unei clase
class Dreptunghi
{
    int lungime, latime;

public:
    void setare_valori(int, int);
    int aria(void);
};
//funcția setare valori care a fost declarata in clasa Dreptunghi
void Dreptunghi::setare_valori(int a, int b)
{
    lungime = a;
    latime = b;
}
//functia pentru calcularea ariei
int Dreptunghi ::aria(void)
{
    return (lungime * latime);
}
int main()
{
    //crearea unui obiect de tip Dreptunghi
    Dreptunghi drept;
    //setarea valorilor
    drept.setare_valori(3, 8);
    //afisarea ariei
    cout << "Aria este: " << drept.aria();
    return 0;
}