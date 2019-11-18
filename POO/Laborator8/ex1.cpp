#include <iostream>
using namespace std;
// crearea clasei template
template <class TipVector>
class vectorVar
{
    TipVector v[20]; // elementele vectorului
    int index;       // indexul elemetelor vectorului
public:
    vectorVar() { index = 0; }      // initializare vectorVar (constructor)
    void introducere(TipVector ob); // introducere obiect in vectorVar
    void afisare();                 // afisare obiect din vectorVar
};
template <class TipVector>
void vectorVar<TipVector>::introducere(TipVector ob)
{
    v[index] = ob;
    index++;
}
template <class TipVector>
void vectorVar<TipVector>::afisare()
{
    if (index == 0)
    {
        cout << "Vectorul este gol!\n";
    }
    for (int i = 0; i < index; i++)
        cout << v[i] << " ";
}
int main()
{
    //creare vectori de caractere
    vectorVar<char> v1, v2;
    v1.introducere('a');
    v2.introducere('@');
    v1.introducere('b');
    v2.introducere('*');
    v1.introducere('c');
    v2.introducere('&');
    //afisare vectori

    cout << "Vectorii cu elemente de tip char:\n";
    v1.afisare();
    cout << "\n";
    v2.afisare();
    cout << "\n";
    //creare vectori de intregi
    vectorVar<double> x1, x2;
    x1.introducere(1);
    x2.introducere(20);
    x1.introducere(3);
    x2.introducere(40);
    x1.introducere(5);
    x2.introducere(60);
    //afisare vectori
    cout << "Vectorii cu elemente de tip int:\n";
    x1.afisare();
    cout << "\n";
    x2.afisare();
    cout << "\n";
    return 0;
}