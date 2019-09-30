#include <iostream>
using namespace std;
int main()
{
    // citirea a doua numere intregi
    int x, y;
    cout << "Dati valoarea lui x: ";
    cin >> x;
    cout << "Dati valoarea lui y: ";
    cin >> y;
    //afisarea minimului
    cout << "Minimul este: " << (x < y ? x : y);
    return 0;
}