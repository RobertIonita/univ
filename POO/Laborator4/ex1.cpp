#include <iostream>
using namespace std;
class A
{
private:
    int m;

public:
    // se declara clasa B ca fiind clasa prietena a clasei A
    friend class B;
    // declararea functiei g_print_m ca si functie prietena cu clasa A
    friend void g_afiseaza_m();
};
class B
{
public:
    //functia de afisare
    void afiseaza_m()
    {
        A a;
        a.m = 255;
        cout << "clasa B este prietena cu clasa A" << endl
             << " poate accesa membrul privat A::m" << endl
             << a.m << endl;
    }
};
// functia de afisare care este functie friend cu clasa A
void g_afiseaza_m()
{
    A a;
    a.m = 300;
    cout << "functia g_afiseaza_m nu este un membru a clasei A dar este prieten"
         << endl
         << "poate accesa membrul privat A::m " << endl
         << a.m << endl;
}
int main()
{
    //crearea unui obiect de tipul clasei B
    B b;
    //apelarea celor două functii afisare
    b.afiseaza_m();
    g_afiseaza_m();
    return 0;
}