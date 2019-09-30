#include <iostream>
using namespace std;
//functie care va returna o valoarea negativa
int negativ(int &i)
{
    return -i;
}
int main()
{
    int valoare;
    cout << "Dati valoarea: ";
    cin >> valoare;
    cout << "Valoarea negativa este: " << negativ(valoare);
    return 0;
}