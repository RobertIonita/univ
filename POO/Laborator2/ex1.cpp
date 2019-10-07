#include <iostream>
using namespace std;
class Dreptunghi
{
    int latime, lungime;

public:
    //constructor
    Dreptunghi(int, int);
    //functie care calculeaza aria unui dreptungi
    int calcul_arie(void)
    {
        //returnăm aria dreptunghiului
        return (latime * lungime);
    }
};
//constructor
Dreptunghi::Dreptunghi(int a, int b)
{
    //initializam variabilele
    latime = a;
    lungime = b;
}
int main()
{
    //apelare constructor
    Dreptunghi drepta(3, 4);
    //apelare constructor
    Dreptunghi dreptb(5, 6);
    cout << "Aria primului dreptunghi este: " << drepta.calcul_arie() << endl;
    cout << "Aria celui de-al doilea dreptunghi este: " << dreptb.calcul_arie() << endl;
    return 0;
}