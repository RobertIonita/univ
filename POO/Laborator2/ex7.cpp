#include <iostream>
using namespace std;
class Dreptunghi
{
    int latime, lungime;

public:
    Dreptunghi();         //constructor fără parametri
    Dreptunghi(int, int); //constructor cu parametri de tip intreg
    int aria(void)        //funcție care calculează aria
    {
        return (latime * lungime);
    }
};
Dreptunghi::Dreptunghi()
{
    latime = 5;
    lungime = 5;
}
Dreptunghi::Dreptunghi(int a, int b)
{
    latime = a;
    lungime = b;
}
int main()
{
    //crearea unui obiect de tip Dreptunghi care are 2 parametrii de tip întreg și care va apela constructorul cu 2 parametrii
    Dreptunghi drepta(3, 4);
    //crearea unui obiect de tip Dreptunghi care nu are nici un parametru și care va apela constructorul fără parametrii
    Dreptunghi dreptb;
    //afișarea ariei
    cout << "Aria dreptunghi a: " << drepta.aria() << endl;
    cout << "Aria dreptunghi b: " << dreptb.aria() << endl;
    return 0;
}