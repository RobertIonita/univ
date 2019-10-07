#include <iostream>
using namespace std;
//functie ce returneaza suma a doua numere intregi
int suma(int a, int b)
{
    return a + b;
}
//functie ce returneaza suma a doua numere reale
float suma(float a, float b)
{
    return a + b;
}
int main()
{
    int a, b;
    //citirea celor doua numare intregi
    cout << "Valoare numarului intreg a este: ";
    cin >> a;
    cout << "Valoare numarului intreg b este: ";
    cin >> b;
    //afisarea sumei numerelor intregi
    cout << "Suma celor doua numere intregi este: " << suma(a, b) << endl;
    float x, y;
    //citirea numerelor reale
    cout << "Valoare numarului real x este: ";
    cin >> x;
    cout << "Valoare numarului real y este: ";
    cin >> y;
    //afisarea sumei numerelor reale
    cout << "Suma celor doua numere reale este: " << suma(x, y);
    getchar();
    return 0;
}