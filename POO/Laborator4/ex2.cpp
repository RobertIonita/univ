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

void Nod::adaugare_in_fata()
{
    Nod *c;
    //daca lista este vida (prim==0) se aloca primul Nod
    if (!prim)
    {

        6

            prim = new Nod;
        cout << "Dati informatia din nod: ";
        cin >> prim->info;
        //la creare primul si ultimul Nod vor fi identici
        ultim = prim;
        ultim->next = NULL;
    }
    //altfel se adauga un nou element la inceput
    else
    {
        //se aloca un nou Nod
        c = new Nod;
        cout << "Dati informatia din nod: ";
        //se completeaza campul informatie utila
        cin >> c->info;
        //se adauga inaintea primului nod
        c->next = prim;
        //noul nod devine primul
        prim = c;
    }
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