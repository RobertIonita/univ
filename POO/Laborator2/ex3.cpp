#include <iostream>
using namespace std;
class Dreptunghi
{
    int *latime, *lungime;

public:
    //declarare constructor
    Dreptunghi(int, int);
    //declarare destructor
    ~Dreptunghi();
    //funcție de calcul a ariei
    int calcul_arie(void)
    {
        return (*latime * *lungime);
    }
};
//constructor
Dreptunghi::Dreptunghi(int a, int b)
{
    //alocare memorie pentru cele două variabile
    latime = new int;
    lungime = new int;
    *latime = a;
    *lungime = b;
}
//destructor
Dreptunghi::~Dreptunghi()
{
    //eliberare memorie
    delete latime;
    delete lungime;
    printf("\nAm eliberat memoria!\n");
}
int main()
{
    //apelare constructor pentru anumite valori
    Dreptunghi drepta(3, 4), dreptb(5, 6);
    //apelare funcție de calcul arie
    cout << "Aria primului dreptunghi este: " << drepta.calcul_arie() << endl;
    cout << "Aria celui de-al doilea dreptunghi este: " << dreptb.calcul_arie() << endl;
    //apelare destructor
    drepta.~Dreptunghi();
    dreptb.~Dreptunghi();
    return 0;
}