#include <iostream>
using namespace std;
//crearea clasei Exemplu
class Exemplu
{
    int x, y;

public:
    void initializare(int, int);
    void afisare();
};
//crearea unei functii inline pentru initializarea a doua variabile intregi
inline void Exemplu::initializare(int a, int b)
{
    x = a;
    y = b;
}
//crearea unei functii inline pentru afisarea celor doua variabile intregi
inline void Exemplu::afisare()
{
    cout << "Valoarea lui x:" << x << endl;
    cout << "Valoarea lui y: " << y;
}
int main()
{
    //crearea unui obiect de tip Exemplu
    Exemplu ex;
    int var1, var2;
    //citirea a doua variabile intregi
    cout << "Valoarea var 1: ";
    cin >> var1;
    cout << "Valoarea var 2: ";
    cin >> var2;
    // apelarea functiei initializare
    ex.initializare(var1, var2);
    // afisarea
    ex.afisare();
    return 0;
}