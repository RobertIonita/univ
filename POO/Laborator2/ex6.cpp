#include <iostream>
using namespace std;
class Dreptunghi
{
    int latime, lungime;

public:
    void set_values(int, int); //funcție pentru setarea valorilor
    int aria(void)                //funcție pentru calcularea ariei
    {
        return (latime * lungime);
    }
};
void Dreptunghi::set_values(int a, int b)
{
    latime = a;
    lungime = b;
}
int main()
{
    Dreptunghi a, *b, *c;
    Dreptunghi *d = new Dreptunghi[2];
    a.set_values(1, 2);
    c = &a;
    b = new Dreptunghi;
    b->set_values(3, 4);
    d->set_values(5, 6);
    d[1].set_values(7, 8);
    //afișarea ariilor
    cout << "a aria: " << a.aria() << endl;
    cout << "*b aria: " << b->aria() << endl;
    cout << "*c aria: " << c->aria() << endl;
    cout << "d[0] aria: " << d[0].aria() << endl;
    cout << "d[1] aria: " << d[1].aria() << endl;
    return 0;
}